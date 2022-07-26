//
//  project.h
//  project_3_interstellar_parking_lot
//
//  Created by 娄辰飞 on 2018/12/6.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#ifdef __APPLE__
#include <GLUT/glut.h>
#elif _WIN32
#include <windows.h>
#include <GL/freeglut.h>
#else
#include <GL/freeglut.h>
#endif

#ifndef project_h
#define project_h
#include <iostream>
#include <stdio.h>
#include "concrete vehicles.hpp"
#include <vector>
#define PI 3.14159
using namespace std;

void display();
void test_display();
void test2_display();
void test3_display();
void test4_display();
void test5_display();

void reshape (int width, int height);

void TimeStep(int n);


class Interstellar{
public:
    Interstellar(int slot_n);
    ~Interstellar();
    int return_slot_num() {return slot_num;}
    void vehicles_move_lovely();
    void vehicle_enter();
    void display();
    // a function for all vehicles' self-animation.
    // a function to let a car moving into the interstellar and park into an empty slot. door need to open, and vehicle still need to self-animate, together with its moving and rotating.
private:
    Group** vehiclep;
    Colored_Fig** slotsp;
    float time;
    Group* entering_vehicle;
    int slot_num;
};

class Singleton_of_Interstellar{
public:
    static Interstellar* Instance(int slot_n);
protected:
    Singleton_of_Interstellar();
    ~Singleton_of_Interstellar() {delete m_pInstance;}
private:
    static Interstellar* m_pInstance;
};

#endif /* project_h */
