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

        void draw(RenderWindow& window);
        void random_display();

        void mousepressed(RenderWindow& window);
        void set_square();
        bool check_win(Window& window);
        Texture img,e;


    protected:

    private:
        int w;

        int k ;
        int taille;
        int width;
        int height;
        int grid[6][6];
        square T[N];




};

#endif // MATRICE_H
