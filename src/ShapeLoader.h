#pragma once
#ifndef _SHAPELOADER_H_
#define _SHAPELOADER_H_
#include "Shape.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
class ShapeLoader {
  
  std::vector <Shape> shapes;
  std::vector <int> numStates;
  std::vector <std::string> fileLines;
  int amountShapes = 0;
  
  std::vector<std::string>getFileString();
  void generateArrayNumStates();
  std::vector<ShapeState> generateShapeStates();
  void parseToState(std::string str, ShapeState &currentState, int y);
  
public:
  
  ShapeLoader();
  Shape* getShape(int number);
  int getAmount();
  
};


#endif
