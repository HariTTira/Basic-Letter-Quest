#include "Game.hpp"
#include "Game.cpp"
#include "TextureManager.hpp"
#include "TextureManager.cpp"
#include "GameObject.hpp"
#include "GameObject.cpp"
#include "Player.hpp"
#include "Player.cpp"
#include "RandomLetter.hpp"
#include "RandomLetter.cpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <ctime>
#include <algorithm>
#include <string>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define FPS 60
#define frameDelay 1000/FPS
#define Scale 1.5
#define BUTTON_ROWS 4
#define BUTTON_COLS 4
#define BUTTON_WIDTH 60
#define BUTTON_HEIGHT 50
#define BUTTON_MARGIN 10
#define MAX_LETTER 16
#define MIN_LETTER 3
#define TEXTBOX_HEIGHT BUTTON_HEIGHT
#define TEXTBOX_WIDTH (BUTTON_WIDTH + BUTTON_MARGIN) * BUTTON_COLS
#define TEXTBOX_MARGIN BUTTON_MARGIN * 25
#define FULL_PLAYERHPS 150

//Declare Renderer and Background
//Declare Players
//main
int main(int argc, char* argv[])
{   

    try{
    Game* game = nullptr;
    Uint32 frameStart;
    int frameTime;
    std::string filename = "assets/dictionary.txt";
    RandomLetter randomlet = RandomLetter(filename);
    std::vector<std::string> dict = randomlet.getdict() ;

    std::vector<std::string> vecofranlet;
    for (int i = 0; i != MAX_LETTER;i++){
        vecofranlet.push_back("");
    }
    
    game = new Game();
    
    game->init("Grim", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false,vecofranlet);
    

    while (game->isRunning())
    {   
        frameStart = SDL_GetTicks();
        game->handleEvents();
        
        game->update(vecofranlet,dict);
        game->render();
        randomlet.randomlt(vecofranlet);
        
        frameTime = SDL_GetTicks() -frameStart;
        if(frameDelay > frameTime){
            SDL_Delay(frameDelay-frameTime);
        }
    }

    game->clean();
    delete game;
    }
    catch(const std::bad_alloc& e){
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    }

    return 0;
}
