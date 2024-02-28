#ifndef		__H__ARROW__
#define		__H__ARROW__

#include "LEAGUE/common_data_structures.h"
#include "LEAGUE/physics.h"
#include <box2d/box2d.h>

class Arrow : public Drawable, public Updateable, public b2ContactListener {
	public:
		Arrow(PhysicsWorld*);
		~Arrow();
		void draw(SDL_Renderer* renderer) override;
		void update(double delta) override;
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
		float elapsedTime;
		int numTimes;
};

#endif
