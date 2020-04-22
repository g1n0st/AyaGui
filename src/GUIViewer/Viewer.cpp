#include <GUI/AyaGUI.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace Aya;

void InitializeWindowsInfo() {
	HWND hwnd = GetConsoleWindow();

	HGLRC mhRC;
	HDC mhDC;

	PIXELFORMATDESCRIPTOR pf = {
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		24,
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		32,
		0,
		0,
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};
	mhDC = GetDC(hwnd);
	int idx = ChoosePixelFormat(mhDC, &pf);
	SetPixelFormat(mhDC, idx, &pf);

	mhRC = wglCreateContext(mhDC);
	wglMakeCurrent(mhDC, mhRC);
}

void OnResize(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void OnEvent(GLFWwindow *window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

int main() {
	InitializeWindowsInfo();
	InitializeOpenGLExtensions();
	GUIRenderer *mpGUIRender = GUIRenderer::instace();

	glfwInit();

	GLFWwindow* window = glfwCreateWindow(1280, 800, "OpenGLTest", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window " << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, OnEvent);

	glViewport(0, 0, 1280, 800);
	glfwSetFramebufferSizeCallback(window, OnResize);

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Main Loop here ...

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	GUIRenderer::deleteInstance();

	return 0;
}