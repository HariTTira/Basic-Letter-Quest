#include "GameObject.hpp"

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
GameObject* mainMenubackground;
GameObject* background;
GameObject* playerheart;
GameObject* enemyheart;
GameObject* Gameover;

//GameObject constructer
GameObject::GameObject(const char* texturesheet, int x,int y,int width,int height,int srcw,int srch):objTexture(TextureManager::LoadTexture(texturesheet)),xpos(x),ypos(y),objwidth(width),objheight(height),srcwidth(srcw),srcheight(srch)
{
};

//GameObject deconstructer
GameObject::~GameObject(){};

//GameObject function to update
void GameObject::Update(bool bg)
{   
    if (bg == true){
    srcRect.h = 600;
    srcRect.w = 800;
    srcRect.x = 0;
    srcRect.y = 0;
    }
    srcRect.h = 2000;
    srcRect.w = 2000;
    srcRect.x = 0;
    srcRect.y = 0;
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = objwidth;
    destRect.h = objheight;
}

//GameObject function to render
void GameObject::Render(bool bg)
{   
    if (bg == true)
    {
        SDL_RenderCopy(Game::renderer, objTexture, NULL, NULL);
    }
    else
    { 
    SDL_RenderCopy(Game::renderer,objTexture,&srcRect,&destRect);
    }
}