#ifndef RADIOBUTTONGROUP_H
#define RADIOBUTTONGROUP_H

#include "RadioButton.h"
#include <vector>
#include <string>


class RadioButtonGroup : public Widget
{
    private:
        std::vector<RadioButton*> radiobuttons;
    protected:
    public:
        RadioButtonGroup(int x0, int y0, int sx0, int sy0, std::vector<std::string> buttonlabels);
        virtual ~RadioButtonGroup();
        virtual void draw();
        virtual bool contains(int posx, int posy);
        virtual void handle(genv::event ev);
};

#endif // RADIOBUTTONGROUP_H
