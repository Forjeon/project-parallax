# Project Plan: Second-Person Robot Thriller

This document outlines the development milestones for the second-person puzzle action thriller game. The core concept is a damaged robot navigating a hostile environment by jacking into the video feeds of enemy robots and security cameras.

The development is broken down into small, achievable milestones. Each milestone should be treated as a complete, playable mini-game to provide a sense of accomplishment and build momentum.

---

## Milestone 1: The Core Mechanic Prototype ("The Observation Room")

**Goal:** Build a text-based prototype that proves the core camera-switching and robot-control mechanic.

**Key Features:**
1.  **Ground-Truth Map:**
    *   Create a simple 2D array in code (e.g., `char map[WIDTH][HEIGHT]`) to represent the "real" layout of a single room.
    *   Use characters like `#` for walls and `.` for floors.

2.  **Noisy Sensor View (The Robot's Damaged Vision):**
    *   When rendering the map to the console, do not show the ground-truth map directly.
    *   For each tile, introduce a small, weighted probability (e.g., 5-10%) of displaying the *wrong* tile (showing a wall as a floor or vice-versa).
    *   This creates tension and makes the robot's own sensors unreliable, forcing the player to rely on other feeds.

3.  **Objects and Player Control:**
    *   Place the player's robot (`@`) and at least two static security cameras (`C1`, `C2`) on the map by storing their coordinates.
    *   Implement simple keyboard controls for moving the robot (e.g., arrow keys or WASD). Movement logic should check against the **ground-truth map** for collisions.

4.  **Camera Switching:**
    *   Allow the player to switch between different "views" using number keys (e.g., '0' for the robot's noisy sensor view, '1' for Camera 1's view, '2' for Camera 2's view).
    *   A "view" from a security camera should be a clean, accurate rendering of the ground-truth map.
    *   Initially, a view can just be text output (e.g., "Camera 1 sees the robot at (x, y) and a wall at (x, y+1)").

**Reward:** A playable text-based toy that demonstrates the unique core mechanic of the game.

---

## Milestone 2: The Visual Prototype ("The *Wolfenstein* View")

**Goal:** Transform the text-based prototype into a graphical one using a 2D/3D rendering technique like Raycasting.

**Key Features:**
1.  **Integrate a Graphics Library:**
    *   Choose a simple 2D graphics library for your chosen language (e.g., SFML or SDL2 for C++, Raylib-cs for C#, `ggez` for Rust).
    *   Use this library to create a window and draw basic shapes/pixels.

2.  **Implement a Raycaster:**
    *   Follow a tutorial (Lode's Computer Graphics Tutorial is a classic) to write a raycasting engine.
    *   This engine will take your 2D ground-truth map and render a 3D-style first-person view from it.

3.  **Visualize Perspectives:**
    *   The view from each camera (and eventually, enemy robots) will now be the output of the raycaster from that camera's position and orientation.
    *   When you switch views, the 3D rendering should update to the new perspective.
    *   Draw the player robot as a 2D sprite within the 3D world.

**Reward:** A visually impressive prototype that feels like a real game. You can watch your robot move around the level from different camera angles.

---

## Milestone 3: The First Puzzle ("The Button and The Door")

**Goal:** Introduce a simple objective and a win condition to create a complete game loop.

**Key Features:**
1.  **Design a Puzzle Room:**
    *   Create a level where the exit is blocked by a locked door.
    *   Place a button to open the door somewhere else in the level, possibly in a location that requires switching cameras to see and navigate to.

2.  **Implement Game State:**
    *   Add a boolean variable like `isDoorOpen`.
    *   The door tile on the map should act as a wall when `isDoorOpen` is false, and a floor when it's true.

3.  **Implement Interactivity:**
    *   When the robot moves onto the button's coordinates, set `isDoorOpen` to `true`.
    *   The objective is to guide the robot to the button and then through the now-open door.

**Reward:** A complete, winnable puzzle game that serves as a proof-of-concept for the entire game idea.

---

## Future Ideas & Expansion

These are ideas to consider *after* completing the first three milestones.

*   **"Stabilize Sensors" Power-up:** An item the robot can find that reduces the "noise" percentage on its personal map view, making it more reliable.
*   **Mobile Enemies:** Add simple enemies (`E`) that patrol on a set path.
*   **Camera Jacking:** The core idea. Allow the player to jack into the view of mobile enemies, not just static cameras. This becomes the primary way to navigate complex levels.
*   **Stealth Mechanics:**
    *   Give enemies a simple field-of-view.
    *   If the player robot enters an enemy's view, an alert state is triggered.
*   **More Puzzle Elements:** Pressure plates, keycards, terminals that reveal map sections, etc.
*   **Sound Design:** Add simple sound effects for movement, camera switching, and alerts to build atmosphere.
*   **Story/Lore:** Introduce snippets of text through terminals to explain the robot's mission and the story of the facility.
