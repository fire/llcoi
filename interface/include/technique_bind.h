/******************************************************************************
 * technique_bind.h - bindings for Ogre::Technique
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

typedef void* TechniqueHandle;
typedef void* PassHandle;

#include "ogre_interface.h"

//Technique(Material* parent)
//Technique(Material* parent, const Technique& oth)
//~Technique()
//bool isSupported(void) const
//String _compile(bool autoManageTextureUnits)
//bool checkGPURules(StringUtil::StrStreamType& errors)
//bool checkHardwareSupport(bool autoManageTextureUnits, StringUtil::StrStreamType& compileErrors)
//void _compileIlluminationPasses(void)
//Pass* createPass(void)
//Pass* getPass(unsigned short index)
//Pass* getPass(const String& name)
//unsigned short getNumPasses(void) const
//void removePass(unsigned short index)
//void removeAllPasses(void)
//bool movePass(const unsigned short sourceIndex, const unsigned short destinationIndex)
//typedef VectorIterator<Passes> PassIterator
//const PassIterator getPassIterator(void)
//typedef VectorIterator<IlluminationPassList> IlluminationPassIterator
//const IlluminationPassIterator getIlluminationPassIterator(void)
//Material* getParent(void) const
//Technique& operator=(const Technique& rhs)
//const String& getResourceGroup(void) const
//bool isTransparent(void) const
//bool isTransparentSortingEnabled(void) const
//bool isTransparentSortingForced(void) const
//void _prepare(void)
//void _unprepare(void)
//void _load(void)
//void _unload(void)
//bool isLoaded(void) const
//void _notifyNeedsRecompile(void)
//Ogre::MaterialPtr getShadowCasterMaterial() const
//void setShadowCasterMaterial(Ogre::MaterialPtr val)
//void setShadowCasterMaterial(const Ogre::String &name)
//Ogre::MaterialPtr getShadowReceiverMaterial() const
//void setShadowReceiverMaterial(Ogre::MaterialPtr val)
//void setShadowReceiverMaterial(const Ogre::String &name)
//void setPointSize(Real ps)
//void setAmbient(Real red, Real green, Real blue)
//void setAmbient(const ColourValue& ambient)
//void setDiffuse(Real red, Real green, Real blue, Real alpha)
//void setDiffuse(const ColourValue& diffuse)
//void setSpecular(Real red, Real green, Real blue, Real alpha)
//void setSpecular(const ColourValue& specular)
//void setShininess(Real val)
//void setSelfIllumination(Real red, Real green, Real blue)
//void setSelfIllumination(const ColourValue& selfIllum)
//void setDepthCheckEnabled(bool enabled)
//void setDepthWriteEnabled(bool enabled)
//void setDepthFunction( CompareFunction func )
//void setColourWriteEnabled(bool enabled)
//void setCullingMode( CullingMode mode )
//void setManualCullingMode( ManualCullingMode mode )
//void setLightingEnabled(bool enabled)
//void setShadingMode( ShadeOptions mode )
//void setFog(bool overrideScene, FogMode mode = FOG_NONE, const ColourValue& colour = ColourValue::White, Real expDensity = 0.001, Real linearStart = 0.0, Real linearEnd = 1.0 )
//void setDepthBias(float constantBias, float slopeScaleBias)
//void setTextureFiltering(TextureFilterOptions filterType)
//void setTextureAnisotropy(unsigned int maxAniso)
//void setSceneBlending( const SceneBlendType sbt )
//void setSeparateSceneBlending( const SceneBlendType sbt, const SceneBlendType sbta )
//void setSceneBlending( const SceneBlendFactor sourceFactor, const SceneBlendFactor destFactor)
//void setSeparateSceneBlending( const SceneBlendFactor sourceFactor, const SceneBlendFactor destFactor, const SceneBlendFactor sourceFactorAlpha, const SceneBlendFactor destFactorAlpha)
//void setLodIndex(unsigned short index)
//unsigned short getLodIndex(void) const
//void setSchemeName(const String& schemeName)
//const String& getSchemeName(void) const
//unsigned short _getSchemeIndex(void) const
//bool isDepthWriteEnabled(void) const
//bool isDepthCheckEnabled(void) const
//bool hasColourWriteDisabled(void) const
//void setName(const String& name)
//const String& getName(void) const
//bool applyTextureAliases(const AliasTextureNamePairList& aliasList, const bool apply = true) const
//void addGPUVendorRule(GPUVendor vendor, IncludeOrExclude includeOrExclude)
//void addGPUVendorRule(const GPUVendorRule& rule)
//void removeGPUVendorRule(GPUVendor vendor)
//typedef ConstVectorIterator<GPUVendorRuleList> GPUVendorRuleIterator
//GPUVendorRuleIterator getGPUVendorRuleIterator() const
//void addGPUDeviceNameRule(const String& devicePattern, IncludeOrExclude includeOrExclude, bool caseSensitive = false)
//void addGPUDeviceNameRule(const GPUDeviceNameRule& rule)
//void removeGPUDeviceNameRule(const String& devicePattern)
//typedef ConstVectorIterator<GPUDeviceNameRuleList> GPUDeviceNameRuleIterator
//GPUDeviceNameRuleIterator getGPUDeviceNameRuleIterator() const
//UserObjectBindings&	getUserObjectBindings()
//const UserObjectBindings& getUserObjectBindings() const
