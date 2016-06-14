#include "RadioButton.h"
#include "Graphics.hpp"
using namespace genv;

RadioButton::RadioButton(int x0, int y0, int sx0, int sy0, std::string label0)
                        : Widget(x0,y0,sx0,sy0), label(label0){
       checked = false;
       sx = 20 + gout.twidth(' '+label+' ');
       sy = gout.cascent()+gout.cdescent();
}
RadioButton::~RadioButton(){}

void RadioButton::draw(){

    int r = 10;
    for (int i= -r; i<= r; i++){
        for (int j= -r; j<= r; j++){
            if (i*i + j*j <= (r*r)/3 ){
                gout <<move_to((x+r)+i,(y+r)+j) <<color (255,255,255) <<dot;
            }
        }
    }

    if(checked){
        for (int i= -r; i<= r; i++){
            for (int j= -r; j<= r; j++){
                if (i*i + j*j <= r/2){
                    gout <<move_to((x+r)+i,(y+r)+j) <<color(51,153,255) <<dot;
                }
            }
        }
    }

    if(focused){
        gout <<move_to(x+23, y+1) << color(100,100,100);
        for(int i=0; i<(gout.twidth(label+' ')/2+2); i++) gout <<genv::move(2,0) <<dot;
        for(int i=0; i<(sy/2+1); i++) gout <<genv::move(0,2) <<dot;
        for(int i=0; i<(gout.twidth(label+' ')/2+2); i++) gout <<genv::move(-2,0) <<dot;
        for(int i=0; i<(sy/2+1); i++) gout <<genv::move(0,-2) <<dot;
    }

    gout <<move_to(x+21, y+2+ gout.cascent()) <<color(100,100,100)
         <<text(' '+label);
}

void RadioButton::handle(event ev){
    Widget::handle(ev);
    if(focused && ev.type == ev_mouse && ev.button == btn_left){
        checked = true;
    }
    if(focused && ev.type == ev_key && ev.keycode == key_space){
        checked = true;
    }
}

bool RadioButton::contains(int posx, int posy){
    return (posx >= x && posx <= x+sx && posy >= y && posy <=y+sy);
}

