#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "mainmenu.h"
using namespace sf;
using namespace std;

mainmenu::mainmenu(float width,float height)
{
 if(!font.loadFromFile("University.otf")){
    cout<<"pas de font ici"<<endl;

 }
 //play
 mainMenu[0].setColor(Color::Blue);
 mainMenu[0].setString("Play");
 mainMenu[0].setCharacterSize(50);
 mainMenu[0].setPosition(320,420);
 mainMenu[0].setFont(font);
 mainMenu[0].setOrigin(mainMenu[0].getLocalBounds().width/2,mainMenu[0].getLocalBounds().height/2);

 //Exit
 mainMenu[1].setColor(Color::White);
 mainMenu[1].setString("Exit");
 mainMenu[1].setCharacterSize(50);
 mainMenu[1].setPosition(320,520);
 mainMenu[1].setFont(font);
 mainMenu[1].setOrigin(mainMenu[1].getLocalBounds().width/2,mainMenu[1].getLocalBounds().height/2);

 //Mainmenuselected
 mainmenuselected=0;
}

mainmenu::~mainmenu()
{
    //dtor
}

void mainmenu::Draw(RenderWindow& window){
    for(int i=0;i<2;i++){
        window.draw(mainMenu[i]);
    }
}

void mainmenu::moveup(){
    if (mainmenuselected-1>=0){
        mainMenu[mainmenuselected].setColor(Color::White);
        mainmenuselected--;
        mainMenu[mainmenuselected].setColor(Color::Blue);
    }else if (mainmenuselected==0){
        mainMenu[mainmenuselected].setColor(Color::White);
        mainmenuselected=1;

        mainMenu[mainmenuselected].setColor(Color::Blue);
    }

}

void mainmenu::movedown(){
    if (mainmenuselected+1<=1){
        mainMenu[mainmenuselected].setColor(Color::White);
        mainmenuselected++;

        mainMenu[mainmenuselected].setColor(Color::Blue);
    }else if(mainmenuselected==1){
        mainMenu[mainmenuselected].setColor(Color::White);
        mainmenuselected=0;
        mainMenu[mainmenuselected].setColor(Color::Blue);
        }

}
int mainmenu::mainmenupressed(){
    return mainmenuselected;

    }
