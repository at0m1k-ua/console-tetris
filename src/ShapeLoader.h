#pragma once
#ifndef _SHAPELOADER_H_
#define _SHAPELOADER_H_
#include "Shape.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
class ShapeLoader {
  ShapeState* shapes;
  std::vector <int> numStates;
  std::vector <std::string> fileLines;
  int amountShapes;
  std::vector<std::string>getFileString();
  void generateArrayNumStates();
  void generateArrayShapeStates();
  void stringConvertor(std::string str, bool* shapeStateValue, int startIndex);
public:
  ShapeLoader();
  ~ShapeLoader();
  void generateShapeStates();
  Shape* getShape(int number);
  int getAmount();
};


#endif
