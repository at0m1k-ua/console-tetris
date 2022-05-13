#include "ShapeLoader.h"

ShapeLoader::ShapeLoader()
{
  getFileString();
  generateArrayNumStates();  
  std::vector <ShapeState> states = generateShapeStates();
}

std::vector<std::string> ShapeLoader::getFileString()
{
  std::ifstream fileInput;
  std::string str;
  std::vector <std::string> lines;
  
  fileInput.exceptions(std::ifstream::badbit | std::ifstream::failbit);
  try
  {
    fileInput.open("shapes.conf");
  }
  catch(const std::ifstream::failure& ex)
  {
    std::cout << ex.what() << std::endl;
  }
  
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


std::vector<ShapeState> ShapeLoader::generateShapeStates()
{
  std::vector<ShapeState> states(amountShapes);
  int i = 0;      // number of line (exept state quatities)
  for(std::string str: this->fileLines)
    if(str == "" || !std::isdigit(str[0]))
    {
      parseToState(str, states[i/4], i%4);
      i++;
    }
  return states;
}

void ShapeLoader::parseToState(std::string str, ShapeState &currentState, int y)
{
  for(int i = 0; i < (int) str.size(); i++)
    currentState.setValue(i, y, !isspace(str.at(i)));
}
