# 🎮 so_long

**so_long** is a 2D game project from the 42 curriculum that introduces basic graphics programming in C using the MiniLibX library.  
The goal is to create a small top-down game where the player collects items and reaches an exit, all while learning how to handle textures, events, and simple game loops.

---

## 🧠 Project Overview

You’ll build a simple game where:
- The player moves around a map using the keyboard.
- The goal is to collect all collectibles and then reach the exit.
- The game ends when all items are collected and the player reaches the exit.
- The map is read from a file with the `.ber` extension.

This project teaches event handling, window management, and image rendering using **MiniLibX**.

---

## ⚙️ How It Works

1. The game reads a map file (e.g. `map.ber`) containing:
   - `1` → Wall  
   - `0` → Floor  
   - `C` → Collectible  
   - `E` → Exit  
   - `P` → Player start position

2. The map is checked for validity:
   - Surrounded by walls  
   - Contains one player, one exit, and at least one collectible  
   - Rectangular shape  
   - Reachability of all collectibles and the exit is verified (flood fill algorithm is often used)

3. The game uses **MiniLibX** to:
   - Create a window  
   - Display images (player, walls, collectibles, etc.)  
   - Handle keypress events for player movement  

---

## 🧩 Example Map
111111
1P0C01
100001
1C0E11
111111


---

## 🕹️ Controls

| Key | Action |
|-----|--------|
| W / ↑ | Move up |
| A / ← | Move left |
| S / ↓ | Move down |
| D / → | Move right |
| ESC | Exit game |

Each move increases the move counter, which is printed to the terminal.

---

## 🧱 Key Concepts

- Reading and validating `.ber` map files  
- Using **MiniLibX** for graphics  
- Handling keyboard events  
- Managing game states (win/lose, moves, collectibles)  
- Implementing flood fill algorithms for map validation  
- Resource management (avoiding memory leaks and freeing images/windows properly)

---

## 🧪 Example Run

$ ./so_long maps/map.ber


When you move your player, the terminal will display the number of moves.

---

## 🛠️ Compilation

Compile the game with:

make


To recompile from scratch:

make re

To clean object files:

make clean


---

## 📁 Files

- `so_long.c` — Entry point of the program  
- `map.c` — Map reading and validation  
- `render.c` — Handles rendering of the game window  
- `events.c` — Keyboard input handling  
- `utils.c` — Helper functions  
- `so_long.h` — Header file  
- `assets/` — Folder containing your `.xpm` textures  
- `maps/` — Example map files (`.ber`)

---

## 🧾 License

This project is part of the **42 School Curriculum** and is intended for educational purposes only.

---

## 🌟 Learning Goals

- Gain first-hand experience with a graphics library  
- Understand event-driven programming  
- Learn how to manage memory and resources in interactive C programs  
- Build the foundation for more advanced graphical or game projects



