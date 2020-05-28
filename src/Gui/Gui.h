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

		GLint m_textListBase;
		GLint m_width, m_height;

		HDC m_HDC;

		GLuint m_handleProgram;
		GLuint m_handleBackgroundTex;
		GLuint m_handleFBO;
		GLuint m_handleColorRBO;

		// Gaussian blur weights and offsets
		static const size_t BLUR_SAMPLE = 13;
		GLfloat m_gaussianWeights[BLUR_SAMPLE];
		GLfloat m_gaussianOffsets[BLUR_SAMPLE * 2];

		// Precomputed coordinates for circle
		static const size_t CIRCLE_VERTEX_COUNT = 24;
		GLfloat m_circleCoords[CIRCLE_VERTEX_COUNT * 2];
		
		static const GLchar *s_vertShaderSource;
		static const GLchar *s_blurFragShaderSource;

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
		int screenWidth;
		int screenHeight;
		
		int dialogPosX;
		int dialogPosY;
		int dialogWidth;
		int dialogHeight;

		int currentPosX;
		int currentPosY;
		int widgetEndX;
		LayoutStrategy currentLayoutStrategy;
		GrowthStrategy currentGrowthStrategy;

		int currentId;
		int hoveredId;
		int  activeId;
		int currentDialogId;
		int activeDialogId;
		int movingId;
		MouseEvent mouseState;
		MouseEvent prevGlobalMouseState;
		MouseEvent globalMouseState;
		KeyboardEvent keyState;

		// Text edit states
		int editingId;
		int cursorPos;
		int cursorIdx;
		int selectIdx;
		std::string stringBuffer;
		std::vector<int> stringWidthPrefixSum;
		std::string clipboard;

		// Scroller states
		int scrollerInitY;
		int scrollerOriginY;
		int scrollerBottonDownOffset;
		bool scrollerActive;
	};

	class AyaGui {
	private:
		static GuiStates *states;
		static const int c_defaultMarginBottom			= 10;
		static const int c_defaultMarginRight			= 5;
		static const int c_lineMarginBottom				= 8;
		static const int c_paddingLeft					= 18;
		static const int c_sidebarPaddingTop				= 24;
		static const int c_titledDialogPaddingTop		= 32;
		static const int c_untitledDialogPaddingTop		= 12;

		static const int c_sidebarWidth					= 200;
		static const int c_dialogTitleHeight				= 24;
		static const int c_textHeight					= 10;
		static const int c_multilineTextHeight			= 16;
		static const int c_buttonDefaultHeight			= 24;
		static const int c_comboBoxDefaultWidth			= 140;
		static const int c_comboBoxHeight				= 18;
		static const int c_comboBoxItemHeight			= 20;
		static const int c_checkBoxSize					= 12;
		static const int c_radioButtonCircleDiameter		= 12;
		static const int c_scrollerWidth					= 8;
		static const int c_scrollerMargin				= 15;
		static const int c_pageControlHeight				= 50;
		static const int c_arrowControlHeight			= 20;
		static const int c_sliderDefaultHeight			= 14;
		static const int c_sliderDefaultWidth			= 140;
		static const int c_sliderButtonDefaultWidth		= 7;
		static const int c_defaultColorBlockSize			= 32;
		static const int c_inputTextDefaultWidth			= 100;
		static const int c_inputTextDefaultHeight		= 18;
		static const int c_inputTextIndent				= 4;
		static const int c_headerHeight					= 30;
		static const int c_headerTextHeight				= 11;

	public:
		static void Init();
		static void Release();
		static void Resize(int width, int height);

		static void Vertical();
		static void Horizontal();
		static void ExpandVertical(int margin = c_defaultMarginBottom);
		static void ExpandHorizontal(int margin = c_defaultMarginRight);
		static void NextLine(int margin = c_defaultMarginBottom, int padding = c_paddingLeft);
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
		static bool Button(const char *label, const int width = 114514, const int height = c_buttonDefaultHeight, const bool banned = false);
		static void Line();
		static void ComboBox(const char *label, 
			const std::vector<std::string> items, int &selected, const int width = c_comboBoxDefaultWidth, const bool banned = false);
		static bool CheckBox(const char *label, bool &checked, const bool banned = false);
		static bool RadioButton(const char *label, int active, int &current, const bool banned = false);
		static void ColorBlock(float r, float g, float b, const int size = c_defaultColorBlockSize);
		static void InputText(std::string &str, const int width = c_inputTextDefaultWidth,
			const bool auto_select_all = false, const bool auto_clear_on_enter = false, const bool banned = false);
		static bool InputDigit(const char *label, int &digit, const bool banned = false);

		static void Scroller(int limit, int actual, float &lin);
		static void BeginScroller(int area_height, int &content_height, float &scroller);
		static void EndScroller(int area_height, int &content_height, float &scroller);

		static bool CollapsingHeader(const char *label, bool &show);

		template<typename T>
		static bool Slider(const char *label, T &val, T min, T max, int width = c_sliderDefaultWidth, const bool banned = false) {
			const int id(states->currentId++);
			bool modified = false;

			if (label) Text(label);

			if (width > states->widgetEndX - states->currentPosX)
				width = states->widgetEndX - states->currentPosX;
			const int slider_base = states->currentPosX + c_sliderButtonDefaultWidth;
			const int slider_end = states->currentPosX + width - c_sliderButtonDefaultWidth;

			
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

			const float lin = fix01(float(val), float(min), float(max));
			int button_x = int(slider_base + (slider_end - slider_base) * lin);

			const int bar_left = states->currentPosX;
			const int bar_top = states->currentPosY;
			const int bar_right = bar_left + width;
			const int bar_bottom = bar_top + c_sliderDefaultHeight;

			if (!banned) {
				if (PtInRect(states->mouseState.x, states->mouseState.y,
					bar_left, bar_top, bar_right, bar_bottom)) {
					if (states->mouseState.action == MouseAction::LButtonDown)
						states->activeId = id;

					if (states->mouseState.action == MouseAction::LButtonUp) {
						if (states->activeId == id) {
							button_x = fix(states->mouseState.x, slider_base, slider_end);
							float btn_lin = fix01(float(button_x), float(slider_base), float(slider_end));
							val = T(min + (max - min) * btn_lin);
							float lin = fix01(float(val), float(min), float(max));
							button_x = int(slider_base + (slider_end - slider_base) * lin);

							modified = true;
							states->activeId = -1;
						}
					}

					states->hoveredId = id;
				}

				if (states->mouseState.action == MouseAction::Move && states->mouseState.l_down) {
					if (states->activeId == id) {
						button_x = fix(states->mouseState.x, slider_base, slider_end);
						float btn_lin = fix01(float(button_x), float(slider_base), float(slider_end));
						val = T(min + (max - min) * btn_lin);
						float lin = fix01(float(val), float(min), float(max));
						button_x = int(slider_base + (slider_end - slider_base) * lin);

						modified = true;
					}
				}
			}
			else {
				if (states->activeId == id)
					states->activeId = -1;
			}

			if (states->mouseState.action == MouseAction::LButtonUp)
				if (states->activeId == id)
					states->activeId = -1;

			const Color4f color1 = banned ? Color4f(1.0f, 1.0f, 1.0f, 0.3f) : states->hoveredId == id && states->activeId == -1 || states->hoveredId == id ?
				Color4f(1.0f, 1.0f, 1.0f, 0.65f) : Color4f(1.0f, 1.0f, 1.0f, 0.5f);
			const Color4f color2 = banned ? Color4f(0.15f, 0.15f, 0.15f, 0.3f) : states->hoveredId == id && states->activeId == -1 || states->hoveredId == id ?
				Color4f(0.3f, 0.3f, 0.3f, 0.65f) : Color4f(0.15f, 0.15f, 0.15f, 0.5f);

			GuiRenderer::instance()->drawRect(bar_left - 1, bar_top - 1, bar_right + 1, bar_bottom + 1, 
				GuiRenderer::DEPTH_MID, false, banned ? Color4f(1.0f, 1.0f, 1.0f, 0.65f)  : Color4f(1.0f, 1.0f, 1.0f, 1.0f));
			GuiRenderer::instance()->drawRect(bar_left, bar_top, bar_right, bar_bottom, GuiRenderer::DEPTH_MID, true, color2, Color4f(1.0f, 1.0f, 1.0f, 0.6f));
			GuiRenderer::instance()->drawRect(button_x - c_sliderButtonDefaultWidth, bar_top, button_x + c_sliderButtonDefaultWidth, bar_bottom, 
				GuiRenderer::DEPTH_MID, true, color1);

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
				if (!banned)
					glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
				else
					glColor4f(1.0f, 1.0f, 1.0f, 0.65f);
				GuiRenderer::instance()->drawString(bar_left + width / 2 - text_extent.cx / 2, bar_top + c_sliderButtonDefaultWidth - 4, GuiRenderer::DEPTH_MID, str);
			}

			if (states->currentGrowthStrategy == GrowthStrategy::Vertical) {
				states->currentPosY += c_checkBoxSize + c_defaultMarginBottom;
				states->currentPosX = c_paddingLeft;
			}
			else {
				states->currentPosX += width + c_defaultMarginRight;
			}
			
			return 0;
		}

	private:
		static bool PtInRect(int x0, int y0, int left, int top, int right, int bottom);
	};
}

#endif