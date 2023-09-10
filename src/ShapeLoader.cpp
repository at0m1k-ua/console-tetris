#include "ShapeLoader.h"

void ShapeLoader::load() {
    std::vector <std::string> fileLines = getFileLines();  // get lines from shapes.conf
    std::vector <int> numStates = getNumStates(fileLines); // get numbers of shape states
    this->amountShapes = (int) numStates.size();           // get amount of shapes
    auto* states = new ShapeState[amountShapes];           // create an array with initial shape states
    generateShapeStates(states, fileLines);                // generate shape states from file lines
    generateShapes(states, numStates);                     // generate shapes and save them in ShapeLoader object
}

std::vector<std::string> ShapeLoader::getFileLines()
{

	std::ifstream fileInput;
	std::string str;
	std::vector <std::string> lines;

	fileInput.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    // info about ifstream bits are got from this lesson:
    // https://www.youtube.com/watch?v=dQw4w9WgXcQ

	try
	{
		fileInput.open("../shapes.conf");
	}
	catch(const std::ifstream::failure& ex)
	{
		std::cout << "Cannot find file \"shapes.conf\"" << std::endl;
	}

	while(!fileInput.eof())
	{
		std::getline(fileInput, str);
		lines.push_back(str);
	}
	fileInput.close();
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
  int i = 0;      // number of line (except state quantities)
  for(std::string str: fileLines)
    if(str.empty() || !std::isdigit(str[0]))
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

void ShapeLoader::generateShapes(ShapeState* states, std::vector <int> &numStates)
{
    shapes = new Shape*[amountShapes];
    for (int i = 0; i < amountShapes; i++)
        shapes[i] = new Shape(&states[i], numStates.at(i));
}

Shape* ShapeLoader::getShape(int num)
{
    return shapes[num];
}

int ShapeLoader::getAmount()
{
    return this->amountShapes;
}