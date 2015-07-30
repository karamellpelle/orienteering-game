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
#ifndef BATB_FOREST_FOREST_KEYSET_HPP
#define BATB_FOREST_FOREST_KEYSET_HPP
#include "batb/batb_include.hpp"
#include "batb/keys.hpp"

namespace batb
{

class BATB;

namespace forest
{


class KeySet : public keys::KeySet //, Module
{
public:
    KeySet(BATB& b);

    // define 'this' from map defined by file
    void load(const std::string& filepath);
    void save(const std::string& filepath);

    void reset();

    keys::KeyClicker* forward = nullptr;
    keys::KeyClicker* backward = nullptr;
    keys::KeyClicker* left = nullptr;
    keys::KeyClicker* right = nullptr;
    keys::KeyPointer* aim = nullptr;

    keys::KeyClicker* tmp = nullptr;

    BATB& batb;
};

} // namespace forest

} // namespace batb


#endif
