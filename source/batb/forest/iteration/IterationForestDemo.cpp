//    open-forest: an orientering game.
//    Copyright (C) 2014  carljsv@student.matnat.uio.no
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License along
//    with this program; if not, write to the Free Software Foundation, Inc.,
//    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
#include "batb.hpp"
#include "glm/gtx/euler_angles.hpp"


namespace batb
{

namespace forest
{



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


IterationForestDemo::IterationForestDemo(BATB& b) : IterationForest( b )
{

}



void IterationForestDemo::iterate_begin(World& forest)
{
    BATB_LOG_FUNC( batb );

    // we want clean state for our Key's, no garbage:
    batb.forest.keyset.reset();

    // we want free movement (no pointer, only movement)
    batb.keys.setCursorFree( true );

    if ( !forest.runners.empty() )
    {
        aiming = &forest.runners.front(); // is this pointer safe??

        // set start pos as in tmp::ogre:
        aiming->pos = glm::vec4( 0.0, 400.0, 0.0, 1.0 ); 
    }
    std::cout << "Starting Forest demo. " << std::endl;
}


IterationStack IterationForestDemo::iterate_forest(World& forest)
{


    ////////////////////////////////////////////////////////////////////////////////
    //  STEP
    // 

    float_t x, y;
    batb.forest.keyset.aim->axis( x, y );
    bool press_l = batb.forest.keyset.aim->left()->press();
    bool press_r = batb.forest.keyset.aim->right()->press();

    constexpr tick_t aim_dt = 0.02;
    aim_a = (-x);
    aim_b = y;

    ////////////////////////////////////////
    // set aim of runner from aim_x_
    if ( aiming )
    {
        aiming->aim = glm::eulerAngleYXZ( aim_a, aim_b, aim_c );
    }


    ////////////////////////////////////////
    // * step dt of runner
    constexpr tick_t dt = 0.02;
    constexpr float_t press_speed = 100.0;

    tick_t tick_next = forest.run.tick;
    while ( forest.tick + dt <= tick_next )
    {
      
        // TODO: step 'aiming' (physics)
        if ( press_l || press_r )
        {
            glm::vec4 dir = aiming->aim[2];
            float alpha = ( press_r ? (-1.0) : (1.0) ) * dt * press_speed;
            aiming->pos += alpha * dir;
        }
        //
        forest.tick += dt;
    }

    glm::vec4 pos = aiming->pos;
    //std::cout << "\rcursor: " << x << " " << y << ", "
    //          << "pos: " << pos[0] << " "<< pos[1] << " "<< pos[2];
              

    // continue with this iteration
    return { this };

}


////////////////////////////////////////////////////////////////////////////////
//
//
void begin(IterationForestDemo& iter)
{
    BATB_LOG_FUNC( iter.batb );


}

void end(IterationForestDemo& iter)
{
    BATB_LOG_FUNC( iter.batb );
}



} // namespace forest

} // namespace batb


