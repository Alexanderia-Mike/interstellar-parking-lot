//
//  concrete shapes.cpp
//  project_3_interstellar_parking_lot
//
//  Created by 娄辰飞 on 2018/12/6.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "concrete shapes.hpp"
#include <iostream>
#include <math.h>

inline Vec p2v(Point p){
    Vec an(p.x, p.y);
    return an;
}

Line::Line(float r, float g, float b, float len, float angle, Point midpoint) : Colored_Fig(r, g, b){
    length=len;
    ini_angle=angle;
    setAnchor(p2v(midpoint));
}

void Line::draw(){
    glColor3f(color.gr(), color.gg(), color.gb());
    glBegin(GL_LINES);
    glVertex2f(anchor.getX()+length/2*cos(ini_angle), anchor.getY()+length/2*sin(ini_angle));
    glVertex2f(anchor.getX()-length/2*cos(ini_angle), anchor.getY()-length/2*sin(ini_angle));
    glEnd();
}

void Line::rotate(Vec center, float angle){
    Vec tmp=anchor-center;
    tmp=tmp<<angle;
    anchor=center+tmp;
    ini_angle+=angle;
}

void Line::zoom(Vec center, float k){
    Vec tmp=anchor-center;
    tmp=tmp*k;
    anchor=center+tmp;
    length*=k;
}

Ring::Ring(float r, float g, float b, float ra, float door_fangle, Point center) : Colored_Fig(r, g, b){
    radius=ra;
    door_field_angle=door_fangle;
    setAnchor(p2v(center));
}

void Ring::draw(){
    glColor3f(color.gr(), color.gg(), color.gb());
    float pi=3.1415926f;
    int n=3600;
    int k=floor(door_field_angle*n/(4*pi));
    if (door_field_angle==0){
        glBegin(GL_LINE_LOOP);
        for (int i=0; i<n; i++)
            glVertex2f(anchor.getX()+radius*cos(2*pi*i/n), anchor.getY()+radius*sin(2*pi*i/n));
        glEnd();
    }
    else {
        glBegin(GL_LINE_STRIP);
        for (int i=k; i<n-k; i++)
            glVertex2f(anchor.getX()+radius*cos(2*pi*i/n-pi/2), anchor.getY()+radius*sin(2*pi*i/n-pi/2));
        glEnd();
    }
}

void Ring::rotate(Vec center, float angle){
    Vec tmp=anchor-center;
    tmp=tmp<<angle;
    anchor=center+tmp;
}

void Ring::zoom(Vec center, float k){
    Vec tmp=anchor-center;
    tmp=tmp*k;
    anchor=center+tmp;
    radius*=k;
}

Trapezium::Trapezium(Point ve1, Point ve2, Point ve3, Point ve4, float r, float g, float b) : Colored_Fig(r, g, b), v1(p2v(ve1)), v2(p2v(ve2)), v3(p2v(ve3)), v4(p2v(ve4)){
}

Triangle::Triangle(Point ve1, Point ve2, Point ve3, float r, float g, float b) : Colored_Fig(r, g, b), v1(p2v(ve1)), v2(p2v(ve2)), v3(p2v(ve3)){
}

polyg::polyg(float r, float g, float b, int sides, float ra) : Colored_Fig(r, g, b){
    side_num=sides;
    radius=ra;
    ini_angle=0.0;
}

void polyg::draw(){
    float pi=3.14159;
    glColor3f(color.gr(), color.gg(), color.gb());
    glBegin(GL_POLYGON);
    for (int i=0; i<side_num; i++){
        glVertex2f(anchor.getX()+radius*cos(2*pi*i/(float)side_num), anchor.getY()+radius*sin(2*pi*i/(float)side_num));
    }
    glEnd();
}

void polyg::move(Vec dir){
    anchor=anchor+dir;
}

void polyg::rotate(Vec center, float angle){
    Vec tmp=anchor-center;
    tmp=tmp<<angle;
    anchor=center+tmp;
    ini_angle+=angle;
}

void polyg::zoom(Vec center, float k){
    radius*=k;
    Vec tmp=anchor-center;
    tmp=tmp*k;
    anchor=center+tmp;
}

Rectan::Rectan(Point ve1, Point ve2, float r, float g, float b) : Trapezium(ve1, ve1, ve2, ve2, r, g, b){
    Point tmp1={ve2.x, ve1.y}; Point tmp2={ve1.x, ve2.y};
    v2=p2v(tmp1); v4=p2v(tmp2);
}

void Triangle::draw(){
    glColor3f(color.gr(), color.gg(), color.gb());
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(v1.getX(), v1.getY()); glVertex2f(v2.getX(), v2.getY()); glVertex2f(v3.getX(), v3.getY());
    glEnd();
}

void Triangle::move(Vec dir){
    anchor=anchor+dir;
    v1=v1+dir;
    v2=v2+dir;
    v3=v3+dir;
}

void Triangle::rotate(Vec center, float angle){
    Vec tmp0=anchor-center;
    Vec tmp1=v1-center;
    Vec tmp2=v2-center;
    Vec tmp3=v3-center;
    tmp0=tmp0<<angle;
    tmp1=tmp1<<angle;
    tmp2=tmp2<<angle;
    tmp3=tmp3<<angle;
    anchor=center+tmp0;
    v1=center+tmp1;
    v2=center+tmp2;
    v3=center+tmp3;
}

void Triangle::zoom(Vec center, float k){
    Vec tmp0=anchor-center;
    Vec tmp1=v1-center;
    Vec tmp2=v2-center;
    Vec tmp3=v3-center;
    tmp0=tmp0*k;
    tmp1=tmp1*k;
    tmp2=tmp2*k;
    tmp3=tmp3*k;
    anchor=center+tmp0;
    v1=center+tmp1;
    v2=center+tmp2;
    v3=center+tmp3;
}

void Trapezium::draw(){
    glColor3f(color.gr(), color.gg(), color.gb());
    glBegin(GL_QUADS);
    glVertex2f(v1.getX(), v1.getY()); glVertex2f(v2.getX(), v2.getY());
    glVertex2f(v3.getX(), v3.getY()); glVertex2f(v4.getX(), v4.getY());
    glEnd();
}

void Trapezium::move(Vec dir){
    anchor=anchor+dir;
    v1=v1+dir;
    v2=v2+dir;
    v3=v3+dir;
    v4=v4+dir;
}

void Trapezium::rotate(Vec center, float angle){
    Vec tmp0=anchor-center;
    Vec tmp1=v1-center;
    Vec tmp2=v2-center;
    Vec tmp3=v3-center;
    Vec tmp4=v4-center;
    tmp0=tmp0<<angle;
    tmp1=tmp1<<angle;
    tmp2=tmp2<<angle;
    tmp3=tmp3<<angle;
    tmp4=tmp4<<angle;
    anchor=center+tmp0;
    v1=center+tmp1;
    v2=center+tmp2;
    v3=center+tmp3;
    v4=center+tmp4;
}

void Trapezium::zoom(Vec center, float k){
    Vec tmp0=anchor-center;
    Vec tmp1=v1-center;
    Vec tmp2=v2-center;
    Vec tmp3=v3-center;
    Vec tmp4=v4-center;
    tmp0=tmp0*k;
    tmp1=tmp1*k;
    tmp2=tmp2*k;
    tmp3=tmp3*k;
    tmp4=tmp4*k;
    anchor=center+tmp0;
    v1=center+tmp1;
    v2=center+tmp2;
    v3=center+tmp3;
    v4=center+tmp4;
}

void Circle::draw(){
    float pi=3.1415926f;
    int n=3600;
    glColor3f(color.gr(), color.gg(), color.gb());
    glBegin(GL_POLYGON);
    for (int i=0; i<n; i++)
        glVertex2f(anchor.getX()+radius*cos(2*pi*i/n), anchor.getY()+radius*sin(2*pi*i/n));
    glEnd();
}

void Circle::move(Vec dir){
    anchor=anchor+dir;
}

void Circle::rotate(Vec center, float angle){
    Vec tmp=anchor-center;
    tmp=tmp<<angle;
    anchor=center+tmp;
}

void Circle::zoom(Vec center, float k){
    radius*=k;
    Vec tmp=anchor-center;
    tmp=tmp*k;
    anchor=center+tmp;
}

void Semi_circle::draw(){
    float pi=3.1415926f;
    int n=1800;
    glColor3f(color.gr(), color.gg(), color.gb());
    glBegin(GL_POLYGON);
    for (int i=0; i<=n; i++)
        glVertex2f(anchor.getX()+radius*cos(pi*i/n+ini_angle), anchor.getY()+radius*sin(pi*i/n+ini_angle));
    glEnd();
}

void Semi_circle::rotate(Vec center, float angle){
    Vec tmp=anchor-center;
    tmp=tmp<<angle;
    anchor=center+tmp;
    ini_angle+=angle;
}
