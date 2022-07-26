//
//  concrete vehicles.hpp
//  project_3_interstellar_parking_lot
//
//  Created by 娄辰飞 on 2018/12/6.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#ifndef concrete_vehicles_hpp
#define concrete_vehicles_hpp

#include "concrete shapes.hpp"
#include <ctime>
#include <cstdlib>

class Car : public Group{
    // already existed functions: getAnchor, setAnchor, draw, move, rotate, zoom, anchor, fpp, figure_num.
public:
    Car(Point a);
    void self_animation();
    // a function to let the car swinging and vibrating simultaneously.
private:
    // maybe I could add an ini_angle..
};

class UFO : public Group{
public:
    UFO(Point a);
    void self_animation();
    // a function to let it rotating and vibrating simultaneouly.
private:
    
};

class Rocket : public Group{
public:
    Rocket(Point a);
    void self_animation();
    void zoom_self();
    // a function to let it zooming and vibrating simultaneouly.
private:
    
};

class Teleported : public Group{
public:
    Teleported(Point a);
    void self_animation();
    // a function to let it zooming and changing color simultaneouly.
    void change_sides();
private:
    int sides;
};

#endif /* concrete_vehicles_hpp */
