# Cub3D

A small raycasting engine inspired by early 3D games. Built in C with MiniLibX as part of the 42 graphics curriculum.

## What it does

- Parses `.cub` map files
- Renders a textured 3D scene from a 2D map
- Handles player movement and camera rotation
- Loads wall textures and validates map configuration
- Uses MiniLibX for window creation, input, and pixel rendering

## Tech stack

- C
- MiniLibX
- libft
- Make

## Build

On Linux with MiniLibX dependencies installed:

```bash
make
```

## Run

```bash
./cub3D map1.cub
```

## Useful commands

```bash
make clean
make fclean
make re
make valgrind
```

## Skills practiced

- Raycasting math
- Manual memory management
- Texture mapping
- Input handling
- Parsing and validation
- Low-level graphics programming
