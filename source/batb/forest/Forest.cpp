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
#include "Forest.hpp" 
#include "batb.hpp" 

namespace batb
{



namespace forest
{


////////////////////////////////////////////////////////////////////////////////
//  Forest

Forest::Forest(BATB& b) : batb( b ), keyset( b ),
                          iterationForestDemo( b )
{

}



void Forest::save()
{

    // FIXME: write to file
}


////////////////////////////////////////////////////////////////////////////////
// 
void begin(Forest& forest)
{

    BATB_LOG_FUNC( forest.batb );


    // set up this Forest object from file
    YAML::Node yaml = YAML::LoadFile( forest.filepath_ );

    // load associated keys 
    forest.keyset.load("batb/forest/KeySet.yaml");

    // begin iterations:
    forest::begin( forest.iterationForestDemo );

    forest.initialized_ = true;
}

void end(Forest& forest)
{
    BATB_LOG_FUNC( forest.batb );

    if ( forest.initialized_ )
    {
        // end  iterations:
        forest::end( forest.iterationForestDemo );

        // clear keys
        forest.keyset.clear();

        forest.save();
    }
    
    forest.initialized_ = false;

}


} // namespace forest

} // namespace batb


