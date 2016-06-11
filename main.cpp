////////////////////////////////////////////////////////
//
//  - Csak a szambeallito widget van kesz felig-meddig
//  - Fajlba irni az F1 billentyuvel lehet
//
///////////////////////////////////////////////////////

#include "graphics.hpp"
#include "Widget.h"
#include "NumberControl.h"
#include <vector>
#include <fstream>
using namespace genv;
#include <iostream>

const int XX = 800, YY = 600;

void kepernyottorol(){
    gout <<move_to(0,0) <<color(255,255,255) << box(XX,YY);
}

int main()
{
    gout.open(XX,YY);
    std::ofstream file;
    file.open("Ittvan.txt");

    std::vector<Widget*> widgets;
    NumberControl *n1 = new NumberControl(50,50,0,0,-50,50,0); widgets.push_back(n1);
    NumberControl *n2 = new NumberControl(200,50,0,0,0,1000,1); widgets.push_back(n2);
    std::vector<NumberControl*> numbercontrols;
    numbercontrols.push_back(n1);
    numbercontrols.push_back(n2);

    Button *b1 = new Button(350,50,0,0,"Ez mi?");
    b1->eztcsinalja( [] {std::cout << "Ez mi?" << std::endl;});
    Button *b2 = new Button(450,50,0,0,"Es ez?");
    b2->eztcsinalja([](){std::cout << "Es ez?" << std::endl;});
    widgets.push_back(b1);
    widgets.push_back(b2);

    Text *t1 = new Text(50,150,0,0,"Ide nem lehet irni"); widgets.push_back(t1);
    Text *t2 = new Text(50,250,0,0,"Ide sem"); widgets.push_back(t2);

    EditText *et1 = new EditText(350,150,0,0,"Ide lehet"); widgets.push_back(et1);
    EditText *et2 = new EditText(350,250,0,0,"Ide is"); widgets.push_back(et2);

    event ev;
    while(gin >> ev && ev.keycode != key_escape) {
            kepernyottorol();
            for(Widget *w: widgets){
                w->draw();
                w->handle(ev);
            }
            gout << refresh;

            if(ev.type == ev_key && ev.keycode == key_f1){
                for(NumberControl *n: numbercontrols)
                    n->fajlbair(file);
            }
    }

    for(Widget *w: widgets){
        delete w;
    }
    file.close();

    return 0;
}
