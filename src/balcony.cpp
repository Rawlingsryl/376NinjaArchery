#include "balcony.h"
#include "LEAGUE/engine.h"
#include <iostream>

Balcony::Balcony(){
    x = 500;
    y = 300;
    loadImage("/home/fidlerja/Public/images-2/balcony.png");
}

Balcony::Balcony(int x_coord, int y_coord){
    x = x_coord;
    y = y_coord;
    loadImage("/home/fidlerja/Public/images-2/balcony.png");
}

Balcony::~Balcony(){

}

void Balcony::update(double delta){

}

void Balcony::draw(SDL_Renderer* renderer){
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = rect.w;
    dest.h = rect.h;

    int result = SDL_RenderCopy(renderer, texture, NULL, &dest);
    if(result != 0){
        std::cout << SDL_GetError() << std::endl;
    }
}
