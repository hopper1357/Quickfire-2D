# Raylib JS Game Engine

## Overview

This is a 2D game engine built with Raylib and QuickJS, as described in the `raylib_js_game_engine_full_draft.md` document. The goal is to create a flexible and powerful engine for creating 2D games, with a focus on scripting and modding capabilities.

## TODO

This is a list of the main components from the design document that need to be implemented.

- [x] Rendering & Visuals
- [x] Input & Controls
- [ ] Audio & Music
- [ ] Physics & Collisions
- [ ] Scripting & Modding (QuickJS)
- [ ] Game Mode / Scene System
- [ ] UI & HUD
- [ ] WYSIWYG Map & UI Editor
- [ ] Data & Persistence
- [ ] Advanced Features & Performance
- [ ] Map Logic / Trigger System
- [ ] Trigger Library
- [ ] Object Pooling & Entity System
- [ ] Memory Management & Performance
- [ ] Mini-Game Example
- [ ] Map Maker + Logic Editor

## Requirements

- `gcc`
- `make`
- Raylib dependencies: `sudo apt-get install -y libxrandr-dev libxcursor-dev libxinerama-dev libxi-dev`
- For running in a headless environment: `sudo apt-get install -y xvfb`

## How to compile and run

The `libraylib.a` file is not included in this repository. You need to build it from source first.

### 1. Build Raylib

```bash
# Install raylib dependencies
sudo apt-get update && sudo apt-get install -y libxrandr-dev libxcursor-dev libxinerama-dev libxi-dev

# Clone and build raylib
git clone https://github.com/raysan5/raylib.git /tmp/raylib
cd /tmp/raylib/src && make
```

### 2. Copy the Raylib library

Copy the generated `libraylib.a` from `/tmp/raylib/src` to the `lib` directory of this project.

```bash
cp /tmp/raylib/src/libraylib.a lib/
```

### 3. Build the game engine

```bash
make
```

### 4. Run the game

To run in a headless environment:

```bash
# Install xvfb if you haven't already
sudo apt-get install -y xvfb

# Run the game
xvfb-run ./build/game
```
