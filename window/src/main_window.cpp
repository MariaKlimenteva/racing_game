#include "glfw.h"
#include "window.h"

int main()
{
    glfw glfw;
    window window("Races", 840, 500);
    window.setContextCurrent();
    window.loop();
    exit(EXIT_SUCCESS);
}