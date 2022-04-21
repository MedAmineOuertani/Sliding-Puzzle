#ifndef SQUARE_H
#define SQUARE_H
#include <SFML/Graphics.hpp>
#include <string>

using  namespace sf;
using namespace std;

class square
{
    public:
        square();
        virtual ~square();
        Sprite body;
        void setsquare(Texture& t, int w, int i , int j);
        void setposition(int w,int i,int j);
        void draw(RenderWindow& window);
        void translate(int,int);

    protected:

    private:

};

#endif // SQUARE_H
