#include "ShapeLoader.h"

ShapeLoader::ShapeLoader()
{
  getFileString();
  generateArrayNumStates();
  this->shapes = new ShapeState[amountShapes];
  this->shapes[0].setValue(0, 0, true);
  std::cout<<this->shapes[0].getValue(0, 0)<< ' ';
  std::cout<<this->shapes[0].getValue(0, 0)<< ' ';
  //generateShapeStates();  <- stacksmashing after end of method's work
  for(int i = 0; i < 16; i++)
  {
    if(i%4 == 0)
      std::cout<<"\n";
    std::cout<<this->shapes[1].getValue(i%4, (int) i/4)<< ' ';
  }
  std::cout<<"\n";
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


ShapeLoader::~ShapeLoader()
{
  delete[] shapes;
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
  int i = 0;
  for(std::string str: this->fileLines)
  {
    if(str != "")
    {
      if(!std::isdigit(str[0]))
      {
	stringConventor(str, shapeStateValue, (i%4)*4);   // (i%4)*4 = 0 4 8 12 16 0 4 8 12 16 ...
	i++;
      }
      else
      {
	if(i == 4)
	  for(int j = 0; j < 16; j++)
	    shapes[(int)(i-4)/4].setValue(j%4,(int) j/4, shapeStateValue[j]); // (i-4)/4 = 0 1 2 3 ... if i = 4 8 12 16 ...
      }
    }
    else if(str == "")
    {
      stringConventor(str, shapeStateValue, (i%4)*4);
      i++;
    }
  }
}

void ShapeLoader::stringConventor(std::string str, bool *shapeStateValue, int startIndex)
{
  if(str == "")
  {
    std::cout<<"1"<<std::endl;
  }
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
