#include "include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include "Shader.h"
#include "Mesh.h"

//Hadles resizing of window
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

//Handles user input
void processInput(GLFWwindow *window);

int main()
{
    //Initializing GLFW
	glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


    //Creating a window object
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    //Fetching pointers to OpenGL functions
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //Set size of rendering window
    glViewport(0, 0, 800, 600);

    //Set resize functiont to framebuffer_size_callback
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    std::vector<Vertex> vertices;
    vertices.push_back(Vertex(glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f)));
    vertices.push_back(Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f)));
    vertices.push_back(Vertex(glm::vec3(0.0f,  0.5f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f)));

    std::vector<unsigned int> indices;
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(2);

    Mesh triangleDeluxe(vertices, indices);

    Shader ourShader("vertex.glsl", "fragment.glsl");

    //Drawing mode
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


    //Rendering Loop
    while(!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ourShader.use();
        triangleDeluxe.Draw(ourShader);

        glfwSwapBuffers(window);
        glfwPollEvents();    
    }

    //Close window
    glfwTerminate();
    return 0;
}

//Hadle resizing of window
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

//Hadles resizing of window
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}