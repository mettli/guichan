#ifndef GCN_FOCUSHANDLER_HPP
#define GCN_FOCUSHANDLER_HPP

#include <vector>
#include "guichan/widget.hpp"

namespace gcn
{
  class Widget;

  /**
   * 
   */
  class FocusHandler
  {
  public:

    FocusHandler(){}
    /**
     * 
     */
    void requestFocus(Widget* widget){}
    /**
     * 
     */
    Widget* getFocused(){}
    /**
     * 
     */
    void focusNext(){}
    /**
     * 
     */
    void focusPrevious(){}
    /**
     * 
     */
    bool hasFocus(Widget* widget){}
    /**
     * 
     */
    void add(Widget* widget){}
    /**
     * 
     */
    void remove(Widget* widget){} 
    
    
  protected:
    std::vector<Widget*> mWidgets;
    Widget* mFocusedWidget;
    Widget* mPreviousFocusedWidget;
    
  }; // FocusHandler
  
} // end gcn

#endif // end GCN_FOCUSHANDLER_HPP
