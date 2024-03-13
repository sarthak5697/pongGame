video link : https://ik.imagekit.io/uqqv36val/video/pingPong.mp4?updatedAt=1710337691324

# Pong Game

This is a simple Pong game implemented in C++ using the Raylib library. The game features a player paddle, a CPU-controlled paddle, and a ball that bounces between them. The objective is to score points by successfully hitting the ball past the opponent's paddle.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Game Controls](#game-controls)
- [Dependencies](#dependencies)
- [Contributing](#contributing)
- [License](#license)

## Features

- Player-controlled paddle
- CPU-controlled paddle
- Bouncing ball with scoring logic
- Simple collision detection
- Score tracking for both the player and CPU
- Visual elements using Raylib drawing functions

## Installation

### Prerequisites

- C++ compiler
- Raylib library installed

### Build and Run

1. Clone the repository:

    ```bash
    git clone https://github.com/your-username/pong-game.git
    ```

2. Navigate to the project directory:

    ```bash
    cd pong-game
    ```

3. Compile the code:

    ```bash
    g++ main.cpp -o pong_game -lraylib -IC:/path/to/raylib/src -LC:/path/to/raylib/src -Wl,-rpath,C:/path/to/raylib/src
    ```

    Make sure to replace `/path/to/raylib/src` with the actual path to the Raylib source folder on your system.

4. Run the executable:

    ```bash
    ./pong_game
    ```

## Usage and Game Controls

- Use the UP and DOWN arrow keys to control the player paddle.
- The CPU-controlled paddle will automatically move to try and hit the ball.
- Score points by getting the ball past the CPU-controlled paddle.
- The game window will close when you exit the game.
- UP Arrow Key:** Move player paddle up.
- DOWN Arrow Key:** Move player paddle down.

## Dependencies

- [Raylib](https://github.com/raysan5/raylib): A simple and easy-to-use library to learn videogames programming.

## How to use this template
1. Double click on the main.code-workspace file. This will open the template in VS Code.
2. From the Explorer Window of VS Code navigate to the src folder and double click on the main.cpp file.
3. Press F5 on the keyboard to compile and run the program.

