#include <iostream>
#include <GLFW/glfw3.h>
#include <string>

class window
{
 public:
    GLFWwindow* window_;

    window(const std::string& title, int width, int height);
    void setContextCurrent();
    void loop();
    ~window();
};



