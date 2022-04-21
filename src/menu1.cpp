#include "menu1.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
menu1::menu1(float width,float height)
{
  if(!font.loadFromFile("University.otf")){
    cout<<"pas de font ici"<<endl;

 }
 //play
 menu[0].setColor(Color::Blue);
 menu[0].setString("Level 1");
 menu[0].setCharacterSize(50);
 menu[0].setPosition(320,320);
 menu[0].setFont(font);
 menu[0].setOrigin(menu[0].getLocalBounds().width/2,menu[0].getLocalBounds().height/2);
 //Options
 menu[1].setColor(Color::White);
 menu[1].setString("Level 2");
 menu[1].setCharacterSize(50);
 menu[1].setPosition(320,420);
 menu[1].setFont(font);
 menu[1].setOrigin(menu[1].getLocalBounds().width/2,menu[1].getLocalBounds().height/2);
 //Exit
 menu[2].setColor(Color::White);
 menu[2].setString("Level 3");
 menu[2].setCharacterSize(50);
 menu[2].setPosition(320,520);
 menu[2].setFont(font);
 menu[2].setOrigin(menu[2].getLocalBounds().width/2,menu[2].getLocalBounds().height/2);

 //menu1selected
 menu1selected=0;
}

menu1::~menu1()
{
    //dtor
}

void menu1::draw(RenderWindow& window){
    for(int i=0;i<3;i++){
        window.draw(menu[i]);
    }
}

void menu1::moveup(){
    if (menu1selected-1>=0){
        menu[menu1selected].setColor(Color::White);
        menu1selected--;
        menu[menu1selected].setColor(Color::Blue);
    }else if (menu1selected==0){
        menu[menu1selected].setColor(Color::White);
        menu1selected=2;

        menu[menu1selected].setColor(Color::Blue);
    }

}

void menu1::movedown(){
    if (menu1selected+1<=2){
        menu[menu1selected].setColor(Color::White);
        menu1selected++;

        menu[menu1selected].setColor(Color::Blue);
    }else if(menu1selected==2){
        menu[menu1selected].setColor(Color::White);
        menu1selected=0;
        menu[menu1selected].setColor(Color::Blue);
        }

}
int menu1::menu1pressed(){
    return menu1selected;

    }
