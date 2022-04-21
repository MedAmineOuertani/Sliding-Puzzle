#include <SFML/Graphics.hpp>
#include <iostream>
#include "menu1.h"
#include "menu2.h"
#include "mainmenu.h"
#include "matrice.h"
#include "square.h"

using namespace sf;
using namespace std;
void run(){
    RenderWindow mn(VideoMode(640,640),"Main Menu",Style::Close);
    mainmenu mnn(mn.getSize().x,mn.getSize().y);
    RectangleShape bg(Vector2f(640,640));
    Texture h;
    h.loadFromFile("images/Background.png");
    bg.setTexture(&h);
    while(mn.isOpen()){
    Event evnt;
    while(mn.pollEvent(evnt)){
        if (evnt.type==Event::Closed){
            mn.close();
            break;
        }
        if(evnt.type==Event::KeyReleased){

            if(evnt.key.code==Keyboard::Up){
                mnn.moveup();
                break;

            }else if(evnt.key.code==Keyboard::Down){
                mnn.movedown();
                break;

            }else if (evnt.key.code==Keyboard::Return){

                int x= mnn.mainmenupressed();
                if(x==0){
                RenderWindow window(VideoMode(1240,640),"Play !",Style::Close);
                window.setFramerateLimit(70);
                menu2 menu_2(1100,320);
                Sprite t;
                Texture k;
                k.loadFromFile("images/fond.jpg");
                t.setTexture(k);
                t.setTextureRect(IntRect(0,0,1240,640));
                string random_image[3]={"images/einshtein.jpg","images/2.png","images/3.png"};
                matrice m(16,random_image,"/home/amine/Desktop/finalproject/images/transparent.png",window);
                m.random_display();
                while(window.isOpen()){
                    Event ev;
                    while(window.pollEvent(ev)){
                        if (ev.type==Event::Closed){
                        window.close();
                        break;
                        }else if(ev.type==Event::MouseButtonPressed){
                        if(ev.key.code==Mouse::Left){
                            m.mousepressed(window);
                        }
                        }else if(ev.type==Event::KeyReleased){

                                if(ev.key.code==Keyboard::Up){
                                    menu_2.moveup();
                                    break;

                                }else if(ev.key.code==Keyboard::Down){
                                    menu_2.movedown();
                                    break;

                                }else if (ev.key.code==Keyboard::Return){

                                    int x= menu_2.menu2pressed();
                                    if(x==0){

                                        m.set_square();
                                        m.random_display();

                                    }else if (x==1){
                                        m.set_square();
                                    }else{
                                        window.close();
                                        break;
                                    }
                                }

                    }
                    }


                    window.clear(Color::White);
                    window.draw(t);
                    menu_2.draw(window);
                    m.draw(window);

                    window.display();
                }

                    }else if(x==1){

                 mn.close();
                 break;
                 }



          }

        }


    }
        mn.clear();
        mn.draw(bg);
        mnn.Draw(mn);

        mn.display();

    }
}

int main()
{
    run();

}
