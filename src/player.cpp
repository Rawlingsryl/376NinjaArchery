#include "player.h"
#include "LEAGUE/engine.h"
#include "mathfu/vector.h"
#include "mathfu/glsl_mappings.h"
#include <iostream>

Player::Player(){
	x = 135;
	y = 160;
    elapsed = 0.0f;
	loadImage("/home/fidlerja/Public/images-2/player-idle.png");
}

Player::~Player(){

}

void Player::update(double delta){
            
}

void Player::draw(SDL_Renderer* renderer){
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = rect.w *1.25;
	dest.h = rect.h * 1.25;
	int result = SDL_RenderCopy(renderer, texture, NULL, &dest);
	if(result != 0){
		std::cout << SDL_GetError() << std::endl;
	}
}
