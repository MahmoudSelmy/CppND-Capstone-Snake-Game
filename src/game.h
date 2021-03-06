#ifndef GAME_H
#define GAME_H

#include <random>
#include <thread>
#include <chrono>
#include <future>
#include <mutex>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height, bool has_wall);
  ~Game();
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  void TogglePaused();

 private:
  Snake snake;
  SDL_Point food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void Update(Renderer &renderer);
  void StartBonusCycles();
  void RenderScene(Renderer &renderer);

  bool is_paused;
  bool has_wall;
  bool has_bonus_food;
  std::thread bonusTimer;
  std::mutex mutex;
};

#endif