#include "ShapeLoader.h"

ShapeLoader::ShapeLoader() {
  getFileString();
}

std::vector<std::string> ShapeLoader::getFileString() {
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
