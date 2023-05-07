#  Racing Game
---
The group project for the 4th semester.
Authors:
Klimenteva Maria
Sharlovsky Ivan
Grigory Guskov
Alexander Kuntsevich

---
### Distribution of tasks
1) Map: representation of it in memory, and reading from a file (Maria)
2) Map display on SDL window (Maria)
3) Machine Physics + keystroke processing (Grigory)
4) User interface: menu with buttons to start the game (Alexander)
5) Displaying the car on the SDL window + connection with the physics of the car (Maria)
6) General game logic and structure (Maria)
7) Table of records (Ivan)
8) Points and time counter
9) Camera (Maria)
### How the project works
The car moves across the screen by pressing the keys: W, A, D, space. Your task in the game is not to run into obstacles and earn as many points as possible. In the table of records you can find your personal records.

Everything is very simple. In the game window you see green obstacles, hitting them takes away your points (-20). There are also multi-colored checkpoints: yellow +10, blue +20, purple +40. If you reach the finish line, you will finish the game and get +20 points.
### How to build and run
Clone the repository to yourself: https://github.com/MariaKlimenteva/racing_game
Next you need to download vcpkg using: https://vcpkg.io/en/getting-started.html
To build, run the root cmake.