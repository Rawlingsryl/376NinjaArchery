#include "mathfu/vector.h"
#include "enemy.h"
#include "LEAGUE/physics.h"
#include "LEAGUE/engine.h"
#include <iostream>
#include <string>
#include <box2d/box2d.h>
#include <random>

Enemy::Enemy(PhysicsWorld* physics, int spawnTime, int spawnPoint){
	this->spawnTime = spawnTime;
	this->spawnPoint = spawnPoint;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distribution(10, 12);
	animation = 0;
	

	// Generate a random number between 0 and RAND_MAX
	loadImage("/home/fidlerja/Public/images-2/Erun1.png");
	// Need a body definition before we can make a body
	bodyDef = new b2BodyDef();
	bodyDef->type = b2_dynamicBody;
	bodyDef->position.Set(spawnPoint,.5);
	// Physics engine makes the body for us and returns a pointer to it
	body = physics->addBody(bodyDef);
	// Need a shape
	b2PolygonShape enemyShape;
	enemyShape.SetAsBox(.16, .16);
	// Must apply a fixture.  Fixes shape and other properties to it.
	b2FixtureDef enemyFixture;
	enemyFixture.shape = &enemyShape;
	enemyFixture.density = 1.0f;
	enemyFixture.friction = 0.0f;
	enemyFixture.restitution = 0.1f;
	// Make the fixture.
	body->CreateFixture(&enemyFixture);
}

Enemy::~Enemy(){
	delete bodyDef;
}

void Enemy::setBody(b2Body* body){
	this->body = body;
}

b2BodyDef* Enemy::getBodyDef(){
	return bodyDef;
}

void Enemy::update(double delta){
	timeElapsed += delta;
    framesSinceLastAnimation += 1;
	//handles the running animation
    if(framesSinceLastAnimation > 10){
		if(animation%6 == 0){
			loadImage("/home/fidlerja/Public/images-2/Erun1.png");
		}
		if(animation%6 == 1){
			loadImage("/home/fidlerja/Public/images-2/Erun2.png");
		}
		if(animation%6 == 2){
			loadImage("/home/fidlerja/Public/images-2/Erun3.png");
		}
		if(animation%6 == 3){
			loadImage("/home/fidlerja/Public/images-2/Erun4.png");
		}
		if(animation%6 == 4){
			loadImage("/home/fidlerja/Public/images-2/Erun5.png");
		}
		if(animation%6 == 5){
			loadImage("/home/fidlerja/Public/images-2/Erun6.png");
		}
		animation += 1;
		framesSinceLastAnimation = 0;
	}

	//std::cout << body->GetPosition().x << ", " << body->GetPosition().y << std::endl;
	//makes them run left, only applies the force for 3 seconds (change spawnTime + X to make it go X seconds)
	if (timeElapsed > spawnTime && timeElapsed < spawnTime + 3){
		b2Vec2 left(-0.0001f, 0.0f);
    	b2Vec2 pos = body->GetPosition();
    	body->ApplyLinearImpulse(left, pos, true);
	}
    
}

void Enemy::draw(SDL_Renderer* renderer){
	SDL_Rect dest;
	b2Vec2 pos = body->GetPosition();
	dest.x = pos.x * 100;
	dest.y = pos.y * -1 * 100 -20; // added a -20 here to make the image level with the bridge.
	//the shape is level with the bridge, but due to the image having transparent space around the whole ninja
	//if the shape is the same size as the ninja itself and not the whole image, it prints the ninja below/inside the bridge.
	//this is solved by just printing the picutre an arbitrary number of pixels up. This, in theory
	//makes the shape (hitbox) roughly the same size as the ninja, might have to toy around a bit with the size yet.
	//cannot do that without an arrow to shoot at it.
	dest.w = rect.w;
	dest.h = rect.h;
	float angle = body->GetAngle();
	//std::cout << dest.x << ", " << dest.y << std::endl;
	int result = SDL_RenderCopyEx(renderer, texture, NULL, &dest, angle, NULL, SDL_FLIP_HORIZONTAL);
	if(result != 0){
		std::cout << SDL_GetError() << std::endl;
	}
}

void Enemy::BeginContact(b2Contact* contact){
    std::cout << contact->GetFixtureB() << std::endl;
}

void Enemy::EndContact(b2Contact* contact){
    
}

b2Body* Enemy::getBody(){
	return body;
}
