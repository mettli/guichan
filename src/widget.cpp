#include "guichan/widget.hpp"
#include "guichan/focushandler.hpp"

namespace gcn
{
  /**
   *
   */
  Widget::Widget()
  {
    mParent = 0; // null
    mForegroundColor = Color(255,255,255);
    mBackgroundColor = Color(0,0,0);
    mFocusHandler = 0; // null
    mMouseListener = 0; // null
    mKeyListener = 0; // null
    mActionListener = 0; // null
    mFocusable = true;
    mClickTimeStamp = 0;
    mClickCount = 0;
    mHasMouse = false;
  }

  /**
   * 
   */
  void Widget::setParent(Widget* parent)
  {
    mParent = parent;
  }

  /**
   * 
   */
  Widget* Widget::getParent() const
  {
    return mParent;
  }

  /**
   * 
   */
  void Widget::setWidth(int width)
  {
    mDimension.width = width;
  }

  /**
   * 
   */
  int Widget::getWidth()
  {
    return mDimension.width;
  }

  /**
   * 
   */
  void Widget::setHeight(int height)
  {
    mDimension.height = height;
  }

  /**
   * 
   */
  int Widget::getHeight()
  {
    return mDimension.height;
  }

  /**
   * 
   */
  void Widget::setX(int x)
  {
    mDimension.x = x;
  }

  /**
   * 
   */
  int Widget::getX()
  {
    return mDimension.x;
  }

  /**
   * 
   */
  void Widget::setY(int y)
  {
    mDimension.y = y;
  }

  /**
   * 
   */
  int Widget::getY()
  {
    return mDimension.y;
  }

  /**
   * 
   */
  void Widget::setPosition(int x, int y)
  {
    mDimension.x = x;
    mDimension.y = y;
  }

  /**
   * 
   */
  void Widget::setDimension(const Rectangle& dimension)
  {
    mDimension = dimension;
  }

  /**
   * 
   */
  const Rectangle& Widget::getDimension()
  {
    return mDimension;
  }
  
  /**
   * 
   */
  void Widget::setFocusable(bool focusable)
  {
    mFocusable = focusable;
  }

  /**
   * 
   */
  const std::string& Widget::getEventId() const
  {
    return mEventId;
  }

  /**
   * 
   */
  void Widget::setEventId(const std::string& eventId)
  {
    mEventId = eventId;
  }
  
  /**
   * 
   */
  bool Widget::hasFocus()
  {
    return false;
    //TODO: return (mFocusHandler->getFocusedWidget() == this)
  }

  /**
   *
   */
  bool Widget::hasMouse()
  {
    return mHasMouse;
  }

  /**
   * 
   */
  bool Widget::isFocusable()
  {
    return mFocusable;
  }
  
  /**
   * 
   */
  void Widget::requestFocus()
  {
    if (isFocusable())
    {
      //TODO: mFocusHandler->requestFocus(this);
    }
  }

  /**
   * 
   */
  void Widget::setVisible(bool visible)
  {
    mVisible = visible;
  }
  
  /**
   * 
   */
  bool Widget::isVisible()
  {
    return mVisible;
  }

  /**
   * 
   */
  void Widget::setForegroundColor(const Color& color)
  {
    mForegroundColor = color;
  }

  /**
   *
   */
  const Color& Widget::getForegroundColor() const
  {
    return mForegroundColor;
  }
  
  /**
   * 
   */
  void Widget::setBackgroundColor(const Color& color)
  {
    mBackgroundColor = color;
  }

  /**
   *
   */
  const Color& Widget::getBackgroundColor() const
  {
    return mBackgroundColor;
  }

  /**
   * 
   */
  const std::string& Widget::getMouseType() const
  {
    return mMouseType;
  }

  /**
   *
   */
  void Widget::setMouseType(const std::string &mouseType)
  {
    mMouseType = mouseType;
  }


  void Widget::_setFocusHandler(FocusHandler* focusHandler)
  {
    if (mFocusHandler)
    {
      mFocusHandler->remove(this);
    }
    
    if (focusHandler)
    {
      focusHandler->add(this);
    }
    
    mFocusHandler = focusHandler;
  }

  void Widget::setActionListener(ActionListener* actionListener)
  {
    mActionListener = actionListener;
  }

  void Widget::setKeyListener(KeyListener* keyListener)
  {
    mKeyListener = keyListener;
  }
  
  void Widget::_mouseInputMessage(const MouseInput& mouseInput)
  {
    int x = mouseInput.x;
    int y = mouseInput.y;
    int b = mouseInput.getButton();
    int ts = mouseInput.getTimeStamp();
      
    switch(mouseInput.getType())
    {
      case MouseInput::MOTION:
        mouseMotionMessage(x, y);
        if (mMouseListener)
        {
          mMouseListener->mouseMotionEvent(mEventId, x, y);
        }
        break;
        
      case MouseInput::PRESS:
        if (b != MouseInput::WHEEL_UP && b != MouseInput::WHEEL_DOWN)
        {
          mousePressMessage(x, y, b);
          if (mMouseListener)
          {
            mMouseListener->mousePressEvent(mEventId, x, y, b);
          }

          // TODO: fajntjuna det här
          if (ts - mClickTimeStamp < 100 && mClickButton == b)
          {
            mClickCount++;
          }
          else
          {
            mClickCount = 0;
          }
          mClickButton = b;
          mClickTimeStamp = ts;
        }
        else if (b == MouseInput::WHEEL_UP)
        {
          mouseWheelUpMessage(x, y);
          if (mMouseListener)
          {
            mMouseListener->mouseWheelUpEvent(mEventId, x, y);
          }                    
        }
        else
        {
          mouseWheelDownMessage(x, y);
          if (mMouseListener)
          {
            mMouseListener->mouseWheelDownEvent(mEventId, x, y);
          }                    
        }
        break;

      case MouseInput::RELEASE:
        if (b != MouseInput::WHEEL_UP && b != MouseInput::WHEEL_DOWN)
        {
          mouseReleaseMessage(x, y, b);
          if (mMouseListener)
          {
            mMouseListener->mouseReleaseEvent(mEventId, x, y, b);
          }
        }

        if (mHasMouse)
        {
          if (b == mClickButton)
          {
            mouseClickMessage(x, y, b, mClickCount+1);
            if (mMouseListener)
            {
              mMouseListener->mouseClickEvent(mEventId, x, y, b, mClickCount+1);
            }
          }
          else
          {
            mouseClickMessage(x, y, b, 1);
            if (mMouseListener)
            {
              mMouseListener->mouseClickEvent(mEventId, x, y, b, 1);
            }
            mClickCount = 0;            
          }
        }
        else
        {
          mClickCount = 0;
          mClickTimeStamp = 0;
        }
        break;
    }
  }

  void Widget::_keyInputMessage(const KeyInput& keyInput)
  {
    switch(keyInput.getType())
    {
      case KeyInput::PRESS:
        keyPressMessage(keyInput.getKey());
        if (mKeyListener)
        {
          mKeyListener->keyPressEvent(mEventId, keyInput.getKey());
        }           
        break;
        
      case KeyInput::RELEASE:
        keyReleaseMessage(keyInput.getKey());
        if (mKeyListener)
        {
          mKeyListener->keyReleaseEvent(mEventId, keyInput.getKey());
        }        
        break;
    }
  }

  void Widget::_mouseInMessage()
  {
    mHasMouse = true;
    mouseInMessage();
  }

  void Widget::_mouseOutMessage()
  {
    mHasMouse = false;
    mouseOutMessage();
  }
  
} // end gcn
