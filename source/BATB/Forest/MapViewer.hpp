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
#ifndef BATB_FOREST_MAPVIEWER_HPP
#define BATB_FOREST_MAPVIEWER_HPP
#include "BATB/Forest.hpp"
#include "BATB/GL.hpp"



namespace batb
{
class BATB;
class Scene;

namespace forest
{
class World;
class MapDrawer2D;





class MapViewer 
{
public:
    MapViewer();

    // connect to world
    //void init(World* );

    void step(tick_t );
    void draw2D(BATB* , const Scene& );

    ////////////////////////////////////////////////////////////////
    //
    //// use this map
    //void useMap(Map* );
    // mapscale alá orienteering map
    void mapscale(uint one, uint many); // map_drawer.mapscale( 1, 15000 );

    ////////////////////////////////////////////////////////////////
    // view map based by World coordinates. 
    // world coordinates makes it easy to switch Map's on the fly
    // TODO: use decltype of world coordinates
    // view draw map from this point
    void setPosition(const glm::vec3& , tick_t = 0.0);
    void setPositionScaleInv(const glm::vec3& , tick_t = 0.0);
    // look direction, i.e. upwards
    void setDirection(const glm::vec3& , tick_t = 0.0);
    void lookAt(const glm::vec3& , tick_t = 0.0);
    void setRotation(double , tick_t = 0.0); 

    glm::vec3 getPosition() const;
    glm::vec3 getDirection() const;
    double getRotation() const; 

    // working on context
    void setZoom(double , tick_t = 0.0); // 1.0 is mapscale
    double getZoom() const; // 1.0 is mapscale

    void setOpacity(double );
    double getOpacity() const;

    ////////////////////////////////////////////////////////////////
    // we need to work with pixel since NanoVG has problem with 
    // non-pixel coordinates, especially fonts
    class Draw2D
    {
    public:
        // scaling: world -> context
        //double scale = 1.0;
        //double scale_inv = 1.0;

        // bounding box, world coordinates
        double x = 0.0;
        double z = 0.0;
        double w = 1.0;
        double h = 1.0;
    
        // world coordinates scaled down (i.e. mapscale)
        double to_m = 1.0;
        // mapscale to NanoVG coordinates
        double from_m = 1.0;
        // world coordinates to NanoVG coordinates (NanoVG fonts needs pixels)
        double to_pixel = from_m * to_m;

        double opacity = 1.0;
    };

protected:
    virtual void beginDraw2D(NVGcontext* , const Draw2D& ) {}
    virtual void endDraw2D(NVGcontext* , const Draw2D& )   {}


private:
    glm::vec3 p0_;
    glm::vec3 u0_;
    glm::vec3 v0_;
    double rotate0_ = 0.0;
    double opacity0_ = 1.0;

    tick_t tick_ = 0.0;

    double scale_     = 1.0;
    double scale_inv_ = 1.0;

    double zoom_     = 1.0;
    double zoom_inv_ = 1.0;


};


} // namespace forest

} // namespace batb


#endif

