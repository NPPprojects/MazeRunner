#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <SDL2/SDL.h>
  

class Map
{
public:
  
  Map(std::string _path);
  
  void printMap();

  void renderMap();

private:

  int mapWidth;
  int mapHeight;

  int xStart, yStart;
  int xFinish, yFinish;

  std::vector<std::vector<int>> mapData; // A 2d vector to hold map data

  void splitStringWhitespace(std::string & input, std::vector<std::string>& output);
  void initialiseMap();
  std::vector<std::vector<int>> getMapData();
};