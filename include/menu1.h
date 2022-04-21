#ifndef MENU1_H
#define MENU1_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class menu1
{
    public:
        menu1(float width,float height);
        int menu1pressed();
        void draw(RenderWindow& window);
        void moveup();
        void movedown();

        virtual ~menu1();

    protected:

    private:
    Font font;
    int menu1selected;
    Text menu[3];
};

#endif // MENU1_H
