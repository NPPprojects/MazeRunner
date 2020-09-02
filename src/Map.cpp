#include "Map.h"



Map::Map(std::string _path)
{
  initialiseMap();

  std::ifstream file(_path.c_str());

  if (!file.is_open())
  {
    throw std::exception();
  }

  std::string line;
  std::vector < std::string > Splitline;

  int tempX(0);
  int tempY(0);

  while (!file.eof())
  {
    std::getline(file, line);                                 // Stores data in a string
    splitStringWhitespace(line, Splitline);                                    //removing the blank spaces from string

    mapWidth = atoi(Splitline.at(0).c_str());                                //first and second characters of the string will give the size of the maze
    mapHeight = atoi(Splitline.at(1).c_str());                                //so they are converted into an int and stored for later

    for (int i = 2; i < Splitline.size(); i++)
    {
      mapData[tempX][tempY] = atoi(Splitline.at(i).c_str());
      tempX++;
      //std::cout << mapData[SYSXtemp][SYSYtemp] << " ";
      if (tempX >= mapWidth)
      {
        tempX = 0;
        tempY++;
        //		std::cout << std::endl;
      }
    }
    file.close();
    //finding starting point
    for (int y = 0; y < mapHeight; y++)
    {
      for (int x = 0; x < mapWidth; x++)
      {
        if (mapData[x][y] == 2)
        {
          yStart = y;
          xStart = x;
        }
        if (mapData[x][y] == 3)
        {
          yFinish = y;
          xFinish = x;
        }
      }
    }
    std::cout << "Starting point:(X/Y) " << xStart << "," << yStart << std::endl;
    //finding finish point


  }

}
void Map::printMap()
{
  for (int y = 0; y < mapHeight; y++)
  {
    std::cout<<""<<std::endl;
    for (int x = 0; x < mapWidth; x++)
    {
      if (mapData[x][y] == 0)
        std::cout << "0" << " ";
      else if (mapData[x][y] == 1)
        std::cout << "1" << " "; //Wall
      else if (mapData[x][y] == 2)
        std::cout << "2" << " "; //start
      else if (mapData[x][y] == 3)
        std::cout << "3" << " "; //finish
      else if (mapData[x][y] == 4)
        std::cout << "R" << " "; //route
    }
  }
}
//function that removes the white space from the text file
void Map::splitStringWhitespace(std::string& input, std::vector<std::string>& output)
{
  std::string curr;
  output.clear();
  for (size_t i = 0; i < input.length(); i++)
  {
    if (input.at(i) == ' ' ||
      input.at(i) == '\r' ||
      input.at(i) == '\n' ||
      input.at(i) == '\t')
    {
      if (curr.length() > 0)
      {
        output.push_back(curr);
        curr = "";
      }
    }
    else
    {
      curr += input.at(i);
    }
  }
  if (curr.length() > 0)
  {
    output.push_back(curr);
  }
}

void Map::initialiseMap() 
{
  mapData.resize(20, std::vector<int>(20));
  for (int i = 0; i < 20; i++) // initialise all map values to 1
  {
    for (int j = 0; j < 20; j++)
    {
      mapData[j][i] = 0;
    }
  }

}
