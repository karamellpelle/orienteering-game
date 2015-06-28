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
#ifndef BATB_INCLUDE_HPP
#define BATB_INCLUDE_HPP

////////////////////////////////////////////////////////////////////////////////
// stdlib
#include <stdint.h>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cstdio>
#include <list>
#include <forward_list>

////////////////////////////////////////////////////////////////////////////////
// project includes
#include "include.hpp"
#include "env.hpp"
#include "file.hpp"
#include "game.hpp"

////////////////////////////////////////////////////////////////////////////////
// GLM
// see: http://www.glm.g-truc.net/glm.pdf
#define GLM_SWIZZLE           // implement swizzles (increses compilation time)
//#define GLM_PRECISION_XXX // define precisions
//#define GLM_MESSAGES          // let glm print system messages
#define GLM_FORCE_RADIANS       // let glm angles be in radians
//#define GLM_FORCE_INLINE      // let glm be inlined
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/matrix_access.hpp"
#include "glm/gtc/matrix_inverse.hpp"
#include "glm/gtc/epsilon.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtc/constants.hpp"
#include "glm/gtc/type_ptr.hpp"

////////////////////////////////////////////////////////////////////////////////
//  nanovg
#include "nanovg.hpp"

////////////////////////////////////////////////////////////////////////////////
//  tinyxml2
#include "tinyxml2.h"

////////////////////////////////////////////////////////////////////////////////
//  yaml
#include "yaml-cpp/yaml.h"


#include "debug.hpp"
#include "debug/gl.hpp"

// handling GL in our game
#include "batb/gl.hpp"


////////////////////////////////////////////////////////////////////////////////
namespace batb
{

// export whole include module
using namespace include;

// nameclash (????)
typedef include::uint       uint;
typedef include::float_t    float_t;

// our tick type
typedef env::tick_t tick_t;



}



#endif
