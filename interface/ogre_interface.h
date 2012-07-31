/******************************************************************************
 * ogre_interface.h - main include file for C clients
 ******************************************************************************
 * This file is part of
 *     __ __              _ 
 *    / // /_____ ____   (_)
 *   / // // ___// __ \ / / 
 *  / // // /__ / /_/ // /  
 * /_//_/ \___/ \____//_/   
 *                          
 * Low Level C Ogre Interface (llcoi)
 *
 * See http://code.google.com/p/llcoi/ for more information.
 *
 * Copyright (c) 2011, Llcoi Team
 * 
 * License: MIT
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/
#pragma once
#ifndef LLCOI_OGRE_INTERFACE
#define LLCOI_OGRE_INTERFACE

// Detect platform
#if defined( WINCE )
#   if !defined( PLATFORM_WIN_CE )
#       define PLATFORM_WIN_CE
#   endif
#elif defined( WIN32 ) || defined( _WINDOWS )
#   if !defined( PLATFORM_WIN )
#       define PLATFORM_WIN
#   endif
#elif defined( __APPLE__ ) || defined( __APPLE_CC__ )
#   if !defined( PLATFORM_MAC )
#      define PLATFORM_MAC
#   endif
#else
#   if !defined( PLATFORM_LINUX )
#       define PLATFORM_LINUX
#   endif
#endif

#if defined(LLCOI_BUILD_DYNAMIC)
#   if defined( WIN32 ) || defined( _WINDOWS )
#       ifndef llcoi_EXPORTS
#           define DLL __declspec(dllimport)
#       else
#           define DLL extern "C" __declspec(dllexport)
#       endif
#   else
#       ifndef llcoi_EXPORTS
#           define DLL
#       else
#           if defined( __GNUC__ ) && __GNUC__ >= 4
#               define DLL extern "C" __attribute__ ((visibility("default")))
#           else
#               define DLL extern "C"
#           endif
#       endif
#   endif
#else
#   if defined( LLCOI_BUILD_STATIC )
#       if defined( __GNUC__ ) && __GNUC__ >= 4
#           define DLL extern "C" __attribute__ ((visibility("default")))
#       else
#           define DLL extern "C"
#       endif
#   else
#       define DLL
#   endif
#endif

#include <stddef.h> // for size_t

//defines

#define coiReal float

#define EVENT_FRAME_STARTED 1
#define EVENT_FRAME_RENDERING_QUEUED 2
#define EVENT_FRAME_ENDED 4


#define COI_DECLARE_HANDLE(name) struct name##__ { int unused; }; typedef struct name##__ *name

// COI_DECLARE_HANDLE(CameraHandle);
// COI_DECLARE_HANDLE(EntityHandle);
// COI_DECLARE_HANDLE(SceneNodeHandle);
// COI_DECLARE_HANDLE(LightHandle);
// COI_DECLARE_HANDLE(RenderWindowHandle);
// COI_DECLARE_HANDLE(RootHandle);
// COI_DECLARE_HANDLE(RenderSystemHandle);
// COI_DECLARE_HANDLE(SceneManagerHandle);
// COI_DECLARE_HANDLE(ViewportHandle);

#define CameraHandle void*
#define EntityHandle void*
#define SceneNodeHandle void*
#define LightHandle void*
#define RenderWindowHandle void*
#define RootHandle void*
#define RenderSystemHandle void*
#define RenderSystemListHandle void*
#define SceneManagerHandle void*
#define ViewportHandle void*
#define LogManagerHandle void*
#define LogHandle void*
#define LogListenerHandle void*
#define NameValuePairListHandle void*
#define FrameListenerHandle void*
#define PlaneHandle void*
#define MeshHandle void*

// listener typedefs
typedef int(*FrameListenerEvent)(float,float,int);
typedef void(*WindowListenerEvent)(RenderWindowHandle);

// From OgrePlatform.h
typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;
typedef int int32;
typedef short int16;
typedef char int8;

// OgreColourValue.h
typedef uint32 RGBA;
typedef uint32 ARGB;
typedef uint32 ABGR;
typedef uint32 BGRA;

// OgreSceneManager.h
typedef uint16 SceneTypeMask;

typedef struct
{
    float w;
    float x;
    float y;
    float z;
} coiQuaternion;

typedef struct
{
    float x;
    float y;
    float z;
} coiVector3;

typedef struct
{
    coiVector3 position;
    coiQuaternion orientation;
} ViewPoint;

typedef struct
{
    coiReal time_since_last_event;
    coiReal time_since_last_frame;
} FrameEvent;

typedef struct
{
    float r;
    float g;
    float b;
    float a;
} ColourValue;

typedef struct
{
    const char* renderer_s;
    const char* plugin_folder_s;
    const char* window_title;
    const char* log_name;
    int width, height, auto_window;
} engine_options;

typedef struct
{
    float lastFPS;
    float avgFPS;
    float bestFPS;
    float worstFPS;
    unsigned long bestFrameTime;
    unsigned long worstFrameTime;
    size_t triangleCount;
    size_t batchCount;
} FrameStats;


typedef enum
{
    LL_LOW = 1,
    LL_NORMAL = 2,
    LL_BOREME = 3
} logging_level;

typedef enum
{
    LML_TRIVIAL = 1,
    LML_NORMAL = 2,
    LML_CRITICAL = 3
} log_message_level;

typedef enum
{
    SF_NONE           = 0,
    SF_FPS            = 1,
    SF_AVG_FPS        = 2,
    SF_BEST_FPS       = 4,
    SF_WORST_FPS      = 8,
    SF_TRIANGLE_COUNT = 16,
    SF_ALL            = 0xFFFF
} stat_flags;

typedef enum
{
    FB_FRONT,
    FB_BACK,
    FB_AUTO
} frame_buffer;

typedef enum
{
    ST_GENERIC = 1,
    ST_EXTERIOR_CLOSE = 2,
    ST_EXTERIOR_FAR = 4,
    ST_EXTERIOR_REAL_FAR = 8,
    ST_INTERIOR = 16
} scene_type;

typedef enum
{
    NO_SIDE,
    POSITIVE_SIDE,
    NEGATIVE_SIDE,
    BOTH_SIDE
} plane_side;

typedef enum 
{
    HBU_STATIC = 1,
    HBU_DYNAMIC = 2,
    HBU_WRITE_ONLY = 4,
    HBU_DISCARDABLE = 8,
    HBU_STATIC_WRITE_ONLY = 5, 
    HBU_DYNAMIC_WRITE_ONLY = 6,
    HBU_DYNAMIC_WRITE_ONLY_DISCARDABLE = 14
} hardware_buffer_usage;


typedef enum
{
    LT_POINT = 0,
    LT_DIRECTIONAL = 1,
    LT_SPOTLIGHT = 2
} light_types;


typedef enum
{
    TS_LOCAL,
    TS_PARENT,
    TS_WORLD
} transform_space;



typedef void(*LogListenerEvent)(const char* message, log_message_level lml, int maskDebug, const char* log_name, int skip_message);

// Same as LogListenerEvent but allows the client to
// send additional data via a void pointer. We assume the
// client knows what they're doing if they use this. (:
typedef void(*LogListenerCtx)(const char* message, log_message_level lml, int maskDebug, const char* log_name, int skip_message, void* userdata);


// Again, variation of FrameListenerEvent
typedef int(*FrameListenerCtx)(const FrameEvent* event, int evt_type, void* userdata);

// Root functions
DLL void release_engine();

DLL void default_engine_options(engine_options* options);

DLL void init_engine(const engine_options options);

DLL RootHandle create_root(const char* pluginFileName, const char* configFileName, const char* logFileName);

DLL RenderWindowHandle root_initialise(int auto_create_window, const char* render_window_title);

DLL RenderWindowHandle create_render_window(const char* name, const int width, const int height, const int full_screen);

DLL RenderWindowHandle create_render_window_gl_context(const char* name, const int width, const int height, const int full_screen);

DLL RenderWindowHandle create_render_window_hwnd(const char* name, const int width, const int height, const int full_screen, unsigned long hwnd);

DLL unsigned int render_window_get_hwnd(RenderWindowHandle window_handle);

DLL void render_window_set_visible(RenderWindowHandle window_handle, int visible);

DLL void render_window_update(RenderWindowHandle window_handle, int swap_buffers);

DLL void current_window_update(int swap_buffers);

DLL void render_window_resize(unsigned int width, unsigned int height);

DLL void render_window_moved_or_resized();

DLL int render_window_closed();

DLL int root_is_initialised();

DLL void save_config();

DLL int restore_config();

DLL int show_config_dialog();

DLL void load_ogre_plugin(const char * plugin);

// Doesn't use OgreManager. Can still throw if type_name doesn't exist.
DLL SceneManagerHandle root_create_scene_manager(const char* type_name, const char* instance_name);

// Doesn't use OgreManager. If a specific scene manager is not found,
// the default implementation is always returned.
DLL SceneManagerHandle root_create_scene_manager_by_mask(SceneTypeMask type_mask, const char* instance_name);

// Does use OgreManager.
DLL SceneManagerHandle create_scene_manager(const char* type_name, const char* instance_name);

DLL SceneManagerHandle get_scene_manager();

DLL SceneManagerHandle get_scene_manager_by_name(const char* scene_manager_instance_name);

DLL int render_one_frame();

DLL int render_one_frame_ex(float time_since_last_frame);

DLL void render_loop();

DLL void pump_messages();

DLL void log_message(const char* message);

DLL RenderWindowHandle root_create_render_window(const char* name, unsigned int width, unsigned int height, int fullscreen, NameValuePairListHandle params);

DLL RenderSystemListHandle root_get_available_renderers();

// Ogre::SceneManager calls
DLL EntityHandle scenemanager_create_entity(SceneManagerHandle handle, const char* name, const char* mesh_name, const char* group_name);

DLL SceneNodeHandle scenemanager_get_root_scene_node(SceneManagerHandle handle);

DLL LightHandle scenemanager_create_light(SceneManagerHandle handle, const char* name);

DLL void scenemanager_set_sky_box(SceneManagerHandle handle, int enable, const char* material_name, float distance,
                                  int draw_first, const coiQuaternion* orientation,
                                  const char* group_name);

DLL void scenemanager_set_sky_dome(SceneManagerHandle handle, int enable, const char* material_name, float curvature,
                               float tiling, float distance, int draw_first, const coiQuaternion* orientation,
                               int xsegments, int ysegments, int ysegments_keep, const char* group_name);
// RenderSystem functions
DLL void set_render_system(RenderSystemHandle render_system);

DLL void add_render_system(RenderSystemHandle render_system);

DLL RenderSystemHandle get_render_system();

DLL RenderSystemHandle get_render_system_by_name(const char* render_system_name);

DLL const char * render_system_get_name(RenderSystemHandle handle);

DLL void render_system_set_config_option(RenderSystemHandle render_system_handle, const char* option, const char* value);

DLL unsigned int render_system_list_size(RenderSystemListHandle list_handle);

DLL RenderSystemHandle render_system_list_get(RenderSystemListHandle list_handle, unsigned int index);

DLL void destroy_render_system_list(RenderSystemListHandle handle);


// SceneManager functions
DLL void set_default_num_mipmaps(int number);

DLL void set_ambient_light_rgba(const float r, const float g, const float b, const float a);

DLL void set_ambient_light_rgb(const float r, const float g, const float b);

DLL ViewportHandle add_viewport(CameraHandle camera_handle);

DLL void scene_manager_log_name();

// Scene nodes
DLL SceneNodeHandle create_child_scenenode(const char* node_name);

DLL void attach_entity_to_scenenode(EntityHandle entity_handle, SceneNodeHandle scenenode_handle);

DLL void scenenode_update(SceneNodeHandle scenenode_handle, int update_children, int parent_has_changed);

DLL void scenenode_update_bounds(SceneNodeHandle scenenode_handle);

DLL EntityHandle scenenode_get_attached_entity_int(SceneNodeHandle scenenode_handle, int entity_index);

DLL EntityHandle scenenode_get_attached_entity(SceneNodeHandle scenenode_handle, const char* entity_name);

DLL int scenenode_num_attached_objects(SceneNodeHandle scenenode_handle);

DLL void scenenode_detach_entity_int(SceneNodeHandle scenenode_handle, int entity_index);

DLL void scenenode_detach_entity(SceneNodeHandle scenenode_handle, EntityHandle entity_handle);

DLL void scenenode_detach_entity_string(SceneNodeHandle scenenode_handle, const char* entity_name);

DLL void scenenode_detach_all_objects(SceneNodeHandle scenenode_handle);

DLL int scenenode_is_in_scenegraph(SceneNodeHandle scenenode_handle);

DLL void scenenode_notify_rootnode(SceneNodeHandle scenenode_handle);

DLL void scenenode_show_boundingbox(SceneNodeHandle scenenode_handle, int show_boundingbox);

DLL void scenenode_hide_boundingbox(SceneNodeHandle scenenode_handle, int hide_boundingbox);

DLL int scenenode_get_show_boundingbox(SceneNodeHandle scenenode_handle);

DLL SceneNodeHandle scenenode_get_parent_scenenode(SceneNodeHandle scenenode_handle);

DLL void scenenode_set_visible(SceneNodeHandle scenenode_handle, int visible);

DLL void scenenode_set_visible_ex(SceneNodeHandle scenenode_handle, int visible, int cascade);

DLL void scenenode_flip_visibility(SceneNodeHandle scenenode_handle);

DLL void scenenode_flip_visibility_ex(SceneNodeHandle scenenode_handle, int cascade);

DLL void scenenode_set_debug_display_enabled(SceneNodeHandle scenenode_handle, int enabled);

DLL void scenenode_set_debug_display_enabled_ex(SceneNodeHandle scenenode_handle, int enabled, int cascade);

DLL SceneManagerHandle scenenode_get_creator(SceneNodeHandle scenenode_handle);

DLL void scenenode_set_direction(SceneNodeHandle scenenode_handle, float x, float y, float z);

DLL void scenenode_set_orientation(SceneNodeHandle scenenode_handle, float w, float x, float y, float z);

DLL void scenenode_set_position(SceneNodeHandle scenenode_handle, float x, float y, float z);

DLL void scenenode_yaw_degree(SceneNodeHandle handle, coiReal angle);

DLL void scenenode_yaw(SceneNodeHandle scenenode_handle, coiReal radians);

DLL void scenenode_set_scale(SceneNodeHandle scenenode_handle, float x, float y, float z);

DLL void scenenode_scale(SceneNodeHandle scenenode_handle, float x, float y, float z);

DLL void scenenode_translate(SceneNodeHandle scenenode_handle, float x, float y, float z);

DLL void scenenode_roll(SceneNodeHandle scenenode_handle, coiReal radians);

DLL void scenenode_pitch(SceneNodeHandle scenenode_handle, coiReal radians);

DLL SceneNodeHandle scenenode_create_child_scenenode(SceneNodeHandle handle, const char* name, const coiVector3* translate, const coiQuaternion* rotate);


// Viewports
DLL void viewport_set_background_colour(ViewportHandle viewport_handle, float r, float g, float b, float a);

DLL void viewport_set_background_colour_cv(ViewportHandle viewport_handle, ColourValue* cv);

DLL void viewport_set_auto_updated(ViewportHandle handle, int autoupdate);

DLL int viewport_is_auto_updated(ViewportHandle handle);

DLL float viewport_get_top(ViewportHandle handle);

DLL float viewport_get_left(ViewportHandle handle);

DLL float viewport_get_width(ViewportHandle viewport_handle);

DLL float viewport_get_height(ViewportHandle viewport_handle);

DLL int viewport_get_actual_top(ViewportHandle handle);

DLL int viewport_get_actual_left(ViewportHandle handle);

DLL int viewport_get_actual_width(ViewportHandle handle);

DLL int viewport_get_actual_height(ViewportHandle handle);


// Resource management
DLL void setup_resources(const char* resources_cfg);

DLL void add_resource_location(const char* location, const char* type, const char* group);

DLL const char * resourcegroupmanager_DEFAULT_RESOURCE_GROUP_NAME();
DLL const char * resourcegroupmanager_INTERNAL_RESOURCE_GROUP_NAME();
DLL const char * resourcegroupmanager_AUTODETECT_RESOURCE_GROUP_NAME();
DLL size_t resourcegroupmanager_RESOURCE_SYSTEM_NUM_REFERENCE_COUNTS();


DLL void initialise_all_resourcegroups();


// Camera
DLL CameraHandle create_camera(const char* camera_name);

DLL CameraHandle get_camera(const char* camera_name);

DLL void camera_move(CameraHandle handle, const float x, const float y, const float z);

DLL void camera_move_relative(CameraHandle handle, const float x, const float y, const float z);

DLL void camera_set_direction(CameraHandle handle, const float x, const float y, const float z);

DLL void camera_get_direction(CameraHandle handle, coiVector3* v3);

DLL void camera_set_near_clip_distance(CameraHandle camera_handle, float d);

DLL void camera_set_far_clip_distance(CameraHandle camera_handle, float d);

DLL void camera_set_aspect_ratio(CameraHandle camera_handle, float w, float h);

DLL void camera_set_aspect_ratio_ex(CameraHandle handle, float ratio);

DLL float camera_get_aspect_ratio(CameraHandle handle);

DLL void camera_set_auto_aspect_ratio(CameraHandle camera_handle, int on);

DLL void camera_set_fovy(CameraHandle camera_handle, float angle);

DLL void camera_set_frustum_offset(CameraHandle camera_handle, const int offset_x, const int offset_y);

DLL void camera_set_focal_length(CameraHandle camera_handle, float fl);

DLL void camera_set_position(CameraHandle camera_handle, const float x, const float y, const float z);

DLL void camera_get_position(CameraHandle handle, coiVector3* result);

DLL void camera_lookat(CameraHandle camera_handle, const float x, const float y, const float z);


// Entity
DLL EntityHandle create_entity(const char* entity_name, const char* mesh_file);

DLL void entity_set_cast_shadows(EntityHandle handle, int enabled);

DLL int entity_get_cast_shadows(EntityHandle handle);

DLL int entity_get_receives_shadows(EntityHandle handle);

DLL void entity_set_material_name(EntityHandle handle, const char* material_name, const char* group_name);


// Light
DLL LightHandle create_light(const char* light_name);

DLL void light_set_position(LightHandle light_handle, const float x, const float y, const float z);

DLL void destroy_light(LightHandle handle);

DLL void light_set_type(LightHandle handle, light_types type);

DLL void light_set_diffuse_colour(LightHandle handle, const ColourValue* colour);

DLL void light_set_specular_colour(LightHandle handle, const ColourValue* colour);


// FrameListener
DLL void add_frame_listener(FrameListenerEvent frame_event,int frame_event_type);

DLL void remove_frame_listener(FrameListenerEvent frame_event);

DLL FrameListenerHandle add_frame_listener_ctx(FrameListenerCtx callback, void* userdata);

DLL void remove_frame_listener_ctx(FrameListenerHandle handle);


// WindowListener
DLL void add_window_listener(RenderWindowHandle window_handle, WindowListenerEvent window_event);

DLL void remove_window_listener(RenderWindowHandle window_handle);

// LogManager
DLL LogManagerHandle create_log_manager();

// LogManager::getSingletonPtr
DLL LogManagerHandle get_log_manager();

//LogManager::getLog
DLL LogHandle logmanager_get_log(const char* name);

//LogManager::getDefaultLog
DLL LogHandle logmanager_get_default_log();

//LogManager::setDefaultLog
DLL LogHandle logmanager_set_default_log(LogHandle log_handle);

//LogManager::createLog
DLL LogHandle logmanager_create_log(const char* name, int default_log, int debugger_output, int suppress_file_output);

// n.b., Allows for finer grained control over the log messages at the cost of
// having to supply all these variables. If you don't need this control,
// use log_message above.
//LogManager::logMessage
DLL void logmanager_log_message(const char* message, log_message_level lml, int maskDebug, const char* log_name, int skip_message);

//LogManager::setLogDetail
DLL void logmanager_set_log_detail(logging_level lvl);

//LogManager::destroyLog
DLL void logmanager_destroy_log(const char* name);

//LogManager::destroyLog
DLL void logmanager_destroy_log_by_handle(LogHandle log_handle);

//Log::addListener
DLL LogListenerHandle add_log_listener(LogListenerEvent log_event, LogHandle log_handle);

//Log::addListener
DLL LogListenerHandle add_log_listener_ctx(LogListenerCtx log_event, LogHandle log_handle, void* userdata);

//Log::removeListener
DLL void remove_log_listener(LogListenerHandle handle, LogHandle log_handle);

//Log::addListener
DLL void remove_log_listener_ctx(LogListenerHandle handle, LogHandle log_handle);

//Log::logMessage
DLL void log_log_message(LogHandle handle, const char *message, log_message_level lml, int maskDebug);


// NameValuePairList 
DLL NameValuePairListHandle create_name_value_pair_list();
DLL void add_pair(NameValuePairListHandle params, const char* name, const char* value);
DLL void destroy_name_value_pair_list(NameValuePairListHandle params);


// RenderWindow
DLL ViewportHandle render_window_add_viewport(RenderWindowHandle window_handle, CameraHandle camera_handle, int zorder, float left, float top, float width, float height);

DLL int render_window_is_closed(RenderWindowHandle handle);

DLL void render_window_set_active(RenderWindowHandle handle, int state);

DLL void render_window_swap_buffers(RenderWindowHandle handle, int wait_for_vsync);

DLL void render_window_get_custom_attribute(RenderWindowHandle handle, const char* attribute, void* pdata);


// ColourValue
DLL void colourvalue_zero(ColourValue* c);
DLL void colourvalue_black(ColourValue* c);
DLL void colourvalue_white(ColourValue* c);
DLL void colourvalue_red(ColourValue* c);
DLL void colourvalue_green(ColourValue* c);
DLL void colourvalue_blue(ColourValue* c);


// Vector3
// TODO: Probably change these to pass pointers to coiV3 rather than passing the 
// structs on the stack, as shown above with ColourValue. 
//Vector3::operator !=
DLL int vector3_notequals_vector3(coiVector3 lhs, coiVector3 rhs);

//Vector3::operator ==
DLL int vector3_equals_vector3(coiVector3 lhs, coiVector3 rhs);

//Vector3::operator +
DLL coiVector3 vector3_add_vector3(coiVector3 lhs, coiVector3 rhs);

//Vector3::operator +=
DLL void vector3_update_add_vector3(coiVector3 lhs, coiVector3 rhs);

//Vector3::operator -
DLL coiVector3 vector3_subtract_vector3(coiVector3 lhs, coiVector3 rhs);

//Vector3::operator -=
DLL void vector3_update_subtract_vector3(coiVector3 lhs, coiVector3 rhs);

//Vector3::operator - 
DLL coiVector3 vector3_negate(coiVector3 v3);

// Vector3::operator/ 
DLL coiVector3 vector3_divide_vector3(coiVector3 lhs, coiVector3 rhs);

// Vector3::operator*
DLL coiVector3 vector3_multiply_vector3(coiVector3 lhs, coiVector3 rhs);


// Vector3::isNaN
DLL int vector3_is_nan(coiVector3 v3);

//Vector3::primaryAxis
DLL coiVector3 vector3_primary_axis(coiVector3);

// Vector3::ZERO
DLL coiVector3 vector3_ZERO();

// Vector3::UNIT_X
DLL coiVector3 vector3_UNIT_X();

// Vector3::UNIT_Y
DLL coiVector3 vector3_UNIT_Y();

// Vector3::UNIT_Z
DLL coiVector3 vector3_UNIT_Z();

// Vector3::NEGATIVE_UNIT_X
DLL coiVector3 vector3_NEGATIVE_UNIT_X();

// Vector3::NEGATIVE_UNIT_Y
DLL coiVector3 vector3_NEGATIVE_UNIT_Y();

// Vector3::NEGATIVE_UNIT_Z
DLL coiVector3 vector3_NEGATIVE_UNIT_Z();

// Vector3::UNIT_SCALE
DLL coiVector3 vector3_UNIT_SCALE();

// Plane
DLL PlaneHandle plane_create_plane();
DLL PlaneHandle plane_create_plane_normal(float x, float y, float z, float distance);
DLL void plane_destroy_plane(PlaneHandle handle);
DLL void plane_get_normal(PlaneHandle handle, coiVector3* normal);
DLL void plane_set_normal(PlaneHandle handle, const coiVector3* normal);
DLL coiReal plane_get_d(PlaneHandle handle);
DLL void plane_set_d(PlaneHandle handle, coiReal d);



// MeshManager

DLL MeshHandle meshmanager_create_plane(const char* name, const char* group_name,
                                        PlaneHandle plane, float width,
                                        float height, int xsegments, int ysegments,
                                        int normals, unsigned short num_tex_coord_sets,
                                        float utile, float vtile, coiVector3* up_vector,
                                        hardware_buffer_usage vertex_buffer_usage,
                                        hardware_buffer_usage index_buffer_usage,
                                        int vertex_shadow_buffer, int index_shadow_buffer);

#endif
