//    open-forest: an orienteering game.
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
#ifndef BATB_OGRE_BATBCONTEXT_HPP
#define BATB_OGRE_BATBCONTEXT_HPP
#include "batb/batb_include.hpp"

namespace batb
{

namespace ogre
{


// class for making Ogre not mess up all GL and create seperate
// GL states
//
// see implementation of 
//    void GLRenderSystem::_switchContext(GLContext *context)
//    void GLStateCacheManager::switchContext(intptr_t id)
//
class BATBContext : public Ogre::GLContext
{
friend void begin(BATBContext& );
friend void end(BATBContext& );

public:
    void setCurrent() override;
    void endCurrent() override;
    void Ogre::GLContext* clone() override;

private:
     

};

////////////////////////////////////////////////////////////////////////////////
// 

void begin(BATBContext& );
void end(BATBContext& );

} // namespace ogre

} // namespace batb


#endif

