#ifndef     __H_BALCONY__
#define     __H_BALCONY__

#include "LEAGUE/common_data_structures.h"

class Balcony : public Drawable, public Updateable{
    public:
        Balcony();
        Balcony(int x_coord, int y_coord);
        ~Balcony();
        void draw(SDL_Renderer* renderer) override;
        void update(double delta) override;
};

#endif
