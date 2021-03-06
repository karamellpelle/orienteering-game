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
#include "BATB/GUI/tb/tb_system_batb.hpp"

#include "tb/tb_core.h"
#include "tb/renderers/tb_renderer_gl.h"
#include "tb/tb_font_renderer.h"
#include "tb/animation/tb_animation.h"
#include "tb/animation/tb_widget_animation.h"

#include <stdio.h>



// interface for batb::gui to 
namespace batb
{

namespace gui
{

// current time (given by BATB::GUI)
static double tbsystem_time = 0.0;



// set time for TBSystem:
void tbsystem_ms(double t)
{
    // BATB::GUI sets the time for TBSystem
    tbsystem_time = t;   

}



} // namespace gui

} // namespace batb


namespace tb
{

#ifdef TB_RUNTIME_DEBUG_INFO
void TBDebugOut(const char *str)
{
    // TODO:
    //batb->log << str;
	//printf("%s", str);
}
#endif // TB_RUNTIME_DEBUG_INFO

////////////////////////////////////////////////////////////////////////////////
//  TBSystem


// this function is called by TBMessageHandler when the time for the 
// next message to be delivered got changed. however, we do not use
// such wake-up system in our game application, instead a continuous
// loop, so we do not care about this notification.
void TBSystem::RescheduleTimer(double fire_time)
{

}



double TBSystem::GetTimeMS()
{
    return batb::gui::tbsystem_time;
}


// only for touch platforms
int TBSystem::GetLongClickDelayMS()
{
	return 500;
}

// only for touch platforms
int TBSystem::GetPanThreshold()
{
    // FIXME!
    // (probably not necessary, only for touch platforms...)
	return 5 * GetDPI() / 96;
}

// only for touch platforms
int TBSystem::GetPixelsPerLine()
{
	return 40 * GetDPI() / 96;
}

// we currently use this during our GUI setup for fonts
// FIXME: make our TB implementation independent of this,
//        so the view across different screens is mostly consistent. 
//        we are also using MSAA typically, anyway
int TBSystem::GetDPI()
{
	// FIX: Implement!
	return 96;
}


////////////////////////////////////////////////////////////////////////////////
//  clipboard (empty)
//
static TBStr clipboard; ///< Obviosly not a full implementation since it ignores the OS :)

void TBClipboard::Empty()
{
	clipboard.Clear();
}

bool TBClipboard::HasText()
{
	return !clipboard.IsEmpty();
}

bool TBClipboard::SetText(const char *text)
{
	return clipboard.Set(text);
}

bool TBClipboard::GetText(TBStr &text)
{
	return text.Set(clipboard);
}

} // namespace tb



