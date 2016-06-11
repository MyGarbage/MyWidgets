#ifndef WIDGET_H
#define WIDGET_H
#include "graphics.hpp"

class Widget
{
    protected:
        int x,y,sx,sy;
        bool focused;
        bool folottevan;
        bool fokuszalhato;
    public:
        Widget(int x0, int y0, int sx0, int sy0);
        virtual ~Widget();
        virtual void draw() = 0;
        virtual bool contains(int posx, int posy) = 0;
        virtual void handle(genv::event ev);
};

#endif // WIDGET_H
