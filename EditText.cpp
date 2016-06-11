#include "EditText.h"
#include <string>
#include <sstream>
using namespace genv;

std::string szamtostring(int szam){
    std::stringstream ss;
    ss <<szam;
    return ss.str();
}

EditText::EditText(int x0, int y0, int sx0, int sy0, std::string label_0): Text(x0, y0, sx0, sy0, label_0){
        kurzor = 0;
        fokuszalhato = true;
}
EditText::~EditText(){}

using namespace genv;

void EditText::draw(){
    Text::draw();
    //kurzor
    if(focused){
        gout <<move_to(x+gout.twidth(" ") + gout.twidth(label.substr(0,kurzor)), y+2)
             <<color(255,255,255)
             <<line(0,gout.cascent()+gout.cdescent());
    }
}

void EditText::handle(event ev){
    Text::handle(ev);

    if (ev.type == ev_mouse && contains(ev.pos_x, ev.pos_y) && ev.button == btn_left){
        bool eddig = false;
        for (int i = 0; i<label.length(); i++){
            if (gout.twidth(label.substr(0,i+1)) >= ev.pos_x - (x+gout.twidth(" ")) && !eddig) {
                kurzor = i+1;
                eddig = true;
            }
        }
    }

    if (ev.type == ev_key && focused) {
        if (31 < ev.keycode && ev.keycode < 127) {
            setText(label.substr(0,kurzor) + (char)ev.keycode + label.substr(kurzor,label.length()));
            if (kurzor != label.length()) ++kurzor;
        }
        else if (47 < ev.keycode && ev.keycode < 58) {
            setText(label.substr(0,kurzor) + szamtostring(ev.keycode-47) + label.substr(kurzor,label.length()));
            if (kurzor != label.length()) ++kurzor;
        }
        else if (ev.keycode == key_backspace && label.length() > 0) {
            setText(label.substr(0,kurzor-1)+ label.substr(kurzor,label.length()-1));
            if (kurzor != 0) --kurzor;
        }


        else if (ev.keycode == key_left && kurzor !=0) --kurzor;
        else if (ev.keycode == key_right && kurzor != label.length()) ++kurzor ;
        else if (ev.keycode == key_delete && kurzor != label.length()){
                setText(label.substr(0,kurzor)+ label.substr(kurzor+1,label.length()));
        }

    }

}

