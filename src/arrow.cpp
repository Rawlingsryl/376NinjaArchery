#include "mathfu/vector.h"
#include "arrow.h"
#include "LEAGUE/physics.h"
#include "LEAGUE/engine.h"
#include <iostream>
#include <string>
#include <box2d/box2d.h>


Arrow::Arrow(PhysicsWorld* physics){

	loadImage("/home/fidlerja/Public/images-2/arrow_middle.png");

	// Need a body definition before we can make a body
	bodyDef = new b2BodyDef();
	bodyDef->type = b2_dynamicBody;
	bodyDef->position.Set(-1,.75); //arrow starts having spawned offscreen
	// Physics engine makes the body for us and returns a pointer to it
	body = physics->addBody(bodyDef);
	// Need a shape
	b2PolygonShape arrowShape;
	//set as box takes half the width and half the height as it's parameters.
	//since it's 36x12 pixels, we divide by 100 like always and then by 2
	//to get the half sizes.
	arrowShape.SetAsBox(.18,.06);
	// Must apply a fixture.  Fixes shape and other properties to it.
	b2FixtureDef arrowFixture;
	arrowFixture.shape = &arrowShape;
	arrowFixture.density = 1.0f;
	arrowFixture.friction = 1.0f;
	arrowFixture.restitution = 0.0f;
	// Make the fixture.
	body->CreateFixture(&arrowFixture);
	elapsedTime = 0;
	numTimes = 0;
	mouseDown = false;
}
Arrow::~Arrow(){
	delete bodyDef;
}

void Arrow::setBody(b2Body* body){
	this->body = body;
}

b2BodyDef* Arrow::getBodyDef(){
	return bodyDef;
}

void Arrow::update(double delta){
    /*
	elapsedTime += delta;
	if(elapsedTime > 2 && numTimes < 1){ // if 2 seconds have passed, and we haven't already moved
		body->SetTransform(b2Vec2(1.25,-1.75),body->GetAngle()); //move arrow to correct position
		std::cout << "moved" << std::endl;//debugging print, can be deleted
		numTimes = 1; //making sure we don't keep moving the arrow

		//fling arrow to right, the force has to be pretty high for it to go anywhere
		b2Vec2 right(20.0f, 0.0f); 
    	b2Vec2 pos = body->GetPosition(); 
    	body->ApplyForce(right, pos, true);
	}
    */

   if(mouseDown){
	elapsedTime += delta; //increase elapsed time if mouse is down
   }

    //Referencing Bird Code from class for loop
    auto events = Engine::getEvents();
    for(auto event = events.begin(); event!=events.end(); ++event){
		
        if(event->type==SDL_MOUSEBUTTONDOWN){
            
			mouseDown = true; //to keep track of when mouse is down
        }
        else if(event->type==SDL_MOUSEBUTTONUP){
            std::cout << "Elapsed Time: " << elapsedTime <<std::endl;
			body->SetTransform(b2Vec2(1.6,-1.75), body->GetAngle());
			// resets velocity before we apply next force so the arrow doesn't keep velocity from previous shots
			body->SetLinearVelocity(b2Vec2(0,0)); 
			float rightwardForce = 30.0f * elapsedTime; // force determined by elapsed time, 
			//increase 60.0f if you want force to increase more in less time.
			if (rightwardForce > 30.0f){
				rightwardForce = 30.0f; //setting a max force, current max reached after 1 sec of mouseHold
			}
			std::cout << "rightwordForce: " << rightwardForce <<std::endl;
			b2Vec2 right(rightwardForce,0.0f);
                b2Vec2 pos = body->GetPosition();
                body->ApplyForce(right,pos,true);
				mouseDown = false; //mouse is no longer down
                elapsedTime = 0;
        }
    }

	/*
	TODO: figure out mouse events, move arrow to bow and fire it when mouse clicks, 
	look to code above for what that looks like.

	Then, arrow needs to have collision detection, when it collides with a enemy,
	a. move the arrow back offscreen, 
	body->SetTransform(b2Vec2(-1,.75),body->GetAngle()); (I think this would work)

	b. delete the enemy, or also move the enemy into the abyss offscreen.
	moving it to like (-5, -5) would probably do that.
	It's not best practice but it might be easier to just move it offscreen
	even though we would NOT do that in an official product due to memory/processing waste
	*/
}

void Arrow::draw(SDL_Renderer* renderer){
	SDL_Rect dest;
	b2Vec2 pos = body->GetPosition();
	dest.x = pos.x * 100;
	dest.y = pos.y * -1 * 100;
	dest.w = rect.w;
	dest.h = rect.h;
	float angle = body->GetAngle();
	//std::cout << dest.x << ", " << dest.y << std::endl;
	int result = SDL_RenderCopyEx(renderer, texture, NULL, &dest, angle, NULL, SDL_FLIP_NONE);
	if(result != 0){
		std::cout << SDL_GetError() << std::endl;
	}
}

void Arrow::BeginContact(b2Contact* contact){
	std::cout << contact->GetFixtureB() << std::endl;
	
	/*
	b2Fixture *check = contact->GetFixtureB();
	int* one = (int*)check->GetUserData();
	if(*one == 1){
		//WORKING ON FINDING HOW TO DESTROY ENEMY!!!!!!
		//DELETE BODY
	}
	*/
}

void Arrow::EndContact(b2Contact* contact){
    
}

b2Body* Arrow::getBody(){
	return body;
}
