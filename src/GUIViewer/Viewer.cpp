#include <Gui/AyaGui.h>

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
	//glViewport(0, 0, width, height);
	//mpGUIRender->resize(width, height);
	AyaGui::Resize(width, height);
}

KeyboardEvent keyboardEvent;
void OnKeyboardEvent(GLFWwindow *window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}

	if (action == GLFW_PRESS) {
		switch (key) {
		case GLFW_KEY_ESCAPE:
			keyboardEvent.funckey = FunctionKey::Esc;
			break;
		case GLFW_KEY_ENTER:
			keyboardEvent.funckey = FunctionKey::Enter;
			break;
		case GLFW_KEY_LEFT:
			keyboardEvent.funckey = FunctionKey::LeftArrow;
			break;
		case GLFW_KEY_RIGHT:
			keyboardEvent.funckey = FunctionKey::RightArrow;
			break;
		case GLFW_KEY_DOWN:
			keyboardEvent.funckey = FunctionKey::DownArrow;
			break;
		case GLFW_KEY_UP:
			keyboardEvent.funckey = FunctionKey::UpArrow;
			break;
		case GLFW_KEY_INSERT:
			keyboardEvent.funckey = FunctionKey::Insert;
			break;
		case GLFW_KEY_BACKSPACE:
			keyboardEvent.funckey = FunctionKey::BackSpace;
			break;
		case GLFW_KEY_DELETE:
			keyboardEvent.funckey = FunctionKey::Delete;
			break;
		case GLFW_KEY_TAB:
			keyboardEvent.funckey = FunctionKey::Tab;
			break;
		case GLFW_KEY_HOME:
			keyboardEvent.funckey = FunctionKey::Home;
			break;
		case GLFW_KEY_END:
			keyboardEvent.funckey = FunctionKey::End;
			break;
		default:
			keyboardEvent.funckey = FunctionKey::None;
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
int last_left_click;
int last_right_click;
int double_click_interval = 500;
void OnMouseEvent(GLFWwindow *window, int key, int action, int mods) {
	//mouse_event.action = MouseAction::
	if (key == GLFW_MOUSE_BUTTON_LEFT) {
		last_right_click = 0;

		if (action == GLFW_PRESS) {
			mouseEvent.l_down = true;
			if (std::clock() - last_left_click < double_click_interval) {
				last_left_click = 0;
				mouseEvent.action = MouseAction::LButtonDbClick;
			}
			else {
				last_left_click = std::clock();
				mouseEvent.action = MouseAction::LButtonDown;
			}
		}
		else if (action == GLFW_RELEASE) {
			mouseEvent.l_down = false;
			mouseEvent.action = MouseAction::LButtonUp;
		}
	}
	if (key == GLFW_MOUSE_BUTTON_RIGHT) {
		last_left_click = 0;

		if (action == GLFW_PRESS) {
			mouseEvent.r_down = true;
			if (std::clock() - last_right_click < double_click_interval) {
				last_right_click = 0;
				mouseEvent.action = MouseAction::RButtonDbClick;
			}
			else {
				last_right_click = std::clock();
				mouseEvent.action = MouseAction::RButtonDown;
			}
		}
		else if (action == GLFW_RELEASE) {
			mouseEvent.r_down = false;
			mouseEvent.action = MouseAction::RButtonUp;
		}
	}

	AyaGui::HandleMouseEvent(mouseEvent);
}
void OnCursorEvent(GLFWwindow *window, double x, double y) {
	int x0 = int(x), y0 = int(y);
	if (x0 != mouseEvent.x || y0 != mouseEvent.y) {
		last_left_click = 0;
		last_right_click = 0;
		mouseEvent.x = x0;
		mouseEvent.y = y0;
	}
	mouseEvent.action = MouseAction::Move;
	AyaGui::HandleMouseEvent(mouseEvent);
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
	glfwSetKeyCallback(window, OnKeyboardEvent);
	glfwSetMouseButtonCallback(window, OnMouseEvent);
	glfwSetCursorPosCallback(window, OnCursorEvent);
	

	glViewport(0, 0, 1280, 800);
	glfwSetFramebufferSizeCallback(window, OnResize);

	AyaGui::Init();
	AyaGui::Resize(1280, 800);

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		AyaGui::BeginFrame();

		AyaGui::BeginSidebarDialog(LayoutStrategy::DockLeft);
		AyaGui::EndDialog();

		AyaGui::BeginSidebarDialog(LayoutStrategy::DockRight);
		AyaGui::EndDialog();
		int x = mouseEvent.x, y = mouseEvent.y;
		AyaGui::BeginDialog(x, y, 500, 500);
		AyaGui::EndDialog();

		AyaGui::EndFrame();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	AyaGui::Release();

	glfwTerminate();
	GuiRenderer::deleteInstance();

	return 0;
}