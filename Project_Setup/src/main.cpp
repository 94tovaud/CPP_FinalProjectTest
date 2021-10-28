//#include <gl/gl.h>
#include <Windows.h>
#include <GL/glew.h> // needs to be included before glfw
#include <GLFW/glfw3.h>
#include <stdio.h>


int main(int argc, char* argv[]) {
printf("hello");

  // 1. Initialize GLFW
  if (!glfwInit())
  {
    printf("Failed to initialize GLFW.\n");
    return 1;
  }

  // tell glfw that we want to use OpenGL 3.3+
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // tell glfw that the window should be floating on top of other windows
  glfwWindowHint(GLFW_FLOATING, GL_TRUE);

  // tell glfw that the window should not be resizable
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  // 2. Create main window
  GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
  if (!window)
  {
    printf("Failed to create window.\n");
    return 1;
  }


  // tell GLFW that we want to draw on this specific window
  glfwMakeContextCurrent(window);

  // 3. Initialize GLEW (api to use OpenGL)
  GLenum err = glewInit();
  if (err != GLEW_OK) {
    fprintf(stderr, "GLEW error: %s\n", glewGetErrorString(err));
    return 1;
  }


  // application main loop
  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear screen
    glClearColor(0, 255, 0, 1); // fill screen with green color
    glViewport(0, 0, 640, 480); // remind OpenGL about our window size.

    // update and draw here

    glfwSwapBuffers(window); // tell glfw to go to next frame
    glfwPollEvents();
  }


  // window was closed, so let's exit.
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
