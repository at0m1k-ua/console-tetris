#include "ShapeLoader.h"

ShapeLoader::ShapeLoader() {
  getFileString();
}

std::vector<std::string> ShapeLoader::getFileString() {
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
