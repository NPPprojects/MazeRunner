#include "Menu.h"
#include "Map.h";
#include <memory>
Menu::Menu()
{
  windowWidth = 640;
  windowHeight = 480;

  running = true;

  run();
}

void Menu::run()
{
  while (running)
  {
    printToConsole();
    std::cin >> userInput;
    processInput();
    std::shared_ptr<Map> map = std::make_shared<Map>(path);
    map->printMap();
    map->renderMap();
  }
}

void Menu::printToConsole()
{
  std::cout << "Select Map" << std::endl;
  std::cout << "[1] 4x6 Map " << std::endl;
  std::cout << "[2] 6x4 Map"<< std::endl;
  std::cout << "[3] 10x10 Map" << std::endl;
  std::cout << std::endl;
}

void Menu::processInput()
{
  if (userInput == "1")
  {
    std::cout << "4x6 Map was selected" << std::endl;
    path = "../resources/4x6MAZE.txtt";
  }
  else if (userInput == "2")
  {
    std::cout << "6x4 Map was selected" << std::endl;
    path = "../resources/6x4MAZE.txtt";
  }
  else if (userInput == "3")
  {
    std::cout << "10x10 Map was selected" << std::endl;
    path = "../resources/10x10MAZE.txtt";
  }
  else
  {
    std::cout << "Invalid input" << std::endl;
   ;
  }
}
