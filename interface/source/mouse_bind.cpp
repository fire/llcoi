#include "mouse_bind.h"
#include "binding_utils.h" // ois_mouse_event_to_llcoi_mouse_event

#include <OISMouse.h>

void mouse_set_buffered(MouseInputHandle mouse_handle, int buffered)
{
    OIS::Mouse* mouse = reinterpret_cast<OIS::Mouse*>(mouse_handle);
    mouse->setBuffered((bool)buffered);
}

void mouse_capture(MouseInputHandle mouse_handle)
{
    OIS::Mouse* mouse = reinterpret_cast<OIS::Mouse*>(mouse_handle);
    mouse->capture();
}

MouseState mouse_get_state(MouseInputHandle mouse_handle)
{
    OIS::Mouse* mouse = reinterpret_cast<OIS::Mouse*>(mouse_handle);
    OIS::MouseState state = mouse->getMouseState();
    MouseState out_state;
    out_state.buttons = state.buttons;
    out_state.height = state.height;
    out_state.width = state.width;
    out_state.X.abs = state.X.abs;
    out_state.X.rel = state.X.rel;
    out_state.X.absOnly = state.X.absOnly;
    out_state.Y.abs = state.Y.abs;
    out_state.Y.rel = state.Y.rel;
    out_state.Y.absOnly = state.Y.absOnly;
    out_state.Z.abs = state.Z.abs;
    out_state.Z.rel = state.Z.rel;
    out_state.Z.absOnly = state.Z.absOnly;
    return out_state;
}



class MouseListenerCTX : public OIS::MouseListener
{
public:
    MouseListenerCTX(MouseMovedEvent _moved, MousePressedEvent _pressed, MouseReleasedEvent _released, void* data) : 
                     moved(_moved), pressed(_pressed), released(_released), userdata(data)
    {
    }

    bool mouseMoved(const OIS::MouseEvent &arg)
    {
        MouseEvent evt;
        bool result;

        // Convert OIS MouseEvent to LLCOI MouseEvent
        ois_mouse_event_to_llcoi_mouse_event(&arg, &evt);

        // Fire off the callback.
        result = moved(&evt, userdata);
        return result;
    }

    bool mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
    {
        MouseEvent evt;
        MouseButtonID llcoi_id;
        bool result;

        // Convert OIS MouseEvent to LLCOI MouseEvent
        ois_mouse_event_to_llcoi_mouse_event(&arg, &evt);

        llcoi_id = ois_mbid_to_llcoi_mbid(id);

        // Fire off the callback.
        result = pressed(&evt, llcoi_id, userdata);
        return result;
    }

    bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
    {
        MouseEvent evt;
        MouseButtonID llcoi_id;
        bool result;

        // Convert OIS MouseEvent to LLCOI MouseEvent
        ois_mouse_event_to_llcoi_mouse_event(&arg, &evt);

        llcoi_id = ois_mbid_to_llcoi_mbid(id);

        // Fire off the callback.
        result = released(&evt, llcoi_id, userdata);
        return result;
    }

    MouseMovedEvent moved;
    MousePressedEvent pressed;
    MouseReleasedEvent released;

    void* userdata;
};

MouseListenerHandle mouse_set_event_callback(MouseInputHandle handle, MouseMovedEvent moved, MousePressedEvent pressed, MouseReleasedEvent released, void* userdata)
{
    OIS::Mouse* mouse = reinterpret_cast<OIS::Mouse*>(handle);

    MouseListenerCTX* listener = new MouseListenerCTX(moved, pressed, released, userdata);

    mouse->setEventCallback(listener);
    return reinterpret_cast<MouseListenerHandle>(listener);
}

void mouse_remove_event_callback(MouseInputHandle mouse_handle, MouseListenerHandle handle)
{
    OIS::Mouse* mouse          = reinterpret_cast<OIS::Mouse*>(mouse_handle);
    MouseListenerCTX* listener = reinterpret_cast<MouseListenerCTX*>(handle);
    mouse->setEventCallback(0);
    delete listener;
}
