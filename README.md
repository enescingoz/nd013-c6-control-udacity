# Control and Trajectory Tracking for Autonomous Vehicle

# Proportional-Integral-Derivative (PID)

In this project, designed a PID controller to perform vehicle trajectory tracking. Tested on CARLA simulator.
![carla_initial](../master/project/pid_controller/screenshot/carla_initial.PNG)


# PID Output Plots
![test1](../master/project/pid_controller/screenshot/test1.png)
![test2](../master/project/pid_controller/screenshot/test2.png)
![test3](../master/project/pid_controller/screenshot/test3.png)
![test4](../master/project/pid_controller/screenshot/test4.png)


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

