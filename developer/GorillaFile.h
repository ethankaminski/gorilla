/*
    Gorilla
    -------
    
    Copyright (c) 2010 Robin Southern
                                                                                  
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
                                                                                  
    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.
                                                                                  
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE. 
    
*/

#ifndef GORILLA_FILE_H
#define GORILLA_FILE_H

#include "Shared.h"

namespace Gorilla
{
 
 class GorillaFile
 {
   
   public:
    
    Gorilla();
    
   ~Gorilla();
    
    size_t    getNbReferences() const;
    
   protected:
    
    struct TextureCoordinates
    {
     unsigned int x, y, w, h;
    };

    struct Glyph
    {
     TextureCoordinates                    mTextureCoords;
     unsigned int                          mHorizontalOffset,
                                           mVerticalOffset;
     std::map<GlyphCodePoint, Ogre::Real>  mKerning;
     unsigned int                          mAdvance;
    };

    struct GlyphData
    {
     std::map<GlyphCodePoint, Glyph*>     mGlyphs;
     Ogre::Real                           mLineHeight;
     unsigned int                         mTextureID;
    };

    struct Sprite
    {
     TextureCoordinates                   mTextureCoords;
    };

    struct TextureAtlas
    {
     Ogre::String                         mImageName;
    };
    
    std::map<unsigned int, TextureAtlas>  mTextures;
    std::map<Ogre::String, GlyphData*>    mFonts;
    
    size_t                                mReferences;
    
 };
 
}


#endif
