Author: Project 3 Group 4 (in the alphabetic order): Lou Chenfei, Qiang Lvbing, Wu Zhehong, Xi Guanghan.

Date: December 14, 2018



The operating system: Mac, Xcode (but the code has included header guard). 



Compilation (using command line): 
g++ -Wall -Werror -pedantic -Wno-unused-result -Wno-deprecated-declarations -std=c++14 -o exe main.cpp vec_and_figure.cpp concrete_shapes.cpp concrete_vehicles.cpp Interstellar.cpp -framework OpenGL -framework GLUT


./exe



Class:
1. "Vec", as provided in p3.pdf

2. "Color", which can store color in form of r, g, b. This class is a protected member in class "Colored_Fig", which inherit from class "Figure".

3. "Figure", as provided in p3.pdf, is a virtual class. 

4. "Colored_Fig", as mentioned above, it is a "Figure" with "Color" inside.

5. "Group", inheriting from "Figure", which also acts as a virtual class to generate different vehicles, contains a double pointer to "Colored_Fig", so it could contain several figures (the component of a certain vehicle). And it also has the functions to rotate, move zoom and letting a flag moving up and down.

6. "Line", "Ring", "Triangle", "Trapezium", "Circle" and "Polygon" inherit from "Colored_Fig".

7. "Rectangle" inherit from "Trapezium", and "Semi_Circle" inherit from "Circle".

8. "Car", "UFO", "Rocket" and "Teleported" inherit from "Group", and they only differ in their initializations about "Figures", except that "Teleported" can also change its shape.

9. "Interstellar" is a class containing double pointers to various "Figures" and "Colored_Figs", and different functions to realize the animations.

10. "Singleton_of_Interstellar" is a singleton of "Interstellar", and in display function, we just use "Singleton_of_Interstellar" to create an Interstellar.



Interstellar animation:
The Interstellar is designed to be in shape of a circle. It could adjust its size automatically according to the number of slots given by the user. In the whole animation, some vehicles are located in some previously-determined slots, and one vehicle could enter in the Interstellar and park in an empty slot. The entering vehicle is randomly generated.

Apart from the motion of the parking vehicle, every vehicle has its own animation, including rotating, moving and zooming. And Teleported could change its number of side and also its color.



Main, reshape, display and TimeStep:
The design of class is introduced above, and the main function would call display (create and animate the Interstellar), reshape (reshape the figures so the image wouldn't change when reshaping the window) and TimerStep. Also, in main function, glOrtho function is used to control the view.



Usage:
First you are asked to input a number representing the number of slots (should no smaller than 12, otherwise the code would take the number you input as 12 automatically), than the window would be created and you would see the animation.



Evident bonus:
1. Adding a small flag moving up and down. 
2. Letting Teleported change color and its number of sides over time.
3. Avoiding a very long drawing function that continuously creates (destroys) objects.