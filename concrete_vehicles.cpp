//
//  concrete vehicles.cpp
//  project_3_interstellar_parking_lot
//
//  Created by 娄辰飞 on 2018/12/6.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "concrete vehicles.hpp"

Car::Car(Point a) : Group(a, 5){
    fpp[0]=new Trapezium({-0.35, 0.0}, {0.3, 0.0}, {0.09, 0.18}, {-0.3, 0.18}, 0.73, 1.0, 1.0);
    fpp[1]=new Trapezium({-0.5, -0.18}, {0.5, -0.18}, {0.45, 0.0}, {-0.5, 0}, 0.54, 0.39, 0.03);
    fpp[2]=new Circle(0.06, 0.54, 0.53, 0.47);
    fpp[3]=new Circle(0.06, 0.54, 0.53, 0.47);
    fpp[4]=new Circle(0.03, 0.6, 1.0, 0.6);
    Vec tmp1(-0.25, -0.2);
    fpp[2]->move(tmp1);
    Vec tmp2(0.25, -0.2);
    fpp[3]->move(tmp2);
    Vec tmp3(0.45, -0.09);
    fpp[4]->move(tmp3);
    for (int i=0; i<figure_num; i++)
        fpp[i]->move(anchor);
    float pi=3.14159;
    flagp[0]=new Line(0.0, 0.0, 0.0, 0.2, pi/2, {0.0, 0.18}); flagp[0]->move(anchor);
    flagp[1]=new Triangle({0.0, 0.28}, {0.0, 0.18}, {0.15, 0.18}, 1.0, 0.0, 0.0); flagp[1]->move(anchor);
}

void Car::self_animation(){
    flag_moving();
}

UFO::UFO(Point a) : Group(a, 4){
    fpp[0]=new Semi_circle(0.35, 0.0, 0.12, 0.56, 1.0);
    fpp[1]=new Semi_circle(0.06, 3.14159, 0.54, 0.41, 0.8);
    fpp[2]=new Semi_circle(0.06, 3.14159, 0.54, 0.41, 0.8);
    fpp[3]=new Trapezium({-0.5, -0.15}, {0.5, -0.15}, {0.4, 0}, {-0.4, 0}, 0.54, 0.54, 0.54);
    Vec tmp1(-0.35, -0.15);
    fpp[1]->move(tmp1);
    Vec tmp2(0.35, -0.15);
    fpp[2]->move(tmp2);
    for (int i=0; i<figure_num; i++)
        fpp[i]->move(anchor);
    float pi=3.14159;
    flagp[0]=new Line(0.0, 0.0, 0.0, 0.2, pi/2, {0.0, 0.35}); flagp[0]->move(anchor);
    flagp[1]=new Triangle({0.0, 0.45}, {0.0, 0.35}, {0.15, 0.35}, 1.0, 0.0, 0.0); flagp[1]->move(anchor);
}

void UFO::self_animation(){
    rotate(anchor, 0.01);
    flag_moving();
}

Rocket::Rocket(Point a) : Group(a, 9){
    fpp[0]=new Triangle({0, 0.5}, {0.12, 0.45}, {-0.12, 0.45}, 1.0, 1.0, 0.0);
    fpp[1]=new Trapezium({-0.22, 0.25}, {0.22, 0.25}, {0.12, 0.45}, {-0.12, 0.45}, 1.0, 1.0, 0.0);
    fpp[2]=new Trapezium({-0.25, 0.0}, {0.25, 0.0}, {0.22, 0.25}, {-0.22, 0.25}, 0.59, 1.0, 1.0);
    fpp[3]=new Rectan({-0.25, -0.25}, {0.25, 0.0}, 0.59, 1.0, 1.0);
    fpp[4]=new Semi_circle(0.15, 3.14159, 0.69, 0.69, 0.69);
    Vec tmp(0, -0.25);
    fpp[4]->move(tmp);
    fpp[5]=new Trapezium({0.25, -0.5}, {0.35, -0.5}, {0.35, -0.25}, {0.25, -0.12}, 1.0, 0.0, 0.0);
    fpp[6]=new Trapezium({-0.25, -0.5}, {-0.35, -0.5}, {-0.35, -0.25}, {-0.25, -0.12}, 1.0, 0.0, 0.0);
    fpp[7]=new Rectan({0.15, -0.5}, {0.25, -0.25}, 1.0, 0.0, 0.0);
    fpp[8]=new Rectan({-0.15, -0.5}, {-0.25, -0.25}, 1.0, 0.0, 0.0);
    for (int i=0; i<figure_num; i++)
        fpp[i]->move(anchor);
    float pi=3.14159;
    flagp[0]=new Line(0.0, 0.0, 0.0, 0.2, pi/2, {0.0, 0.5}); flagp[0]->move(anchor);
    flagp[1]=new Triangle({0.0, 0.6}, {0.0, 0.5}, {0.15, 0.5}, 1.0, 0.0, 0.0); flagp[1]->move(anchor);
}

void Rocket::zoom_self(){
    static float rocket_zoom=0.99;
    zoom(anchor, rocket_zoom);
    if (size>1.5 | size<0.5)
        rocket_zoom=1/rocket_zoom;
}

void Rocket::self_animation(){
    zoom_self();
    flag_moving();
}

Teleported::Teleported(Point a) : Group(a, 1){
    sides=4;
    fpp[0]=new Rectan({-0.4, -0.6}, {0.4, 0.6}, (float)rand()/RAND_MAX, (float)rand()/RAND_MAX, (float)rand()/RAND_MAX);
    fpp[0]->move(anchor);
    float pi=3.14159;
    flagp[0]=new Line(0.0, 0.0, 0.0, 0.2, pi/2, {0.0, 0.4}); flagp[0]->move(anchor);
    flagp[1]=new Triangle({0.0, 0.5}, {0.0, 0.4}, {0.15, 0.4}, 1.0, 0.0, 0.0); flagp[1]->move(anchor);
}

void Teleported::change_sides(){
    Vec tmp=fpp[0]->getAnchor();
    delete fpp[0];
    int sides=rand()%5+4;
    fpp[0]=new polyg((float)rand()/RAND_MAX, (float)rand()/RAND_MAX, (float)rand()/RAND_MAX, sides, 0.5);
    fpp[0]->move(tmp);
}

void Teleported::self_animation(){
    if (time%40==0){
        fpp[0]->paint((float)rand()/RAND_MAX, (float)rand()/RAND_MAX, (float)rand()/RAND_MAX);
        change_sides();
    }
    flag_moving();
}
