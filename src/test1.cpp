#include <iostream>
#include <GLFW/glfw3.h>

GLFWwindow* StartGLFW();

int main(){

  GLFWwindow* window = StartGLFW();

  while(!glfwWindowShouldClose(window)){


    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}

GLFWwindow* StartGLFW(){
  if(!glfwInit()){

    std::cerr << "Failed to initialize glfw" << std::endl;
    return nullptr;
  }

  GLFWwindow* window = glfwCreateWindow(800, 600, "Praise The Omnissiah", NULL, NULL);

  if(window == nullptr){
    std::cerr << "Failed to create window" << std::endl;
    return nullptr;
  }

  return window;
}
