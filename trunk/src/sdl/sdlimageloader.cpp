/*
 *    _aaaa,  _aa.  sa,  aaa              _aaaa,_  ac  .aa.   .aa.  .aa,  _a, sa
 *  .wWV!!!T  |Wm;  dQ[  $WF            _mWT!"?Y  ]QE  :Q#:   ]QW[  :WWk. ]Q[ dW
 * .jWf       :WW: .dQ[  dQ[           .mW(       )WE  :Q#:  .mSQh. :mWQa.]W[ dQ
 * |QW:       :Wm;  mQ[  dQ[           ]Qk        )Qmi_aQW:  <B:$Qc :WBWQ()W[ dQ
 * |W#:  .ww  ;WW;  dQ[  dQ[  .......  ]Qk        )QB?YYW#:  jf ]Qp.:mE)Qm]Q[ )W
 * +WQ;  :Wm  |Wm; .mQ[  dQ[ :qgggggga ]Qm.       ]WE  :Q# :=QasuQm;:Wk 3QQW[ )Y
 *  ]Wmi.:Wm  +$Q; .mW(  dQ[  !"!!"!!^ dQk,  ._   ]WE  :Q# :3D"!!$Qc.Wk -$WQ[   
 *   "?????? ` "?!=m?!   ??'            -??????!  -?!  -?? -?'   "?"-?"  "??' "?
 *
 * Copyright (c) 2004 darkbits                              Js_./
 * Per Larsson a.k.a finalman                          _RqZ{a<^_aa
 * Olof Naessén a.k.a jansem/yakslem                _asww7!uY`>  )\a//
 *                                                 _Qhm`] _f "'c  1!5m
 * Visit: http://guichan.darkbits.org             )Qk<P ` _: :+' .'  "{[
 *                                               .)j(] .d_/ '-(  P .   S
 * License: (BSD)                                <Td/Z <fP"5(\"??"\a.  .L
 * Redistribution and use in source and          _dV>ws?a-?'      ._/L  #'
 * binary forms, with or without                 )4d[#7r, .   '     )d`)[
 * modification, are permitted provided         _Q-5'5W..j/?'   -?!\)cam'
 * that the following conditions are met:       j<<WP+k/);.        _W=j f
 * 1. Redistributions of source code must       .$%w\/]Q  . ."'  .  mj$
 *    retain the above copyright notice,        ]E.pYY(Q]>.   a     J@\
 *    this list of conditions and the           j(]1u<sE"L,. .   ./^ ]{a
 *    following disclaimer.                     4'_uomm\.  )L);-4     (3=
 * 2. Redistributions in binary form must        )_]X{Z('a_"a7'<a"a,  ]"[
 *    reproduce the above copyright notice,       #}<]m7`Za??4,P-"'7. ).m
 *    this list of conditions and the            ]d2e)Q(<Q(  ?94   b-  LQ/
 *    following disclaimer in the                <B!</]C)d_, '(<' .f. =C+m
 *    documentation and/or other materials      .Z!=J ]e []('-4f _ ) -.)m]'
 *    provided with the distribution.          .w[5]' _[ /.)_-"+?   _/ <W"
 * 3. Neither the name of darkbits nor the     :$we` _! + _/ .        j?
 *    names of its contributors may be used     =3)= _f  (_yQmWW$#(    "
 *    to endorse or promote products derived     -   W,  sQQQQmZQ#Wwa]..
 *    from this software without specific        (js, \[QQW$QWW#?!V"".
 *    prior written permission.                    ]y:.<\..          .
 *                                                 -]n w/ '         [.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT       )/ )/           !
 * HOLDERS AND CONTRIBUTORS "AS IS" AND ANY         <  (; sac    ,    '
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING,               ]^ .-  %
 * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF            c <   r
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR            aga<  <La
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE          5%  )P'-3L
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR        _bQf` y`..)a
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,          ,J?4P'.P"_(\?d'.,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES               _Pa,)!f/<[]/  ?"
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT      _2-..:. .r+_,.. .
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,     ?a.<%"'  " -'.a_ _,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION)                     ^
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * For comments regarding functions please see the header file. 
 */

#include "guichan/sdl/sdlimageloader.hpp"
#include <SDL/SDL_image.h>

namespace gcn
{

  SDLImageLoader::SDLImageLoader()
  {

    mCurrentImage = NULL;
    
  } // end SDLImageLoader
  
  void SDLImageLoader::prepare(const std::string& filename)
  {
    if (mCurrentImage != NULL)
    {
      //TODO
      //Add error
      return;
    }
    
    if (mImages.find(filename) == mImages.end())
    {
      mCurrentImage = IMG_Load(filename.c_str());

      if (mCurrentImage == NULL)
      {
        //TODO
        //Add error
        return;
      }
    }
    else
    {
      mCurrentImage = mImages[filename].first;
    }
    
  } // end prepare
  
  void* SDLImageLoader::finalize()
  {
    if (mCurrentImage == NULL)
    {
      //TODO
      //Add error
      return NULL;
    }
    
    SDL_DisplayFormat(mCurrentImage);
    return finalizeNoConvert();

  } // end finalize
  
  void* SDLImageLoader::finalizeNoConvert()
  {
    if (mCurrentImage == NULL)
    {
      //TODO
      //Add error
      return NULL;
    }

    SDL_Surface* temp = mCurrentImage;
    mCurrentImage = NULL;
    return temp;
    
  } // end finalizeNoConvert

  void* SDLImageLoader::load(int& width, int& height, const std::string& filename)
  {
    SDL_Surface* temp;
    temp = IMG_Load(filename.c_str());
    temp = SDL_DisplayFormat(temp);

    if (mImages.find(filename) == mImages.end())
    {
      mImages[filename] = imageRefCount(temp,0);
    }
    
    mImages[filename].second++;
    
    width = temp->w;
    height = temp->h; 

    return (void*)mImages[filename].first;
    
  } // end load

  void* SDLImageLoader::loadNoConvert(int& width, int& height, const std::string& filename)
  {
    SDL_Surface* temp;
    temp = IMG_Load(filename.c_str());
    
    if (mImages.find(filename) == mImages.end())
    {
      mImages[filename] = imageRefCount(temp,0);
    }
    
    mImages[filename].second++;

    width = temp->w;
    height = temp->h; 
    
    return (void*)mImages[filename].first;

  } // end loadNoConvert

  void SDLImageLoader::discard()
  {
    if (mCurrentImage == NULL)
    {
      return;
    }
    
    SDL_FreeSurface(mCurrentImage);
    
    mCurrentImage = NULL;
    
  } // end discard
  
  void SDLImageLoader::free(Image* image)
  {
    
     if (mImages.find(image->getFilename()) == mImages.end())
     {
       SDL_FreeSurface((SDL_Surface*)image->getData());
       return;
     }
    
     mImages[image->getFilename()].second--;
     
     if (mImages[image->getFilename()].second == 0)
     {
       SDL_FreeSurface((SDL_Surface*)image->getData());
       mImages.erase(image->getFilename());
     }
     
  } // end free
  
  int SDLImageLoader::getWidth() const
  {
    if (mCurrentImage == NULL)
    {
      //TODO: add error
      return 0;
    }
    
    return mCurrentImage->w;
  }

  int SDLImageLoader::getHeight() const
  {
    if (mCurrentImage == NULL)
    {
      //TODO: add error
      return 0;
    }
    
    return mCurrentImage->h;
  }

} // end gcn
