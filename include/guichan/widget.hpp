#ifndef GCN_WIDGET_HPP
#define GCN_WIDGET_HPP

#include <string>

#include "guichan/actionlistener.hpp"
#include "guichan/color.hpp"
#include "guichan/graphics.hpp"
#include "guichan/keyinput.hpp"
#include "guichan/keylistener.hpp"
#include "guichan/mouseinput.hpp"
#include "guichan/mouselistener.hpp"
#include "guichan/rectangle.hpp"

namespace gcn
{
  class FocusHandler;

  /**
   * 
   */
  class Widget
  {
  public:
    /**
     *
     */
    Widget();
    
    /**
     * 
     */
    virtual ~Widget(){}

    /**
     * 
     */
    virtual void logic() = 0;

    /**
     * 
     */
    virtual void draw(Graphics* graphics) = 0;

    /**
     * 
     */
    virtual Widget* getParent() const;
    
    /**
     * 
     */
    virtual void setWidth(int width);

    /**
     * 
     */
    virtual int getWidth();
    
    /**
     * 
     */
    virtual void setHeight(int height);

    /**
     * 
     */
    virtual int getHeight();

    /**
     * 
     */
    virtual void setX(int x);

    /**
     * 
     */
    virtual int getX();

    /**
     * 
     */
    virtual void setY(int y);

    /**
     * 
     */
    virtual int getY();

    /**
     * 
     */
    virtual void setPosition(int x, int y);
    
    /**
     * 
     */
    virtual void setDimension(const Rectangle& dimension);
    
    /**
     * 
     */
    virtual const Rectangle& getDimension();

    /**
     * 
     */
    virtual void setFocusable(bool focusable);

    /**
     * 
     */
    bool hasFocus();

    /**
     *
     */
    bool hasMouse();

    /**
     * 
     */
    virtual bool isFocusable();
    
    /**
     * 
     */
    virtual void setVisible(bool visible);

    /**
     * 
     */
    virtual bool isVisible();

    /**
     * 
     */
    virtual void setForegroundColor(const Color& color);

    /**
     *
     */
    virtual const Color& getForegroundColor() const;
    
    /**
     * 
     */
    virtual void setBackgroundColor(const Color& color);

    /**
     *
     */
    virtual const Color& getBackgroundColor() const;    
    
    /**
     * 
     */
    virtual void keyPressMessage(const Key& key){}

    /**
     * 
     */
    virtual void keyReleaseMessage(const Key& key){}
    
    /**
     * Hanteras av förälderobjekt.
     */
    virtual void mouseInMessage(){}
    
    /**
     * Hanteras av förälderobjekt.
     */
    virtual void mouseOutMessage(){}
    
    /**
     * 
     */
    virtual void mousePressMessage(int x, int y, int button){}
    
    /**
     * 
     */
    virtual void mouseReleaseMessage(int x, int y, int button){}
    
    /**
     * Mouse intryckt och släppt på widget resulterar i ett click.
     */
    virtual void mouseClickMessage(int x, int y, int button, int count){}
    
    /**
     * 
     */
    virtual void mouseWheelUpMessage(int x, int y){}

    /**
     * 
     */
    virtual void mouseWheelDownMessage(int x, int y){}

    /**
     * 
     */
    virtual void mouseMotionMessage(int x, int y){}

    /**
     * 
     */
    virtual void setMouseType(const std::string& mouseType);

    /**
     * 
     */
    virtual const std::string& getMouseType() const;
        
    /**
     * Musmedelanden propageras till barnobjekt om de inte är
     * i fokus. Detta för att undkiva dubblarade medelanden då
     * medelanden alltid skickas till fokuserat object.
     * Föräldraobjektet har ansvar för att skicka _mouseIn/Out
     * till barnen.
     */
    virtual void _mouseInputMessage(const MouseInput& mouseInput);

    /**
     * Skickas bara till fokuserat objekt.
     */
    virtual void _keyInputMessage(const KeyInput& keyInput);

    /**
     *
     */
    void _mouseInMessage();

    /**
     *
     */
    void _mouseOutMessage();
    
    /**
     * 
     */
    void requestFocus();

    /**
     * Should be propagated to child widgets when called
     */
    virtual void _setFocusHandler(FocusHandler* focusHandler);

    /**
     * 
     */
    void setActionListener(ActionListener* actionListener);

    /**
     * 
     */
    void setMouseListener(MouseListener* mouseListener);
    
    /**
     * 
     */
    void setKeyListener(KeyListener* keyListener);

    /**
     * 
     */
    void setEventId(const std::string& eventId);

    /**
     * 
     */
    virtual const std::string& getEventId() const;

    /**
     * Skicka actionEvent ifall att actionlistener inte är null. 
     */
    void sendActionEvent();

  protected:
    /**
     * 
     */
    void setParent(Widget* parent);

    Rectangle mDimension;
    bool mFocusable;
    bool mVisible;
    Widget* mParent;
    Color mForegroundColor;
    Color mBackgroundColor;
    std::string mMouseType;
    FocusHandler* mFocusHandler;
    
  private:
    /**
     * Dessa är private då vi inte anser att de bör pillas på.
     */
    MouseListener* mMouseListener;
    KeyListener* mKeyListener;
    ActionListener* mActionListener;
    std::string mEventId;
    int mClickTimeStamp;
    int mClickCount;
    int mClickButton;
    bool mHasMouse;
  }; // end Widget
  
} // end gcn

#endif // end GCN_WIDGET_HPP
