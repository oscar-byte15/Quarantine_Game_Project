# Quarantine_Game_Project
I developed **Quarantine Game**, a Windows desktop action game built with C++/CLI and Windows Forms in Visual Studio 2019. It has multiple levels and difficulty modes, with player movement, shooting, different character behaviors, collision detection, lives, scoring, and timed gameplay.

I used object-oriented programming to organize the game. For example, the player, asymptomatic characters, healthy characters, police officers, and ambulances inherit shared properties from a base `Entidad` class, such as position and dimensions. Each class then implements the behavior it needs. This helped me separate the responsibilities of different game entities instead of putting all the logic in one place.

I also implemented collections of game objects using dynamically allocated arrays of pointers. These arrays hold entities such as enemies and projectiles, and the game uses loops to add, move, draw, check, and remove them. A key part of the gameplay logic is iterating through those collections to detect collisions between characters and projectiles, then updating health or points based on the result.

The interface uses keyboard and mouse events for player input and timers to update the game over time. Building this project gave me practical experience connecting data structures, iteration, inheritance, event handling, and game logic in a working interactive application.
