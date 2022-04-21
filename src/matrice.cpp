#include "matrice.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace sf;
using namespace std;

matrice::matrice(int n ,string imgs[3] ,string b ,RenderWindow& window)
{
    taille=n;
    int y=rand()%3;
    e.loadFromFile(b);
    k=(int)pow(taille,0.5);
    if (!img.loadFromFile(imgs[y]))
        cout<<"error loading the image"<<endl;
    width=window.getSize().x;
    height=window.getSize().y;
    w=160;
    this->set_square();
}

matrice::~matrice()
{

}
void matrice::draw(RenderWindow& window){
    for (int i =0;i<taille;i++){
        T[i].draw(window);}
}
void matrice::random_display(){
    int h=(int)pow(taille,0.5);
    int l[h];
    int c[h];

    int i =0;
    while (i<h){
        int k=rand()%h;
        bool a=true ;
        for (int v=0;v<h;v++){
            if (l[v]==k)
                a=false;
        }
        if (a){
            l[i]=k;
            i++;
        }
    }
    i =0;
    while (i<h){
        int k=rand()%h;
        bool a=true ;
        for (int v=0;v<h;v++){
            if (c[v]==k)
                a=false;
        }
        if (a){
            c[i]=k;
            i++;

        }
    }
    i=0;
    for (int d=0;d<h;d++){
    for (int x=0;x<h;x++){
        T[i].setposition(w,l[d],c[x]);
        i++;
        grid[l[d]+1][c[x]+1]=i ; }
    }

}
void matrice::mousepressed(RenderWindow& window){
                     int k=(int)pow(taille,0.5);
                     Vector2i pos = Mouse::getPosition(window);
                     int x = (pos.x-300)/w + 1;
                     int y = pos.y/w + 1;
                    if (x>0&&x<5){

                     int dx=0;
                     int dy=0;

                     if (grid[x+1][y]==16) {dx=1; dy=0;};
                     if (grid[x][y+1]==16) {dx=0; dy=1;};
                     if (grid[x][y-1]==16) {dx=0; dy=-1;};
                     if (grid[x-1][y]==16) {dx=-1;dy=0;};

                     int l = grid[x][y];
                     grid[x][y] = 16;
                     grid[x+dx][y+dy] = l;
                     l--;

                     //animation
                     T[15].translate(-dx*w,-dy*w);
                     float speed=4;

                     for (int i=0;i<w;i+=speed)
                     {T[l].translate(speed*dx,speed*dy);
                        T[15].draw(window);
                        T[l].draw(window);

                      window.display(); }
                    }


                  }
void matrice::set_square(){
 int i =0;
    for (int h =0;(h<k);h++){
        for(int j=0;(j<k);j++){
                T[i].setsquare(img,w,h,j);
                T[i].setposition(w,h,j);


                i++;
        }

    }
    T[15].setsquare(e,w,4,4);
    T[15].body.setColor(Color(0,0,0,128));
    T[15].setposition(w,3,3);


    for (int h=0;h<6;h++)
        for(int j=0;j<6;j++)
            grid[h][j]=0;
}
