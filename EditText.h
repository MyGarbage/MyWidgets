#ifndef EDITTEXT_H
#define EDITTEXT_H

#include "Text.h"
#include <string>


class EditText : public Text
{
    private:
        int kurzor;
    protected:
    public:
        EditText(int x0, int y0, int sx0, int sy0, std::string label_0);
        virtual ~EditText();
        virtual void draw();
        virtual void handle(genv::event ev);
        int getSx() {return sx;}
        void keepFocused(){focused = true;};
};

#endif // EDITTEXT_H
