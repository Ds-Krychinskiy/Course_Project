#include "./src/Window/Window.h"

int main() 
{   
    srand(time(static_cast<unsigned>(0)));
    Windows windows;
    while(windows.getWindows().isOpen())
    {
        windows.update();
        windows.render();
    }
    return 0;
}
