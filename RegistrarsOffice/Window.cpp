#include "Window.h"

bool Window::isOpen()
{
    if (timeLeft<=0)
    {
        timeLeft = 0;
        return true;
    }
    return false;
}
