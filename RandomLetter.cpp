#include "RandomLetter.hpp"

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

RandomLetter::RandomLetter(std::string& filename){readfile(filename);}//RandomLetter contructer
RandomLetter::~RandomLetter(){};//RandomLetter decontructer

std::vector<std::string> RandomLetter::getdict(){return dictionary;}//Fuction to get the vecter of the d

//Function use to get 16 random letter
void RandomLetter::randomlt(std::vector<std::string>& vector){
    std::uniform_int_distribution<> dis('a', 'z');
    std::vector<char> vowel{'a','e','i','o','u'};

    int vowel_counter = 0;
    for (auto& letter:vector){
        if(letter == "a" ||letter == "e"||letter == "i"||letter == "o"||letter == "u"){
            vowel_counter++;
        }
    }


    for (auto& letter : vector) {
        if (letter.empty()) {
            char randomChar = static_cast<char>(dis(gen));
            if ((vowel_counter<2)){letter.push_back(vowel[random_vowel_order%5]);
                random_vowel_order++;
                vowel_counter++;}
            else{letter.push_back(randomChar);}
        }
    }
};

//Function to read dictionary.txt
void RandomLetter::readfile(std::string& filename){
std::vector<std::string> dict;
  std::fstream textfile(filename);
    if (textfile.is_open()){
      std::string line;
      while(getline(textfile,line)){
        if (line.size() <= MAX_LETTER && line.size() >= MIN_LETTER){
        dict.push_back(line);
        }
      }
    }
  dictionary = dict;
}