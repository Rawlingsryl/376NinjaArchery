#include "mathfu/vector.h"
#include "arrow.h"
#include "LEAGUE/physics.h"
#include "LEAGUE/engine.h"
#include <iostream>
#include <string>
#include <box2d/box2d.h>


Arrow::Arrow(PhysicsWorld* physics){

	// Generate a random number between 0 and RAND_MAX
	loadImage("/home/fidlerja/Public/images-2/arrow_middle.png");
	// Need a body definition before we can make a body
	bodyDef = new b2BodyDef();
	bodyDef->type = b2_dynamicBody;
	bodyDef->position.Set(1.25,.75);
	// Physics engine makes the body for us and returns a pointer to it
	body = physics->addBody(bodyDef);
	// Need a shape
	b2PolygonShape arrowShape;
	arrowShape.SetAsBox(.01,.1);
	// Must apply a fixture.  Fixes shape and other properties to it.
	b2FixtureDef arrowFixture;
	arrowFixture.shape = &arrowShape;
	arrowFixture.density = 1.0f;
	arrowFixture.friction = 0.3f;
	arrowFixture.restitution = 0.3f;
	// Make the fixture.
	body->CreateFixture(&arrowFixture);
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
}

void Arrow::EndContact(b2Contact* contact){
    
}

b2Body* Arrow::getBody(){
	return body;
}
