#ifndef NUMBERCONTROL_H
#define NUMBERCONTROL_H

#include "EditText.h"
#include "Button.h"


class NumberControl : public Widget
{
    private:
        int min;
        int max;
        int szam;
        EditText *t1;
        Button *b1;
        Button *b2;
    public:
        NumberControl(int x0, int y0, int sx0, int sy0, int min0, int max0, int szam0);
        virtual ~NumberControl();
        virtual void draw();
        virtual bool contains(int posx, int posy);
        virtual void handle(genv::event ev);
        virtual void fajlbair(std::ostream &file);
};

#endif // NUMBERCONTROL_H
