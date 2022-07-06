# Control and Trajectory Tracking for Autonomous Vehicle

# Proportional-Integral-Derivative (PID)

In this project, designed a PID controller to perform vehicle trajectory tracking. Tested on CARLA simulator.
![carla_initial](../master/project/pid_controller/screenshot/carla_initial.PNG)


# PID Output Plots

Simulation environment is consists of 3 cars placed on sides of a road. This project's mission is make the ego car move forward while avoiding these cars. To do this, desired path and velocities are given by path planner. Using these desired target points and velocities, designed a PID controller to move along this path smoothly while avoiding crashes from cars or other objects. After implemented a PID controller in "main.cpp", "pid_controller.hpp" and "pid_controller.cpp", to test this controller initial values are given randomly to pid coefficients for test 1.

Each test has 2 plots; throttle outputs and steering outputs. After test 1, by examining the plots pid coefficients are tuned.

### Test 1

PID coefficients are set to random values for initial state. As shown in the plots, throttle errors are too high than expected. Reason of this, when car speed is increased, avoiding crashes is getting harder. Also, it is getting harder to compute the angle between next target point. If car speed is too high, algorithm can not calculate angle between target point and ego car. Therefore, the ego car is trying to turn backside immediately and crashes.

After plotting the errors, pid coefficients are tuned for test 2.

![test1](../master/project/pid_controller/screenshot/test1.png)
-------------

### Test 2

After tuning pid parameters, outputs are plotted as result of test 2. It is clear to see that, throttle error is less than compared to test 1. As a result, we can say that car speed is higher than test 1. As another inference, we can see that throttle output is rise too fast at the beginning. This means, P coefficient is too high and it should be reduced.

Also, throttle outputs are oscillated too much. This might have 3 different causation:
```
- P coefficient is too high.
- I coefficient is too high.
- D coefficient is too low.
```

When steering outputs are examined, we can say that the ego car is steering more sharper but oscillating too much.

![test2](../master/project/pid_controller/screenshot/test2.png)
-------------

### Test 3

After tuned P coefficient for throttle, the outputs are started to rise smoothly and oscillating less. Also D coefficient is increased for more smooth throttle output. By decreasing I coefficient, throttle outputs became more stable compared to test 1 and test 2.

For steering outputs, P coefficient is increased, D and I coefficients are decreased. As a result of this, steering outputs are started to react a bit late but became more sharper when needed.

![test3](../master/project/pid_controller/screenshot/test3.png)
-------------

### Test 4

For test 4 while keeping P coefficient constant, reduced I and D coefficient of steering parameters. By doing this, as seen on the plots, steering outputs are reacted a bit late to turn, but the ego car moved more smooth compared to other tests. 

Also, in all tests steering errors are bigger than steering outputs. Because P coefficient is not given too much to move ego car more smoothly. If P coefficient is increased, steering error will be less than now but car will start to turn sharper.


For throttle outputs, I and D coefficients are decreased to prevent from oscillating. But it is still able to react sharp enough when needed, as expected.


![test4](../master/project/pid_controller/screenshot/test4.png)


-------------
# Answer the following questions:

- What is the effect of the PID according to the plots, how each part of the PID affects the control command?
```
- If P coefficient is too high, it will cause oscillation. Conversely, if P coefficient is not high enough, it will not reach to target value.
- If I coefficient is too high, it will cause oscillation and will not reach to targeted value. If it is too low, it will take too much time to reach targeted value.
- If D coefficient is too low, it will cause immediate reaction and then oscillation. If this coefficient is too high, it will take too much time to reach targeted value. 
```

- How would you design a way to automatically tune the PID parameters?
```

- As mentioned in the course lectures, Twiddle algorithm can be used. 
```

- PID controller is a model free controller, i.e. it does not use a model of the car. Could you explain the pros and cons of this type of controller?
```
- When inputs are increased for an algorithm, we will need too much coding time and calculations. For this reason, PID controller is very useful when we have only target value and current value as input. Also, PID contoller is really easy to implement.

- On the other hand, because we don't have mathematical model of the car, we have to tune PID parameters on every change on the car engine or steering system. Moreover, we may cannot obtain robust outputs with PID controller unless we tuned properly.
```

-------------
### Installation

Run the following commands to install the starter code in the Udacity Workspace:

Clone the <a href="[https://github.com/enescingoz/nd013-c6-control-udacity)" target="_blank">repository</a>:

`git clone https://github.com/enescingoz/nd013-c6-control-udacity`

## Run Carla Simulator

Open new window

* `su - student`
// Will say permission denied, ignore and continue
* `cd /opt/carla-simulator/`
* `SDL_VIDEODRIVER=offscreen ./CarlaUE4.sh -opengl`

## Compile and Run the Controller

Open new window

* `cd nd013-c6-control-starter/project`
* `./install-ubuntu.sh`
* `cd pid_controller/`
* `rm -rf rpclib`
* `git clone https://github.com/rpclib/rpclib.git`
* `cmake .`
* `make` (This last command compiles your c++ code, run it after every change in your code)

## Testing

To test your installation run the following commands.

* `cd nd013-c6-control-starter/project`
* `./run_main_pid.sh`
This will silently fail `ctrl + C` to stop
* `./run_main_pid.sh` (again)
Go to desktop mode to see CARLA

If error bind is already in use, or address already being used

* `ps -aux | grep carla`
* `kill id`






### Tips:

- When you wil be testing your c++ code, restart the Carla simulator to remove the former car from the simulation.
- If the simulation freezes on the desktop mode but is still running on the terminal, close the desktop and restart it.

