#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

bool hasWall = false;

void ConfigureGame()
{
  while (true)
  {
    int hasWallResponces;
    std::cout << "Which mode?: [1] wall [2] default : " << std::endl;
    std::cin >> hasWallResponces;
    if ((hasWallResponces != 1) && (hasWallResponces != 2))
    {
      std::cout << "Please enter a valid number !!" << std::endl;
      continue;
    }
    hasWall = hasWallResponces == 1;
    return;
  }
}
int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  ConfigureGame();
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight, hasWall);
  Controller controller;
  Game game(kGridWidth, kGridHeight, hasWall);

  game.Run(controller, renderer, kMsPerFrame);

  renderer.ShowResultMessage(game.GetScore(), game.GetSize());
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}