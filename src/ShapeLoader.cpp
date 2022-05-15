#include "ShapeLoader.h"

void ShapeLoader::load() {
    std::vector <std::string> fileLines = getFileString();
    std::vector <int> numStates = getNumStates(fileLines);
    this->amountShapes = (int) numStates.size();
    auto* states = new ShapeState[amountShapes];
    generateShapeStates(states, fileLines);
    generateShapes(states, numStates);
}

std::vector<std::string> ShapeLoader::getFileString()
{
  std::ifstream fileInput;
  std::string str;
  std::vector <std::string> lines;
  
  fileInput.exceptions(std::ifstream::badbit | std::ifstream::failbit);
  try
  {
    fileInput.open("../shapes.conf");
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

std::vector <int> ShapeLoader::getNumStates(std::vector <std::string> &fileLines)
{
  std::vector <int> numStates;
  for(std::string str: fileLines)
  {
    if(std::isdigit(str[0]))
    {
      numStates.push_back((int) str[0] - '0');
    }
  }
  return numStates;
}


void ShapeLoader::generateShapeStates(ShapeState* states, std::vector <std::string> &fileLines)
{
  int i = 0;      // number of line (exept state quatities)
  for(std::string str: this->fileLines)
    if(str == "" || !std::isdigit(str[0]))
    {
      parseToState(str, states[i/4], i%4);
      i++;
    }
}

void ShapeLoader::parseToState(std::string str, ShapeState &currentState, int y)
{
  for(int i = 0; i < (int) str.size(); i++)
    currentState.setValue(i, y, !isspace(str.at(i)));
}

void ShapeLoader::generateShapes(ShapeState* states)
{
    shapes = new Shape*[amountShapes];
    for(int i = 0; i < amountShapes; i++)
    {
        shapes[i] = new Shape(&states[i], numStates.at(i), 0);
    }
}

Shape* ShapeLoader::getShape(int num)
{
    return shapes[num];
}

int ShapeLoader::getAmount() const
{
    return this->amountShapes;
}