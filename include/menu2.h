#ifndef MENU2_H
#define MENU2_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class menu2
{
    public:
        menu2(float x,float y);
        int menu2pressed();
        void draw(RenderWindow& window);
        void moveup();
        void movedown();

        virtual ~menu2();

    protected:

    private:
    Font font;
    int menu2selected;
    Text menu[3];
};

#endif // MENU2_H
