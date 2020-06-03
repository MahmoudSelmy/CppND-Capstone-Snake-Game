#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height, const bool has_wall);
  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food, const bool &has_bonus);
  void UpdateWindowTitle(int score, int fps);

 private:
  void RenderWall(SDL_Rect &block);
  void RenderFood(SDL_Point const &food, SDL_Rect &block, const bool &has_bonus);
  
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
  const bool has_wall;
};

#endif