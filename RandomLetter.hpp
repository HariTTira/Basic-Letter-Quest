#pragma once

#include "Game.hpp"
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

//random variable
std::random_device rd;
std::mt19937 gen(static_cast<unsigned int>(std::time(0)));
int random_vowel_order = 0;

// ----------------------------------------------------------------------------------------------------------------------------------------------
//Randomletter Class
class RandomLetter{
    public:
        RandomLetter(std::string& filename); //filename
        ~RandomLetter();
        void randomlt(std::vector<std::string>& vector); //check if vec is completed(16 member) ,if not then add it up
        void readfile(std::string& filename);

        //check
        std::vector<std::string> getdict();
        
    private:
        std::vector<std::string> dictionary;

};