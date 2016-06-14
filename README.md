# ModelRocket
A C++ Physics Simulator for Rockets for AP Computer Science.
There are three classes, projectile, rocket, and world. A projectile is a simple class that stores information about how far the projectile has traveled, its mass, its cross sectional areas (across both the X and Y planes), and the drag coefficents across the x and y planes. 
The second class, rocket extends projectile and adds the amount of thrust and any flow rate and burn time information to the projectile.
A world contains information about the air density and the acceleration due to gravity on that world. 

Once these are defined the user makes a call to thrust() passing it the rocket being simulated, the world it is in, and the initial launch angle. Rocket will then return an array containing the distance traveled on the x distance, the distance traveled on the y, and the time the entire launch would take. 

After that the user can make a call to out(), which requires X11 and gnuplot. If these are installed it will open a window containing a graph of the rocket's path. 



