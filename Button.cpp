#include "Button.h"
#include "graphics.hpp"
using namespace genv;

//-----------------------------------------------------------------------
Button::Button(int x0, int y0, int sx0, int sy0, std::string szoveg0): Widget(x0, y0, sx0, sy0),
               szoveg(szoveg0), csinalvalamit([](){}), levannyomva(0) {
    if (szoveg == "Control+" || szoveg == "Control-"){
        sx = 14;  sy = 11;}
    else {
        sx = gout.twidth(szoveg) + 6;
        sy = gout.cascent() + gout.cdescent() + 4;
    }
}
Button::~Button(){}

//-----------------------------------------------------------------------
bool Button::contains(int posx, int posy){
    return posx >= x && posx <= x+sx && posy >= y && posy <=y+sy;
}

void Button::eztcsinalja(std::function<void()> valami) {
    csinalvalamit = valami;
}

void Button::handle(event ev){
    Widget::handle(ev);
    if(ev.button == btn_left && folottevan){//contains(ev.pos_x, ev.pos_y)){
            levannyomva = true;
            this->draw();
            csinalvalamit();
    }
    if (ev.button == -btn_left &&folottevan){
        levannyomva = false;
        this->draw();
    }
}

//------------------------------------------------------------------------
void Button::draw(){



    if (folottevan)  {
        if (levannyomva) gout <<color(100,100,100);
        else gout <<color(200,200,200);
        gout <<move_to(x,y) <<box(sx,sy);
    }
    else if (szoveg != "Control+" && szoveg != "Control-"){
        gout <<color(225,225,225) <<move_to(x,y) <<box(sx,sy);
    }

    //nyil vagy szoveg
    gout <<color(0,0,0);//(150,150,150);
    if(szoveg == "Control+"){
        for(int i=1; i<6; i++){
            gout <<move_to(x+7-i,y+3+i) <<line(2*i,0);
        }
    }
    else if (szoveg == "Control-"){
        for(int i=5; i>0; i--){
            gout <<move_to(x+7-i,y+7-i) <<line(2*i,0);
        }
    }
    else{
        if (focused){
            gout <<move_to(x-3, y-3) << color(100,100,100);
            for(int i=0; i<(sx/2+2); i++) gout <<genv::move(2,0) <<dot;
            for(int i=0; i<(sy/2+3); i++) gout <<genv::move(0,2) <<dot;
            for(int i=0; i<(sx/2+2); i++) gout <<genv::move(-2,0) <<dot;
            for(int i=0; i<(sy/2+3); i++) gout <<genv::move(0,-2) <<dot;
        }
        if (levannyomva) gout <<color(0,0,0);
        else gout <<color(100,100,100);
        gout <<move_to(x,y) //<<color(100,100,100)
             <<line(sx,0) <<line(0,sy) <<line(-sx,0) <<line(0,-sy);

        gout <<move_to(x+3, y+3+gout.cascent()) <<color(0,0,0)
             <<text(szoveg);
    }
}


