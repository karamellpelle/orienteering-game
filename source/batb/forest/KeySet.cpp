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
#include "batb/forest/KeySet.hpp"
#include "batb.hpp"


namespace batb
{


namespace forest
{


KeySet::KeySet(BATB& b) : batb( b )
{

}

void KeySet::load(const std::string& path)
{
    BATB_LOG_FUNC( batb );

    // clear current content
    clear();

    // FIXME: parse keys from definition in file
    //        the function createKey is handy...

    ////////////////////////////////////////////////////////////////////////////////
    // instead, hardcode!


    // tmp:
    //old = createKeyClicker( createKeyButton( GLFW_KEY_INSERT ) );
}

} // namespace forest

} // namespace batb
