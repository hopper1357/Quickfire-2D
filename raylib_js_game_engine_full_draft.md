# 2D Game Engine Design Document (Raylib + QuickJS) - Full Draft Pre-Code

## Table of Contents
1. Rendering & Visuals
2. Input & Controls
3. Audio & Music
4. Physics & Collisions
5. Scripting & Modding (QuickJS)
6. Game Mode / Scene System
7. UI & HUD
8. WYSIWYG Map & UI Editor
9. Data & Persistence
10. Advanced Features & Performance
11. Map Logic / Trigger System
12. Trigger Library
13. Object Pooling & Entity System
14. Memory Management & Performance
15. Mini-Game Example Outline
16. Map Maker + Logic Editor
  - 16.1 Overview
  - 16.2 Editor Layout
  - 16.3 Features
    - 16.3.1 Map Editing
    - 16.3.2 Entity Placement
    - 16.3.3 UI Design
    - 16.3.4 Logic / Trigger Editing
  - 16.4 Data Export
  - 16.5 Modding Considerations

---

# 1. Rendering & Visuals
Handles 2D graphics rendering using Raylib. Supports tilemaps, sprites, animations, and layers.

- Layers for background, interactive objects, and foreground.
- Sprite animations and frame management.
- Tilemap rendering with grid alignment.

---

# 2. Input & Controls
Handles keyboard, mouse, and gamepad input.

- Unified input system for player actions.
- Provides an API for scripting and mod integration.
- Supports custom key bindings and gamepad mapping.

---

# 3. Audio & Music
Play sound effects and background music.

- Supports volume control, looping, and fade in/out.
- Separate channels for sound effects and music.
- QuickJS API for triggering audio in mods.

---

# 4. Physics & Collisions
Handles basic 2D physics, collisions, and bounding boxes.

- AABB and tile-based collision detection.
- Integration with entity positions and velocities.
- Collision callbacks for triggers and scripts.

---

# 5. Scripting & Modding (QuickJS)
Allows loading JS + JSON modules as mods or game content.

- Hot-reloading support for development.
- Isolated QuickJS contexts for sandboxing mods.
- Exposes engine API to scripts for spawning entities, playing sounds, and manipulating game state.

---

# 6. Game Mode / Scene System
Manages multiple scenes or game modes.

- Each scene contains entities, tiles, UI elements, and triggers.
- Scene switching supports initialization, cleanup, and state preservation.
- Supports both persistent and ephemeral scenes.

---

# 7. UI & HUD
Create interactive HUD elements.

- WYSIWYG interface for modders.
- Anchoring, scaling, and layering support.
- Supports interactive elements like buttons, sliders, and text fields.

---

# 8. WYSIWYG Map & UI Editor
Visual editor for tiles, entities, and UI.

- Drag-and-drop placement for tiles, entities, and props.
- Layer management for tiles, collisions, and decorations.
- UI elements placement with anchoring and scaling.
- Property inspector for modifying tile, entity, UI, and trigger properties.

---

# 9. Data & Persistence
Save/load game state, player profiles, and mod data.

- Autosave and manual save points.
- JSON-based storage for scene, entities, triggers, and UI.
- Mod-specific data storage and versioning support.

---

# 10. Advanced Features & Performance
Object pooling, memory management, and optimization.

- Entity object pooling for performance.
- Memory-efficient tile and sprite management.
- Optimized QuickJS execution and trigger evaluation.

---

# 11. Map Logic / Trigger System
Triggers with conditions and actions for visual scripting.

- Supports time-based, player-based, entity-based, resource-based, and custom triggers.
- Actions include spawning entities, playing sounds, modifying variables, displaying messages.
- Supports AND/OR/NOT logic, sequences, random chance, delayed actions.
- Triggers can be repeatable or one-time.

---

# 12. Trigger Library
- TimeElapsed, CountdownReached, EveryNSeconds
- PlayerEntersRegion, PlayerLeavesRegion, PlayerHealthCondition, PlayerScoreCondition
- ButtonPressed
- EntitySpawned, EntityDestroyed, EntityHealthCondition, EntityCountCondition
- EntityEntersRegion, EntityLeavesRegion
- ResourceChanged, InventoryContains, AchievementUnlocked
- OnCollision, OnDeath, OnLevelStart, OnLevelEnd, OnDialogCompleted, OnCustomEvent
- WeatherChange, TimeOfDay, TileCondition
- RandomChance, SequenceTrigger, DelayedAction
- Supports nesting and logical operators (AND/OR/NOT)

---

# 13. Object Pooling & Entity System
- Object pools for entities and projectiles to reduce GC overhead.
- Modder can choose pooled vs. manual entity creation.
- Fully integrated with entity update loop and trigger system.

---

# 14. Memory Management & Performance
- Entities, UI, and tile objects are memory-managed.
- QuickJS execution contexts are isolated per mod.
- Hot-reloading updates objects without full reload.

---

# 15. Mini-Game Example Outline
- Scenario: simple playable map with a player entity.
- Demonstrates triggers, UI updates, entity interactions, and save/load.
- Example: spawn an enemy after time elapsed and update score.

---

# 16. Map Maker + Logic Editor

## 16.1 Overview
- WYSIWYG tool combining map tiles, entity placement, UI creation, and logic triggers.
- Exports fully compatible JSON modules.

## 16.2 Editor Layout
- Canvas / Map View
- Tile Palette
- Entity Library
- UI Panel
- Logic / Triggers Panel
- Property Inspector
- Hierarchy / Layers Panel

## 16.3 Features

### 16.3.1 Map Editing
- Grid-based tile placement
- Layer management: terrain, collision, objects, decorations
- Tile properties: collidable, destructible, spawn points
- Export/import JSON modules

### 16.3.2 Entity Placement
- Drag-and-drop entities onto map
- Set properties: type, health, AI, spawn rules
- Snap to grid or free placement
- Entities can be referenced in triggers

### 16.3.3 UI Design
- Drag and place UI widgets
- Anchor and scale support
- Assign callbacks to buttons and sliders
- UI elements can be tied to scene logic or entities

### 16.3.4 Logic / Trigger Editing
- Visual scripting panel
- Drag triggers onto entities, tiles, or regions
- Conditions: time, player actions, entity state, score, resources
- Actions: spawn entities, play sounds, display messages, modify variables
- Supports AND/OR/NOT logic, sequences, random chance, delayed actions
- Repeatable or one-time triggers

## 16.4 Data Export
- Exports single JSON module per map or scene:
  - `map`: tile layers and properties
  - `entities`: all entities and properties
  - `ui`: all UI elements
  - `triggers`: all logic triggers, conditions, actions
- Hot-reload support

## 16.5 Modding Considerations
- No coding required for basic logic
- Logic can be extended via QuickJS scripts for advanced behaviors
- Namespaces for triggers, variables, and mod-specific entities prevent conflicts
- Fully integrated with object pooling, UI system, and entity system for performance
- Supports multi-genre maps: arcade (Space Invaders), strategy (RTS), puzzle (Tetris)

