/******************************************************************************
 * skeletoninstance_bind.h - bindings for Ogre::SkeletonInstance
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

typedef void* SkeletonInstanceHandle;
typedef void* SkeletonHandle;
typedef void* BoneHandle;
typedef void* TagPointHandle;

#include "ogre_interface.h"

//~SkeletonInstance();
DLL void destroy_skeletoninstance(SkeletonInstanceHandle handle);
//unsigned short getNumAnimations(void) const;
DLL unsigned short skeletoninstance_get_num_animations(const SkeletonInstanceHandle handle);
//TODO: Animation* getAnimation(unsigned short index) const;
//TODO: Animation* _getAnimationImpl(const String& name,  const LinkedSkeletonAnimationSource** linker = 0) const;
//TODO: Animation* createAnimation(const String& name, Real length);
//TODO: Animation* getAnimation(const String& name,  const LinkedSkeletonAnimationSource** linker = 0) const;
//void removeAnimation(const String& name);
DLL void skeletoninstance_remove_animation(SkeletonInstanceHandle handle, const char* name);
//TagPoint* createTagPointOnBone(Bone* bone, const Quaternion &offsetOrientation = Quaternion::IDENTITY,const Vector3 &offsetPosition = Vector3::ZERO);
DLL TagPointHandle skeletoninstance_create_tag_point_on_bone(SkeletonInstanceHandle handle, BoneHandle bone_handle, const coiQuaternion* offset_orientation, const coiVector3* offset_position);
//void freeTagPoint(TagPoint* tagPoint);
DLL void skeletoninstance_free_tag_point(SkeletonInstanceHandle handle, TagPointHandle tag_point);
//void addLinkedSkeletonAnimationSource(const String& skelName, Real scale = 1.0f);
DLL void skeletoninstance_add_linked_skeleton_animation_source(SkeletonInstanceHandle handle, const char* skel_name, coiReal scale);
//void removeAllLinkedSkeletonAnimationSources(void);
DLL void skeletoninstance_remove_all_linked_skeleton_animation_sources(SkeletonInstanceHandle handle);
//TODO: LinkedSkeletonAnimSourceIterator getLinkedSkeletonAnimationSourceIterator(void) const;
//TODO: void _initAnimationState(AnimationStateSet* animSet);
//TODO: void _refreshAnimationState(AnimationStateSet* animSet);
//const String& getName(void) const;
DLL const char*  skeletoninstance_get_name(const SkeletonInstanceHandle handle);
//TODO: ResourceHandle getHandle(void) const;
//const String& getGroup(void);
DLL const char* skeletoninstance_get_group(SkeletonInstanceHandle handle);
