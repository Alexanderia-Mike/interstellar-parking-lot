//
//  vec_and_figure.cpp
//  project_3_interstellar_parking_lot
//
//  Created by 娄辰飞 on 2018/12/6.
//  Copyright © 2018 娄辰飞. All rights reserved.
//

#include "vec_and_figure.hpp"

inline Vec p2v(Point p){
    Vec an(p.x, p.y);
    return an;
}

Group::Group(Point a, int n) : flag_dir(0.0, 0.01){
    fpp=new Colored_Fig*[n];
    anchor=p2v(a);
    figure_num=n;
    ini_angle=0;
    size=1;
    deviation=0.0;
    deflection=0.0;
    time=0;
    flagp=new Colored_Fig* [2];
}

void Group::draw(){
    for (int i=0; i<figure_num; i++)
        fpp[i]->draw(); // at last the detailed shapes would substitute figure, so their draw function would have contents.
    flagp[0]->draw();
    flagp[1]->draw();
}

void Group::move(Vec dir){
    anchor=anchor+dir; // I don't know why we need function setanchor()...
    for (int i=0; i<figure_num; i++)
        fpp[i]->move(dir);
//        fpp[i]->setAnchor(getAnchor()+dir);
    flagp[0]->move(dir);
    flagp[1]->move(dir);
}

void Group::rotate(Vec center, float angle){
    Vec tmp1=anchor-center;
    tmp1=tmp1<<angle;
    anchor=center+tmp1;
    ini_angle+=angle;
    for (int i=0; i<figure_num; i++)
        fpp[i]->rotate(center, angle);
    flagp[0]->rotate(center, angle);
    flagp[1]->rotate(center, angle);
    flag_dir=flag_dir<<angle;
}

void Group::zoom(Vec center, float k){
    size*=k;
    for (int i=0; i<figure_num; i++)
        fpp[i]->zoom(anchor, k);
    flagp[0]->zoom(anchor, k);
    flagp[1]->zoom(anchor, k);
    flag_dir=flag_dir*k;
}

void Group::flag_moving(){
    flagp[0]->move(flag_dir);
    flagp[1]->move(flag_dir);
    time++;
    Vec tmp(0.0, 0.0);
    if (time%20==0)
        flag_dir=tmp-flag_dir;
}

Group::~Group(){
    for (int i=0; i<figure_num; i++)
        delete fpp[i];
    delete flagp[0];
    delete flagp[1];
    delete[] fpp;
    delete[] flagp;
}
