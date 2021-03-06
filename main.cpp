#define GLM_ENABLE_EXPERIMENTAL

#ifdef __linux__
#define GL_GLEXT_PROTOTYPES
#endif

#include "Shader.h"
#include "Shader.h"
#include "Tree.h"
#include <GLFW/glfw3.h>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/type_ptr.hpp>

//Hadles resizing of window
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

//Handles user input
void processInput(GLFWwindow *window);

GLFWwindow* initializeWindow(int width, int height, const char* title);

glm::mat4 createPerspective(float vfov, float aspect, float znear, float zfar);

bool resetTree=false;

int main()
{
    GLFWwindow* window = initializeWindow(800,800,"Trees");

    Tree* treeBoi = new Tree();
    MatrixStack SceneGraph;
    glm::mat4 per = createPerspective(0.8f, 1.0f, 0.1f, 20.0f);
    glm::mat4 identity(1.0f);
    float angle = 0;

    Shader ourShader("vertex.glsl", "fragment.glsl");

    GLint location_PER = glGetUniformLocation( ourShader.ID, "PER" );

    //Drawing mode
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST); // Use the Z buffer
    glEnable(GL_CULL_FACE);  // Use back face culling
    glCullFace(GL_BACK);


    //Rendering Loop
    while(!glfwWindowShouldClose(window))
    {
        processInput(window);
        if(resetTree) {
            delete treeBoi;
            treeBoi = new Tree();
            resetTree=false;
        }

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ourShader.use();
        SceneGraph.push();
        angle+= 0.01;
        SceneGraph.addTransformation(glm::translate(identity, glm::vec3(0.0f, -3.0f, -8.0f)));
        SceneGraph.addTransformation(glm::rotate(identity, angle, glm::vec3(0.0f, 1.0f, 0.0f)));
        glUniformMatrix4fv( location_PER, 1, GL_FALSE, glm::value_ptr(per));
        treeBoi->Draw(ourShader, SceneGraph);
        SceneGraph.flush();

        glfwSwapBuffers(window);
        glfwPollEvents();    
    }

    //Close window
    delete treeBoi;
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

    if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    if(glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
        resetTree=true;
}

GLFWwindow* initializeWindow(int width, int height, const char* title)
{
    //Initializing GLFW
	glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


    //Creating a window object
    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(window);

    //Fetching pointers to OpenGL functions
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }

    //Set size of rendering window
    glViewport(0, 0, width, height);

    //Set resize functiont to framebuffer_size_callback
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    return window;
}

glm::mat4 createPerspective(float vfov, float aspect, float znear, float zfar){

    float f = 1/tan(vfov/2); //cot(vfov/2)
    float A = -(zfar+znear)/(zfar-znear);
    float B = -(2*znear*zfar)/(zfar-znear);
    glm::mat4 M(0.0f);

    M[0][0] = f/aspect;
    M[1][1] = f;
    M[2][2] = A;
    M[3][2] = B;
    M[2][3] = -1;
    return M;
}