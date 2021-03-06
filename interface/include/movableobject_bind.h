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

/* As this is an abstract object, no need for construction. */
///~MovableObject();
DLL void destroy_movableobject(MovableObjectHandle handle);
///TODO: void _notifyCreator(MovableObjectFactory* fact);
///TODO: MovableObjectFactory*  _getCreator(void) const;
///void _notifyManager(SceneManager* man);
DLL void movableobject__notify_manager(MovableObjectHandle handle, SceneManagerHandle man);
///SceneManager* _getManager(void) const;
DLL SceneManagerHandle movableobject__get_manager(const MovableObjectHandle handle);
///const String& getName(void) const;
DLL const char* movableobject_get_name(const MovableObjectHandle handle);
///const String& getMovableType(void) const = 0;
DLL const char* movableobject_get_movable_type(const MovableObjectHandle handle);
///Node* getParentNode(void) const;
DLL NodeHandle movableobject_get_parent_node(const MovableObjectHandle handle);
///SceneNode* getParentSceneNode(void) const;
DLL SceneNodeHandle movableobject_get_parent_scene_node(const MovableObjectHandle handle);
///bool isParentTagPoint() const;
DLL int movableobject_is_parent_tag_point(const MovableObjectHandle handle);
///void _notifyAttached(Node* parent, bool isTagPoint = false);
DLL void movableobject__notify_attached(MovableObjectHandle handle, NodeHandle parent, int is_tag_point);
///bool isAttached(void) const;
DLL int movableobject_is_attached(const MovableObjectHandle handle);
///void detachFromParent(void);
DLL void movableobject_detach_from_parent(MovableObjectHandle handle);
///bool isInScene(void) const;
DLL int movableobject_is_in_scene(const MovableObjectHandle handle); 
///void _notifyMoved(void);
DLL void movableobject__notify_moved(MovableObjectHandle handle);
///void _notifyCurrentCamera(Camera* cam);
DLL void movableobject__notify_current_camera(MovableObjectHandle handle, CameraHandle cam);
///const AxisAlignedBox& getBoundingBox(void) const = 0;
DLL AxisAlignedBoxHandle movableobject_get_bounding_box(const MovableObjectHandle handle);
///Real getBoundingRadius(void) const = 0;
DLL coiReal movableobject_get_bounding_radius(const MovableObjectHandle handle);
///const AxisAlignedBox& getWorldBoundingBox(bool derive = false) const;
DLL AxisAlignedBoxHandle movableobject_get_world_bounding_box(const MovableObjectHandle handle, int derive);
///const Sphere& getWorldBoundingSphere(bool derive = false) const;
DLL SphereHandle movableobject_get_world_bounding_sphere(const MovableObjectHandle handle, int derive);
///void _updateRenderQueue(RenderQueue* queue) = 0;
//TODO:DLL void movableobject__update_render_queue(MovableObjectHandle handle, RenderQueueHandle queue);
///void setVisible(bool visible);
DLL void movableobject_set_visible(MovableObjectHandle handle, int visible);
///bool getVisible(void) const;
DLL int movableobject_get_visible(const MovableObjectHandle handle);
///bool isVisible(void) const;
DLL int movableobject_is_visible(const MovableObjectHandle handle);
///void setRenderingDistance(Real dist);
DLL void movableobject_set_rendering_distance(MovableObjectHandle handle, coiReal dist);
///Real getRenderingDistance(void) const;
DLL coiReal movableobject_get_rendering_distance(const MovableObjectHandle handle);
///void setRenderingMinPixelSize(Real pixelSize);
DLL void movableobject_set_rendering_min_pixel_size(MovableObjectHandle handle, coiReal pixel_size);
///Real getRenderingMinPixelSize() const;
DLL coiReal movableobject_get_rendering_min_pixel_size(const MovableObjectHandle handle); 
//void setUserAny(const Any& anything); XXX: deprecated
//const Any& getUserAny(void) const; XXX: deprecated
///UserObjectBindings&	getUserObjectBindings();
///const UserObjectBindings& getUserObjectBindings() const;
///void setRenderQueueGroup(uint8 queueID);
DLL void movableobject_set_render_queue_group(MovableObjectHandle handle, unsigned char queue_id);
///void setRenderQueueGroupAndPriority(uint8 queueID, ushort priority);
DLL void movableobject_set_render_queue_group_and_priority(MovableObjectHandle handle, unsigned char queue_id, unsigned short priority);
///uint8 getRenderQueueGroup(void) const;
DLL unsigned char movableobject_get_render_queue_group(const MovableObjectHandle handle); 
///const Matrix4& _getParentNodeFullTransform(void) const;
DLL void movableobject__get_parent_node_full_transform(const MovableObjectHandle handle, coiMatrix4* result);
///void setQueryFlags(uint32 flags);
DLL void movableobject_set_query_flags(MovableObjectHandle handle, unsigned int flags);
///void addQueryFlags(uint32 flags);
DLL void movableobject_add_query_flags(MovableObjectHandle handle, unsigned int flags);
///void removeQueryFlags(uint32 flags);
DLL void movableobject_remove_query_flags(MovableObjectHandle handle, unsigned int flags);
///uint32 getQueryFlags(void) const;
DLL unsigned int movableobject_get_query_flags(const MovableObjectHandle handle); 
///static void setDefaultQueryFlags(uint32 flags);
DLL void movableobject_set_default_query_flags(unsigned int flags);
///static uint32 getDefaultQueryFlags();
DLL unsigned int movableobject_get_default_query_flags();
///void setVisibilityFlags(uint32 flags)
DLL void movableobject_set_visibility_flags(MovableObjectHandle handle, unsigned int flags);
///void addVisibilityFlags(uint32 flags);
DLL void movableobject_add_visibility_flags(MovableObjectHandle handle, unsigned int flags);
///void removeVisibilityFlags(uint32 flags);
DLL void movableobject_remove_visibility_flags(MovableObjectHandle handle, unsigned int flags);
///uint32 getVisibilityFlags(void) const;
DLL unsigned int movableobject_get_visibility_flags(const MovableObjectHandle handle); 
///static void setDefaultVisibilityFlags(uint32 flags);
DLL void movableobject_set_default_visibility_flags(unsigned int flags);
///static uint32 getDefaultVisibilityFlags();
DLL unsigned int movableobject_get_default_visibility_flags();
///void setListener(Listener* listener);
//movableobject_set_listener(MovableObjectHandle handle, 
///Listener* getListener(void) const;
//movableobject_get_listener(MovableObjectHandle handle, 
///const LightList& queryLights(void) const;
DLL size_t movableobject_query_lights(const MovableObjectHandle handle, LightHandle result);
///uint32 getLightMask() const;
DLL unsigned int movableobject_get_light_mask(const MovableObjectHandle handle); 
///void setLightMask(uint32 lightMask);
DLL void movableobject_set_light_mask(MovableObjectHandle handle, unsigned int light_mask);
///LightList* _getLightList();
///EdgeData* getEdgeList(void);
///bool hasEdgeList(void);
DLL int movableobject_has_edge_list(MovableObjectHandle handle);
///ShadowRenderableListIterator getShadowVolumeRenderableIterator(ShadowTechnique shadowTechnique, const Light* light, HardwareIndexBufferSharedPtr* indexBuffer,  bool extrudeVertices, Real extrusionDist, unsigned long flags = 0);
///const AxisAlignedBox& getLightCapBounds(void) const;
DLL AxisAlignedBoxHandle movableobject_get_light_cap_bounds(const MovableObjectHandle handle); 
///const AxisAlignedBox& getDarkCapBounds(const Light& light, Real dirLightExtrusionDist) const;
DLL AxisAlignedBoxHandle movableobject_get_dark_cap_bounds(const MovableObjectHandle handle, const LightHandle light, coiReal dir_light_extrusion_dist);
///void setCastShadows(bool enabled);
DLL void movableobject_set_cast_shadows(MovableObjectHandle handle, int enabled);
///bool getCastShadows(void) const;
DLL int movableobject_get_cast_shadows(const MovableObjectHandle handle); 
///bool getReceivesShadows();
DLL int movableobject_get_receives_shadows(MovableObjectHandle handle);
///Real getPointExtrusionDistance(const Light* l) const;
DLL coiReal movableobject_get_point_extrusion_distance(const MovableObjectHandle handle, const LightHandle l);
///uint32 getTypeFlags(void) const;
DLL unsigned int movableobject_get_type_flags(const MovableObjectHandle handle);
///void visitRenderables(Renderable::Visitor* visitor,bool debugRenderables = false) = 0;
///void setDebugDisplayEnabled(bool enabled);
DLL void movableobject_set_debug_display_enabled(MovableObjectHandle handle, int enabled);
///bool isDebugDisplayEnabled(void) const;
DLL int movableobject_is_debug_display_enabled(const MovableObjectHandle handle); 
