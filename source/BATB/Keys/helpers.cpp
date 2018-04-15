//    open-forest: an orientering game.
//    Copyright (C) 2018  karamellpelle@hotmail.com
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
#include "BATB/Keys/helpers.hpp"

#define CASE_GLFW_KEY(name) case name: return #name
#define CASE_GLFW_KEYNAME(name) if ( arg == #name ) return name


namespace batb
{

namespace keys
{


std::string cast_key(int key)
{


    switch (key)
    {
    CASE_GLFW_KEY( GLFW_KEY_SPACE ); 
    CASE_GLFW_KEY( GLFW_KEY_SPACE );
    CASE_GLFW_KEY( GLFW_KEY_APOSTROPHE );
    CASE_GLFW_KEY( GLFW_KEY_COMMA );
    CASE_GLFW_KEY( GLFW_KEY_MINUS );
    CASE_GLFW_KEY( GLFW_KEY_PERIOD );
    CASE_GLFW_KEY( GLFW_KEY_SLASH );
    CASE_GLFW_KEY( GLFW_KEY_0 );
    CASE_GLFW_KEY( GLFW_KEY_1 );
    CASE_GLFW_KEY( GLFW_KEY_2 );
    CASE_GLFW_KEY( GLFW_KEY_3 );
    CASE_GLFW_KEY( GLFW_KEY_4 );
    CASE_GLFW_KEY( GLFW_KEY_5 );
    CASE_GLFW_KEY( GLFW_KEY_6 );
    CASE_GLFW_KEY( GLFW_KEY_7 );
    CASE_GLFW_KEY( GLFW_KEY_8 );
    CASE_GLFW_KEY( GLFW_KEY_9 );
    CASE_GLFW_KEY( GLFW_KEY_SEMICOLON );
    CASE_GLFW_KEY( GLFW_KEY_EQUAL );
    CASE_GLFW_KEY( GLFW_KEY_A );
    CASE_GLFW_KEY( GLFW_KEY_B );
    CASE_GLFW_KEY( GLFW_KEY_C );
    CASE_GLFW_KEY( GLFW_KEY_D );
    CASE_GLFW_KEY( GLFW_KEY_E );
    CASE_GLFW_KEY( GLFW_KEY_F );
    CASE_GLFW_KEY( GLFW_KEY_G );
    CASE_GLFW_KEY( GLFW_KEY_H );
    CASE_GLFW_KEY( GLFW_KEY_I );
    CASE_GLFW_KEY( GLFW_KEY_J );
    CASE_GLFW_KEY( GLFW_KEY_K );
    CASE_GLFW_KEY( GLFW_KEY_L );
    CASE_GLFW_KEY( GLFW_KEY_M );
    CASE_GLFW_KEY( GLFW_KEY_N );
    CASE_GLFW_KEY( GLFW_KEY_O );
    CASE_GLFW_KEY( GLFW_KEY_P );
    CASE_GLFW_KEY( GLFW_KEY_Q );
    CASE_GLFW_KEY( GLFW_KEY_R );
    CASE_GLFW_KEY( GLFW_KEY_S );
    CASE_GLFW_KEY( GLFW_KEY_T );
    CASE_GLFW_KEY( GLFW_KEY_U );
    CASE_GLFW_KEY( GLFW_KEY_V );
    CASE_GLFW_KEY( GLFW_KEY_W );
    CASE_GLFW_KEY( GLFW_KEY_X );
    CASE_GLFW_KEY( GLFW_KEY_Y );
    CASE_GLFW_KEY( GLFW_KEY_Z );
    CASE_GLFW_KEY( GLFW_KEY_LEFT_BRACKET );
    CASE_GLFW_KEY( GLFW_KEY_BACKSLASH );
    CASE_GLFW_KEY( GLFW_KEY_RIGHT_BRACKET );
    CASE_GLFW_KEY( GLFW_KEY_GRAVE_ACCENT );
    CASE_GLFW_KEY( GLFW_KEY_WORLD_1 );
    CASE_GLFW_KEY( GLFW_KEY_WORLD_2 );
    CASE_GLFW_KEY( GLFW_KEY_ESCAPE );
    CASE_GLFW_KEY( GLFW_KEY_ENTER );
    CASE_GLFW_KEY( GLFW_KEY_TAB );
    CASE_GLFW_KEY( GLFW_KEY_BACKSPACE );
    CASE_GLFW_KEY( GLFW_KEY_INSERT );
    CASE_GLFW_KEY( GLFW_KEY_DELETE );
    CASE_GLFW_KEY( GLFW_KEY_RIGHT );
    CASE_GLFW_KEY( GLFW_KEY_LEFT );
    CASE_GLFW_KEY( GLFW_KEY_DOWN );
    CASE_GLFW_KEY( GLFW_KEY_UP );
    CASE_GLFW_KEY( GLFW_KEY_PAGE_UP );
    CASE_GLFW_KEY( GLFW_KEY_PAGE_DOWN );
    CASE_GLFW_KEY( GLFW_KEY_HOME );
    CASE_GLFW_KEY( GLFW_KEY_END );
    CASE_GLFW_KEY( GLFW_KEY_CAPS_LOCK );
    CASE_GLFW_KEY( GLFW_KEY_SCROLL_LOCK );
    CASE_GLFW_KEY( GLFW_KEY_NUM_LOCK );
    CASE_GLFW_KEY( GLFW_KEY_PRINT_SCREEN );
    CASE_GLFW_KEY( GLFW_KEY_PAUSE );
    CASE_GLFW_KEY( GLFW_KEY_F1 );
    CASE_GLFW_KEY( GLFW_KEY_F2 );
    CASE_GLFW_KEY( GLFW_KEY_F3 );
    CASE_GLFW_KEY( GLFW_KEY_F4 );
    CASE_GLFW_KEY( GLFW_KEY_F5 );
    CASE_GLFW_KEY( GLFW_KEY_F6 );
    CASE_GLFW_KEY( GLFW_KEY_F7 );
    CASE_GLFW_KEY( GLFW_KEY_F8 );
    CASE_GLFW_KEY( GLFW_KEY_F9 );
    CASE_GLFW_KEY( GLFW_KEY_F10 );
    CASE_GLFW_KEY( GLFW_KEY_F11 );
    CASE_GLFW_KEY( GLFW_KEY_F12 );
    CASE_GLFW_KEY( GLFW_KEY_F13 );
    CASE_GLFW_KEY( GLFW_KEY_F14 );
    CASE_GLFW_KEY( GLFW_KEY_F15 );
    CASE_GLFW_KEY( GLFW_KEY_F16 );
    CASE_GLFW_KEY( GLFW_KEY_F17 );
    CASE_GLFW_KEY( GLFW_KEY_F18 );
    CASE_GLFW_KEY( GLFW_KEY_F19 );
    CASE_GLFW_KEY( GLFW_KEY_F20 );
    CASE_GLFW_KEY( GLFW_KEY_F21 );
    CASE_GLFW_KEY( GLFW_KEY_F22 );
    CASE_GLFW_KEY( GLFW_KEY_F23 );
    CASE_GLFW_KEY( GLFW_KEY_F24 );
    CASE_GLFW_KEY( GLFW_KEY_F25 );
    CASE_GLFW_KEY( GLFW_KEY_KP_0 );
    CASE_GLFW_KEY( GLFW_KEY_KP_1 );
    CASE_GLFW_KEY( GLFW_KEY_KP_2 );
    CASE_GLFW_KEY( GLFW_KEY_KP_3 );
    CASE_GLFW_KEY( GLFW_KEY_KP_4 );
    CASE_GLFW_KEY( GLFW_KEY_KP_5 );
    CASE_GLFW_KEY( GLFW_KEY_KP_6 );
    CASE_GLFW_KEY( GLFW_KEY_KP_7 );
    CASE_GLFW_KEY( GLFW_KEY_KP_8 );
    CASE_GLFW_KEY( GLFW_KEY_KP_9 );
    CASE_GLFW_KEY( GLFW_KEY_KP_DECIMAL );
    CASE_GLFW_KEY( GLFW_KEY_KP_DIVIDE );
    CASE_GLFW_KEY( GLFW_KEY_KP_MULTIPLY );
    CASE_GLFW_KEY( GLFW_KEY_KP_SUBTRACT );
    CASE_GLFW_KEY( GLFW_KEY_KP_ADD );
    CASE_GLFW_KEY( GLFW_KEY_KP_ENTER );
    CASE_GLFW_KEY( GLFW_KEY_KP_EQUAL );
    CASE_GLFW_KEY( GLFW_KEY_LEFT_SHIFT );
    CASE_GLFW_KEY( GLFW_KEY_LEFT_CONTROL );
    CASE_GLFW_KEY( GLFW_KEY_LEFT_ALT );
    CASE_GLFW_KEY( GLFW_KEY_LEFT_SUPER );
    CASE_GLFW_KEY( GLFW_KEY_RIGHT_SHIFT );
    CASE_GLFW_KEY( GLFW_KEY_RIGHT_CONTROL );
    CASE_GLFW_KEY( GLFW_KEY_RIGHT_ALT );
    CASE_GLFW_KEY( GLFW_KEY_RIGHT_SUPER );
    CASE_GLFW_KEY( GLFW_KEY_MENU );
    };

    return "GLFW_KEY_UNKNOWN";
 
}

std::string cast_mouse_button(int key)
{

    switch (key)
    {
    CASE_GLFW_KEY( GLFW_MOUSE_BUTTON_1 );
    CASE_GLFW_KEY( GLFW_MOUSE_BUTTON_2 );
    CASE_GLFW_KEY( GLFW_MOUSE_BUTTON_3 );
    CASE_GLFW_KEY( GLFW_MOUSE_BUTTON_4 );
    CASE_GLFW_KEY( GLFW_MOUSE_BUTTON_5 );
    CASE_GLFW_KEY( GLFW_MOUSE_BUTTON_6 );
    CASE_GLFW_KEY( GLFW_MOUSE_BUTTON_7 );
    CASE_GLFW_KEY( GLFW_MOUSE_BUTTON_8 );
    CASE_GLFW_KEY( GLFW_MOUSE_BUTTON_LAST );
    CASE_GLFW_KEY( GLFW_MOUSE_BUTTON_LEFT );
    CASE_GLFW_KEY( GLFW_MOUSE_BUTTON_RIGHT );
    CASE_GLFW_KEY( GLFW_MOUSE_BUTTON_MIDDLE );
    };

    return "GLFW_KEY_UNKNOWN";
}

std::string cast_modifier(int key)
{

    switch (key)
    {
    CASE_GLFW_KEY( GLFW_MOD_ALT );
    CASE_GLFW_KEY( GLFW_MOD_CONTROL );
    CASE_GLFW_KEY( GLFW_MOD_SHIFT );
    CASE_GLFW_KEY( GLFW_MOD_SUPER );
    };

    return "GLFW_KEY_UNKNOWN";
}


int cast(const std::string& name)
{
    auto& arg = name;

    CASE_GLFW_KEYNAME( GLFW_KEY_SPACE ); 
    CASE_GLFW_KEYNAME( GLFW_KEY_SPACE );
    CASE_GLFW_KEYNAME( GLFW_KEY_APOSTROPHE );
    CASE_GLFW_KEYNAME( GLFW_KEY_COMMA );
    CASE_GLFW_KEYNAME( GLFW_KEY_MINUS );
    CASE_GLFW_KEYNAME( GLFW_KEY_PERIOD );
    CASE_GLFW_KEYNAME( GLFW_KEY_SLASH );
    CASE_GLFW_KEYNAME( GLFW_KEY_0 );
    CASE_GLFW_KEYNAME( GLFW_KEY_1 );
    CASE_GLFW_KEYNAME( GLFW_KEY_2 );
    CASE_GLFW_KEYNAME( GLFW_KEY_3 );
    CASE_GLFW_KEYNAME( GLFW_KEY_4 );
    CASE_GLFW_KEYNAME( GLFW_KEY_5 );
    CASE_GLFW_KEYNAME( GLFW_KEY_6 );
    CASE_GLFW_KEYNAME( GLFW_KEY_7 );
    CASE_GLFW_KEYNAME( GLFW_KEY_8 );
    CASE_GLFW_KEYNAME( GLFW_KEY_9 );
    CASE_GLFW_KEYNAME( GLFW_KEY_SEMICOLON );
    CASE_GLFW_KEYNAME( GLFW_KEY_EQUAL );
    CASE_GLFW_KEYNAME( GLFW_KEY_A );
    CASE_GLFW_KEYNAME( GLFW_KEY_B );
    CASE_GLFW_KEYNAME( GLFW_KEY_C );
    CASE_GLFW_KEYNAME( GLFW_KEY_D );
    CASE_GLFW_KEYNAME( GLFW_KEY_E );
    CASE_GLFW_KEYNAME( GLFW_KEY_F );
    CASE_GLFW_KEYNAME( GLFW_KEY_G );
    CASE_GLFW_KEYNAME( GLFW_KEY_H );
    CASE_GLFW_KEYNAME( GLFW_KEY_I );
    CASE_GLFW_KEYNAME( GLFW_KEY_J );
    CASE_GLFW_KEYNAME( GLFW_KEY_K );
    CASE_GLFW_KEYNAME( GLFW_KEY_L );
    CASE_GLFW_KEYNAME( GLFW_KEY_M );
    CASE_GLFW_KEYNAME( GLFW_KEY_N );
    CASE_GLFW_KEYNAME( GLFW_KEY_O );
    CASE_GLFW_KEYNAME( GLFW_KEY_P );
    CASE_GLFW_KEYNAME( GLFW_KEY_Q );
    CASE_GLFW_KEYNAME( GLFW_KEY_R );
    CASE_GLFW_KEYNAME( GLFW_KEY_S );
    CASE_GLFW_KEYNAME( GLFW_KEY_T );
    CASE_GLFW_KEYNAME( GLFW_KEY_U );
    CASE_GLFW_KEYNAME( GLFW_KEY_V );
    CASE_GLFW_KEYNAME( GLFW_KEY_W );
    CASE_GLFW_KEYNAME( GLFW_KEY_X );
    CASE_GLFW_KEYNAME( GLFW_KEY_Y );
    CASE_GLFW_KEYNAME( GLFW_KEY_Z );
    CASE_GLFW_KEYNAME( GLFW_KEY_LEFT_BRACKET );
    CASE_GLFW_KEYNAME( GLFW_KEY_BACKSLASH );
    CASE_GLFW_KEYNAME( GLFW_KEY_RIGHT_BRACKET );
    CASE_GLFW_KEYNAME( GLFW_KEY_GRAVE_ACCENT );
    CASE_GLFW_KEYNAME( GLFW_KEY_WORLD_1 );
    CASE_GLFW_KEYNAME( GLFW_KEY_WORLD_2 );
    CASE_GLFW_KEYNAME( GLFW_KEY_ESCAPE );
    CASE_GLFW_KEYNAME( GLFW_KEY_ENTER );
    CASE_GLFW_KEYNAME( GLFW_KEY_TAB );
    CASE_GLFW_KEYNAME( GLFW_KEY_BACKSPACE );
    CASE_GLFW_KEYNAME( GLFW_KEY_INSERT );
    CASE_GLFW_KEYNAME( GLFW_KEY_DELETE );
    CASE_GLFW_KEYNAME( GLFW_KEY_RIGHT );
    CASE_GLFW_KEYNAME( GLFW_KEY_LEFT );
    CASE_GLFW_KEYNAME( GLFW_KEY_DOWN );
    CASE_GLFW_KEYNAME( GLFW_KEY_UP );
    CASE_GLFW_KEYNAME( GLFW_KEY_PAGE_UP );
    CASE_GLFW_KEYNAME( GLFW_KEY_PAGE_DOWN );
    CASE_GLFW_KEYNAME( GLFW_KEY_HOME );
    CASE_GLFW_KEYNAME( GLFW_KEY_END );
    CASE_GLFW_KEYNAME( GLFW_KEY_CAPS_LOCK );
    CASE_GLFW_KEYNAME( GLFW_KEY_SCROLL_LOCK );
    CASE_GLFW_KEYNAME( GLFW_KEY_NUM_LOCK );
    CASE_GLFW_KEYNAME( GLFW_KEY_PRINT_SCREEN );
    CASE_GLFW_KEYNAME( GLFW_KEY_PAUSE );
    CASE_GLFW_KEYNAME( GLFW_KEY_F1 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F2 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F3 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F4 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F5 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F6 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F7 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F8 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F9 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F10 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F11 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F12 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F13 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F14 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F15 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F16 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F17 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F18 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F19 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F20 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F21 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F22 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F23 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F24 );
    CASE_GLFW_KEYNAME( GLFW_KEY_F25 );
    CASE_GLFW_KEYNAME( GLFW_KEY_KP_0 );
    CASE_GLFW_KEYNAME( GLFW_KEY_KP_1 );
    CASE_GLFW_KEYNAME( GLFW_KEY_KP_2 );
    CASE_GLFW_KEYNAME( GLFW_KEY_KP_3 );
    CASE_GLFW_KEYNAME( GLFW_KEY_KP_4 );
    CASE_GLFW_KEYNAME( GLFW_KEY_KP_5 );
    CASE_GLFW_KEYNAME( GLFW_KEY_KP_6 );
    CASE_GLFW_KEYNAME( GLFW_KEY_KP_7 );
    CASE_GLFW_KEYNAME( GLFW_KEY_KP_8 );
    CASE_GLFW_KEYNAME( GLFW_KEY_KP_9 );
    CASE_GLFW_KEYNAME( GLFW_KEY_KP_DECIMAL );
    CASE_GLFW_KEYNAME( GLFW_KEY_KP_DIVIDE );
    CASE_GLFW_KEYNAME( GLFW_KEY_KP_MULTIPLY );
    CASE_GLFW_KEYNAME( GLFW_KEY_KP_SUBTRACT );
    CASE_GLFW_KEYNAME( GLFW_KEY_KP_ADD );
    CASE_GLFW_KEYNAME( GLFW_KEY_KP_ENTER );
    CASE_GLFW_KEYNAME( GLFW_KEY_KP_EQUAL );
    CASE_GLFW_KEYNAME( GLFW_KEY_LEFT_SHIFT );
    CASE_GLFW_KEYNAME( GLFW_KEY_LEFT_CONTROL );
    CASE_GLFW_KEYNAME( GLFW_KEY_LEFT_ALT );
    CASE_GLFW_KEYNAME( GLFW_KEY_LEFT_SUPER );
    CASE_GLFW_KEYNAME( GLFW_KEY_RIGHT_SHIFT );
    CASE_GLFW_KEYNAME( GLFW_KEY_RIGHT_CONTROL );
    CASE_GLFW_KEYNAME( GLFW_KEY_RIGHT_ALT );
    CASE_GLFW_KEYNAME( GLFW_KEY_RIGHT_SUPER );
    CASE_GLFW_KEYNAME( GLFW_KEY_MENU );
    // TODO: mouse buttons
    //       modifiers

    return GLFW_KEY_UNKNOWN;
  
}

} // namespace keys

} // namespace batb

