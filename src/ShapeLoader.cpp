#include "ShapeLoader.h"

using namespace std;

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
  int i = 0;      // number of line (except states quantities)
  for(std::string str: this->fileLines)
  {
    if (str == "" || !isdigit(str[0])) {
      cout << i/4 << i%4 << endl;
      parseToShapeState(str, shapes[i/4], i%4);
      i++;
    }
  }
}

void ShapeLoader::parseToShapeState(string str, ShapeState &state, int y) {
  for (int i = 0; i < (int) str.size(); i++) {
    state.setValue(i, y, !isspace(str.at(i)));
  }
}
