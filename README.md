# CUB3D
A 3D game engine using raycasting technology, similar to Wolfenstein 3D (1992).

## Project Overview
This project implements a 3D game engine using the raycasting technique. It reads a .cub file containing map information and renders a 3D maze using first-person perspective.

#  Ilustration of the Project

[Screencast from 02-28-2025 04:39:36 PM.webm](https://github.com/user-attachments/assets/150450ce-bcc0-4d70-ab37-8ce6d29734b4)

## Features
- 3D maze rendering using raycasting
- Texture mapping for walls
- Player movement and rotation
- Minimap display
- Color management for floor and ceiling

## Installation
### Linux
```bash
git clone https://github.com/flaviogonca/Cub3D.git
cd Cub3D
make
```

2. Install minilibx:
```bash
cd minilibx_opengl
make
sudo cp mlx.h /usr/local/include
sudo cp libmlx.a /usr/local/lib
sudo reboot
```

## Usage
```bash
make                    # Compile cub3D executable
./cub3d maps/map.cub        # Run with a specific map
```

## Map File Format
The .cub file must contain:
```markdown
R 1920 1080    # Resolution
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 184,113,39    # Floor color (RGB)
C 51,198,227    # Ceiling color (RGB)

         1111111111
         1000000001
         1011000001
         1000000001
111111111011000000000001
100000000011000000000001
1111011111111101110000001
```

## Technical Implementation
### Raycasting Algorithm
The engine uses a raycasting algorithm that:
1. Calculates wall distances using trigonometry
2. Projects 3D space onto a 2D screen
3. Handles texture mapping for walls
4. Manages sprite rendering

### Key Components
- **Map Parsing**: Reads and validates .cub files
- **Raycasting Engine**: Handles 3D rendering
- **Event System**: Manages keyboard and mouse input
- **Texture Management**: Handles XPM texture files
- **Memory Management**: Proper memory allocation and deallocation

## Bonus Features
- Wall collisions
- Minimap display
- Doors
- Animations
- Mouse rotation

## Dependencies
- minilibx (for graphics)
- libft (for string manipulation)
- X11 (for window management)

## Developed By:
Flávio Malungo & Gilson Bravo (https://github.com/gilson-chipombo)
