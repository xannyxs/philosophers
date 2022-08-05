# Philosophers - I never thought philosophy would be so deadly

### Final score: <br>
[![xvoorvaa's 42 Philosophers Score](https://badge42.vercel.app/api/v2/cl1l0g8q3005209mm02a81gfy/project/2487697)](https://github.com/JaeSeoKim/badge42)

## What is it?

Aim of the project to simulate dining philosophers problem formulated by Edsger Dijkstra. The problem is illustration of synchronization issues such as deadlock and resource 
starvation. The task was to crate two programs that simulates this problem. Each philosopher is a thread and simulation works on mutexes.

## How to launch?

Use ``make``. Each program takes 5 mandatory parameters and 1 optional:

- number_of_philosophers: The number of philosophers and also the number
  of forks
- time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
  milliseconds since the beginning of their last meal or the beginning of the simulation, they die
- time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
  During that time, they will need to hold two forks
- time_to_sleep (in milliseconds): The time a philosopher will spend sleeping
- number_of_times_each_philosopher_must_eat (optional argument): If all
  philosophers have eaten at least number_of_times_each_philosopher_must_eat
  times, the simulation stops. If not specified, the simulation stops when a
  philosopher dies

Run ``./philo 5 800 200 200 7`` to launch infinite simulation. You can change the parameters and see how simulation 
reacts on it

## Resources
https://en.wikipedia.org/wiki/Dining_philosophers_problem
