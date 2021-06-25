#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream.h>
#include "ex.h"


Ex::Ex(){
     retour=0;
     font.loadFromFile("asset/font.ttf");

    nHS.setFillColor(sf::Color::Yellow);
    nHS.setFont(font);
    nHS.setCharacterSize(75);
    nHS.setPosition(width*0.5,height*0.25);
    nHS.setString("!!!NEW RECCORD!!!");

    scor.setFillColor(sf::Color::Green);
    scor.setFont(font);
    scor.setCharacterSize(50);
    scor.setPosition(width*0.1666,height*0.25);
    scor.setString("SCORE:");

    hS.setFillColor(sf::Color::Green);
    hS.setFont(font);
    hS.setCharacterSize(50);
    hS.setPosition(width*0.135,height*0.75);
    hS.setString("Hight Score:");

    hSN.setFillColor(sf::Color::Green);
    hSN.setFont(font);
    hSN.setCharacterSize(50);
    hSN.setPosition(width*0.26,height*0.75);

    fireT.loadFromFile("asset/shoot.png");
    fireT.setSmooth(true);

    fire.setTexture(fireT);
    fire.setOrigin(fireT.getSize().x*0.5,0);
    //firebox = fire.getGlobalBounds();
    fire.setPosition(0,50);
    fire.setScale(0.01,0.01);

    Buffershoot.loadFromFile("asset/shoot.wav");
    shoot.setBuffer(Buffershoot);

    fondT.loadFromFile("asset/fond.png");
    fond.setTexture(fondT);

    ico.loadFromFile("asset/ico.png");

};

void Ex::fired(){
    sf::Vector2f position = fire.getPosition();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&move==false){
            fire.setPosition(posperso,hperso);
            fire.setScale(1,1);
            move=true;
            shoot.play();
        }
        if(move==true){
            fire.move(0.f,-20.f);
        }
        if(position.y<10||touche==true){
            if(touche==true&&b==1)
                explosion.play();
            touche=false;
            move=false;
            fire.setPosition(0,50);
            fire.setScale(0.01,0.01);
        }


};

void Ex::loop(){
         font.loadFromFile("asset/font.ttf");

    nHS.setFillColor(sf::Color::Yellow);
    nHS.setFont(font);
    nHS.setCharacterSize(75);
    nHS.setPosition(width*0.5,height*0.25);
    nHS.setString("!!!NEW RECCORD!!!");

    scor.setFillColor(sf::Color::Green);
    scor.setFont(font);
    scor.setCharacterSize(50);
    scor.setPosition(width*0.1666,height*0.25);
    scor.setString("SCORE:");

    hS.setFillColor(sf::Color::Green);
    hS.setFont(font);
    hS.setCharacterSize(50);
    hS.setPosition(width*0.135,height*0.75);
    hS.setString("Hight Score:");

    hSN.setFillColor(sf::Color::Green);
    hSN.setFont(font);
    hSN.setCharacterSize(50);
    hSN.setPosition(width*0.26,height*0.75);

    fireT.loadFromFile("asset/shoot.png");
    fireT.setSmooth(true);

    fire.setTexture(fireT);
    fire.setOrigin(fireT.getSize().x*0.5,0);
    fire.setPosition(0,50);
    fire.setScale(0.01,0.01);

    Buffershoot.loadFromFile("asset/shoot.wav");
    shoot.setBuffer(Buffershoot);

    Bufferexplosion.loadFromFile("asset/explosion.wav");
    explosion.setBuffer(Bufferexplosion);

    fondT.loadFromFile("asset/fond.png");
    fond.setTexture(fondT);

    ico.loadFromFile("asset/ico.png");

    SonsM.loadFromFile("asset/sonsMute.png");
    SonsT.loadFromFile("asset/sonsOk.png");

    Sons.setPosition(width*0.75,height*0.75);

    Sons.setTexture(SonsT);
    explosion.setVolume(1);
    shoot.setVolume(1);

    closeT.loadFromFile("asset/close.png");
    close.setTexture(closeT);
    close.setPosition(width*0.75,height*0.125);
}

void Ex::sound(){
    if(sounds==true){
        sounds=false;
        Sons.setTexture(SonsM);
        explosion.setVolume(0);
        shoot.setVolume(0);
    }
    else if(sounds==false){
        sounds=true;
        Sons.setTexture(SonsT);
        explosion.setVolume(1);
        shoot.setVolume(1);
    }

}
