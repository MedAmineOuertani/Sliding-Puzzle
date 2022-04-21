#ifndef MAINMENU_H
#define MAINMENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
#define max_menu 2
using namespace sf;

class mainmenu
{
    public:
        void Draw(RenderWindow& window);
        void moveup();
        void movedown();
        int mainmenupressed();
        mainmenu(float width, float height);
        virtual ~mainmenu();

    protected:

    private:
    int mainmenuselected;
    Font font;
    Text mainMenu[max_menu];
};

#endif // MAINMENU_H
