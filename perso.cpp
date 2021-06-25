#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream.h>

#include "perso.h"
     sf::Texture persoT;
Perso::Perso(){
    point =0;
    persoT.loadFromFile("asset/perso.png");
    persoT.setSmooth(true);
    demie=persoT.getSize().x;
    demieh=persoT.getSize().y;
    demie=demie*0.5;

    perso.setTexture(persoT);
    perso.setOrigin(demie,0);


}

void Perso::deplacement(){
    if(a==true){
        demieh=height-demieh;
        perso.setPosition(sf::Vector2f(width*0.5, demieh));
    }
    a=false;
            sf::Vector2f position = perso.getPosition();
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Q)||sf::Keyboard::isKeyPressed(sf::Keyboard::Left))&&position.x>0)
        {

            perso.move(-10.f, 0.f);
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)||sf::Keyboard::isKeyPressed(sf::Keyboard::Right))&&position.x<1920)
        {

            perso.move(10.f, 0.f);
        }
}
