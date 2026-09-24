# Parking Lot Management System (Stack & Queue)

This repository contains the TP1 assignment for the INF 224 Data Structures course. The project simulates a constrained parking lot system using **Stack** and **Queue** data structures in C.

## System Architecture

The parking facility consists of two main components:
*   **Parking Areas (Stack):** There are 4 parking areas. Each area has a capacity of 4 vehicles, is exactly one car wide, and only allows entry and exit from the rear. This enforces a Last-In-First-Out (LIFO) behavior.
*   **Temporary Area (Queue):** There is 1 temporary area. It is also one car wide, but allows entry from the rear and exit from the front. This enforces a First-In-First-Out (FIFO) behavior.

## Operational Logic

When a vehicle needs to leave a parking area, the system executes the following displacement rules:
1.  All vehicles parked behind the target vehicle must exit the parking area first.
2.  These blocking vehicles are relocated to the remaining 3 parking areas, provided there is available space.
3.  If the other parking areas are completely full, the displaced vehicles are placed into the temporary area.
4.  After the target vehicle successfully leaves the facility, the vehicles waiting in the temporary area are sequentially moved back into the available empty parking spots.

## Core Functions

*   `print_status()`: Prints the current status of all vehicles across all parking areas and the temporary area.
*   `leave(area, position)`: Takes the area and position of the vehicle that wants to leave, handles the relocation logic, and updates the parking system.

## Test Scenario

The `main` function demonstrates a specific scenario required by the assignment guidelines:
*   The system is initialized with an empty temporary area and a single empty spot located in Area 3.
*   The initial state of the system is displayed using `print_status()`.
*   The `leave` function is executed for the very first vehicle that entered Area 1.
*   The final state of the parking lot after all relocations is printed to the console.
