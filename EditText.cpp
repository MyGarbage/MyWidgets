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
    //Text::draw();

    //keret
    gout <<move_to(x,y) <<color(0,0,0)//(150,150,150)
         <<line(sx, 0)  <<line(0, sy)
         <<line(-sx, 0) <<line(0, -sy);

    //kek hatter, feher betuk
    gout <<color(150,150,150);
    if(focused){
        gout <<color(51,153,255) <<move_to(x+gout.twidth(" "), y+2)
             <<box(gout.twidth(label)+2, sy-4);
        gout <<color(255,255,255);
    }
    else gout <<color(0,0,0);

    //szoveghossztol fuggoen
    gout <<move_to(x,y+gout.cascent()+3);
    if (gout.twidth(' '+label) <= sx){
         gout <<text(' '+label);
    }
    else if (!focused){
        bool eddig = false;
        int i=0;
        while (!eddig && i<label.length()){
            if (gout.twidth(' '+label.substr(0,i))+' ' > sx){
                gout <<text(' '+label.substr(0,i)+"..");
                eddig = true;
            }
            i++;
        }

    }
    else{
        gout <<text(' '+label);
    }

    //kurzor
    if(focused){
        gout <<move_to(x+gout.twidth(" ") + gout.twidth(label.substr(0,kurzor)), y+2)
             <<color(255,255,255)
             <<line(0,gout.cascent()+gout.cdescent());
    }
}

void EditText::handle(event ev){
    Text::handle(ev);

    if (ev.button == btn_left && (gout.twidth(label) > sx) &&
       (ev.pos_x >= x && ev.pos_x <= x+gout.twidth(" "+label)) &&
       (ev.pos_y >= y && ev.pos_y <=y+sy)){
        keepFocused();
    }

    if (focused && ev.type == ev_mouse && ev.button == btn_left){  //&& contains(ev.pos_x, ev.pos_y)){
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
        else if (ev.keycode == key_home) kurzor = 0;
        else if (ev.keycode == key_end) kurzor = label.length();
        else if (ev.keycode == key_delete && kurzor != label.length()){
                setText(label.substr(0,kurzor)+ label.substr(kurzor+1,label.length()));
        }
        else if (ev.keycode == key_enter) focused = false;
    }
}

