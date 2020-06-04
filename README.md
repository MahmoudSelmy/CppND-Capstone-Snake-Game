# CPPND: Capstone Snake Game Example

This is the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## New Features
* Pause
  * Game can be **paused/resumed** by pressing `ESC` button.  

* Support 2 modes: 

  * Game asks user before launch to choose one of them.
  
    * Default mode

    * Wall mode

* Result message box shows when snake dies.

* Random bouns periods:
  
  * There is random periods of bonus, it simply add +5 score to each food sample eaten during these periods "the food samples turns to green instead of yellow during the bonus period"


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Rubric Points

- Loops, Functions, I/O

  1. The project accepts user input and processes the input. 
     - [Line 14 @ main.cpp](./src/main.cpp)
  1. The project demonstrates an understanding of C++ functions and control structures.
     - Project is structured into classes and functions

- Object Oriented Programming
  
  1. The project uses Object Oriented Programming techniques. 
     - Project contains classes [controller. game, renderer ,and snake]
  1. Classes use appropriate access specifiers for class members.
     - Any class uses public and private access specifiers to expose abstract API and hide the details. 
     - Example : [Game Class](./src/game.h)
       - Run(...) is public because it allows client to run the game. [line 18]
       - PlaceFood(...) is private because it's an implementation details.
  1. Class constructors utilize member initialization lists.
     - [Line 6 @ game.cpp](./src/game.cpp)
  1. Classes encapsulate behavior.
     - [Lines 24:45 @ game.cpp](./src/game.h)

- Memory Management
  1. The project makes use of references in function declarations.
     - Run(..) takes controller and renderer by reference [Line 18 @ game.cpp](./src/game.h)
  1. The project uses destructors appropriately.
     - Using destructor to join thread before destruction.[Line 27 @ game.cpp](./src/game.cpp)
  1. The project uses move semantics to move data, instead of copying it, where possible.
     - Initilize thread member using move semantics [Line 23 @ game.cpp](./src/game.cpp)

- Concurrency

  1. The project uses multithreading.
     - Background thread to provide random cycles [Line 23 @ game.cpp](./src/game.cpp)
  1. A mutex or lock is used in the project.
     - Using mutex and locks to prevent race condition[Line 140 @ game.cpp](./src/game.cpp)