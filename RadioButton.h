#ifndef RADIOBUTTON_H
#define RADIOBUTTON_H

#include "Widget.h"
#include <string>

class RadioButton : public Widget
{
    private:
        std::string label;
        bool checked;
    protected:
    public:
        RadioButton(int x0, int y0, int sx0, int sy0, std::string label0);
        virtual ~RadioButton();
        virtual void draw();
        virtual bool contains(int posx, int posy);
        virtual void handle(genv::event ev);
        bool isChecked(){return checked;};
        void uncheck(){checked = false;}
};

#endif // RADIOBUTTON_H
