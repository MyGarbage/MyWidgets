#include "Widget.h"
using namespace genv;

Widget::Widget(int x0, int y0, int sx0, int sy0): x(x0), y(y0), sx(sx0), sy(sy0), focused(0), folottevan(0),fokuszalhato(1) {}
Widget::~Widget(){}

void Widget::handle(event ev){
    if(ev.type == ev_mouse){
            folottevan = contains(ev.pos_x, ev.pos_y);
            if (fokuszalhato && ev.button == btn_left)
                focused = folottevan;//contains(ev.pos_x,ev.pos_y);
    }
}

