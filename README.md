# Philosophers

## Project Overview
An implementation of the classic Dining Philosophers problem, demonstrating process synchronization, mutual exclusion, and deadlock prevention using threads and mutexes.

## The Problem
- N philosophers sit at a round table
- Each philosopher needs two forks to eat
- Philosophers alternate between eating, thinking, and sleeping
- Prevent deadlocks and ensure no philosopher starves

## Features
- Multi-threaded implementation
- Mutex-based resource management
- Death detection system
- Configurable number of philosophers
- Precise timing management
- Status monitoring for each philosopher

## Project Structure
```
.
├── Philosophers.c   # Main program logic
├── init.c          # Initialization functions
├── philo_utils.c   # Utility functions
├── philo_utils2.c  # Additional utilities
├── philo_utils3.c  # More helper functions
├── philo.h         # Header file
└── Makefile        # Build configuration
```

## Building

```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

## Usage

```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```

Example:
```bash
./philo 5 800 200 200 7
```

### Parameters
1. `number_of_philosophers`: Number of philosophers and forks
2. `time_to_die`: Time (ms) a philosopher can survive without eating
3. `time_to_eat`: Time (ms) it takes to eat
4. `time_to_sleep`: Time (ms) philosophers spend sleeping
5. `number_of_times_each_philosopher_must_eat` (optional): Stop after each philosopher eats this many times

## Implementation Details
- Each philosopher is a thread
- Forks are protected by mutexes
- Death checking is done without race conditions
- Precise timing using `usleep`
- Resource management to prevent memory leaks

## Key Concepts
- Thread synchronization
- Mutex usage
- Deadlock prevention
- Race condition avoidance
- Resource sharing

## Error Handling
- Input validation
- Resource allocation checks
- Thread creation verification
- Mutex initialization checks

## Author
Project developed for 42 school.

## Note
This project demonstrates fundamental concepts in concurrent programming:
- Thread management
- Synchronization primitives
- Resource sharing
- Race condition prevention
- Deadlock avoidance