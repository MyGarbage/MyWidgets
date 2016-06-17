#include "Checkbox.h"
#include "Graphics.hpp"
using namespace genv;
#include <iostream>


Checkbox::Checkbox(int x0, int y0, int sx0, int sy0): Widget(x0,y0,sx0,sy0){
    checked = false;
    if (sx == 0){
        sx = 20; //gout.cascent()+ gout.cdescent() + 3;
        sy = sx;
    }
}
Checkbox::~Checkbox(){}

void Checkbox::draw(){
    gout <<move_to(x,y) <<color(0,0,0);
    gout <<line(sx,0) <<line(0,sy) <<line(-sx,0) <<line(0,-sy);

    if(checked){
        gout <<move_to(x + 4, y + sy/2) <<color(0,0,0);
        gout <<line(sy/4, sy/4) <<line(sy/2,-(sy/2));
    }

    if (focused){
        gout <<move_to(x-3, y-3) << color(100,100,100);
        for(int i=0; i<(sy/2+2); i++) gout <<genv::move(2,0) <<dot;
        for(int i=0; i<(sy/2+2); i++) gout <<genv::move(0,2) <<dot;
        for(int i=0; i<(sy/2+2); i++) gout <<genv::move(-2,0) <<dot;
        for(int i=0; i<(sy/2+2); i++) gout <<genv::move(0,-2) <<dot;
    }
}

void Checkbox::handle(event ev){
    Widget::handle(ev);

    if (focused && ev.type == ev_mouse && ev.button == btn_left)
        checked = !checked;
    if (focused && ev.type == ev_key && ev.keycode == key_space)
        checked = !checked;
}

bool Checkbox::contains(int posx, int posy){
    return (posx >= x && posx <= x+sx && posy >= y && posy <= y+sy);
}

