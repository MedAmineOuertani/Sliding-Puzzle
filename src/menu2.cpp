#include "menu2.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
menu2::menu2(float x,float y)
{
  if(!font.loadFromFile("University.otf")){
    cout<<"pas de font ici"<<endl;

 }
 //Reset
 menu[0].setColor(Color::Blue);
 menu[0].setString("Reset");
 menu[0].setCharacterSize(35);
 menu[0].setPosition(x,y);
 menu[0].setFont(font);
 menu[0].setOrigin(menu[0].getLocalBounds().width/2,menu[0].getLocalBounds().height/2);
 //Solutions
 menu[1].setColor(Color::White);
 menu[1].setString("Soltuions");
 menu[1].setCharacterSize(35);
 menu[1].setPosition(x,y+100);
 menu[1].setFont(font);
 menu[1].setOrigin(menu[1].getLocalBounds().width/2,menu[1].getLocalBounds().height/2);
 //Exit
 menu[2].setColor(Color::White);
 menu[2].setString("Exit");
 menu[2].setCharacterSize(35);
 menu[2].setPosition(x,y+200);
 menu[2].setFont(font);
 menu[2].setOrigin(menu[2].getLocalBounds().width/2,menu[2].getLocalBounds().height/2);


 //menu2selected
 menu2selected=0;
}

menu2::~menu2()
{
    //dtor
}

void menu2::draw(RenderWindow& window){
    for(int i=0;i<3;i++){
        window.draw(menu[i]);
    }
}

void menu2::moveup(){
    if (menu2selected-1>=0){
        menu[menu2selected].setColor(Color::White);
        menu2selected--;
        menu[menu2selected].setColor(Color::Blue);
    }else if (menu2selected==0){
        menu[menu2selected].setColor(Color::White);
        menu2selected=2;

        menu[menu2selected].setColor(Color::Blue);
    }

}

void menu2::movedown(){
    if (menu2selected+1<=2){
        menu[menu2selected].setColor(Color::White);
        menu2selected++;

        menu[menu2selected].setColor(Color::Blue);
    }else if(menu2selected==2){
        menu[menu2selected].setColor(Color::White);
        menu2selected=0;
        menu[menu2selected].setColor(Color::Blue);
        }

}
int menu2::menu2pressed(){
    return menu2selected;

    }
