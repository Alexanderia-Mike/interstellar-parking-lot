//
//  vec_and_figure.hpp
//  project_3_interstellar_parking_lot
//
//  Created by 娄辰飞 on 2018/12/6.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#ifndef vec_and_figure_hpp
#define vec_and_figure_hpp

#include <GLUT/glut.h>
#include <math.h>

typedef struct Point{
    float x;
    float y;
} Point;

class Color{
public:
    Color(float r=1.0, float g=1.0, float b=1.0) {red=r; green=g; blue=b;}
    void change_color(float r, float g, float b) {red=r; green=g; blue=b;}
    float gr(){return red;}
    float gg(){return green;}
    float gb(){return blue;}
protected:
    float red; float green; float blue;
};

class Vec {
private:
    float x,y;
public:
    Vec(float _x, float _y) { x = _x; y = _y;}
    float getX() {return x;}
    float getY() {return y;}
    // Example Overloads + operator // returns the sum of 2 Vec
    Vec operator+ (Vec v) {
        return Vec(x + v.getX(), y + v.getY());// it's a constructor building a new Vec class.
    }
    // Overload - on 2 Vectors
    // return thier difference Vector
    Vec operator- (Vec v){
        return Vec(x-v.getX(), y-v.getY());
    }
    // Overload * operator on a float k
    // return current Vector scaled by k
    Vec operator* (float k){
        return Vec(k*x, k*y);
    }
    // Overload * on 2 Vectors
    // return thier inner product (scaler product)
    Vec operator* (Vec v){
        return Vec(x*v.getY(), y*getY());
    }
    // Overload << on an angle
    // return current vector rotated counter clockwise by this angle
    Vec operator<< (float seta){
        return Vec(x*cos(seta)-y*sin(seta), x*sin(seta)+y*cos(seta));
    }
    // Overload >> on an angle
    // return current vector rotated clockwise by this angle
    Vec operator>> (float seta){
        return Vec(x*cos(seta)+y*sin(seta), -x*sin(seta)+y*cos(seta));
    }
};

class Figure {
protected:
    Vec anchor;
public:
    Figure() : anchor(0, 0) {}
    Vec getAnchor() {return anchor;}
    void setAnchor(Vec a) {anchor = a;}
    virtual void draw() = 0;
    virtual void move(Vec dir) =0;//{anchor=anchor+dir;}
    // rotate: the figure rotate through angle around center.
    virtual void rotate(Vec center, float angle) =0;//{anchor=anchor<<angle;}
    virtual void zoom(Vec center, float k) =0;//{anchor=anchor*k;}
    virtual ~Figure() {}
};

class Colored_Fig : public Figure{
public:
    Colored_Fig(float r, float g, float b) : Figure(), color(r, g, b) {};
    void paint(float r, float g, float b) {color.change_color(r, g, b);}
protected:
    Color color;
};

class Group : public Figure {
protected:
    Colored_Fig** fpp;
    int figure_num;
    float ini_angle;
    float size;
    float deviation;
    float deflection;
    Colored_Fig** flagp;
    int time;
    Vec flag_dir;
public:
    Group(Point a, int n);
    void draw(); // Draw out all its figures
    void move(Vec dir); // Move all its figures
    // here, rotate makes the whole group ratate through angle around center.
    void rotate(Vec center, float angle); // Rotate the group as a whole. void zoom(float k);
    void zoom(Vec center, float k); // Zoom the group as a whole.
    float return_size() {return size;}
    ~Group();
    // apart from them, it has : getanchor, setanchor, anchor.
    // add a function to let a flag moving up and down.
    void flag_moving();
    virtual void self_animation()=0;
};

#endif /* vec_and_figure_hpp */
