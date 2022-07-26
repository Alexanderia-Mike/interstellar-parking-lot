# Intestellar Parking Lot Animation Project

Author: Chenfei Lou

Date: December 14, 2018

This is a course project for VG101: Intro to Programming. The concrete requirements of this project can be found in the file [p3.pdf](https://github.com/Alexanderia-Mike/interstellar-parking-lot/blob/main/p3.pdf).


### Compile \& Run

The operating system: MacOS, Windows, Linux

Compilation \& Run commands:
```
g++ -Wall -Werror -pedantic -Wno-unused-result -Wno-deprecated-declarations -std=c++14 -o exe main.cpp vec_and_figure.cpp concrete_shapes.cpp concrete_vehicles.cpp Interstellar.cpp -framework OpenGL -framework GLUT

./exe
```
At the beginning of the program, you will be prompted to enter the number of slots (no less than 12, otherwise the code would take the number you input as 12 automatically) to initialize the circular insterstallar parking lot. After that, a new window will appear and you can just sit and watch the animation.


### Project Overview

This project is an Object-Oriented Design project using C++. It creates a circular intestellar parking lot where many lovely and innovative vehicles are parked inside (including cars for humans, UFOs for aliens, rockets for astronomers and teleported gates). At the beginning of the animation, a random vehicle will appear at the entrance of the parking lot, and with the gate bar rising up, the vehicle enters the parking lot and finds a empty lot to park. Apart from the motion of the parking vehicle, every vehicle has its own animation effects, including rotating, moving and zooming. 

#### Object-Oriented Design
The program are built through a bunch of classes and a full use of class polymorphisms. The relations of different classes is clearly illustrated in the file [hierarchy diagram.pdf](https://github.com/Alexanderia-Mike/interstellar-parking-lot/blob/main/hierarchy%20diagram.pdf).

For sake of convenience, they are also listed here:
Class:
1. "Vec"

2. "Color", which can store color in form of r, g, b. This class is a protected member in class "Colored_Fig", which inherit from class "Figure".

3. "Figure", as provided in p3.pdf, is a virtual class. 

4. "Colored_Fig", as mentioned above, it is a "Figure" with "Color" inside.

5. "Group", inheriting from "Figure", which also acts as a virtual class to generate different vehicles, contains a double pointer to "Colored_Fig", so it could contain several figures (the component of a certain vehicle). And it also has the functions to rotate, move zoom and letting a flag moving up and down.

6. "Line", "Ring", "Triangle", "Trapezium", "Circle" and "Polygon" inherit from "Colored_Fig".

7. "Rectangle" inherit from "Trapezium", and "Semi_Circle" inherit from "Circle".

8. "Car", "UFO", "Rocket" and "Teleported" inherit from "Group", and they only differ in their initializations about "Figures", except that "Teleported" can also change its shape.

9. "Interstellar" is a class containing double pointers to various "Figures" and "Colored_Figs", and different functions to realize the animations.

10. "Singleton_of_Interstellar" is a singleton of "Interstellar", and in display function, we just use "Singleton_of_Interstellar" to create an Interstellar.


#### Interstellar animation:
The Interstellar is designed to be in shape of a circle. It could adjust its size automatically according to the number of slots given by the user. In the whole animation, some vehicles are located in some previously-determined slots, and one vehicle could enter in the Interstellar and park in an empty slot. The entering vehicle is randomly generated.

The special animation effects for single vehicles are specified as:
- UFO: rotate
- rocket: zoom in and out
- teleported gate: change its number of sides
- all: a small flag at the top, moving up and down

Main, reshape, display and TimeStep:
The design of class is introduced above, and the main function would call display (create and animate the Interstellar), reshape (reshape the figures so the image wouldn't change when reshaping the window) and TimerStep. Also, in main function, glOrtho function is used to control the view.

Through object implementation, it avoids a very long drawing function that continuously creates (destroys) objects.
