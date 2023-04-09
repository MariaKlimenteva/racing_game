#include "window.h"

window::window(const std::string& title, int width, int height)
{
    window_ = glfwCreateWindow(854, 500, "Races", NULL, NULL);
    
    if(!window_)
    {
        std::cout << "Failed to open window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
}

void window::setContextCurrent()
{
    glfwMakeContextCurrent(window_);
}

void window::loop()
{
    while (!glfwWindowShouldClose(window_))
    {
        glClearColor(1, 1, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window_);
        glfwPollEvents();
    }
}
window::~window()
{
    glfwDestroyWindow(window_);
}