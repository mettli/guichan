/*      _______   __   __   __   ______   __   __   _______   __   __                 
 *     / _____/\ / /\ / /\ / /\ / ____/\ / /\ / /\ / ___  /\ /  |\/ /\                
 *    / /\____\// / // / // / // /\___\// /_// / // /\_/ / // , |/ / /                 
 *   / / /__   / / // / // / // / /    / ___  / // ___  / // /| ' / /                  
 *  / /_// /\ / /_// / // / // /_/_   / / // / // /\_/ / // / |  / /                   
 * /______/ //______/ //_/ //_____/\ /_/ //_/ //_/ //_/ //_/ /|_/ /                    
 * \______\/ \______\/ \_\/ \_____\/ \_\/ \_\/ \_\/ \_\/ \_\/ \_\/                      
 *
 * Copyright (c) 2004 darkbits                              Js_./
 * Per Larsson a.k.a finalman                          _RqZ{a<^_aa
 * Olof Naess�n a.k.a jansem/yakslem                _asww7!uY`>  )\a//
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
 * 3. Neither the name of Guichan nor the      :$we` _! + _/ .        j?
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

#ifndef GCN_SDLGRAPHICS_HPP
#define GCN_SDLGRAPHICS_HPP

#include <map>
#include <SDL/SDL.h>
#include <string>

#include "guichan/graphics.hpp"
#include "guichan/image.hpp"
#include "guichan/platform.hpp"
#include "guichan/rectangle.hpp"

namespace gcn
{
  /**
   * This is an SDL implementation of the Graphics object. For more
   * information about the Graphics object please see the Graphics
   * header.
   *
   * @see Graphics
   * @todo Alpha channel support.
   */
  class DECLSPEC SDLGraphics : public Graphics
  {
  public:

    /**
     * This function sets the target on which to draw Gui-chan.
     * Gui-chan is drawn upon calling the draw function found in
     * the Gui class. As you might notice, Gui-chan can be drawn
     * on any SDL_Surface. This funtion also pushes a clip area
     * corresponding to the dimension of the target.
     *
     * @param target the target where to draw Gui-chan
     * @see Graphics
     */
    virtual void setTarget(SDL_Surface* target);

    /**
     * @return the target on which Gui-chan is drawn
     */
    virtual SDL_Surface* getTarget() const;


		// Inherited from Graphics

		virtual void _beginDraw();

		virtual void _endDraw();
		
    virtual bool pushClipArea(Rectangle area);
    
    virtual void popClipArea();
    
    virtual void drawImage(const Image* image, int srcX, int srcY,
                           int dstX, int dstY, int width,
                           int height);    
    
    virtual void drawPoint(int x, int y);
    
    virtual void drawLine(int x1, int y1, int x2, int y2);
    
    virtual void drawRectangle(const Rectangle& rectangle);

    virtual void fillRectangle(const Rectangle& rectangle);
    
  protected:
    /**
     * This function draws a horizontal line.
     *
     * @param x1 the start coordinate of the line
     * @param y the y coordinate of the line
     * @param x2 the end coordinate of the line
     */
    virtual void drawHLine(int x1, int y, int x2);

    /**
     * This function draws a vertical line.
     *
     * @param x the x coordinate of the line
     * @param y1 the start coordinate of the line
     * @param y2 the end coordinate of the line
     */
    virtual void drawVLine(int x, int y1, int y2);

    SDL_Surface* mTarget;
    
  }; // end SDLGraphics
  
} // end gcn

#endif // end GCN_SDLGRAPHICS_HPP