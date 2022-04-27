#ifndef MATRICE_H
#define MATRICE_H
#include <SFML/Graphics.hpp>
#include <string>
#include "square.h"
#define N 16

using  namespace sf;
using namespace std;
class matrice
{
    public:
        matrice(int n ,string imgs[3] ,string b ,RenderWindow& window);
        virtual ~matrice();
        square T[N];
        void draw(RenderWindow& window);
        void random_display();
        int w;
        Texture img,e;
        int k ;
        int taille;
        int width;
        int height;
        int grid[6][6];
        void mousepressed(RenderWindow& window);
        void set_square();
        bool check_win(Window& window);


    protected:

    private:




};

#endif // MATRICE_H
