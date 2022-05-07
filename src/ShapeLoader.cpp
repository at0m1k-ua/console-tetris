#include "ShapeLoader.h"

ShapeLoader::ShapeLoader()
{
  getFileString();
  generateArrayNumStates();
  this->shapes = new ShapeState[amountShapes];  
  generateShapeStates();
}

ShapeLoader::~ShapeLoader()
{
  delete[] shapes;
}


std::vector<std::string> ShapeLoader::getFileString()
{
  std::ifstream fileInput;
  std::string str;
  std::vector <std::string> lines;
  fileInput.open("shapes.conf");
  if (!fileInput.is_open())
    {
      std::cout<<"Failed to open file \"shapes.conf\""<<std::endl;
      exit(1);
    }
  else
    while(!fileInput.eof())
      {
	std::getline(fileInput, str);
	lines.push_back(str);
      }
  fileInput.close();
  this->fileLines = lines;
  return lines;
}

void ShapeLoader::generateArrayNumStates()
{
  int i = 0;
  for(std::string str: this->fileLines)
  {
    if(std::isdigit(str[0]))
    {
      this->numStates.push_back((int) str[0] - '0');
      i++;
    }
  }
  this->amountShapes = i;
}


void ShapeLoader::generateShapeStates()
{
  bool shapeStateValue[16];
  int i = 0;      // number of line
  for(std::string str: this->fileLines)
  {
    if(str != "")
    {
      if(!std::isdigit(str[0]))
      {
	stringConvertor(str, shapeStateValue, (i%4)*4);   // (i%4)*4 = 0 4 8 12 16 0 4 8 12 16 ...
	i++;
      }
      else
      {
        for(int j = 0; j < 16; j++)
          shapes[(int)(i-4)/4].setValue(j%4,(int) j/4, shapeStateValue[j]); // (i-4)/4 = 0 1 2 3 ... if i = 4 8 12 16 ...
      }
    }
    else if(str == "")
    {
      stringConvertor(str, shapeStateValue, (i%4)*4);
      i++;
    }
  }
}

void ShapeLoader::stringConvertor(std::string str, bool *shapeStateValue, int startIndex)
{
  for(int i = 0; i < (int) str.size(); i++)
  {
    if(!std::isspace(str[i]))
      shapeStateValue[i+startIndex] = true;
    else
      shapeStateValue[i+startIndex] = false;
  }
  for(int i = str.size(); i < 4; i++)
  {
    shapeStateValue[i+startIndex] = false;
  }
}
