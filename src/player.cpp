#include "player.h"
#include "LEAGUE/engine.h"
#include "mathfu/vector.h"
#include "mathfu/glsl_mappings.h"
#include <SDL2/SDL.h>
#include <iostream>


Player::Player(){
	x = 135;
	y = 155;
    elapsed = 0.0f;
    center = 192;
    angle = 0;
    loadImage("/home/fidlerja/Public/images-2/player-idle.png");
}

Player::~Player(){

}

void Player::update(double delta){
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    
    // Calculate target angle based on mouse position
    double targetAngle = 0.0;
    if (mouseY < center) {
        targetAngle = -20.0; // Rotate left
    } else if (mouseY > center) {
        targetAngle = 30.0; // Rotate right
    }

    // This section uses delta time in order to smoothly rotate the player image
    double rotationSpeed = 65.0; // Adjust as needed for desired rotation speed
    double angleChange = rotationSpeed * delta; //computes the rotation per frame to rotate with consistent speed over frams
    if (angle < targetAngle) {  //Checks if currect angle less than target
        angle += angleChange;   //If lower then adds average change per frame
        if (angle > targetAngle) {  //if Angle still over since rotation speed couldnt get exactlly
            angle = targetAngle;    //then sets to target, but is already close
        }
    } else if (angle > targetAngle) {
        angle -= angleChange;
        if (angle < targetAngle) {
            angle = targetAngle;
        }
    }
    
    // Load appropriate texture based on angle
    auto events = Engine::getEvents();
    for(auto event = events.begin(); event!=events.end(); ++event){
        if(event->type == SDL_MOUSEBUTTONDOWN){
            loadImage("/home/fidlerja/Public/images-2/player-firing.png");
        }
        else if(event->type == SDL_MOUSEBUTTONUP){
            loadImage("/home/fidlerja/Public/images-2/player-idle.png");
        }
    }

}


void Player::draw(SDL_Renderer* renderer){
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = rect.w * 1.25;
	dest.h = rect.h * 1.25;
	
    SDL_Point pivotPoint = {(int)(rect.w*1.25)/2, (int)(rect.h*1.25*1.25)/2};

    int result = SDL_RenderCopyEx(renderer, texture, NULL, &dest,angle,&pivotPoint, SDL_FLIP_NONE);
	if(result != 0){
		std::cout << SDL_GetError() << std::endl;
	}
}

int Player::getAngle(){
    return angle;
}
