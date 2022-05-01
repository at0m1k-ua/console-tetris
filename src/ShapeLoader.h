#pragma once
#ifndef _SHAPELOADER_H
#define _SHAPELOADER_H
#include "Shape.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
class ShapeLoader {
  std::vector <std::string> shapes;
  std::vector <int> numStates;
  std::vector <std::string> fileLines;
  int amountShapes;
  std::vector<std::string>getFileString();
 public:
  ShapeLoader();
  Shape* getShape(int number);
  int getAmonunt();
};


#endif
