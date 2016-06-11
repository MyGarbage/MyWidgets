#ifndef TEXT_H
#define TEXT_H

#include "Widget.h"
#include <string>

class Text : public Widget
{
    protected:
        std::string label;

    public:
        Text(int x0, int y0, int sx0, int sy0, std::string label_0);
        virtual ~Text();
        virtual void draw();
        virtual bool contains(int posx, int posy);
        virtual void handle(genv::event ev);
        void setText(std::string szoveg);
        std::string getText(){return label;}
        virtual void fajlbair(std::ostream &file);
};

#endif // TEXT_H
