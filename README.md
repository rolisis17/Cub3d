# Cub3D

Cub3D is a small raycasting engine written in C with MiniLibX. It recreates the core rendering idea behind early 3D games: a 2D map is interpreted as a world, and the player sees a textured first-person projection of it.

This is one of the more visual 42 projects, combining parsing, math, graphics, input handling, and careful memory management.

## What it does

- Reads and validates `.cub` map files
- Checks wall closure and player spawn rules
- Loads wall textures
- Renders a textured first-person scene using raycasting
- Handles player movement with `W`, `A`, `S`, and `D`
- Handles camera rotation with the arrow keys
- Performs collision checks against the map
- Uses MiniLibX for the window, input, and pixel output

## Tech stack

- C
- MiniLibX
- libft
- Make
- Linux/X11 graphics dependencies

## Build

```bash
make
```

## Run

```bash
./cub3D map1.cub
```

You can also try:

```bash
./cub3D map2.cub
```

## Controls

```text
W / S          Move forward / backward
A / D          Strafe left / right
Left / Right   Rotate camera
Esc            Exit
```

## Repository structure

```text
cube.c              Program entry and render loop
parse.c, map*.c     Map parsing and validation
projection.c        Raycasting projection logic
move.c              Movement and collision
texture.c           Texture loading and sampling
libft/              Custom C utility library
mlx_linux/          MiniLibX dependency
textures/           Wall texture assets
```

## Technical highlights

- Uses ray direction, camera plane, and DDA-style stepping to find visible walls
- Separates parsing/validation from rendering and movement
- Stores per-wall texture data for directional wall rendering
- Applies collision checks before updating player position
- Keeps graphics output close to the pixel buffer for performance and control

## Useful commands

```bash
make clean
make fclean
make re
make valgrind
```

## Skills demonstrated

- Raycasting math
- Graphics programming in C
- File parsing and validation
- Event-driven input handling
- Manual memory management
- Turning a strict specification into an interactive program
