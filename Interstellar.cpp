//
//  Interstellar.cpp
//  project_3_interstellar_parking_lot
//
//  Created by 娄辰飞 on 2018/12/8.
//  Copyright © 2018 娄辰飞. All rights reserved.
//


#include "project.h"

inline float theta1(int i, float fangle, float afa){
    float theta0=fangle/2-afa/2;
    return theta0+i*afa-PI/2;
};

inline float theta2(int i, float fangle, float afa){
    float theta0=fangle/2-afa;
    return theta0+i*afa-PI/2;
}

Interstellar::Interstellar(int slot_n){
    slot_num=slot_n;
    time=0.0;
    float r0=(3*slot_num+4)/(4*PI);
    float R=r0+1.2;
    float r=r0-1.5;
    float fangle=3.0/R;
    float afa=(2*PI-fangle)/slot_num;
    float pi=PI;
    float  r1=r0+0.6;
    vehiclep=new  Group* [8];
    slotsp=new  Colored_Fig* [slot_num+6];
    for (int i=1; i<=slot_num+1; i++)
        slotsp[i-1]=new Line(0.2, 0.2, 0.2, 1.2, theta2(i, fangle, afa), {r1*cos(theta2(i, fangle, afa)), r1*sin(theta2(i, fangle, afa))});
    slotsp[slot_num+1]=new Line(0.2, 0.2, 0.2, 1.0, PI/2, {R*cos(-pi/2-fangle/2), R*sin(-pi/2-fangle/2)-(float)0.5});
    slotsp[slot_num+2]=new Line(0.2, 0.2, 0.2, 1.0, PI/2, {R*cos(-pi/2+fangle/2), R*sin(-pi/2-fangle/2)-(float)0.5});
    slotsp[slot_num+3]=new Line(0.2, 0.2, 0.2, 2.9, 0.0, {0.0, R*sin(-pi/2-fangle/2)-(float)0.5});// the door
    slotsp[slot_num+4]=new Ring(0.2, 0.2, 0.2, r, 0.0, {0.0, 0.0});
    slotsp[slot_num+5]=new Ring(0.2, 0.2, 0.2, R, fangle, {0.0, 0.0});
    vehiclep[0]=new Car({r1*cos(theta1(1, fangle, afa)), r1*sin(theta1(1, fangle, afa))}); vehiclep[0]->rotate(vehiclep[0]->getAnchor(), theta1(1, fangle, afa)+PI/2);
    vehiclep[1]=new UFO({r1*cos(theta1(2, fangle, afa)), r1*sin(theta1(2, fangle, afa))}); vehiclep[1]->rotate(vehiclep[1]->getAnchor(), theta1(2, fangle, afa)+PI/2);
    vehiclep[2]=new UFO({r1*cos(theta1(7, fangle, afa)), r1*sin(theta1(7, fangle, afa))}); vehiclep[2]->rotate(vehiclep[2]->getAnchor(), theta1(7, fangle, afa)+PI/2);
    vehiclep[3]=new Rocket({r1*cos(theta1(8, fangle, afa)), r1*sin(theta1(8, fangle, afa))}); vehiclep[3]->rotate(vehiclep[3]->getAnchor(), theta1(8, fangle, afa));
    vehiclep[4]=new Rocket({r1*cos(theta1(4, fangle, afa)), r1*sin(theta1(4, fangle, afa))}); vehiclep[4]->rotate(vehiclep[4]->getAnchor(), theta1(4, fangle, afa));
    vehiclep[5]=new Teleported({r1*cos(theta1(6, fangle, afa)), r1*sin(theta1(6, fangle, afa))}); vehiclep[5]->rotate(vehiclep[5]->getAnchor(), theta1(6, fangle, afa));
    vehiclep[6]=new Teleported({r1*cos(theta1(11, fangle, afa)), r1*sin(theta1(11, fangle, afa))}); vehiclep[6]->rotate(vehiclep[6]->getAnchor(), theta1(11, fangle, afa));
    vehiclep[7]=new Teleported({r1*cos(theta1(12, fangle, afa)), r1*sin(theta1(12, fangle, afa))}); vehiclep[7]->rotate(vehiclep[7]->getAnchor(), theta1(12, fangle, afa));
    int n=rand()%3;
    switch (n) {
        case 0:
            entering_vehicle=new Car({0.0, -8.0});
            break;
        case 1:
            entering_vehicle=new UFO({0.0, -8.0});
            break;
        default:
            entering_vehicle=new Rocket({0.0, -8.0});
            break;
    }
    entering_vehicle->rotate(entering_vehicle->getAnchor(), pi/2);
}

Interstellar::~Interstellar(){
    for (int i=0; i<8; i++)
        delete vehiclep[i];
    for (int i=0; i<slot_num+6; i++)
        delete slotsp[i];
    delete[] vehiclep;
    delete[] slotsp;
    delete entering_vehicle;
}

void Interstellar::vehicles_move_lovely(){
    for (int i=0; i<8; i++){
        vehiclep[i]->self_animation();
        vehiclep[i]->draw();
    }
    for (int i=0; i<slot_num+6; i++)
        slotsp[i]->draw();
    entering_vehicle->self_animation();
    entering_vehicle->draw();
}

void Interstellar::vehicle_enter() {
    float r0=(3*slot_num+4)/(4*PI);
    float R=r0+1.2;
    float r=r0-1.5;
    float fangle=3.0/R;
    float afa=(2*PI-fangle)/slot_num;
    float pi=PI;
    float r1=r0+0.6;
    float x=(r+r0)/(2*(1/sin(fangle/2)-1));
    float y=-((r+r0)/2+x)*cos(fangle/2);
    float movement=(y+8)/200;
    Vec center1((r1+r0)/2*cos(theta1(4, fangle, afa)), (r1+r0)/2*sin(theta1(4, fangle, afa)));
    if (time<5){
        slotsp[slot_num+3]->rotate({1.45, R*sin(-pi/2-fangle/2)-(float)0.5}, pi/400);
        time+=0.025;
    }
    else if (time<10){
        entering_vehicle->move({0.0, movement});
        time+=0.025;
    }
    else if (time<12){
        entering_vehicle->rotate({x, y}, -(pi/2-fangle/2)/80);
        time+=0.025;
    }
    else if (time<16){
        float flote=theta1(4, fangle, afa)+pi/2;
        entering_vehicle->rotate({0.0, 0.0}, (flote-fangle/2)/160);
        time+=0.025;
    }
    else if (time<18){
        entering_vehicle->rotate(center1, 5*pi/16/80);
        time+=0.025;
    }
    else if (time<20){
        static Vec tmp1=entering_vehicle->getAnchor()-center1;
        static Vec tmp2=entering_vehicle->getAnchor()+tmp1*0.5;
        entering_vehicle->rotate(tmp2, -(5*pi/16+afa)/80);
        time+=0.025;
    }
}

void Interstellar::display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    vehicles_move_lovely();
    vehicle_enter();
    glutSwapBuffers();
    glFlush();
}

Interstellar* Singleton_of_Interstellar::m_pInstance=NULL;

Interstellar* Singleton_of_Interstellar::Instance(int slot_n){
    if (!m_pInstance)
        m_pInstance=new Interstellar(slot_n);
    assert(m_pInstance!=NULL);
    return m_pInstance;
}
