*This project has been created as part of the 42 curriculum by adecauch, ramahrez.*

# Cub3D

A 3D game engine using raycasting, inspired by the legendary Wolfenstein 3D (1992).

## Description

Cub3D is a first-person maze exploration game built from scratch in C using the MinilibX graphics library. The project implements a raycasting engine to render a 3D perspective view of a 2D map, similar to the technique pioneered by id Software in Wolfenstein 3D.

**Goal:** Navigate through the maze, collect all items, and reach the exit while avoiding the Slenderman enemy.

### Features

**Mandatory:**
- Raycasting engine with DDA algorithm
- Textured walls (different textures for N/S/E/W)
- Configurable floor and ceiling colors
- Smooth player movement (WASD) and rotation (arrow keys)
- Map parsing with error handling
- Clean window management (ESC, red cross)

**Bonus:**
- Wall collision detection
- Circular minimap with real-time player position
- Interactive doors (open/close with E key)
- Animated sprites (collectibles)
- Mouse-based camera rotation

**Extra Features:**
- Slenderman enemy AI that chases the player
- Collectible items system
- Win/Game Over screens with animations
- Start menu with navigation
- Retry system after game over
- Dynamic difficulty (enemy speeds up as you collect items)

## Instructions

### Requirements

- macOS or Linux
- MinilibX library (included in `inc/mlx_macos` and `inc/mlx_linux`)
- GCC or Clang compiler

### Compilation

```bash
make        # Compile the project
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile from scratch
```

### Execution

```bash
./cub3D <map_file.cub>
```

Example:
```bash
./cub3D data/map/good/test_textures.cub
```

### Controls

| Key | Action |
|-----|--------|
| W / Up Arrow | Move forward |
| S / Down Arrow | Move backward |
| A | Strafe left |
| D | Strafe right |
| Left/Right Arrow | Rotate view |
| Mouse | Rotate view |
| E | Open/Close doors |
| Enter | Confirm menu selection / Retry after game over |
| ESC | Exit game |

### Map Format

Maps use the `.cub` extension with the following structure:

```
NO ./path_to_north_texture.xpm
SO ./path_to_south_texture.xpm
WE ./path_to_west_texture.xpm
EA ./path_to_east_texture.xpm

F 220,100,0
C 225,30,0

111111111
100000001
10C00X001
100D00001
1000N0001
111111111
```

**Configuration:**
- `NO/SO/WE/EA` - Wall textures paths
- `F` - Floor color (R,G,B)
- `C` - Ceiling color (R,G,B)

**Map Characters:**
| Char | Description |
|------|-------------|
| 0 | Empty space |
| 1 | Wall |
| N/S/E/W | Player spawn (with direction) |
| D | Door (closed) |
| C | Collectible |
| X | Exit |
| s | Slenderman spawn |

## Resources

### References

- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) - Comprehensive raycasting guide
- [Wolfenstein 3D Black Book](https://fabiensanglard.net/gebbwolf3d/) - Technical deep-dive into Wolf3D
- [42 Docs - MinilibX](https://harm-smits.github.io/42docs/libs/minilibx) - MLX documentation
