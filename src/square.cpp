#include "square.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string>

using  namespace sf;
using namespace std;

square::square()
{
    //ctor
}

square::~square()
{
    //dtor
}
void square::setsquare(Texture& t, int w, int i , int j){
    body.setTexture(t);
    body.setTextureRect(IntRect(i*w,j*w,w,w));

}
void square::setposition(int w,int i,int j ){
    body.setPosition((float)(i*w)+300,(float)(j*w));
}
void square::draw(RenderWindow& window ){
    window.draw(body);
}
void square::translate(int i,int j){
    body.move(i,j);

}
