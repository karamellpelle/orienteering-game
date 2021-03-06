//    open-forest: an orienteering game.
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
#ifndef BATB_EVENT_BASE_HPP
#define BATB_EVENT_BASE_HPP
#include "include.hpp"
#include <typeindex>


namespace batb
{


////////////////////////////////////////////////////////////////////////////////
// Event base class
//
// our type id needs these properties:
//  * forall T : T has an id. there is maximum one T for each id.
//
// lets use the natural type_info/type_index for type id.
//
class EventBase
{
template <typename T_>
friend class EventDataCopy;
template <typename T_>
friend class EventDataPoint;
friend class EventList;
friend class Event;

public:
    const std::type_index& type() const { return type_; }
    void* data() const { return data_; }

    // make it live through through this step too (cf. EventList::step())
    void keepAlive()    { ++frame_lifes; }

private:
    EventBase(const std::type_index& t, void* d) : type_( t ), data_( d ) { }
    virtual ~EventBase() { }

    // no copy, assignment (only 1 EventBase for 'this')
    EventBase(const EventBase& ) = delete;
    EventBase& operator=(const EventBase& ) = delete;

    void frames(uint n) { frame_lifes = n; }

    // content
    std::type_index type_;
    void* data_;

    // event info
    // TODO.
    uint frame = 0;
    tick_t tick = 0.0;
    // ...

    // mem
    // should be non-empty. 1 means it only lives through current frame
    uint frame_lifes = 1;

};


////////////////////////////////////////////////////////////////////////////////
// type holder events
// 
// these are the only valid subclasses of EventBase
//

////////////////////////////////////////////////////////////////////////////////
// EventDataCopy: copy value
//
template <typename T>
class EventDataCopy : public EventBase
{
public:
    EventDataCopy(const T& t) : EventBase( typeid( T ), &t_ ), t_( t ) { } // FIXME: pointer to t_ valid before init?? 

private:
    T t_;
};


////////////////////////////////////////////////////////////////////////////////
// EventDataPoint
//
template <typename T>
class EventDataPoint : public EventBase
{
public:
    template <typename D>
    EventDataPoint(T* t, D deleter) : EventBase( typeid( T ), t ), ptr_( t, deleter ) { } 

private:
    std::shared_ptr<T> ptr_; 
    //std::unique_pointer<T> ptr_; 
};



////////////////////////////////////////////////////////////////////////////////
// Event
//
// user does not handle EventBase directly
//
class Event
{
template <typename T>
friend T* eat(const Event& e);
friend class EventEater;

public:
    //template <typename T>
    //Event(const T& ) : Event( std::make_shared<EventDataCopy<T>>( d ) ) { }
    //template <typename T, typename D = std::default_delete<T>> // enable_if is_pointer
    //Event(T* d, const D& del = D()) : Event( std::make_shared<EventDataPoint<T>>( d, del ) ) { }

    Event(const Event& ) = default;
    Event& operator=(const Event& ) = default;
    Event(Event&& ) = default;

    Event(const std::shared_ptr<EventBase>& b) : base_( b ) { } // public for EventList. the whole event implementation should instead be redesigned at bit

    // make it live through through this step too (cf. EventList::step())
    void keepAlive()    { ++base_->frame_lifes; }

private:
    std::shared_ptr<EventBase> base_;
};



////////////////////////////////////////////////////////////////////////////////
// try to eat single event as type T
//
// this is the thing that makes Event useful
// no ownership to returned object shall be acclaimed
//
template <typename T>
T* eat(const Event& e)
{
    return std::type_index( typeid( T ) ) == e.base_->type() ? 
           static_cast<T*>( e.base_->data() ) : nullptr;
}







} // namespace batb


#endif

