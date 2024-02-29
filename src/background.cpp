#include "background.h"
#include "LEAGUE/engine.h"
#include <iostream>

Background::Background(){
	x = 0;
	y = 0;
	loadImage("/home/fidlerja/Public/images-2/Background.png");
}

Background::~Background(){

}

void Background::update(double delta){
}

void Background::draw(SDL_Renderer* renderer){
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = 1024;
    dest.h = 768;
	
    int result = SDL_RenderCopy(renderer, texture, NULL, &dest);
	if(result != 0){
		std::cout << SDL_GetError() << std::endl;
	}
}
