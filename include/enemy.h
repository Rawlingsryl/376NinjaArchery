#ifndef		__H__ENEMY__
#define		__H__ENEMY__

#include "LEAGUE/common_data_structures.h"
#include "LEAGUE/physics.h"
#include <box2d/box2d.h>

class Enemy : public Drawable, public Updateable, public b2ContactListener {
	public:
		Enemy(PhysicsWorld*, int, int);
		~Enemy();
		void draw(SDL_Renderer* renderer) override;
		void update(double delta) override;
		float flip(float);
		void setBody(b2Body*);
		b2BodyDef* getBodyDef();
		b2Body* getBody();
        void BeginContact(b2Contact* contact) override;
        void EndContact(b2Contact* contact) override;
	private:
		int x_vel;
		int y_vel;
		b2Body* body;
		b2BodyDef* bodyDef;
        int animation;
        float timeElapsed;
		int framesSinceLastAnimation;
		int spawnTime;
		int spawnPoint;
		bool notSpawned;
		
};

#endif
