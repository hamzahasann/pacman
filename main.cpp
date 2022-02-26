#include<bits/stdc++.h>
#include<chrono>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
using namespace std;
using namespace sf;
#include "constants.hpp"
#include "map.hpp"
#include "player.hpp"
#include "ghost.hpp"
#include "red.hpp"
#include "pink.hpp"
#include "blue.hpp"
#include "orange.hpp"
int main(){
    Player player(CELLSIZE+PLAYERSIZE,CELLSIZE+PLAYERSIZE);
    Map map;
    Red red(CELLSIZE+GHOSTSIZE,6*CELLSIZE+GHOSTSIZE);
    Pink pink(CELLSIZE+GHOSTSIZE,6*CELLSIZE+GHOSTSIZE);
    Blue blue(CELLSIZE+GHOSTSIZE,6*CELLSIZE+GHOSTSIZE);
    Orange orange(CELLSIZE+GHOSTSIZE,6*CELLSIZE+GHOSTSIZE);
    player.setMap(&map);
    red.setMap(&map);
    red.setPlayer(&player);
    red.loadTexture();
    pink.setMap(&map);
    pink.setPlayer(&player);
    pink.loadTexture();
    blue.setMap(&map);
    blue.setPlayer(&player);
    blue.setRed(&red);
    blue.loadTexture();
    orange.setMap(&map);
    orange.setPlayer(&player);
    orange.loadTexture();
    // SoundBuffer soundbuffer;
    Music music;
    if(!music.openFromFile("../assets/background.wav")){
        cout<<"Cant load background music\n";
    }
    music.setLoop(true);
    music.play();
    RenderWindow window(VideoMode(WIDTH,HEIGHT),"main",Style::Default);
    window.setFramerateLimit(FRAMERATE);
    window.setKeyRepeatEnabled(false);
    bool left=0,right=0,up=0,down=0;
    auto start=chrono::high_resolution_clock::now();
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)){
                window.close();
            }
        }if(Keyboard::isKeyPressed(Keyboard::Left)){
            start=chrono::high_resolution_clock::now();
            left=1;
            right=up=down=0;
        }else if(Keyboard::isKeyPressed(Keyboard::Right)){
            start=chrono::high_resolution_clock::now();
            right=1;
            left=up=down=0;
        }else if(Keyboard::isKeyPressed(Keyboard::Up)){
            start=chrono::high_resolution_clock::now();
            up=1;
            left=right=down=0;
        }else if(Keyboard::isKeyPressed(Keyboard::Down)){
            start=chrono::high_resolution_clock::now();
            down=1;
            left=right=up=0;
        }if(left==1){
            player.turn(LEFT);
        }else if(right==1){
            player.turn(RIGHT);
        }else if(up==1){
            player.turn(UP);
        }else if(down==1){
            player.turn(DOWN);
        }
        auto stop = chrono::high_resolution_clock::now();
        auto duration=chrono::duration_cast<chrono::milliseconds>(stop-start);
        if(duration.count()>INPUTLAG){
            left=right=up=down=0;
        }
        player.move();
        red.update();
        red.move();
        pink.update();
        pink.move();
        blue.update();
        blue.move();
        orange.update();
        orange.move();
        window.clear(Color::Black);
        map.draw(window);
        player.draw(window);
        red.draw(window);
        pink.draw(window);
        blue.draw(window);
        orange.draw(window);
        window.display();
    }
}
