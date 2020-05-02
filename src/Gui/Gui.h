#ifndef AYA_GUI_H
#define AYA_GUI_H

#include <string>
#include <vector>
#include <sstream>
#include <Windows.h>

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
		Color4f(GLfloat r0, GLfloat g0, GLfloat b0, GLfloat a0 = 1.0f) noexcept :
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
		static const size_t CIRCLE_VERTEX_COUNT = 24;
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
		PageUp,
		PageDown,
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
		int scroller_botton_down_offset;
		bool scroller_active;
	};

	class AyaGui {
	private:
		static GuiStates *states;
		static const int default_margin_bottom			= 10;
		static const int default_margin_right			= 5;
		static const int line_margin_bottom				= 8;
		static const int padding_left					= 18;
		static const int sidebar_padding_top				= 24;
		static const int titled_dialog_padding_top		= 32;
		static const int untitled_dialog_padding_top		= 12;

		static const int sidebar_width					= 200;
		static const int dialog_title_height				= 24;
		static const int text_height						= 10;
		static const int multiline_text_height			= 16;
		static const int button_default_height			= 24;
		static const int combo_box_default_width			= 140;
		static const int combo_box_height				= 18;
		static const int combo_box_item_height			= 20;
		static const int check_box_size					= 12;
		static const int radio_button_circle_diameter	= 12;
		static const int scroller_width					= 8;
		static const int scroller_margin					= 15;
		static const int page_control_height				= 50;
		static const int arrow_control_height			= 20;
		static const int slider_default_height			= 14;
		static const int slider_default_width			= 140;
		static const int slider_btn_default_width		= 7;
		static const int default_color_block_size		= 32;

	public:
		static void Init();
		static void Release();
		static void Resize(int width, int height);

		static void Vertical();
		static void Horizontal();
		static void ExpandVertical(int margin = default_margin_bottom);
		static void ExpandHorizontal(int margin = default_margin_right);
		static void NextLine(int margin = default_margin_bottom, int padding = padding_left);
		static void Target(int x, int y);

		static void BeginFrame();
		static void EndFrame();
		static void BeginDialog(LayoutStrategy layout, int &x, int &y, 
			const char *title = nullptr,
			const int width = 250, const int height = 500,
			GrowthStrategy growth_strategy = GrowthStrategy::Vertical);
		static void BeginSidebarDialog(LayoutStrategy layout, 
			const int width = 250, const int height = 500,
			GrowthStrategy growth_strategy = GrowthStrategy::Vertical);
		static void EndDialog();

		static bool HandleMouseEvent(const MouseEvent& mouseArgs);
		static bool HandleKeyboardEvent(const KeyboardEvent& keyArgs);

		static void Text(const char *str, ...);
		static void Text(Color4f color, const char *str, ...);
		static void MultilineText(const char *str, ...);
		static bool Button(const char *label, const int width = 114514, const int height = button_default_height);
		static void Line();
		static void ComboBox(const char *label, 
			const std::vector<std::string> items, int &selected, const int width = combo_box_default_width);
		static bool CheckBox(const char *label, bool &checked);
		static bool RadioButton(const char *label, int active, int &current);
		static void ColorBlock(float r, float g, float b, int size = default_color_block_size);

		static void Scroller(int limit, int actual, float &lin);
		static void BeginScroller(int area_height, int &content_height, float &scroller);
		static void EndScroller(int area_height, int &content_height, float &scroller);

		template<typename T>
		static bool Slider(const char *label, T &val, T min, T max, int width = slider_default_width) {
			int id(states->current_id++);
			bool modified = false;

			if (label) Text(label);

			if (width > states->widget_end_x - states->current_pos_x)
				width = states->widget_end_x - states->current_pos_x;
			const int slider_base = states->current_pos_x + slider_btn_default_width;
			const int slider_end = states->current_pos_x + width - slider_btn_default_width;

			
			auto fix01 = [](float val, float min, float max) {
				if (min == max) return 0.0f;
				float value = (val - min) / (max - min);
				if (value < 0.0f) return 0.0f;
				if (value > 1.0f) return 1.0f;
				return value;
			};
			auto fix = [](int val, int min, int max) {
				if (val < min) return min;
				if (val > max) return max;
				return val;
			};

			float lin = fix01(float(val), float(min), float(max));
			int button_x = int(slider_base + (slider_end - slider_base) * lin);

			int bar_left = states->current_pos_x;
			int bar_top = states->current_pos_y;
			int bar_right = bar_left + width;
			int bar_bottom = bar_top + slider_default_height;

			if (PtInRect(states->mouse_state.x, states->mouse_state.y,
				bar_left, bar_top, bar_right, bar_bottom)) {
				if (states->mouse_state.action == MouseAction::LButtonDown)
					states->active_id = id;

				if (states->mouse_state.action == MouseAction::LButtonUp) {
					if (states->active_id == id) {
						button_x = fix(states->mouse_state.x, slider_base, slider_end);
						float btn_lin = fix01(float(button_x), float(slider_base), float(slider_end));
						val = T(min + (max - min) * btn_lin);
						float lin = fix01(float(val), float(min), float(max));
						button_x = int(slider_base + (slider_end - slider_base) * lin);

						modified = true;
						states->active_id = -1;
					}
				}

				states->hovered_id = id;
			}

			if (states->mouse_state.action == MouseAction::Move && states->mouse_state.l_down) {
				if (states->active_id == id) {
					button_x = fix(states->mouse_state.x, slider_base, slider_end);
					float btn_lin = fix01(float(button_x), float(slider_base), float(slider_end));
					val = T(min + (max - min) * btn_lin);
					float lin = fix01(float(val), float(min), float(max));
					button_x = int(slider_base + (slider_end - slider_base) * lin);

					modified = true;
				}
			}

			if (states->mouse_state.action == MouseAction::LButtonUp)
				if (states->active_id == id)
					states->active_id = -1;

			Color4f color1 = states->hovered_id == id && states->active_id == -1 || states->hovered_id == id ?
				Color4f(1.0f, 1.0f, 1.0f, 0.65f) : Color4f(1.0f, 1.0f, 1.0f, 0.5f);
			Color4f color2 = states->hovered_id == id && states->active_id == -1 || states->hovered_id == id ?
				Color4f(0.3f, 0.3f, 0.3f, 0.65f) : Color4f(0.15f, 0.15f, 0.15f, 0.5f);

			GuiRenderer::instance()->drawRect(bar_left - 1, bar_top - 1, bar_right + 1, bar_bottom + 1, GuiRenderer::DEPTH_MID, false, Color4f(1.0f, 1.0f, 1.0f, 1.0f));
			GuiRenderer::instance()->drawRect(bar_left, bar_top, bar_right, bar_bottom, GuiRenderer::DEPTH_MID, true, color2, Color4f(1.0f, 1.0f, 1.0f, 0.6f));
			GuiRenderer::instance()->drawRect(button_x - slider_btn_default_width, bar_top, button_x + slider_btn_default_width, bar_bottom, GuiRenderer::DEPTH_MID, true, color1);

			{
				std::stringstream text_stream;
				text_stream.setf(std::ios::fixed);
				text_stream.precision(2);
				text_stream << val;
				std::string str_val;
				text_stream >> str_val;
				const char *str = str_val.c_str();

				SIZE text_extent;
				GetTextExtentPoint32A(GuiRenderer::instance()->getHDC(), str, strlen(str), &text_extent);
				glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
				GuiRenderer::instance()->drawString(bar_left + width / 2 - text_extent.cx / 2, bar_top + slider_btn_default_width - 4, GuiRenderer::DEPTH_MID, str);
			}

			if (states->current_growth_strategy == GrowthStrategy::Vertical) {
				states->current_pos_y += check_box_size + default_margin_bottom;
				states->current_pos_x = padding_left;
			}
			else {
				states->current_pos_x += width + default_margin_right;
			}
			
			return 0;
		}

	private:
		static bool PtInRect(int x0, int y0, int left, int top, int right, int bottom);
	};
}

#endif