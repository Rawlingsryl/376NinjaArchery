#include "mathfu/vector.h"
#include "arrow.h"
#include "LEAGUE/physics.h"
#include "LEAGUE/engine.h"
#include <iostream>
#include <string>
#include <box2d/box2d.h>

Arrow::Arrow(PhysicsWorld* physics){

	loadImage("/home/fidlerja/Public/images-2/arrow_middle.png");
	
    double x = 1.3;
    double y = 1.3;

    // Need a body definition before we can make a body
    // Physics engine makes the body for us and returns a pointer to it
	b2BodyDef arrowBodyDef;
	arrowBodyDef.type = b2_dynamicBody;
	arrowBodyDef.position.Set(x,y);
	b2Body* arrowBody = physics->addBody(&arrowBodyDef);
	
    // Need a shape
	b2PolygonShape arrowShape;
	arrowShape.SetAsBox(.5,.5); //NOT SURE WHAT THESE VALUES NEED TO BE
	
    // Must apply a fixture.  Fixes shape and other properties to it.
	b2FixtureDef arrowFixture;
	arrowFixture.shape = &arrowShape;
	arrowFixture.density = 1.0f;
	arrowFixture.friction = 0.3f;
	arrowFixture.restitution = 0.3f;
	
    // Make the fixture.
	arrowBody->CreateFixture(&arrowFixture);
	
    //Need an anchor(static body) to hold a dynamic body in place
    b2BodyDef anchorBodyDef;
    anchorBodyDef.type = b2_staticBody;
    anchorBodyDef.position.Set(x,y);
    b2Body* anchorBody = physics->addBody(&anchorBodyDef);

    //Joint used for connecting arrow and anchor to hold it in place
    b2RevoluteJointDef* revoluteJointDef = new b2RevoluteJointDef();
    revoluteJointDef->bodyA = anchorBody;
    revoluteJointDef->bodyB = arrowBody;
    revoluteJointDef->collideConnected = false;
    revoluteJointDef->localAnchorA.Set(0.0f,0.0f);
    revoluteJointDef->localAnchorB.Set(0.0f,0.0f);
    
    b2JointDef* jointDef = revoluteJointDef;
    
    physics->addJoint(jointDef);
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
    }else if (angle > targetAngle) {
		angle -= angleChange;
		if (angle < targetAngle) {
		    angle = targetAngle;
		}
	}
}

void Arrow::draw(SDL_Renderer* renderer){
	SDL_Rect dest;
	b2Vec2 pos = body->GetPosition();
	dest.x = pos.x * 100;
	dest.y = pos.y * -1 * 100;
	dest.w = rect.w * 1.1;
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
