#include "glfw.h"

glfw::glfw()
{
    if(!glfwInit())
    {
        std::cout << "Initialization GLFW error \n" << std::endl;
        exit(EXIT_FAILURE);
    }
}

glfw::~glfw()
{
    glfwTerminate();
}