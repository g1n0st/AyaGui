#include "ayagui.h"
#include <GLFW\glfw3.h>

using namespace Aya;

void InitializeWindowsInfo() {
	HWND hwnd = GetConsoleWindow();

	HGLRC mhRC;
	HDC mhDC;

	PIXELFORMATDESCRIPTOR pf =
	{
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
int main(void) {
	InitializeWindowsInfo();
	InitializeOpenGLExtensions();
	GUIRenderer *mp = GUIRenderer::instace();
	glBegin(GL_QUADS);

	glVertex3f(1, 0, 1);
	glVertex3f(0, 1, 1);
	glVertex3f(1, 1, 1);
	glVertex3f(0, 0, 1);

	glEnd();
	GUIRenderer::deleteInstance();
	return 0;
}