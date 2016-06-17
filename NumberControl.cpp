#include "NumberControl.h"
#include <sstream>
#include <string>
using namespace genv;

template <typename T>
std::string to_string(T &ezt){
    std::stringstream stream;
    stream << ezt;
    return stream.str();
}

int stringtoszam(std::string szov){
    std::stringstream ss;
    ss <<szov;
    int szam;
    ss >>szam;
    return szam;
}

//-------------------------------------------------------------------
NumberControl::NumberControl(int x0, int y0, int sx0, int sy0, int min0, int max0, int szam0): Widget(x0, y0, sx0, sy0),
                            min(min0), max(max0), szam(szam0){
    t1 = new EditText(x,y,std::max(gout.twidth(to_string(min)),gout.twidth(to_string(max))),0,to_string(szam));
    b1 = new Button(x+ t1->getSx() + 1, y,0,0, "Control+");
    b2 = new Button(x+ t1->getSx() + 1, y+12,0,0, "Control-");
    b1->eztcsinalja([&](){if(szam != max) ++szam;});
    b2->eztcsinalja([&](){if(szam != min) --szam;});
}
NumberControl::~NumberControl(){
    delete t1;
    delete b1;
    delete b2;
}

//-------------------------------------------------------------------
bool NumberControl::contains(int posx, int posy){
    return (t1->contains(posx,posy) || b1->contains(posx,posy) || b2->contains(posx,posy));
}

void NumberControl::handle(genv::event ev){
    Widget::handle(ev);
    if(ev.type == ev_mouse){
        t1->handle(ev); if(focused) t1->keepFocused();

        b1->handle(ev);
        b2->handle(ev);
        t1->setText(to_string(szam));
    }
    if(focused  && ev.type == ev_key){

        if (ev.keycode == key_up && szam != max) {++szam;}
        else if (ev.keycode == key_down && szam != min) {--szam;}
        else if (ev.keycode == key_pgup && szam != max) {szam += 5; if(szam>max) szam=max;}
        else if (ev.keycode == key_pgdn && szam != min) {szam -= 5; if(szam<min) szam=min;}
        else if (ev.keycode == key_end) {szam=max;}
        else if (ev.keycode == key_home) {szam=min;}
        t1->setText(to_string(szam));

        //csak ezek a billenytuk orokolnek az EditTextbol
        bool nemlehet = false;
        if (ev.keycode == key_right || ev.keycode == key_left) {}
        else if (ev.keycode == key_delete || ev.keycode == key_backspace) {}
        else if (ev.keycode > 47 && ev.keycode < 58){
           if (t1->getText() != ""){
                szam = stringtoszam(t1->getText());
           }
        }//nem ert && (szam > min && szam < max)) {}
        //else if (ev.keycode == 45) {} //negativ szamokat nem lehet meg beirni
        else nemlehet = true;



        if (!nemlehet){

            t1->handle(ev);

            if (ev.keycode == key_delete || ev.keycode == key_backspace ||(ev.keycode > 47 && ev.keycode < 58)){
                szam = stringtoszam(t1->getText());
                if (szam < min) szam = min;
                else if (szam > max) szam = max;
            }
            else if(ev.keycode > 47 && ev.keycode < 58){
                    //szam = ev.keycode - 48; //csak sudokunal, hogy a 0-t ne jelenitse meg
            }

            //t1->setText(to_string(szam));
        }

    }
}

//-------------------------------------------------------------------
void NumberControl::draw(){
    t1->draw();
    if(folottevan){
        b1->draw();
        b2->draw();
    }
}

void NumberControl::fajlbair(std::ostream &file) {
    t1->fajlbair(file);
}

