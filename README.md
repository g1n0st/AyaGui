# AyaGui

Last update: 2020/5/11

g1n0st

**AyaGui** is a lite imgui-mode graphical user interface library based on Modern C++ and OpenGL developed by g1n0st, inspired by Dear imgui.  It is lite, portable and self - contained(no external dependencies) You can easily integrate it into your 3D - pipeline enabled application at any time.

**AyaGui** is designed to enable fast iterations and to empower programmers to create content creation tools  and visualization / debug tools(as opposed to UI for the average end - user).  It favors simplicity and productivity toward this goal,  and lacks certain features normally found in more high - level libraries. 

**AyaGui** is particularly suited to integration in games engine(for tooling), real - time 3D applications,   full-screen applications, embedded applications, or any applications on consoles platforms where operating system features are non - standard

## Usage

Before use AyaGui and create windows, you should initialize windows info, just like the function as follows in `GuiViewer/glfwViewer.h`:

```c++
void InitializeWindowsInfo();
```



the input message context of AyaGui is independent of the platform and highly abstraction, you should bind input to AyaGui handful. Our demo gives an simple example of glfw, you can see these functions as follows in `GuiViewer/glfwViewer.h`:

```c++
void OnResize(GLFWwindow* window, int width, int height);
void OnKeyboardEvent(GLFWwindow *window, int key, int scancode, int action, int mods);
void OnMouseEvent(GLFWwindow *window, int key, int action, int mods);
void OnCursorEvent(GLFWwindow *window, double x, double y);
```

Before the rendering loop, initiaze AyaGui and make an resize call first:

```c++
AyaGui::Init();
AyaGui::Resize(1280, 800);
```

All preparation is done! Just create GUI you need in the rendering loop!

##  Demo

You can see our complete demo in `GuiViewer/demo.cpp`, here gives an example corresponded to Dear imgui demo:

```c++
AyaGui::Text("Hello, world %d", 123);
if (AyaGui::Button("Save"))
    MySaveFunction();
AyaGui::InputText(buf);
AyaGui::Slider<float>("float", f, 0.0f, 1.0f);
```

The screen shot of the complete demo:

![AyaGui demo]( https://img-blog.csdnimg.cn/20200510232210656.png )

## License

AyaGui is licensed under the GNU License, see LICENSE.txt for more information. However, unless you really care about the license, you can almost ignore it.

Well, good luck and have fun! : )