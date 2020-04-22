#include <GUI/AyaGUI.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace Aya;

GUIRenderer *mpGUIRender;

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
	mpGUIRender->resize(width, height);
}

void OnEvent(GLFWwindow *window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

int main() {
	InitializeWindowsInfo();
	InitializeOpenGLExtensions();

	glfwInit();

	GLFWwindow* window = glfwCreateWindow(1280, 800, "AyaGUI Viewer", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window " << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, OnEvent);

	glViewport(0, 0, 1280, 800);
	glfwSetFramebufferSizeCallback(window, OnResize);

	mpGUIRender = GUIRenderer::instace();
	mpGUIRender->resize(1280, 800);

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Main Loop here ...
		glClear(GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		glOrtho(0, 1280, 0, 800, 1, -1);

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		mpGUIRender->drawLine(100, 100, 300, 300, 0.3f);
		mpGUIRender->drawRoundedRect(30, 30, 400, 400, 0.2f, 50, false);
		mpGUIRender->drawCircle(500, 500, 0.1f, 150, true, Color4f(0.5f, 0.6f, 0.7f, 0.5f));
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		mpGUIRender->drawString(50, 50, 0.1f, "glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);");
		mpGUIRender->drawString(300, 500, 0.1f, "glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);");
		mpGUIRender->blurBackgroundTexture(0, 0, 300, 300);
		mpGUIRender->drawBackgroundTexture(0, 0, 300, 300);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	GUIRenderer::deleteInstance();

	return 0;
}