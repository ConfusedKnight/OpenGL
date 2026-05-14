#include <iostream>
#include <GLFW/glfw3.h>
#include <cmath>

#define PI 3.14159

GLFWwindow* StartGLFW();
void DrawCircle();

int main(){

  GLFWwindow* window = StartGLFW();

  while(!glfwWindowShouldClose(window)){

    DrawCircle();

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

  glfwMakeContextCurrent(window);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 800, 0, 600, -1, 1);

  glMatrixMode(GL_MODELVIEW);

  return window;
}


void DrawCircle(){

  int screenWidth = 800.0f, screenHeight = 600.0f;

  float centerX = screenWidth / 2.0f;
  float centerY = screenHeight / 2.0f;
  float radius = 50.0f;
  float res = 100;

  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_TRIANGLE_FAN);
  glVertex2f(centerX, centerY);

  for(int i=0; i<=res; i++){
    float angle = 2.0f * PI * i / res;
    float x = centerX + cos(angle) * radius; 
    float y = centerY + sin(angle) * radius;
    glVertex2f(x,y);
  }

  glEnd();
}
