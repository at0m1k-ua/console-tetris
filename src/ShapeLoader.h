#pragma once
#ifndef _SHAPELOADER_H_
#define _SHAPELOADER_H_
#include "Shape.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
class ShapeLoader {

    Shape** shapes = nullptr;
    int amountShapes = 0;

    static std::vector <std::string> getFileLines();
    static std::vector <int> getNumStates(std::vector <std::string> &fileLines);
    static void generateShapeStates(ShapeState* states, std::vector <std::string> &fileLines);
    static void parseToState(std::string str, ShapeState &currentState, int y);
    void generateShapes(ShapeState* states, std::vector <int> &numStates);

public:

    void load();
    Shape* getShape(int number);
    int getAmount();
  
};


#endif
