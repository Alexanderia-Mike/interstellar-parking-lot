//
//  concrete shapes.hpp
//  project_3_interstellar_parking_lot
//
//  Created by 娄辰飞 on 2018/12/6.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#ifndef concrete_shapes_hpp
#define concrete_shapes_hpp
#include "vec_and_figure.hpp"

class Line : public Colored_Fig{
public:
    Line(float r, float g, float b, float len, float angle, Point midpoint);
    void draw();
    void move(Vec dir) {anchor=anchor+dir;}
    void rotate(Vec center, float angle);
    void zoom(Vec center, float k);
private:
    float ini_angle, length;
};

class Ring : public Colored_Fig{
public:
    Ring(float r, float g, float b, float ra, float door_fangle, Point center);
    void draw();
    void move(Vec dir) {anchor=anchor+dir;}
    void rotate(Vec center, float angle);
    void zoom(Vec center, float k);
private:
    float radius, door_field_angle;
};

class Triangle : public Colored_Fig{
public:
//    Triangle(Vec ve1, Vec ve2, Vec ve3, float r, float g, float b) : Colored_Fig(r, g, b), v1(ve1), v2(ve2), v3(ve3){}
    Triangle(Point ve1, Point ve2, Point ve3, float r, float g, float b);
    void draw();
    void move(Vec dir);
    void rotate(Vec center, float angle);
    void zoom(Vec center, float k);
    // apart form these functions, it has getAnchor, setAnchor, anchor, paint, color.
private:
    Vec v1, v2, v3;
};

class Trapezium : public Colored_Fig{
public:
//    Trapezium(Vec ve1, Vec ve2, Vec ve3, Vec ve4, float r, float g, float b) : Colored_Fig(r, g, b), v1(ve1), v2(ve2), v3(ve3), v4(ve4){}
    Trapezium(Point ve1, Point ve2, Point ve3, Point ve4, float r, float g, float b);
    void draw();
    void move(Vec dir);
    void rotate(Vec center, float angle);
    void zoom(Vec center, float k);
    // apart form these functions, it has getAnchor, setAnchor, anchor, paint, color.
protected:
    Vec v1, v2, v3, v4;
};

class Rectan : public Trapezium{
public:
//    Rectan(Vec ve1, Vec ve2, float r, float g, float b);
    Rectan(Point ve1, Point ve2, float r, float g, float b);
};

class Circle : public Colored_Fig{
public:
    Circle(float R, float r, float g, float b) : Colored_Fig(r, g, b) {radius=R;}
    virtual void draw();
    void move(Vec dir);
    virtual void rotate(Vec center, float angle);
    void zoom(Vec center, float k);
    // apart form these functions, it has getAnchor, setAnchor, anchor, paint, color.
protected:
    float radius;
};

class Semi_circle : public Circle{
public:
    Semi_circle(float R, float i_angle, float r, float g, float b) : Circle(R, r, g, b) {ini_angle=i_angle;}
    void draw();
    void rotate(Vec center, float angle);
    // apart form these functions, it has getAnchor, setAnchor, anchor, paint, color.
private:
    float ini_angle;
};

class polyg : public Colored_Fig{
public:
    polyg(float r, float g, float b, int sides, float ra);
    void draw();
    void move(Vec dir);
    void rotate(Vec center, float angle);
    void zoom(Vec center, float k);
private:
    float radius;
    int side_num;
    float ini_angle;
};

#endif /* concrete_shapes_hpp */
