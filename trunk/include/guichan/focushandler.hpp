/*      _______   __   __   __   ______   __   __   _______   __   __                 
 *     / _____/\ / /\ / /\ / /\ / ____/\ / /\ / /\ / ___  /\ /  |\/ /\                
 *    / /\____\// / // / // / // /\___\// /_// / // /\_/ / // , |/ / /                 
 *   / / /__   / / // / // / // / /    / ___  / // ___  / // /| ' / /                  
 *  / /_// /\ / /_// / // / // /_/_   / / // / // /\_/ / // / |  / /                   
 * /______/ //______/ //_/ //_____/\ /_/ //_/ //_/ //_/ //_/ /|_/ /                    
 * \______\/ \______\/ \_\/ \_____\/ \_\/ \_\/ \_\/ \_\/ \_\/ \_\/                      
 *
 * Copyright (c) 2004, 2005 darkbits                        Js_./
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

#ifndef GCN_FOCUSHANDLER_HPP
#define GCN_FOCUSHANDLER_HPP

#include <vector>

#include "guichan/platform.hpp"
#include "guichan/widget.hpp"

namespace gcn
{
	class Widget;
  
	/**
	 * The FocusHandler is used internally in the library to keep
	 * track of widget focus. You will not have to use the FocusHandler
	 * directly to handle focus, use the functions handling focus in
	 * the Widget class instead.
	 *
	 * @see Widget::hasFocus
	 * @see Widget::requestFocus
	 * @see Widget::setFocusable
	 * @see Widget::isFocusable
	 * @see Widget::gotFocus
	 * @see Widget::lostFocus
	 */
	class GCN_CORE_DECLSPEC FocusHandler
	{
	public:

		/**
		 * Constructor.
		 */
		FocusHandler();

        /**
         * Destructor.
         */
        virtual ~FocusHandler() { };
        
		/**
		 * Sets the focus to a certain widget. Widget::lostFocus and
		 * Widget::gotFocus will be called as necessary.
		 *
		 * @param widget the widget to be focused.
		 */
		virtual void requestFocus(Widget* widget);

		/**
		 * Sets a widget to be dragged.
		 *
		 * @param widget the widget to be dragged.
		 */
		virtual void requestDrag(Widget* widget);
        
        /**
		 * Sets modal focus to a certain widget. If a widget already
         * has modal focus, an exception will be thrown.
		 *
		 * @param widget the widget to get modal focus.
         * @throws Exception when another widget already has modal focus.
         */
		virtual void requestModalFocus(Widget* widget);

        /**
         * Releases the modal focus if the widget has modal focus,
         * otherwise nothing will be done.
         *
         * @param widget the widget to release modal focus for.
         */
		virtual void releaseModalFocus(Widget* widget);
        
		/**
		 * Gets the focused widget.
		 *
		 * @return a pointer to the focused widget.
		 */
		virtual Widget* getFocused() const;
		
		/**
		 * Gets the widget that is dragged.
		 *
		 * @return a pointer to the dragged widget.
		 */
		virtual Widget* getDragged() const;

		/**
		 * Gets the widget that has modal focus.
		 *
		 * @return a pointer to the modal focused widget.
		 */
		virtual Widget* getModalFocused() const;
        
		/**
		 * Focuses the next widget. If no widget has focus the first
		 * widget is focused. The order that the widgets are focused
		 * depends on the order that you add them to the GUI.
		 */
		virtual void focusNext();
    
		/**
		 * Focuses the previous widget. If no widget has focus the first
		 * widget is focused. The order that the widgets are focused
		 * depends on the order that you add them to the GUI.     
		 */
		virtual void focusPrevious();

		/**
		 * Checks if a widget currently has focus.
		 *
		 * @param widget a pointer to the widget to check.
		 * @return true if the widget has focus.
		 */
		virtual bool hasFocus(const Widget* widget) const;

		/**
		 * Checks if a widget is dragged
		 *
		 * @param widget a pointer to the widget to check.
		 * @return true if the widget is dragged.
		 */
		virtual bool isDragged(const Widget* widget) const;
		
		/**
		 * Adds a widget to the FocusHandler.
		 *
		 * @param widget a pointer to the widget to add.
		 */
		virtual void add(Widget* widget);
    
		/**
		 * Removes a widget from the FocusHandler.
		 *
		 * @param widget a pointer to the widget to remove.     
		 */
		virtual void remove(Widget* widget);

		/**
		 * Focuses nothing.
		 */
		virtual void focusNone();
        
		/**
		 * Focus the next Widget which allows tab in unless current focused
		 * Widget disallows tab out.
		 */
		virtual void tabNext();

		/**
		 * Focus the previous Widget which allows tab in unless current focused
		 * Widget disallows tab out.
		 */
		virtual void tabPrevious();

		/**
		 * Applies the changes.
		 */
		virtual void applyChanges();

		/**
		 * Drag nothing.
		 */
		virtual void dragNone();
		
	protected:
		typedef std::vector<Widget*> WidgetVector;
		typedef WidgetVector::iterator WidgetIterator;
		WidgetVector mWidgets;
    
		Widget* mFocusedWidget;
        Widget* mDraggedWidget;
		Widget* mToBeFocused;
		Widget* mToBeDragged;
        Widget* mModalFocusedWidget;
        
	}; // FocusHandler
  
} // end gcn

#endif // end GCN_FOCUSHANDLER_HPP
