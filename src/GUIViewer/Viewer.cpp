#include <Gui/Gui.h>

#include <GLFW/glfw3.h>
#include <iostream>
#include <ctime>

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
	AyaGui::Resize(width, height);
}

void OnKeyboardEvent(GLFWwindow *window, int key, int scancode, int action, int mods) {
	static KeyboardEvent keyboardEvent;

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}

	if (action == GLFW_PRESS) {
		switch (key) {
		case GLFW_KEY_ESCAPE: keyboardEvent.funckey = FunctionKey::Esc; break;
		case GLFW_KEY_ENTER: keyboardEvent.funckey = FunctionKey::Enter; break;
		case GLFW_KEY_LEFT: keyboardEvent.funckey = FunctionKey::LeftArrow; break;
		case GLFW_KEY_RIGHT: keyboardEvent.funckey = FunctionKey::RightArrow; break;
		case GLFW_KEY_DOWN: keyboardEvent.funckey = FunctionKey::DownArrow; break;
		case GLFW_KEY_UP: keyboardEvent.funckey = FunctionKey::UpArrow; break;
		case GLFW_KEY_INSERT: keyboardEvent.funckey = FunctionKey::Insert; break;
		case GLFW_KEY_BACKSPACE: keyboardEvent.funckey = FunctionKey::BackSpace; break;
		case GLFW_KEY_DELETE: keyboardEvent.funckey = FunctionKey::Delete; break;
		case GLFW_KEY_TAB: keyboardEvent.funckey = FunctionKey::Tab; break;
		case GLFW_KEY_HOME: keyboardEvent.funckey = FunctionKey::Home; break;
		case GLFW_KEY_END: keyboardEvent.funckey = FunctionKey::End; break;
		case GLFW_KEY_PAGE_UP: keyboardEvent.funckey = FunctionKey::PageUp; break;
		case GLFW_KEY_PAGE_DOWN: keyboardEvent.funckey = FunctionKey::PageDown; break;
		default: keyboardEvent.funckey = FunctionKey::None;
		}

		keyboardEvent.key = key;
		keyboardEvent.keymode = KeyMode::None;

		if (mods | GLFW_MOD_CONTROL) keyboardEvent.keymode = KeyMode(keyboardEvent.keymode | Ctrl);
		if (mods | GLFW_MOD_SHIFT) keyboardEvent.keymode = KeyMode(keyboardEvent.keymode | Shift);
		if (mods | GLFW_MOD_ALT) keyboardEvent.keymode = KeyMode(keyboardEvent.keymode | Alt);
	}
	else if (action == GLFW_RELEASE) {
		keyboardEvent.key = 0;
		keyboardEvent.funckey = FunctionKey::None;
		keyboardEvent.keymode = KeyMode::None;
	}

	AyaGui::HandleKeyboardEvent(keyboardEvent);
}

MouseEvent mouseEvent;
int lastLeftClick;
int lastRightClick;

void OnMouseEvent(GLFWwindow *window, int key, int action, int mods) {
	const int doubleClickInterval = 200;

	auto keyAction = [&](bool &down, MouseAction &mouse, int &lastClick,
		const int Mode, const MouseAction DbClock, const MouseAction Down, const MouseAction Up) {
		if (key == Mode) {
			lastClick = 0;

			if (action == GLFW_PRESS) {
				down = true;
				if (std::clock() - lastClick < doubleClickInterval) {
					lastClick = 0;
					mouse = DbClock;
				}
				else {
					lastClick = std::clock();
					mouse = Down;
				}
			}
			else if (action == GLFW_RELEASE) {
				down = false;
				mouse = Up;
			}
		}
	};

	keyAction(mouseEvent.l_down, mouseEvent.action, lastLeftClick, GLFW_MOUSE_BUTTON_LEFT, 
		MouseAction::LButtonDbClick, MouseAction::LButtonDown, MouseAction::LButtonUp);
	keyAction(mouseEvent.r_down, mouseEvent.action, lastRightClick, GLFW_MOUSE_BUTTON_RIGHT, 
		MouseAction::RButtonDbClick, MouseAction::RButtonDown, MouseAction::RButtonUp);

	AyaGui::HandleMouseEvent(mouseEvent);
}
void OnCursorEvent(GLFWwindow *window, double x, double y) {
	if (int(x) != mouseEvent.x || int(y) != mouseEvent.y) {
		lastLeftClick = 0;
		lastRightClick = 0;
		mouseEvent.x = int(x);
		mouseEvent.y = int(y);
	}

	mouseEvent.action = MouseAction::Move;
	AyaGui::HandleMouseEvent(mouseEvent);
}

int main() {
	InitializeWindowsInfo();
	InitializeOpenGLExtensions();

	glfwInit();

	GLFWwindow* window = glfwCreateWindow(1280, 800, "AyaGui glfw Viewer", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window " << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, OnKeyboardEvent);
	glfwSetMouseButtonCallback(window, OnMouseEvent);
	glfwSetCursorPosCallback(window, OnCursorEvent);
	

	glViewport(0, 0, 1280, 800);
	glfwSetFramebufferSizeCallback(window, OnResize);

	AyaGui::Init();
	AyaGui::Resize(1280, 800);

	int x = 300, y = 300;
	int x0 = 450, y0 = 600;
	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// ...

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	AyaGui::Release();
	glfwTerminate();

	return 0;
}