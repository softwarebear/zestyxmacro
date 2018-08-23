#define EVENT_CODE_GENERATOR(SELECTOR) \
    SELECTOR(LeftMouseDown, LBUTTONDOWN, 0x0201) \
    SELECTOR(LeftMouseUp, LBUTTONUP, 0x0202) \
    SELECTOR(LeftMouseDoubleClick, LBUTTONDBLCLK, 0x0203)

#define EVENT_ENUMS(function, message, number) WM_##message=number, 

typedef enum 
{ 
    EVENT_CODE_GENERATOR( EVENT_ENUMS ) 
    MaxEventNumber 
} WindowsEvent;

#define EVENT_OBSERVERS(function, message, number) void On##function(WindowsEvent windowsEvent)\
{\
    if (windowsEvent != WM_##message)\
    { throw "On" #function "() received some windowsEvent other than WM_" #message; } \
}

EVENT_CODE_GENERATOR( EVENT_OBSERVERS )

int main(int, char**)
{
    WindowsEvent windowsEvent = WindowsEvent::WM_LBUTTONUP;
    OnLeftMouseUp(windowsEvent);
}