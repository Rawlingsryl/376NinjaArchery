#include <SDL2/SDL.h>
#include <iostream>
#include <unistd.h>

#include "LEAGUE/common_data_structures.h"
#include "LEAGUE/engine.h"
#include "LEAGUE/physics.h"
#include "background.h"
#include "ball.h"
#include "player.h"
#include "balcony.h"
#include "arrow.h"
#include "enemy.h"

int main(int argc, char** argv){
	int opt;
	while((opt = getopt(argc, argv, "h")) != -1){

	}
	Scene scene;
	Engine* engine = Engine::getInstance();
    PhysicsWorld physics(b2Vec2(0.0, -10.0f));

	b2BodyDef groundDef;
	groundDef.position.Set(0.0f, -4.5f);
	groundDef.type=b2_staticBody;
	b2Body* ground = physics.addBody(&groundDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 1.0f);
	ground->CreateFixture(&groundBox, 1.0f);

	/*
    b2BodyDef leftDef;
	leftDef.position.Set(0.0f, -7.6f);
	leftDef.type=b2_staticBody;
	b2Body* left = physics.addBody(&leftDef);
	b2PolygonShape leftBox;
	leftBox.SetAsBox(1.0f, 50.0f);
	left->CreateFixture(&leftBox, 1.0f);

	b2BodyDef rightDef;
	rightDef.position.Set(10.0f, -7.6f);
	rightDef.type=b2_staticBody;
	b2Body* right = physics.addBody(&rightDef);
	b2PolygonShape rightBox;
	rightBox.SetAsBox(1.0f, 50.0f);
	right->CreateFixture(&rightBox, 1.0f);
    */
	  
    Background b;
    scene.addDrawable(b);

    Player p;
    scene.addDrawable(p);
    scene.addUpdateable(p);

    Balcony bc(135,220);
    scene.addDrawable(bc);
    
    /*
    Ball* ba = new Ball(&physics);
    scene.addDrawable(*ba);
    scene.addUpdateable(*ba);
    physics.getWorld()->SetContactListener(ba);
    */
    
    Arrow* a = new Arrow(&physics);
    scene.addDrawable(*a);
    scene.addUpdateable(*a);
    physics.getWorld()->SetContactListener(a);
    
	Enemy* enemy1 = new Enemy(&physics, 1, 12);
	scene.addDrawable(*enemy1);
    scene.addUpdateable(*enemy1);

	Enemy* enemy2 = new Enemy(&physics, 1, 14);
	scene.addDrawable(*enemy2);
    scene.addUpdateable(*enemy2);

	Enemy* enemy3 = new Enemy(&physics, 1, 16);
	scene.addDrawable(*enemy3);
    scene.addUpdateable(*enemy3);

    scene.addUpdateable(physics);
	engine->core_loop(scene);
	engine->shutdown();
}
