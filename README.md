# Munchkin Game

## Overview

This repository contains an implementation of the **Munchkin card game** in C++. The game features strategic role-playing with turn-based mechanics, simulating the popular Munchkin card game where players draw cards, battle monsters, and gain treasures.

## Features

- **Turn-Based Gameplay**: Players engage in battles, level up, and collect treasures.
- **Card System**: Includes **monsters, treasures, curses**, and **classes** cards.
- **Leveling System**: Players progress by defeating monsters and using abilities.
- **Multiplayer**: Supports multiple players.
- **Randomized Deck**: Provides a unique game experience each time.

## Technologies

- **Language**: C++
- **Libraries**: Standard C++ Library

## Installation

### Prerequisites

- **C++ Compiler** (e.g., GCC, Clang)
- **CMake** (for building the project)

### Steps

1. Clone the repository:
   ```bash
   git clone https://github.com/gilianb/Munchkin_game.git
   cd Munchkin_game
Build the project:

bash
Copier
Modifier
mkdir build
cd build
cmake ..
make
Usage
Run the game by executing:

bash
Copier
Modifier
./munchkin_game
Example Gameplay
cpp
Copier
Modifier
#include "Game.h"

int main() {
    std::vector<std::string> players = {"Alice", "Bob", "Charlie"};
    Game game(players);
    game.start();
}
Contributing
We welcome contributions! To contribute:

Fork the repository.

Create a new branch for your feature or bug fix.

Commit your changes.

Push to your fork and submit a pull request.

License
This project is licensed under the MIT License. See the LICENSE file for details.

Contact
For questions or suggestions, please contact:

Gilian B.

GitHub: @gilianb

⭐ If you find this project useful, please consider giving it a star! ⭐
