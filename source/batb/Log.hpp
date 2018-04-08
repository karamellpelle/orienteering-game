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
#ifndef BATB_LOG_LOG_HPP
#define BATB_LOG_LOG_HPP
#include "batb/batb_include.hpp"
#include "batb/ModuleBATB.hpp"


namespace batb
{


namespace log
{

// defining custom std::ostream's:
// http://www.angelikalanger.com/Articles/C++Report/IOStreamsDerivation/IOStreamsDerivation.html

// our stream buffer
class LogStreamBuf : public std::streambuf
{
public: 
    virtual std::streamsize xsputn(const char* s, std::streamsize n) override;
    virtual int overflow (int c) override;
};


class Log : public ModuleBATB, public std::ostream
{
friend void begin(Log& log);
friend void end(Log& log);

public:
    Log(BATB& b) : ModuleBATB( b ), std::ostream( &streambuf_ ) { }


    // TODO: tag messages
    //std::ostream& info();
    //std::ostream& error();
    //

    // TMP:
    //std::ostream& operator<<(std::ostream&) { return std::cout; }

private:
    LogStreamBuf streambuf_;

    // TODO:
    //std::ostream* os_; // from definition.
    //uint line_indentation_ = 0;
};



void begin(Log& log);

void end(Log& log);


} // namespace log

} // namespace batb

#endif