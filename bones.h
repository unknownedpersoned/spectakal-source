#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <malloc.h>

static GLFWwindow*  _B_window;

// (#B_initialize)
// Initializes bones's backend (GLFW and GLEW).
//
// RETURNS: Status. Less than 1 means bones failed to initialize.
int B_initialize();

// (#B_destory)
// Destorys bones's backend (GLFW) and terminates all windows.
void B_destroy();

// (#B_mk_window)
// Creates/Initializes a window that can be drawn to.
//
// RETURNS: Window identifier. Store this number to keep track of your window.
//
// "descriptor": Description of window content. Appears as title of window.
int B_mk_window(int width, int height, char* descriptor);

// (#B_free_window)
// Frees the memory that a window takes up, and destroys it.
void B_free_window();

int B_initialize() {
	glewExperimental = GL_TRUE;
	glewInit();
	return glfwInit();
}

void B_destroy() {
	glfwTerminate();
}

int B_mk_window(int width, int height, char* descriptor) {
	_B_window = glfwCreateWindow(width, height, descriptor, NULL, NULL);
	glfwMakeContextCurrent(_B_windows);
}

