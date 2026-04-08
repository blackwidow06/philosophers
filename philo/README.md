*This project has been created as part of the 42 curriculum by malavaud.*

# Philosophers

## Description


The **Philosophers** project is about learning how to work with threads and shared data.

The program simulates philosophers sitting around a table.  
Each philosopher can:
- eat
- sleep
- think

To eat, a philosopher needs two forks. These forks are shared between philosophers.

The goal is to manage this situation correctly and avoid problems like:
- deadlocks (program stops)
- data races
- starvation

The goal is to learn: 
- How to create and use threads (pthread)
- How to use mutex to protect shared data
- How to avoid race conditions
- How to manage time in a program

## Instructions

### Compilation

Run the following command at the root of the repository:

```bash
make
```

To recompile from scratch:

```bash
make fclean && make
```

### Execution

Run the program like this:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number of meals]
```

Arguments:

- number_of_philosophers : number of philosophers and forks
- time_to_die : time a philosopher can survive without eating (in ms)
- time_to_eat : time spent eating (in ms)
- time_to_sleep : time spent sleeping (in ms)
- number_of_meals : number of meals each philosopher must eat before the simulation ends

Example:

```bash
./philo 5 800 200 200 3
```

## Resources

### Documentation & References

- Man pthread
- Man usleep
- Threads and mutex documentation
- Dining Philosophers problem documentation

### How AI was used:

- Rephrase and structure the README
- Provide examples of wording and organization
- Suggest conventional sections and descriptions

*AI* was not used to write core code logic or algorithms. All implementation decisions and coding were done manually.
