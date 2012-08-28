/******************************************************************************
 * ogre_interface.h - linkage include file
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

#define NameValuePairListHandle void*

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
    coiReal w;
    coiReal x;
    coiReal y;
    coiReal z;
} coiQuaternion;

typedef struct
{
    coiReal x;
    coiReal y;
} coiVector2;

typedef struct
{
    coiReal x;
    coiReal y;
    coiReal z;
} coiVector3;

typedef struct
{
    coiReal x;
    coiReal y;
    coiReal z;
    coiReal w;
} coiVector4;

typedef struct
{
    coiReal m[3][3];
} coiMatrix3;

typedef struct
{
    coiReal m[4][4];
} coiMatrix4;

typedef struct
{
    coiVector3 position;
    coiQuaternion orientation;
} ViewPoint;


typedef struct
{
    float r;
    float g;
    float b;
    float a;
} coiColourValue;


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


typedef struct
{
    unsigned short target_buffer_index;
    coiReal parametric;
} hardware_animation_data;

// Start enums

// OgreRenderTarget.h
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

// OgreHardwareBuffer.h
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

//OgreLight.h
typedef enum
{
    LT_POINT = 0,
    LT_DIRECTIONAL = 1,
    LT_SPOTLIGHT = 2
} light_types;

//OgreNode.h
typedef enum
{
    TS_LOCAL,
    TS_PARENT,
    TS_WORLD
} transform_space;

// OgrePlane.h
typedef enum
{
    NO_SIDE,
    POSITIVE_SIDE,
    NEGATIVE_SIDE,
    BOTH_SIDE
} plane_side;


//OgreAxisAlignedBox.h
typedef enum
{
    EXTENT_NULL,
    EXTENT_FINITE,
    EXTENT_INFINITE
} Extent;

typedef enum {
    FAR_LEFT_BOTTOM = 0,
    FAR_LEFT_TOP = 1,
    FAR_RIGHT_TOP = 2,
    FAR_RIGHT_BOTTOM = 3,
    NEAR_RIGHT_BOTTOM = 7,
    NEAR_LEFT_BOTTOM = 6,
    NEAR_LEFT_TOP = 5,
    NEAR_RIGHT_TOP = 4
} CornerEnum;

//OgreSceneQuery.h
typedef enum 
{
    WFT_NONE,
    WFT_PLANE_BOUNDED_REGION,
    WFT_SINGLE_INTERSECTION,
    WFT_CUSTOM_GEOMETRY,
    WFT_RENDER_OPERATION
} world_fragment_type;

//OgreLog.h
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
    OR_DEGREE_0       = 0,
    OR_DEGREE_90      = 1,
    OR_DEGREE_180     = 2,
    OR_DEGREE_270     = 3,

    OR_PORTRAIT       = OR_DEGREE_0,
    OR_LANDSCAPERIGHT = OR_DEGREE_90,
    OR_LANDSCAPELEFT  = OR_DEGREE_270
} orientation_mode;

typedef enum
{
    PT_ORTHOGRAPHIC,
    PT_PERSPECTIVE
} projection_type;

typedef enum
{
    FRUSTUM_PLANE_NEAR   = 0,
    FRUSTUM_PLANE_FAR    = 1,
    FRUSTUM_PLANE_LEFT   = 2,
    FRUSTUM_PLANE_RIGHT  = 3,
    FRUSTUM_PLANE_TOP    = 4,
    FRUSTUM_PLANE_BOTTOM = 5
} frustum_plane;


typedef enum
{
    GMM_RELATIVE,
    GMM_PIXELS,
    GMM_RELATIVE_ASPECT_ADJUSTED
} gui_metrics_mode;

typedef enum
{
    GHA_LEFT,
    GHA_CENTER,
    GHA_RIGHT
} gui_horizontal_alignment;

typedef enum
{
    GVA_TOP,
    GVA_CENTER,
    GVA_BOTTOM
} gui_vertical_alignment;

typedef enum
{
    Left,
    Right,
    Center
} textarea_overlayelement_alignment;

typedef enum
{
    ANIMBLEND_AVERAGE = 0,
    ANIMBLEND_CUMULATIVE = 1
} skeleton_animation_blend_mode;


typedef enum
{
    OT_POINT_LIST = 1,
    OT_LINE_LIST = 2,
    OT_LINE_STRIP = 3,
    OT_TRIANGLE_LIST = 4,
    OT_TRIANGLE_STRIP = 5,
    OT_TRIANGLE_FAN = 6
} operation_type;

typedef enum
{
    ST_GENERIC = 1,
    ST_EXTERIOR_CLOSE = 2,
    ST_EXTERIOR_FAR = 4,
    ST_EXTERIOR_REAL_FAR = 8,
    ST_INTERIOR = 16
} scene_type;



// OgreCommon.h

typedef enum
{
    CMPF_ALWAYS_FAIL,
    CMPF_ALWAYS_PASS,
    CMPF_LESS,
    CMPF_LESS_EQUAL,
    CMPF_EQUAL,
    CMPF_NOT_EQUAL,
    CMPF_GREATER_EQUAL,
    CMPF_GREATER
} compare_function;

typedef enum
{
    TFO_NONE,
    TFO_BILINEAR,
    TFO_TRILINEAR,
    TFO_ANISOTROPIC
} texture_filter_options;

typedef enum
{
    FT_MIN,
    FT_MAG,
    FT_MIP
} filter_type;

typedef enum
{
    FO_NONE,
    FO_POINT,
    FO_LINEAR,
    FO_ANISOTROPIC
} filter_options;

typedef enum
{
    SO_FLAT,
    SO_GOURAUD,
    SO_PHONG
} shade_options;

typedef enum
{
    FOG_NONE,
    FOG_EXP,
    FOG_EXP2,
    FOG_LINEAR
} fog_mode;

typedef enum
{
    CULL_NONE = 1,
    CULL_CLOCKWISE = 2,
    CULL_ANTICLOCKWISE = 3
} culling_mode;

typedef enum
{
    MANUAL_CULL_NONE = 1,
    MANUAL_CULL_BACK = 2,
    MANUAL_CULL_FRONT = 3
} manual_culling_mode;

typedef enum
{
    WFT_SINE,
    WFT_TRIANGLE,
    WFT_SQUARE,
    WFT_SAWTOOTH,
    WFT_INVERSE_SAWTOOTH,
    WFT_PWM
} waveform_type;

typedef enum
{
    PM_POINTS = 1,
    PM_WIREFRAME = 2,
    PM_SOLID = 3
} polygon_mode;

typedef enum
{
    SHADOWTYPE_NONE = 0x00,
    SHADOWDETAILTYPE_ADDITIVE = 0x01,
    SHADOWDETAILTYPE_MODULATIVE = 0x02,
    SHADOWDETAILTYPE_INTEGRATED = 0x04,
    SHADOWDETAILTYPE_STENCIL = 0x10,
    SHADOWDETAILTYPE_TEXTURE = 0x20,
    SHADOWTYPE_STENCIL_MODULATIVE = 0x12,
    SHADOWTYPE_STENCIL_ADDITIVE = 0x11,
    SHADOWTYPE_TEXTURE_MODULATIVE = 0x22,
    SHADOWTYPE_TEXTURE_ADDITIVE = 0x21,
    SHADOWTYPE_TEXTURE_ADDITIVE_INTEGRATED = 0x25,
    SHADOWTYPE_TEXTURE_MODULATIVE_INTEGRATED = 0x26
} shadow_technique;

typedef int track_vertex_colour_type;

typedef enum
{
    TVC_NONE        = 0x0,
    TVC_AMBIENT     = 0x1,        
    TVC_DIFFUSE     = 0x2,
    TVC_SPECULAR    = 0x4,
    TVC_EMISSIVE    = 0x8
} track_vertex_colour_enum;

typedef enum
{
    SM_DIRECTION,
    SM_DISTANCE
} sort_mode;

typedef enum
{
    FBT_COLOUR  = 0x1,
    FBT_DEPTH   = 0x2,
    FBT_STENCIL = 0x4
} frame_buffer_type;

typedef enum
{
    IM_USE16BIT		= 0x0001,
    IM_VTFBESTFIT	= 0x0002,
    IM_VTFBONEMATRIXLOOKUP = 0x0004,
    IM_USEBONEDUALQUATERNIONS = 0x0008,
    IM_USEONEWEIGHT = 0x0010,
    IM_FORCEONEWEIGHT = 0x0020,
    IM_USEALL		= IM_USE16BIT|IM_VTFBESTFIT|IM_USEONEWEIGHT
} instance_manager_flags;

typedef enum
{
    CLIPPED_NONE = 0,
    CLIPPED_SOME = 1, 
    CLIPPED_ALL = 2
} clip_result;

#endif
