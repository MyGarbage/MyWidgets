#ifndef BUTTON_H
#define BUTTON_H

#include "Widget.h"
#include <string>
#include <functional>

class Button : public Widget
{
    private:
        std::string szoveg;
        std::function<void()> csinalvalamit;
        bool levannyomva;
    public:
        Button(int x0, int y0, int sx0, int sy0, std::string szoveg0);
        virtual ~Button();
        virtual void draw();
        virtual bool contains(int posx, int posy);
        virtual void handle(genv::event ev);
        void eztcsinalja(std::function<void()> valami);
};

#endif // BUTTON_H
