#include "./src/Window/Window.h"

int main() 
{   

    Windows windows;
    while(windows.getWindows().isOpen())
    {
        windows.update();
        windows.render();
    }
    return 0;
}
