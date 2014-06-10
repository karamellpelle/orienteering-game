//    orienteering-game: an orientering game.
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
#ifndef BATB_RUNWORLD_HPP
#define BATB_RUNWORLD_HPP
#include "BATB/BATB_include.hpp"
#include "BATB/Run/RunEvent.hpp"
#include "BATB/Run/Scene.hpp"
#include "BATB/Run/Player.hpp"
#include "BATB/Forest.hpp"
#include "BATB/Race.hpp"

namespace BATB
{

class RunWorld
{
public:
    RunWorld() : race( this ), frames_( 0 ) // worlds shall not be singletons!
    {
    }

    RaceWorld race;
    IterationStackRaceWorld race_stack;

    // RunNetwork network;
    // [RunEvent] events;

    // Scene this RunWorld uses
    Scene* scene()
    {
        return &scene_;
    }

private:
    uint frames_;

    Scene scene_;
};


}

#endif
