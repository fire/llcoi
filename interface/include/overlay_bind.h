/*     __ __              _ 
 *    / // /_____ ____   (_)
 *   / // // ___// __ \ / / 
 *  / // // /__ / /_/ // /  
 * /_//_/ \___/ \____//_/   
 * https://bitbucket.org/galaktor/llcoi 
 * copyright (c) 2011, llcoi Team
 * MIT license applies - see file "LICENSE" for details.
*/
#pragma once

#include "ogre_interface.h"

//const String& getName(void) const;
DLL const char* overlay_get_name(OverlayHandle handle);
//void setZOrder(ushort zorder);
DLL void overlay_set_zorder(OverlayHandle handle, unsigned short zorder);
//ushort getZOrder(void) const;
DLL unsigned short overlay_get_zorder(OverlayHandle handle);
//bool isVisible(void) const;
DLL int overlay_is_visible(OverlayHandle handle);
//bool isInitialised(void) const;
DLL int overlay_is_initialised(OverlayHandle handle);
//void show(void);
DLL void overlay_show(OverlayHandle handle);
//void hide(void);
DLL void overlay_hide(OverlayHandle handle);
//void add2D(OverlayContainer* cont);
DLL void overlay_add_2d(OverlayHandle handle, OverlayContainerHandle cont);
//void remove2D(OverlayContainer* cont);
DLL void overlay_remove_2d(OverlayHandle handle, OverlayContainerHandle cont);
//void add3D(SceneNode* node);
DLL void overlay_add_3d(OverlayHandle handle, SceneNodeHandle node_handle);
//void remove3D(SceneNode* node);
DLL void overlay_remove_3d(OverlayHandle handle, SceneNodeHandle node_handle);
// void clear();
DLL void overlay_clear(OverlayHandle handle);
//void setScroll(Real x, Real y);
DLL void overlay_set_scroll(OverlayHandle handle, coiReal x, coiReal y);
//Real getScrollX(void) const;
DLL coiReal overlay_get_scroll_x(OverlayHandle handle);
//Real getScrollY(void) const;
DLL coiReal overlay_get_scroll_y(OverlayHandle handle);
//void scroll(Real xoff, Real yoff);
DLL void overlay_scroll(OverlayHandle handle, coiReal x, coiReal y);
//void setRotate(const Radian& angle);
DLL void overlay_set_rotate(OverlayHandle handle, coiReal angle);
//const Radian &getRotate(void) const;
DLL coiReal overlay_get_rotate(OverlayHandle handle);
//void rotate(const Radian& angle);
DLL void overlay_rotate(OverlayHandle handle, coiReal angle);
//void setScale(Real x, Real y);
DLL void overlay_set_scale(OverlayHandle handle, coiReal x, coiReal y);
//Real getScaleX(void) const;
DLL coiReal overlay_get_scale_x(OverlayHandle handle);
//Real getScaleY(void) const;
DLL coiReal overlay_get_scale_y(OverlayHandle handle);
//void _getWorldTransforms(Matrix4* xform) const;
DLL void overlay_get_world_transforms(OverlayHandle handle, coiMatrix4* xform);
//void _findVisibleObjects(Camera* cam, RenderQueue* queue);
//OverlayElement* findElementAt(Real x, Real y);
//const String& getOrigin(void) const;
DLL const char * overlay_get_origin(OverlayHandle handle);
//void _notifyOrigin(const String& origin);
DLL void overlay_notify_origin(OverlayHandle handle, const char* origin);
