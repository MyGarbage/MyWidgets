#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "Widget.h"


class Checkbox : public Widget
{
    private:
        bool checked;
    protected:
    public:
        Checkbox(int x0, int y0, int sx0, int sy0);
        virtual ~Checkbox();
        virtual void draw();
        virtual bool contains(int posx, int posy);
        virtual void handle(genv::event ev);
};

#endif // CHECKBOX_H
