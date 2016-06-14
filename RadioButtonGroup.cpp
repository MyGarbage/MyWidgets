#include "RadioButtonGroup.h"
#include "Graphics.hpp"
using namespace genv;

#include <string>
#include <vector>


RadioButtonGroup::RadioButtonGroup(int x0, int y0, int sx0, int sy0, std::vector<std::string> buttonlabels)
                :Widget(x0,y0,sx0,sy0){

    for (int i=0; i<buttonlabels.size(); i++){
        RadioButton *rb = new RadioButton(x0,y0+i*20,0,0,buttonlabels[i]);
        radiobuttons.push_back(rb);
    }


    int longest = 0;
    for (int i=0; i<buttonlabels.size(); i++){
            if (gout.twidth(buttonlabels[i]) > longest) longest = gout.twidth(buttonlabels[i]);
    }
    sx = 21 + longest + gout.twidth("  ");
    sy = buttonlabels.size()*20;

}
RadioButtonGroup::~RadioButtonGroup(){}

void RadioButtonGroup::draw(){

    gout <<move_to(x,y) <<color(200,200,200) <<box(sx,sy);
    for (RadioButton* rb: radiobuttons){
        rb->draw();
    }
}
void RadioButtonGroup::handle(event ev){

    Widget::handle(ev);
    if (focused){
        for(int i=0; i<radiobuttons.size(); i++){
            radiobuttons[i]->handle(ev);
            if (radiobuttons[i]->isChecked()){
                for (int j=0; j<radiobuttons.size(); j++){
                    if( i != j) radiobuttons[j]->uncheck();
                }
            }
        }
    }
}

bool RadioButtonGroup::contains(int posx, int posy){
    return (posx >= x && posx <= x+sx && posy >= y && posy <=y+sy);
}

