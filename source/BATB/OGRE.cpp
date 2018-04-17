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
#include "BATB/OGRE.hpp"
#include "BATB/Scene.hpp"
#include "BATB/GL.hpp"
#include "OgreLogManager.h"
#include "OgreLog.h"
#include "OgreRoot.h"
#include "OgreRenderWindow.h"
#include "OgreViewport.h"
#include "OgreCamera.h"
#include "OgreResourceGroupManager.h"
#include "OgreSceneManager.h"
#include "OgreWindowEventUtilities.h"
#include "RenderSystems/GL/include/OgreGLRenderSystem.h"


namespace batb
{

namespace ogre
{

using namespace Ogre;
    
////////////////////////////////////////////////////////////////////////////////
// setup

void OGRE::begin(const std::string& path)
{

    if ( init_empty() )
    {
debug::gl::DebugGroup _dbg( DEBUG_FUNCTION_NAME );

        // set configuration file
        config( path );
        //LogIndent( batb->log, "Ogre::begin()", "-> " );

        ////////////////////////////////////////////////////////////////////////////////
        // setup Ogre
        //

        // control the log output from Ogre by creating the LogManager ourselves,
        // before creating Ogre::Root
debug::gl::msg( "OGRE_NEW LogManager" );
        ogre_logmanager = OGRE_NEW Ogre::LogManager();
        ogre_logmanager->createLog( file::tmp( "openforest-ogre.log" ), true, false, false );

        // set detail level 
        ogre_logmanager->setLogDetail( Ogre::LL_BOREME );

        ////////////////////////////////////////////////////////////////////////////////
        // create Ogre ogre_root object
debug::gl::msg( "OGRE_NEW Root" );
        ogre_root = OGRE_NEW Ogre::Root( "", "", "" ); // no files for plugin, config, log
       
        ////////////////////////////////////////////////////////////////////////////////
        // add plugins (ogre_rendersystem, scene managers, ...)
        batb->log << "OGRE: loading plugins:" << std::endl;
        if ( YAML::Node plugins = yaml[ "plugins" ] )
        {
            for (auto i = std::begin( plugins ); i != std::end( plugins ); ++i )
            {
                std::string plugin = i->as<std::string>();
                batb->log << "  " << plugin;
                
                try
                {
std::ostringstream os; os << "ogre_root->loadPlugin( " << plugin << ")";                
debug::gl::msg( os.str() );
                    ogre_root->loadPlugin( plugin );
                }
                catch (Ogre::Exception& e)
                {
                    batb->log << " (" << e.what() << " )";
                }

                batb->log << "\n";
            }
        }
        else
        {
            throw std::runtime_error( "OGRE: no 'plugins' defined in config" );
        }
        ////////////////////////////////////////////////////////////////////////////////
        // set ogre_rendersystem for Ogre

        // pick defined RenderSystem, default "OpenGL Rendering Subsystem"
debug::gl::msg( "ogre_root->getRenderSystemByName" );
        ogre_rendersystem_name_ = yaml["ogre_rendersystem"] ? yaml["ogre_rendersystem"].as<std::string>() : "OpenGL Rendering Subsystem";
        ogre_rendersystem = ogre_root->getRenderSystemByName( ogre_rendersystem_name_ );

        // set our Ogre render system
        if ( ogre_rendersystem )
        {
debug::gl::msg( "ogre_root->setRenderSystem" );
            ogre_root->setRenderSystem( ogre_rendersystem );
        }
        else
        {
            throw std::runtime_error( "OGRE: no RenderSystem with name " + ogre_rendersystem_name_ );
        }

        ////////////////////////////////////////////////////////////////////////////////    
        // initialize Root, using our defined RenderSystem
        // (this method returns nullptr, since our argument is 'false')
debug::gl::msg( "ogre_root->initialise" );
        ogre_root->initialise( false ); 


        ////////////////////////////////////////////////////////////////////////////////
        // create an Ogre window, using our existing GLFW window.
        //
        // we find the interesting details we need in the implementation of 
        // OSXCocoaWindow/GLXWind::create()!
        //
        // Ogre doc:
        // externalGLControl: "Let the external window control OpenGL i.e. don't select 
        //                    a pixel format for the window, do not change v-sync and 
        //                    do not swap buffer. When set to true, the calling application 
        //                    is responsible of OpenGL initialization and buffer swapping. 
        //                    It should also create an OpenGL context for its own rendering, 
        //                    Ogre will create one for its use. **Then the calling application 
        //                    must also enable Ogre OpenGL context before calling any Ogre 
        //                    function and restore its OpenGL context after these calls.**"
debug::gl::msg( "ogre_root->createRenderWindow()" );
        Ogre::NameValuePairList params;

#ifdef BATB_BUILD_PLATFORM_LINUX
        // let the created RenderWindow use current context
        params["currentGLContext"] = "true";  // let RenderWindow use our GL context
                                  
        params["externalGLControl"] = "true"; 
#endif

#ifdef BATB_BUILD_PLATFORM_MACOS
        // defaults to "carbon", it segfaults if not set
        params["macAPI"] = "cocoa";

        // let the created RenderWindow use current context
        //
        // OgreOSXCocoaWindow::create() seems to ignore these two in the original code; see
        // OgreOSXCocoaWindow.mm. I've fixed this in our Ogre mirror.
        params["currentGLContext"] = "true";  
        params["externalGLControl"] = "true";  // not used!

        // our Ogre mirror has implemented currentGLContext ans so this is redundatn
        //params["macAPICocoaUseNSView"] = "todo: pointer";
        //params["externalWindowHandle"] = "true"; // must be done in order for "macAPICocoaUseNSView" to trigger
#endif
        // OgreRoot::createRenderWindow() -> XXXRenderSystem::_createRenderWindow() -> XXXGLSupport::newWindow() 
        //                                -> XXXWindow::create(). and this creates XXXContext class too.
        ogre_renderwindow = ogre_root->createRenderWindow( "GLFWRenderWindow", 0, 0, false, &params );
        ogre_renderwindow->setVisible(true);

        ////////////////////////////////////////////////////////////////////////////////
        // Ogre GL context
        // NOTE: must not be setCurrent/set_glfwcontext_ here, since we are loading 
        //       OGRE in another GL context (background thread)
        glcontextglfw_.begin();

    }
    ////////////////////////////////////////////////////////////////////////////////
    
    init( true );


    
}


void OGRE::end()
{
debug::gl::DebugGroup _dbg( DEBUG_FUNCTION_NAME );

    if ( init_nonempty() )
    {
        save();
   
        // needs to be done before modding Ogre, since
        // frameBegin/End may be done in other thread (i.e. main thread)
        init( false );

        
debug::gl::msg( "OGRE_DELETE Root" );
        OGRE_DELETE ogre_root;
debug::gl::msg( "OGRE_DELETE LogManager" );
        OGRE_DELETE ogre_logmanager;

        ogre_root = nullptr;

        // since Ogre steal our GLXContext we have to rebind it after 
        // Ogre shutdown
        glcontextglfw_.setCurrent();
    
        glcontextglfw_.end();

    }
   
}
////////////////////////////////////////////////////////////////////////////////
//  OGRE

void OGRE::frameBegin()
{
    Ogre::RenderTarget* ogre_rendertarget = ogre_renderwindow;
    
    if ( init_nonempty() )
    {
        // ensure we can touch Ogre
        if ( enabled_ )
        {
            batb->gl->ogreBegin();
            ////////////////////////////////////////////////////////////////////////////////
            // look at definition of OgreRoot::renderOneFrame() !!

            // ( bool Root::renderOneFrame(void) )
            ogre_root->_fireFrameStarted();
            
            // void RenderTarget::updateImpl(void)
            ogre_rendertarget->_beginUpdate();

            ////////////////////////////////////////////////////////////////////////////////
            batb->gl->ogreEnd();
        }
    } 

}

void OGRE::frameEnd()
{
    Ogre::RenderTarget* ogre_rendertarget = ogre_renderwindow;
    
    if ( init_nonempty() )
    {
        if ( enabled_ )
        {
            batb->gl->ogreBegin();
            ////////////////////////////////////////////////////////////////////////////////
            // look at definition of OgreRoot::renderOneFrame() !!

            // void RenderTarget::updateImpl(void)
            ogre_rendertarget->_endUpdate();

            // bool Root::_updateAllRenderTargets(void)
            ogre_root->_fireFrameRenderingQueued();
            ogre_rendersystem->_swapAllRenderTargetBuffers();
            for (SceneManagerEnumerator::SceneManagerIterator it = ogre_root->getSceneManagerIterator(); it.hasMoreElements(); it.moveNext()) 
                it.peekNextValue()->_handleLodEvents();

            // bool Root::renderOneFrame(void)
            ogre_root->_fireFrameEnded();
            ////////////////////////////////////////////////////////////////////////////////
            batb->gl->ogreEnd();
        }
    }
}


void OGRE::sceneBegin(const Scene& scene)
{
    // setup ogre
    batb->gl->ogreBegin();

    // tell Ogre the size of our window
    ogre_renderwindow->resize( scene.wth, scene.hth );
  
}

void OGRE::outputCamera(Ogre::Camera* camera)
{
    Ogre::RenderTarget* ogre_rendertarget = ogre_renderwindow;
    
    // void RenderTarget::_updateViewport(Viewport* viewport, bool updateStatistics)

    // render into previous used viewport of camera
    // (typically just 1 viewport)
    auto viewport = camera->getViewport();
    if ( viewport )
    {
        assert(viewport->getTarget() == ogre_rendertarget &&
                "RenderTarget::_updateViewport the requested viewport is "
                "not bound to the ogre_rendertarget!");

        //mCamera->_renderScene(this, mShowOverlays);
        bool mShowOverlays = viewport->getOverlaysEnabled();
        camera->_renderScene( viewport, mShowOverlays );
    }
}


void OGRE::outputViewport(Ogre::Viewport* viewport)
{
    Ogre::RenderTarget* ogre_rendertarget = ogre_renderwindow;
    
    // void RenderTarget::_updateViewport(Viewport* viewport, bool updateStatistics)
    {
        assert(viewport->getTarget() == ogre_rendertarget &&
                "RenderTarget::_updateViewport the requested viewport is "
                "not bound to the ogre_rendertarget!");

        //fireViewportPreUpdate(viewport);
        viewport->update();
        //if(updateStatistics)
        //{
        //    mStats.triangleCount += viewport->_getNumRenderedFaces();
        //    mStats.batchCount += viewport->_getNumRenderedBatches();
        //}
        //fireViewportPostUpdate(viewport);
    }

}

void OGRE::sceneEnd()
{


    // set back our context
    set_glfwcontext_();

    // reset gl-state after Ogre, for this framd
    batb->gl->ogreEnd();
}


void OGRE::output(const Scene& scene)
{
debug::gl::DebugGroup _dbg( DEBUG_FUNCTION_NAME );


    if ( init_nonempty() )
    {
        sceneBegin( scene );

        Ogre::WindowEventUtilities::messagePump(); // TODO: remove this, since we use GLFW! (?)
        
debug::gl::msg( "ogre_root->renderOneFrame();" );
        ogre_root->renderOneFrame();

        sceneEnd();
    }
}

////////////////////////////////////////////////////////////////////////////////
// 
// NB: only static currently!
void OGRE::addResourceLocation(const YAML::Node& yaml)
{
    // begin GL state for Ogre
    // FIXME: necessary?
    batb->gl->ogreBegin();

    // iterate over group names
    for (auto i = std::begin( yaml ); i != std::end( yaml ); ++i )
    {
        // NOTE: yaml is a map, not a list. and 'i' is a key. 
        //       this is yaml stuff (scalar, list, map)
        YAML::Node group = i->first;
        std::string name = group.as<std::string>();
        
        batb->log << "OGRE: adding items to resource group '" << name << "':\n";
        // iterate over defined content for that group
        for (auto j = std::begin( i->second ); j != std::end( i->second ); ++j )
        {
            batb->log << "  ";

            YAML::Node resource = *j;
            if ( resource[ "type" ] && resource[ "path" ] )
            {
                std::string type = resource[ "type" ].as<std::string>();
                std::string path = resource[ "path" ].as<std::string>();
                
                batb->log << path;

                // add resource item
                try
                {
                    ogre_root->addResourceLocation(  file::static_data( path ), type, name );
                }
                catch (Ogre::Exception& e)
                {
                    batb->log << " (" << e.what() << ")";
                }

            }
            else
            {
                batb->log << "(invalid item definition)";
            }
            
            batb->log << "\n";
        }
    }

    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

    batb->gl->ogreEnd();
}

void OGRE::enabled(bool e)
{ 
    enabled_ = e; 
}



void OGRE::set_glfwcontext_()
{
debug::gl::DebugGroup _dbg( DEBUG_FUNCTION_NAME );
    // TODO: GL vs GL3Plus
    //
    Ogre::GLRenderSystem* rs = static_cast<Ogre::GLRenderSystem*>( ogre_rendersystem );

    rs->_switchContext( &glcontextglfw_ );

}

} // namespace ogre

} // namespace batb
