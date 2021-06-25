#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "meteore.h"
#include "perso.h"
#include "ex.h"


    sf::RenderWindow window;
    sf::Event event;
    sf::Text score;
    sf::String stringt;
    sf::Text start;
    sf::Texture fond;
    sf::Time times;

    FILE* hightScore;
 Ex Ex;

void setup();
void run();

int  main(){
    hightScore=fopen("asset/Hightscore.hs","ab");
    fclose(hightScore);
    hightScore=fopen("asset/Hightscore.hs","rb");
    char hS[100]="";
    fgets(hS,100,hightScore);
    setup();
            Perso perso;
        while (window.isOpen()){
                 sf::Vector2i mousePos = sf::Mouse::getPosition( window );
                     sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );
            while (window.pollEvent(event)){

                    if (event.type == sf::Event::Closed||(Ex.close.getGlobalBounds().contains(mousePosF)&&sf::Mouse::isButtonPressed(sf::Mouse::Left))){
                    window.close();
                }}
                window.clear(sf::Color::Black);

                        window.draw(Ex.fond);
                      window.draw(start);
                      window.draw(Ex.Sons);
                      window.draw(Ex.close);

                        if( Ex.Sons.getGlobalBounds().contains( mousePosF )&&sf::Mouse::isButtonPressed(sf::Mouse::Left) )
                            Ex.sound();

                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                                run();
                                fgets(hS,100,hightScore);
                            }

                            std::string strc= std::to_string(Ex.retour);
                            score.setString(strc);
                            score.setPosition(window.getSize().x*0.25,window.getSize().y*0.25);
                            Ex.hSN.setString(hS);
                            window.draw(start);
                            window.draw(score);
                            window.draw(Ex.scor);
                            window.draw(Ex.hS);
                            window.draw(Ex.hSN);
                           if (strc>=hS){
                                window.draw(Ex.nHS);
                                fclose(hightScore);
                                 hightScore=fopen("asset/Hightscore.hs","wb");
                                 fprintf(hightScore,"%d",Ex.retour);

                                 fclose(hightScore);
                                 hightScore=fopen("asset/Hightscore.hs","rb");

                           }
                window.display();
        }
    fclose(hightScore);
    return 0;
}
void setup(){

        window.create(sf::VideoMode(),"space asteroid",sf::Style::Fullscreen);
      window.setFramerateLimit(30);
      window.setIcon(200,200,Ex.ico.getPixelsPtr());
      fond.loadFromFile("asset/fond.png");
      score.setCharacterSize(50);
      score.setOrigin(0,0);
      score.setFillColor(sf::Color::Green);
      score.setFont(Ex.font);

    start.setCharacterSize(75);
    start.setFillColor(sf::Color::Blue);
    start.setOrigin(318.f,25.f);
    start.setFont(Ex.font);
    start.setString("press enter to start");
    start.setPosition(window.getSize().x*0.5,window.getSize().y*0.5);


    Ex.height=window.getSize().y;


    Ex.width=window.getSize().x;
    Ex.loop();
}
void run(){
    Ex.fire.setPosition(0,50);
    Ex.fire.setScale(0.01,0.01);
     Perso perso;
    Meteore a ;
    Meteore b ;
    Meteore c ;
    Meteore d ;
    Meteore e ;
    Meteore f ;

    a.height=window.getSize().y;
    b.height=window.getSize().y;
    c.height=window.getSize().y;
    d.height=window.getSize().y;
    e.height=window.getSize().y;
    f.height=window.getSize().y;
    perso.height=window.getSize().y;

    a.width=window.getSize().x;
    b.width=window.getSize().x;
    c.width=window.getSize().x;
    d.width=window.getSize().x;
    e.width=window.getSize().x;
    f.width=window.getSize().x;
    perso.width=window.getSize().x;

    float dep =2;
    score.setString("0");
    score.setPosition(10,100);
    perso.deplacement();
    Ex.hperso = perso.demieh;
    while (window.isOpen()){
            perso.point=0;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
                }
        window.clear(sf::Color::Black);
        window.draw(Ex.fond);

        window.draw(a.meteores);
        window.draw(b.meteores);
        window.draw(c.meteores);
        window.draw(d.meteores);
        window.draw(e.meteores);
        window.draw(f.meteores);

        window.draw(Ex.fire);
        window.draw(perso.perso);

                a.pos(dep);
        b.pos(dep);
        c.pos(dep);
        d.pos(dep);
        e.pos(dep);
        f.pos(dep);
        dep=dep+0.005 ;
        perso.deplacement();
        Ex.fired();
        Ex.posperso=perso.perso.getPosition().x;
        Ex.retour=a.point+b.point+c.point+d.point+e.point+f.point;
        std::string tex= std::to_string(Ex.retour);
        score.setString(tex);
        window.draw(score);
        window.display();
        if (a.meteores.getGlobalBounds().intersects(perso.perso.getGlobalBounds())) {

            return ;}
                else if (b.meteores.getGlobalBounds().intersects(perso.perso.getGlobalBounds())){
            Ex.retour=a.point+b.point+c.point+d.point+e.point+f.point;
            Ex.explosion.play();
            return ;}
                    else if (c.meteores.getGlobalBounds().intersects(perso.perso.getGlobalBounds())){
            Ex.retour =a.point+b.point+c.point+d.point+e.point+f.point;
            Ex.explosion.play();
            return ;}
                    else if (d.meteores.getGlobalBounds().intersects(perso.perso.getGlobalBounds())){
            Ex.retour =a.point+b.point+c.point+d.point+e.point+f.point;
            Ex.explosion.play();
            return ;}
                    else if (e.meteores.getGlobalBounds().intersects(perso.perso.getGlobalBounds())){
            Ex.retour =a.point+b.point+c.point+d.point+e.point+f.point;
            Ex.explosion.play();
            return ;}
                    if (f.meteores.getGlobalBounds().intersects(perso.perso.getGlobalBounds())){
            Ex.retour =a.point+b.point+c.point+d.point+e.point+f.point;
            Ex.explosion.play();
            return ;
                }
                    if (a.meteores.getGlobalBounds().intersects(Ex.fire.getGlobalBounds())){
                        Ex.b=a.b;
                        Ex.touche=true;
                        a.touch=true;
                    }
                    if (b.meteores.getGlobalBounds().intersects(Ex.fire.getGlobalBounds())){
                        Ex.b=b.b;
                        Ex.touche=true;
                        b.touch=true;
                    }
                    if (c.meteores.getGlobalBounds().intersects(Ex.fire.getGlobalBounds())){
                        Ex.b=c.b;
                        Ex.touche=true;
                        c.touch=true;
                    }
                    if (d.meteores.getGlobalBounds().intersects(Ex.fire.getGlobalBounds())){
                        Ex.b=d.b;
                        Ex.touche=true;
                        d.touch=true;
                    }
                    if (e.meteores.getGlobalBounds().intersects(Ex.fire.getGlobalBounds())){
                        Ex.b=e.b;
                        Ex.touche=true;
                        e.touch=true;
                    }
                    if (f.meteores.getGlobalBounds().intersects(Ex.fire.getGlobalBounds())){
                        Ex.b=f.b;
                        Ex.touche=true;
                        f.touch=true;
                    }

        }
    }
