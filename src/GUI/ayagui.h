#ifndef AYA_GUI_H
#define AYA_GUI_H

#include <cassert>
#include <cmath>
#include <cstring>
#include <vector>
#include <Windows.h>
#include <minwindef.h>

#include <gl/glew.h>
#include <gl/GL.h>
#include <gl/GLU.h>

namespace Aya {
	// OpenGL Extension Loader
	extern PFNGLCREATESHADERPROC							glCreateShader;
	extern PFNGLCREATEPROGRAMPROC							glCreateProgram;
	extern PFNGLDELETESHADERPROC							glDeleteShader;
	extern PFNGLDELETEPROGRAMPROC							glDeleteProgram;
	extern PFNGLATTACHSHADERPROC							glAttachShader;
	extern PFNGLDETACHSHADERPROC							glDetachShader;
	extern PFNGLSHADERSOURCEPROC							glShaderSource;
	extern PFNGLCOMPILESHADERPROC							glCompileShader;
	extern PFNGLLINKPROGRAMPROC								glLinkProgram;
	extern PFNGLVALIDATEPROGRAMPROC							glValidateProgram;
	extern PFNGLUSEPROGRAMPROC								glUseProgram;
	extern PFNGLGETSHADERINFOLOGPROC						glGetShaderInfoLog;
	extern PFNGLGETPROGRAMINFOLOGPROC						glGetProgramInfoLog;
	extern PFNGLGETSHADERIVPROC								glGetShaderiv;
	extern PFNGLGETPROGRAMIVPROC							glGetProgramiv;
	extern PFNGLUNIFORM1FPROC								glUniform1f;
	extern PFNGLUNIFORM1FVPROC								glUniform1fv;
	extern PFNGLUNIFORM2FPROC								glUniform2f;
	extern PFNGLUNIFORM2FVPROC								glUniform2fv;
	extern PFNGLUNIFORM3FPROC								glUniform3f;
	extern PFNGLUNIFORM4FPROC								glUniform4f;
	extern PFNGLUNIFORM1IPROC								glUniform1i;
	extern PFNGLUNIFORM1IVPROC								glUniform1iv;
	extern PFNGLUNIFORM2IPROC								glUniform2i;
	extern PFNGLUNIFORM3IPROC								glUniform3i;
	extern PFNGLUNIFORM4IPROC								glUniform4i;
	extern PFNGLUNIFORMMATRIX3FVPROC						glUniformMatrix3fv;
	extern PFNGLUNIFORMMATRIX4FVPROC						glUniformMatrix4fv;
	extern PFNGLGETUNIFORMLOCATIONPROC						glGetUniformLocation;
	extern PFNGLBINDFRAGDATALOCATIONEXTPROC					glBindFragDataLocation;
	extern PFNGLISRENDERBUFFEREXTPROC						glIsRenderbuffer;
	extern PFNGLBINDRENDERBUFFEREXTPROC						glBindRenderbuffer;
	extern PFNGLDELETERENDERBUFFERSEXTPROC					glDeleteRenderbuffers;
	extern PFNGLGENRENDERBUFFERSEXTPROC						glGenRenderbuffers;
	extern PFNGLRENDERBUFFERSTORAGEEXTPROC					glRenderbufferStorage;
	extern PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC		glRenderbufferStorageMultisample;
	extern PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC			glGetRenderbufferParameteriv;
	extern PFNGLISFRAMEBUFFEREXTPROC						glIsFramebuffer;
	extern PFNGLBINDFRAMEBUFFEREXTPROC						glBindFramebuffer;
	extern PFNGLDELETEFRAMEBUFFERSEXTPROC					glDeleteFramebuffers;
	extern PFNGLGENFRAMEBUFFERSEXTPROC						glGenFramebuffers;
	extern PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC				glCheckFramebufferStatus;
	extern PFNGLFRAMEBUFFERTEXTURE1DEXTPROC					glFramebufferTexture1D;
	extern PFNGLFRAMEBUFFERTEXTURE2DEXTPROC					glFramebufferTexture2D;
	extern PFNGLFRAMEBUFFERTEXTURE3DEXTPROC					glFramebufferTexture3D;
	extern PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC				glFramebufferRenderbuffer;
	extern PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC	glGetFramebufferAttachmentParameteriv;
	extern PFNGLBLITFRAMEBUFFEREXTPROC						glBlitFramebuffer;
	extern PFNGLGENERATEMIPMAPEXTPROC						glGenerateMipmap;
	extern PFNGLDRAWBUFFERSPROC								glDrawBuffers;
	extern PFNGLDRAWRANGEELEMENTSPROC						glDrawRangeElements;
	extern PFNGLACTIVETEXTUREPROC							glActiveTexture;
	extern PFNGLCLIENTACTIVETEXTUREPROC						glClientActiveTexture;
	extern PFNGLMULTITEXCOORD1FPROC							glMultiTexcoord1f;
	extern PFNGLMULTITEXCOORD2FPROC							glMultiTexcoord2f;
	extern PFNGLMULTITEXCOORD3FPROC							glMultiTexcoord3f;
	extern PFNGLMULTITEXCOORD4FPROC							glMultiTexcoord4f;
	extern PFNGLLOADTRANSPOSEMATRIXFPROC					glLoadTransposeMatrixf;
	extern PFNGLBINDBUFFERPROC								glBindBuffer;
	extern PFNGLBUFFERDATAPROC								glBufferData;
	extern PFNGLBUFFERSUBDATAPROC							glBufferSubData;
	extern PFNGLDELETEBUFFERSPROC							glDeleteBuffers;
	extern PFNGLGENBUFFERSPROC								glGenBuffers;
	extern PFNGLMAPBUFFERPROC								glMapBuffer;
	extern PFNGLUNMAPBUFFERPROC								glUnmapBuffer;
	extern PFNGLBLENDEQUATIONPROC							glBlendEquation;
	extern PFNGLBLENDCOLORPROC								glBlendColor;
	extern PFNGLBLENDFUNCSEPARATEPROC						glBlendFuncSeperate;
	extern PFNGLBLENDEQUATIONSEPARATEPROC					glBlendEquationSeperate;

	void InitializeOpenGLExtensions();

	struct Color4f {
		GLfloat r, g, b, a;

		Color4f() = default;
		Color4f(GLfloat r0, GLfloat g0, GLfloat b0, GLfloat a0) noexcept :
			r(r0), g(g0), b(b0), a(a0) {
		}
	};

	class GuiRenderer {
	private:
		static GuiRenderer *mp_instance;

		GLint m_text_list_base;
		GLint m_width, m_height;

		HDC m_HDC;

		GLuint m_handle_program;
		GLuint m_handle_bg_tex;
		GLuint m_handle_FBO;
		GLuint m_handle_color_RBO;

		// Gaussian blur weights and offsets
		static const size_t BLUR_SAMPLE = 13;
		GLfloat m_gaussian_weights[BLUR_SAMPLE];
		GLfloat m_gaussian_offsets[BLUR_SAMPLE * 2];

		// Precomputed coordinates for circle
		static const size_t CIRCLE_VERTEX_COUNT = 12;
		GLfloat m_circle_coords[CIRCLE_VERTEX_COUNT * 2];
		
		static const GLchar *vert_shader_source;
		static const GLchar *blur_frag_shader_source;

	public:
		static const GLfloat DEPTH_FAR;
		static const GLfloat DEPTH_MID;
		static const GLfloat DEPTH_NEAR;

	private:
		GuiRenderer();
		~GuiRenderer();

	public:
		static __forceinline GuiRenderer* instance() {
			if (!mp_instance)
				mp_instance = new GuiRenderer;
			return mp_instance;
		}
		static void deleteInstance() {
			if (!mp_instance) {
				delete mp_instance;
				mp_instance = nullptr;
			}
		}

		__forceinline HDC getHDC() const {
			return m_HDC;
		}

		void resize(int width, int height);

		// Draw Call
		void blurBackgroundTexture(int x0, int y0, int x1, int y1);
		void drawBackgroundTexture(int x0, int y0, int x1, int y1);

		void drawLine(int x0, int y0, int x1, int y1, float depth) const;
		void drawRect(int x0, int y0, int x1, int y1, float depth, const bool filled = false, 
			const Color4f &color = Color4f(1.0f, 1.0f, 1.0f, 0.5f), const Color4f &blend_color = Color4f(0.f, 0.f, 0.f, 0.f)) const;
		void drawRoundedRect(int x0, int y0, int x1, int y1, float depth, float radius, const bool filled = false,
			const Color4f &color = Color4f(1.0f, 1.0f, 1.0f, 0.5f), const Color4f &blend_color = Color4f(0.f, 0.f, 0.f, 0.f)) const;
		void drawHalfRoundedRect(int x0, int y0, int x1, int y1, float depth, float radius, const bool filled = false,
			const Color4f &color = Color4f(1.0f, 1.0f, 1.0f, 0.5f), const Color4f &blend_color = Color4f(0.f, 0.f, 0.f, 0.f)) const;
		void drawCircle(int x0, int y0, float depth, int radius, bool filled, const Color4f &color) const;
		void drawString(int x0, int y0, float depth, const char *text, int length = -1) const;

	private:
		void CalcGaussianBlurWeightsAndOffsets();
	};

	// Immediate Mode GUI
	enum class LayoutStrategy {
		DockLeft,
		DockRight,
		Floating,
		Fixed
	};

	enum class GrowthStrategy {
		Vertical,
		Horizontal
	};

	struct ComboBoxItem {
		int  value;
		char *label;
	};

	enum class MouseAction {
		None,
		LButtonDown,
		LButtonUp,
		LButtonDbClick,
		RButtonDown,
		RButtonUp,
		RButtonDbClick,
		Move
	};

	struct MouseEvent {
		int x, y;
		bool l_down, r_down;
		MouseAction action;
	};

	enum class FunctionKey {
		None,
		Esc,
		Enter,
		LeftArrow,
		UpArrow,
		RightArrow,
		DownArrow,
		Insert,
		BackSpace,
		Delete,
		Tab,
		Home,
		End
	};

	enum KeyMode {
		None = 0,
		Ctrl = 1 << 0,
		Shift = 1 << 1,
		Alt = 1 << 2,
		CtrlShift = Ctrl | Shift,
		CtrlAlt = Ctrl | Alt,
		ShiftAlt = Shift | Alt,
		CtrlShiftAlt = Ctrl | Shift | Alt
	};

	struct KeyboardEvent {
		KeyMode keymode;
		char key;
		FunctionKey funckey;
	};

	struct GuiStates {
		int screen_width;
		int screen_height;
		
		int dialog_pos_x;
		int dialog_pos_y;
		int dialog_width;
		int dialog_height;

		int current_pos_x;
		int current_pos_y;
		int widget_end_x;
		LayoutStrategy current_layout_strategy;
		GrowthStrategy current_growth_strategy;

		int current_id;
		int hovered_id;
		int  active_id;
		int current_dialog_id;
		int active_dialog_id;
		int moving_id;
		MouseEvent mouse_state;
		MouseEvent prev_global_mouse_state;
		MouseEvent global_mouse_state;
		KeyboardEvent key_state;

		// Text edit states
		int editing_id;
		int cursor_pos;
		int cursor_idx;
		int select_idx;
		std::string string_buffer;
		std::vector<int> string_width_prefix_sum;

		// Scroller states
		int scroller_init_y;
		int scroller_origin_y;
		int scroller_button_down_offset;
		bool scroller_active;

		// Console states
		std::string console_text_buffer;
		float console_scroller;
	};

	class AyaGui {
	private:
		static GuiStates *states;
		static const int default_margin_buttom			= 10;
		static const int default_margin_right			= 5;
		static const int padding_left					= 18;
		static const int sidebar_padding_top				= 24;
		static const int titled_dialog_padding_top		= 32;
		static const int untitled_dialog_padding_top		= 12;

		static const int sidebar_width					= 200;
		static const int dialog_title_height				= 24;
		static const int text_height						= 10;
		static const int multiline_text_height			= 16;

	public:
		static void Init();
		static void Release();
		static void Resize(int width, int height);

		static void Vertical();
		static void Horizontal();

		static void BeginFrame();
		static void EndFrame();
		static void BeginDialog(LayoutStrategy layout, int &x, int &y, 
			const char *title = NULL,
			const int width = 250, const int height = 500,
			GrowthStrategy growth_strategy = GrowthStrategy::Vertical);
		static void BeginSidebarDialog(LayoutStrategy layout, 
			const int width = 250, const int height = 500,
			GrowthStrategy growth_strategy = GrowthStrategy::Vertical);
		static void EndDialog();

		static bool HandleMouseEvent(const MouseEvent& mouseArgs);
		static bool HandleKeyboardEvent(const KeyboardEvent& keyArgs);

		static void Text(const char* str, ...);
	};
}

#endif