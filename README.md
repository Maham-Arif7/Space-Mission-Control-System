# Space Mission Control System 🚀

## Overview
A C++ program that simulates spacecraft missions using Object-Oriented Programming (OOP) concepts.  
It demonstrates **encapsulation, inheritance, and polymorphism** through different spacecraft types.

## Features
- Add spacecraft dynamically (Satellite, Rover, Manned Mission).
- Launch spacecraft with type-specific behavior.
- Control missions with fuel consumption and speed reduction.
- Display spacecraft details and mission status.

## Concepts Used
- **Encapsulation**: Protecting spacecraft attributes.
- **Inheritance**: Satellite, Rover, and MannedMission inherit from Spacecraft.
- **Polymorphism**: Overridden `launch()` functions for different spacecraft types.

## How to Run
1. Clone the repository:
   git clone https://github.com/Maham-Arif7/Space-Mission-Control.git

2. Compile the program:
   g++ mission.cpp -o mission

3. Run the Executable:
   ./mission
   

(Example Output)

Enter details for spacecraft 1:
Name: Apollo
Fuel Level (%): 100
Speed (km/h): 28000
Type (MannedMission)
Number of astronauts onboard: 3

Initiating Launch Sequence:
Apollo is lifting off with 3 astronauts onboard.

Mission Control Active:
Apollo is in operation at speed: 26600 km/h. Remaining fuel: 95%


(Future Improvements)

Add a menu-driven console interface for easier input.

Extend MissionControl to handle more spacecrafts.

Optional: Build a GUI using Qt or SFML for visualization.

   


   
   


