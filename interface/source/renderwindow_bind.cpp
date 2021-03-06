/*     __ __              _ 
 *    / // /_____ ____   (_)
 *   / // // ___// __ \ / / 
 *  / // // /__ / /_/ // /  
 * /_//_/ \___/ \____//_/   
 * https://bitbucket.org/galaktor/llcoi 
 * copyright (c) 2011, llcoi Team
 * MIT license applies - see file "LICENSE" for details.
*/
#include "renderwindow_bind.h"

#include <OgreRoot.h>
#include <OgreRenderWindow.h>

ViewportHandle add_viewport(RenderWindowHandle window_handle, CameraHandle camera_handle)
{
  Ogre::RenderWindow* window = reinterpret_cast<Ogre::RenderWindow*>(window_handle);
  Ogre::Camera* camera = reinterpret_cast<Ogre::Camera*>(camera_handle);
  Ogre::Viewport* vp = window->addViewport(camera);
  return reinterpret_cast<ViewportHandle>(vp);
}

void render_window_set_visible(RenderWindowHandle window_handle, int visible)
{
  Ogre::RenderWindow* window = reinterpret_cast<Ogre::RenderWindow*>(window_handle);
  window->setActive(true);
  window->setVisible(visible);
}

unsigned int render_window_get_hwnd(RenderWindowHandle window_handle)
{
  size_t windowHnd = 0;
  Ogre::RenderWindow* window = reinterpret_cast<Ogre::RenderWindow*>(window_handle);
  window->getCustomAttribute("WINDOW", &windowHnd);
  return windowHnd;
}

void render_window_update(RenderWindowHandle window_handle, int swap_buffers)
{
  Ogre::RenderWindow* window = reinterpret_cast<Ogre::RenderWindow*>(window_handle);
  window->update(swap_buffers);
}


void render_window_resize(RenderWindowHandle window_handle, unsigned int width, unsigned int height)
{
  Ogre::RenderWindow* window = reinterpret_cast<Ogre::RenderWindow*>(window_handle);
  window->resize(width, height);
}

void render_window_reposition(RenderWindowHandle window_handle, int left, int top)
{
  Ogre::RenderWindow* window = reinterpret_cast<Ogre::RenderWindow*>(window_handle);
  window->reposition(left, top);
}

void render_window_moved_or_resized(RenderWindowHandle window_handle)
{
  Ogre::RenderWindow* window = reinterpret_cast<Ogre::RenderWindow*>(window_handle);
  window->windowMovedOrResized();
}

int render_window_closed(RenderWindowHandle window_handle)
{
  Ogre::RenderWindow* window = reinterpret_cast<Ogre::RenderWindow*>(window_handle);
  if(window->isClosed())
    return 1;
  return 0;
}


// Rendertarget->addViewport 
ViewportHandle render_window_add_viewport(RenderWindowHandle window_handle, CameraHandle camera_handle, int zorder, float left, float top, float width, float height)
{
    Ogre::RenderWindow* window = reinterpret_cast<Ogre::RenderWindow*>(window_handle);
    Ogre::Camera* camera = reinterpret_cast<Ogre::Camera*>(camera_handle);
    return reinterpret_cast<ViewportHandle>(window->addViewport(camera, zorder, left, top, width, height));
}

// RenderWindow::isClosed
int render_window_is_closed(RenderWindowHandle handle)
{
    Ogre::RenderWindow* window = reinterpret_cast<Ogre::RenderWindow*>(handle);
    if (window->isClosed())
        return 1;
    return 0;
}

void render_window_set_active(RenderWindowHandle handle, int state)
{
    Ogre::RenderWindow* window = reinterpret_cast<Ogre::RenderWindow*>(handle);
    window->setActive(state);
}

void render_window_swap_buffers(RenderWindowHandle handle)
{
    Ogre::RenderWindow* window = reinterpret_cast<Ogre::RenderWindow*>(handle);
    window->swapBuffers();
}

void render_window_get_custom_attribute(RenderWindowHandle handle, const char* attribute, void* pdata)
{
    Ogre::RenderWindow* window = reinterpret_cast<Ogre::RenderWindow*>(handle);
    window->getCustomAttribute(attribute, pdata);
}

unsigned int render_window_get_width(RenderWindowHandle handle)
{
    Ogre::RenderWindow* window = reinterpret_cast<Ogre::RenderWindow*>(handle);
    return window->getWidth();
}

unsigned int render_window_get_height(RenderWindowHandle handle)
{
    Ogre::RenderWindow* window = reinterpret_cast<Ogre::RenderWindow*>(handle);
    return window->getHeight();
}

void renderwindow_get_statistics(RenderWindowHandle handle, FrameStats* stats)
{
    Ogre::RenderWindow* window = reinterpret_cast<Ogre::RenderWindow*>(handle);
    const Ogre::RenderTarget::FrameStats& fs = window->getStatistics();

    stats->lastFPS         = fs.lastFPS;
    stats->avgFPS          = fs.avgFPS;
    stats->bestFPS         = fs.bestFPS;
    stats->worstFPS        = fs.worstFPS;
    stats->bestFrameTime   = fs.bestFrameTime;
    stats->worstFrameTime  = fs.worstFrameTime;
    stats->triangleCount   = fs.triangleCount;
    stats->batchCount      = fs.batchCount;
}

void renderwindow_get_statistics_ex(RenderWindowHandle handle, float* lastFPS, float* avgFPS, float* bestFPS, float* worstFPS)
{
    Ogre::RenderWindow* window = reinterpret_cast<Ogre::RenderWindow*>(handle);
    window->getStatistics(*lastFPS, *avgFPS, *bestFPS, *worstFPS);
}

/*
Ogre::RenderWindow::operator=(Ogre::RenderWindow const&)
Ogre::RenderWindow::RenderWindow(Ogre::RenderWindow const&)
Ogre::RenderWindow::RenderWindow()
Ogre::RenderWindow::create(std::string const&, unsigned int, unsigned int, bool, std::map<std::string, std::string, std::less<std::string>, Ogre::STLAllocator<std::pair<std::string const, std::string>, Ogre::CategorisedAllocPolicy<(Ogre::MemoryCategory)0> > > const*)
Ogre::RenderWindow::setFullscreen(bool, unsigned int, unsigned int)
Ogre::RenderWindow::destroy()
Ogre::RenderWindow::resize(unsigned int, unsigned int)
Ogre::RenderWindow::windowMovedOrResized()
Ogre::RenderWindow::reposition(int, int)
Ogre::RenderWindow::isVisible() const
Ogre::RenderWindow::setVisible(bool)
Ogre::RenderWindow::isHidden() const
Ogre::RenderWindow::setHidden(bool)
Ogre::RenderWindow::setVSyncEnabled(bool)
Ogre::RenderWindow::isVSyncEnabled() const
Ogre::RenderWindow::setVSyncInterval(unsigned int)
Ogre::RenderWindow::getVSyncInterval() const
Ogre::RenderWindow::isActive() const
Ogre::RenderWindow::isClosed() const
Ogre::RenderWindow::isPrimary() const
Ogre::RenderWindow::isFullScreen() const
Ogre::RenderWindow::getMetrics(unsigned int&, unsigned int&, unsigned int&, int&, int&)
Ogre::RenderWindow::suggestPixelFormat() const
Ogre::RenderWindow::isDeactivatedOnFocusChange() const
Ogre::RenderWindow::setDeactivateOnFocusChange(bool)
Ogre::RenderWindow::~RenderWindow()
*/
