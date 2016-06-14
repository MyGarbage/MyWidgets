#include "Text.h"
#include "graphics.hpp"
#include <iostream>
using namespace genv;

//-------------------------------------------------------------------
Text::Text(int x0, int y0, int sx0, int sy0, std::string label_0 = "0"): Widget(x0, y0, sx0, sy0), label(label_0) {
    if (sx == 0) sx = gout.twidth(label);
    sx += 16;
    sy = 6+ gout.cascent()+gout.cdescent();
    fokuszalhato = false;
}
Text::~Text(){}

//-------------------------------------------------------------------
bool Text::contains(int posx, int posy){
    return posx >= x && posx <= x+sx && posy >= y && posy <=y+sy;
}

void Text::handle(event ev){
    Widget::handle(ev);
}

void Text::setText(std::string szoveg){
    label = szoveg;
}
//-------------------------------------------------------------------
void Text::draw(){


    //if (label != "0") //csak sudokunal kellett
    //if (!fokuszalhato){  //ha nem EditText
        gout <<move_to(x,y+gout.cascent()+3)  <<text(' '+label);
    //}
}

void Text::fajlbair(std::ostream &file){
    file <<label <<std::endl;
}

