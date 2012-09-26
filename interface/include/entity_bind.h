/******************************************************************************
 * entity_bind.h - bindings for Ogre::Entity
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

typedef void* EntityHandle;

#include "ogre_interface.h"

DLL EntityHandle create_entity(const char* entity_name, const char* mesh_file);

DLL const MeshPtrHandle entity_get_mesh(const EntityHandle handle);

DLL unsigned int entity_get_num_sub_entities(const EntityHandle handle);

DLL EntityHandle entity_clone(const EntityHandle handle, const char* name);

DLL void entity_set_cast_shadows(EntityHandle handle, int enabled);

DLL int entity_get_cast_shadows(const EntityHandle handle);

DLL int entity_get_receives_shadows(EntityHandle handle);

DLL void entity_set_material_name(EntityHandle handle, const char* material_name, const char* group_name);

DLL void entity_set_material(EntityHandle handle, MaterialPtrHandle mat);

DLL void entity__notify_current_camera(EntityHandle handle, CameraHandle cam);

DLL void entity_set_render_queue_group(EntityHandle handle, unsigned char queue_id);

DLL void entity_set_render_queue_group_and_priority(EntityHandle handle, unsigned char queue_id, unsigned short priority);

DLL AxisAlignedBoxHandle entity_get_bounding_box(const EntityHandle handle);

DLL coiReal entity_get_bounding_radius(const EntityHandle handle);

DLL void entity_set_display_skeleton(EntityHandle handle, int display);

DLL int entity_get_display_skeleton(const EntityHandle handle);

DLL int entity_has_skeleton(const EntityHandle handle);

DLL SkeletonInstanceHandle entity_get_skeleton(const EntityHandle handle);

DLL int entity_is_hardware_animation_enabled(EntityHandle handle);
