#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream.h>
#include <time.h>
#include "meteore.h"
#include "perso.h"
#include "ex.h"

    sf::Texture meteoreT;
Meteore::Meteore(){

    meteoreT.loadFromFile("asset/meteore.png");
    meteoreT.setSmooth(true);
    meteores.setTexture(meteoreT);
    b=rand()%5;
    if(b==1)
        meteores.setColor(sf::Color(0,0 , 255));
    else
        meteores.setColor(sf::Color(255, 0, 0));


}
int  Meteore::pos(int dep){

    if(g==true){
        point=0;
        xTemp=1+rand()%width;
            xPos=xTemp;
        meteores.setPosition(sf::Vector2f(xPos, 0));
        }
    if(a==true){
        yPos=5+rand()%15;
        multi=(100+rand()%145)/100;
        Ex Ex;
        meteores.setPosition(sf::Vector2f(xPos, 0));
    }
    a=false;
    g=false;
    xPos=xTemp;
    yPos=yPos+dep*multi;
    meteores.move(0.,dep*multi);
        if(b==1)
            meteores.setColor(sf::Color(0, 0, 255));
        else
            meteores.setColor(sf::Color(255, 0, 0));
        if(yPos >= height){
            yPos=0;
            xTemp=1+rand()%width;
                b=rand()%5;
                 point=point+1;
                 a=true;

        }
        if (touch==true&&b==1){
            yPos=0;
            xTemp=1+rand()%width;
                b=rand()%5;
                 point=point+10;
                 a=true;
                 touch=false;
                }
    return 0;
}
