#ifndef		__H__BACKGROUND__
#define		__H__BACKGROUND__

#include "LEAGUE/common_data_structures.h"
#include "LEAGUE/physics.h"
#include <box2d/box2d.h>

class Background : public Drawable, public Updateable {
	public:
		Background();
		~Background();
		void draw(SDL_Renderer* renderer) override;
		void update(double delta) override;
	private:

};



#endif
