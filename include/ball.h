#ifndef		__H__BALL__
#define		__H__BALL__

#include "LEAGUE/common_data_structures.h"
#include "LEAGUE/physics.h"
#include <box2d/box2d.h>

class Ball : public Drawable, public Updateable, public b2ContactListener {
	public:
		Ball(PhysicsWorld*);
		~Ball();
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
};

#endif
