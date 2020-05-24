#include <Gui/Gui.h>

#include <cmath>
#include <cassert>
#include <exception>
#include <functional>
#include <iostream>
#include <algorithm>

namespace Aya {
	PFNGLCREATESHADERPROC							glCreateShader;
	PFNGLCREATEPROGRAMPROC							glCreateProgram;
	PFNGLDELETESHADERPROC							glDeleteShader;
	PFNGLDELETEPROGRAMPROC							glDeleteProgram;
	PFNGLATTACHSHADERPROC							glAttachShader;
	PFNGLDETACHSHADERPROC							glDetachShader;
	PFNGLSHADERSOURCEPROC							glShaderSource;
	PFNGLCOMPILESHADERPROC							glCompileShader;
	PFNGLLINKPROGRAMPROC							glLinkProgram;
	PFNGLVALIDATEPROGRAMPROC						glValidateProgram;
	PFNGLUSEPROGRAMPROC								glUseProgram;
	PFNGLGETSHADERINFOLOGPROC						glGetShaderInfoLog;
	PFNGLGETPROGRAMINFOLOGPROC						glGetProgramInfoLog;
	PFNGLGETSHADERIVPROC							glGetShaderiv;
	PFNGLGETPROGRAMIVPROC							glGetProgramiv;
	PFNGLUNIFORM1FPROC								glUniform1f;
	PFNGLUNIFORM1FVPROC								glUniform1fv;
	PFNGLUNIFORM2FPROC								glUniform2f;
	PFNGLUNIFORM2FVPROC								glUniform2fv;
	PFNGLUNIFORM3FPROC								glUniform3f;
	PFNGLUNIFORM4FPROC								glUniform4f;
	PFNGLUNIFORM1IPROC								glUniform1i;
	PFNGLUNIFORM1IVPROC								glUniform1iv;
	PFNGLUNIFORM2IPROC								glUniform2i;
	PFNGLUNIFORM3IPROC								glUniform3i;
	PFNGLUNIFORM4IPROC								glUniform4i;
	PFNGLUNIFORMMATRIX3FVPROC						glUniformMatrix3fv;
	PFNGLUNIFORMMATRIX4FVPROC						glUniformMatrix4fv;
	PFNGLGETUNIFORMLOCATIONPROC						glGetUniformLocation;
	PFNGLBINDFRAGDATALOCATIONEXTPROC				glBindFragDataLocation;
	PFNGLISRENDERBUFFEREXTPROC						glIsRenderbuffer;
	PFNGLBINDRENDERBUFFEREXTPROC					glBindRenderbuffer;
	PFNGLDELETERENDERBUFFERSEXTPROC					glDeleteRenderbuffers;
	PFNGLGENRENDERBUFFERSEXTPROC					glGenRenderbuffers;
	PFNGLRENDERBUFFERSTORAGEEXTPROC					glRenderbufferStorage;
	PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC		glRenderbufferStorageMultisample;
	PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC			glGetRenderbufferParameteriv;
	PFNGLISFRAMEBUFFEREXTPROC						glIsFramebuffer;
	PFNGLBINDFRAMEBUFFEREXTPROC						glBindFramebuffer;
	PFNGLDELETEFRAMEBUFFERSEXTPROC					glDeleteFramebuffers;
	PFNGLGENFRAMEBUFFERSEXTPROC						glGenFramebuffers;
	PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC				glCheckFramebufferStatus;
	PFNGLFRAMEBUFFERTEXTURE1DEXTPROC				glFramebufferTexture1D;
	PFNGLFRAMEBUFFERTEXTURE2DEXTPROC				glFramebufferTexture2D;
	PFNGLFRAMEBUFFERTEXTURE3DEXTPROC				glFramebufferTexture3D;
	PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC				glFramebufferRenderbuffer;
	PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC	glGetFramebufferAttachmentParameteriv;
	PFNGLBLITFRAMEBUFFEREXTPROC						glBlitFramebuffer;
	PFNGLGENERATEMIPMAPEXTPROC						glGenerateMipmap;
	PFNGLDRAWBUFFERSPROC							glDrawBuffers;
	PFNGLDRAWRANGEELEMENTSPROC						glDrawRangeElements;
	PFNGLACTIVETEXTUREPROC							glActiveTexture;
	PFNGLCLIENTACTIVETEXTUREPROC					glClientActiveTexture;
	PFNGLMULTITEXCOORD1FPROC						glMultiTexcoord1f;
	PFNGLMULTITEXCOORD2FPROC						glMultiTexcoord2f;
	PFNGLMULTITEXCOORD3FPROC						glMultiTexcoord3f;
	PFNGLMULTITEXCOORD4FPROC						glMultiTexcoord4f;
	PFNGLLOADTRANSPOSEMATRIXFPROC					glLoadTransposeMatrixf;
	PFNGLBINDBUFFERPROC								glBindBuffer;
	PFNGLBUFFERDATAPROC								glBufferData;
	PFNGLBUFFERSUBDATAPROC							glBufferSubData;
	PFNGLDELETEBUFFERSPROC							glDeleteBuffers;
	PFNGLGENBUFFERSPROC								glGenBuffers;
	PFNGLMAPBUFFERPROC								glMapBuffer;
	PFNGLUNMAPBUFFERPROC							glUnmapBuffer;
	PFNGLBLENDEQUATIONPROC							glBlendEquation;
	PFNGLBLENDCOLORPROC								glBlendColor;
	PFNGLBLENDFUNCSEPARATEPROC						glBlendFuncSeperate;
	PFNGLBLENDEQUATIONSEPARATEPROC					glBlendEquationSeperate;

	void InitializeOpenGLExtensions() {
		glCreateShader = (PFNGLCREATESHADEROBJECTARBPROC)wglGetProcAddress("glCreateShaderObjectARB");
		glCreateProgram = (PFNGLCREATEPROGRAMOBJECTARBPROC)wglGetProcAddress("glCreateProgramObjectARB");
		glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
		glDetachShader = (PFNGLDETACHSHADERPROC)wglGetProcAddress("glDetachShader");
		glDeleteShader = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
		glDeleteProgram = (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
		glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
		glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
		glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
		glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)wglGetProcAddress("glValidateProgram");
		glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
		glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
		glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)wglGetProcAddress("glGetProgramInfoLog");
		glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
		glGetProgramiv = (PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
		glUniform1f = (PFNGLUNIFORM1FPROC)wglGetProcAddress("glUniform1f");
		glUniform1fv = (PFNGLUNIFORM1FVPROC)wglGetProcAddress("glUniform1fv");
		glUniform2f = (PFNGLUNIFORM2FPROC)wglGetProcAddress("glUniform2f");
		glUniform2fv = (PFNGLUNIFORM2FVPROC)wglGetProcAddress("glUniform2fv");
		glUniform3f = (PFNGLUNIFORM3FPROC)wglGetProcAddress("glUniform3f");
		glUniform4f = (PFNGLUNIFORM4FPROC)wglGetProcAddress("glUniform4f");
		glUniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
		glUniform1iv = (PFNGLUNIFORM1IVPROC)wglGetProcAddress("glUniform1iv");
		glUniform2i = (PFNGLUNIFORM2IPROC)wglGetProcAddress("glUniform2i");
		glUniform3i = (PFNGLUNIFORM3IPROC)wglGetProcAddress("glUniform3i");
		glUniform4i = (PFNGLUNIFORM4IPROC)wglGetProcAddress("glUniform4i");
		glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)wglGetProcAddress("glUniformMatrix3fv");
		glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");
		glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
		glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONEXTPROC)wglGetProcAddress("glBindFragDataLocationEXT");

		glIsRenderbuffer = (PFNGLISRENDERBUFFEREXTPROC)wglGetProcAddress("glIsRenderbuffer");
		glBindRenderbuffer = (PFNGLBINDRENDERBUFFEREXTPROC)wglGetProcAddress("glBindRenderbuffer");
		glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSEXTPROC)wglGetProcAddress("glDeleteRenderbuffers");
		glGenRenderbuffers = (PFNGLGENRENDERBUFFERSEXTPROC)wglGetProcAddress("glGenRenderbuffers");
		glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEEXTPROC)wglGetProcAddress("glRenderbufferStorage");
		glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC)wglGetProcAddress("glGetRenderbufferParameteriv");
		glIsFramebuffer = (PFNGLISFRAMEBUFFEREXTPROC)wglGetProcAddress("glIsFramebuffer");
		glBindFramebuffer = (PFNGLBINDFRAMEBUFFEREXTPROC)wglGetProcAddress("glBindFramebuffer");
		glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSEXTPROC)wglGetProcAddress("glDeleteFramebuffers");
		glGenFramebuffers = (PFNGLGENFRAMEBUFFERSEXTPROC)wglGetProcAddress("glGenFramebuffers");
		glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC)wglGetProcAddress("glCheckFramebufferStatus");
		glFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DEXTPROC)wglGetProcAddress("glFramebufferTexture1D");
		glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DEXTPROC)wglGetProcAddress("glFramebufferTexture2D");
		glFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DEXTPROC)wglGetProcAddress("glFramebufferTexture3D");
		glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC)wglGetProcAddress("glFramebufferRenderbuffer");
		glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)wglGetProcAddress("glGetFramebufferAttachmentParameteriv");
		glBlitFramebuffer = (PFNGLBLITFRAMEBUFFEREXTPROC)wglGetProcAddress("glBlitFramebuffer");
		glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)wglGetProcAddress("glRenderbufferStorageMultisample");
		glGenerateMipmap = (PFNGLGENERATEMIPMAPEXTPROC)wglGetProcAddress("glGenerateMipmap");
		glDrawBuffers = (PFNGLDRAWBUFFERSPROC)wglGetProcAddress("glDrawBuffers");
		glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)wglGetProcAddress("glDrawRangeElements");

		glActiveTexture = (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");
		glClientActiveTexture = (PFNGLCLIENTACTIVETEXTUREPROC)wglGetProcAddress("glClientActiveTexture");
		glMultiTexcoord1f = (PFNGLMULTITEXCOORD1FPROC)wglGetProcAddress("glMultiTexCoord1f");
		glMultiTexcoord2f = (PFNGLMULTITEXCOORD2FPROC)wglGetProcAddress("glMultiTexCoord2f");
		glMultiTexcoord3f = (PFNGLMULTITEXCOORD3FPROC)wglGetProcAddress("glMultiTexCoord3f");
		glMultiTexcoord4f = (PFNGLMULTITEXCOORD4FPROC)wglGetProcAddress("glMultiTexCoord4f");
		glLoadTransposeMatrixf = (PFNGLLOADTRANSPOSEMATRIXFPROC)wglGetProcAddress("glLoadTransposeMatrixf");

		glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
		glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
		glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers");
		glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");

		glBlendEquation = (PFNGLBLENDEQUATIONPROC)wglGetProcAddress("glBlendEquation");
		glBlendColor = (PFNGLBLENDCOLORPROC)wglGetProcAddress("glBlendColor");
		glBlendFuncSeperate = (PFNGLBLENDFUNCSEPARATEPROC)wglGetProcAddress("glBlendFuncSeperate");
		glBlendEquationSeperate = (PFNGLBLENDEQUATIONSEPARATEPROC)wglGetProcAddress("glBlendEquationSeperate");
	}

	GuiRenderer* GuiRenderer::mp_instance = nullptr;

	const GLfloat GuiRenderer::DEPTH_FAR  = 0.8f;
	const GLfloat GuiRenderer::DEPTH_MID  = 0.6f;
	const GLfloat GuiRenderer::DEPTH_NEAR = 0.4f;

	const GLchar* GuiRenderer::s_vertShaderSource = R"(
		    varying vec2 texCoord;
			void main() {
				gl_Position = gl_Vertex;
				texCoord = gl_MultiTexCoord0.xy;
			})";
	const GLchar* GuiRenderer::s_blurFragShaderSource = R"(
			uniform sampler2D texSampler;
			uniform float weights[13];
			uniform vec2 offsets[13];
			varying vec2 texCoord;
			void main() {
				vec4 sample = 0.0f;
				for(int i = 0; i < 13; i++) {
					sample += weights[i] * texture2DLod(texSampler, texCoord + offsets[i], 2);
				}
				gl_FragColor = vec4(sample.rgb, 1.0);
			})";

	GuiRenderer::GuiRenderer() {
		m_handleProgram = glCreateProgram();

		// Background Tex
		glGenTextures(1, &m_handleBackgroundTex);
		glBindTexture(GL_TEXTURE_2D, m_handleBackgroundTex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 16);

		glGenFramebuffers(1, &m_handleFBO);
		glGenRenderbuffers(1, &m_handleColorRBO);

		m_textListBase = glGenLists(128);
		HFONT font = CreateFont(16,
			0,
			0,
			0,
			FW_BOLD,
			FALSE,
			FALSE,
			FALSE,
			DEFAULT_CHARSET,
			OUT_TT_PRECIS,
			CLIP_DEFAULT_PRECIS,
			ANTIALIASED_QUALITY,
			FF_DECORATIVE | DEFAULT_PITCH,
			"Helvetica");
		m_HDC = wglGetCurrentDC();
		HFONT old_font = (HFONT)SelectObject(m_HDC, font);
		wglUseFontBitmaps(m_HDC, 0, 128, m_textListBase);
		//SelectObject(m_HDC, old_font);
		DeleteObject(font);

		// Compile and Load Shaders
		auto LoadShader = [](GLint type, const GLchar *source) {
			GLint handle = glCreateShader(type);
			GLint length = (GLint)strlen(source);
			glShaderSource(handle, 1, &source, &length);
			glCompileShader(handle);

			GLint compile_status;
			glGetShaderiv(handle, GL_COMPILE_STATUS, &compile_status);
			if (compile_status != GL_TRUE)
				throw std::exception("GLSL compiled error");

			return handle;
		};

		GLint handle_vertex_shader = LoadShader(GL_VERTEX_SHADER, s_vertShaderSource);
		GLint handle_blur_frag_shader = LoadShader(GL_FRAGMENT_SHADER, s_blurFragShaderSource);
		glAttachShader(m_handleProgram, handle_vertex_shader);
		glAttachShader(m_handleProgram, handle_blur_frag_shader);

		
		auto ExcuteAndCheck = [](std::function<void(GLint)> glFunc, GLint handle) {
			GLint status;
			GLchar* status_buffer;
			GLint length;

			glFunc(handle);
			glGetProgramiv(handle, GL_INFO_LOG_LENGTH, &length);
			status_buffer = new GLchar[length];
			glGetProgramInfoLog(handle, length, &length, status_buffer);
			glGetProgramiv(handle, GL_LINK_STATUS, &status);
			if (status != GL_TRUE)
				throw std::runtime_error(status_buffer);

			delete[] status_buffer;
		};
		
		ExcuteAndCheck(glLinkProgram, m_handleProgram);
		ExcuteAndCheck(glValidateProgram, m_handleProgram);

		// Calculate circle coordinates
		const GLfloat phi_itvl = 6.2831853071796f / (CIRCLE_VERTEX_COUNT - 1);
		GLfloat phi = 0.0f;
		for (size_t i = 0; i < CIRCLE_VERTEX_COUNT - 1; ++i) {
			m_circleCoords[i * 2 + 0] = std::sinf(phi);
			m_circleCoords[i * 2 + 1] = -std::cosf(phi);
			phi += phi_itvl;
		}
		m_circleCoords[2 * CIRCLE_VERTEX_COUNT - 2] = m_circleCoords[0];
		m_circleCoords[2 * CIRCLE_VERTEX_COUNT - 1] = m_circleCoords[1];
	}

	GuiRenderer::~GuiRenderer() {
		glDeleteProgram(m_handleProgram);
		glDeleteTextures(1, &m_handleBackgroundTex);
		glDeleteFramebuffers(1, &m_handleFBO);
		glDeleteRenderbuffers(1, &m_handleColorRBO);
	}

	void GuiRenderer::resize(int width, int height) {
		m_width = width;
		m_height = height;

		// Init background texture
		glBindRenderbuffer(GL_RENDERBUFFER, m_handleColorRBO);
		glRenderbufferStorageMultisample(GL_RENDERBUFFER, 0, GL_RGBA, (width + 0x7) >> 2, (height + 0x7) >> 2);
		glBindRenderbuffer(GL_RENDERBUFFER, 0);

		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, m_handleFBO);
		glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, m_handleColorRBO);
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);

		CalcGaussianBlurWeightsAndOffsets();
	}

	void GuiRenderer::blurBackgroundTexture(int x0, int y0, int x1, int y1) {
		glBindTexture(GL_TEXTURE_2D, m_handleBackgroundTex);
		glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 0, 0, m_width, m_height, 0);
		glGenerateMipmap(GL_TEXTURE_2D);

		GLfloat u0 = (GLfloat)x0 / (GLfloat)m_width;
		GLfloat v0 = (GLfloat)y0 / (GLfloat)m_height;
		GLfloat u1 = (GLfloat)x1 / (GLfloat)m_width;
		GLfloat v1 = (GLfloat)y1 / (GLfloat)m_height;
		GLfloat rx0 = u0 * 2.f - 1.f;
		GLfloat ry0 = v0 * 2.f - 1.f;
		GLfloat rx1 = u1 * 2.f - 1.f;
		GLfloat ry1 = v1 * 2.f - 1.f;

		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, m_handleFBO);

		glViewport(0, 0, (m_width + 0x7) >> 2, (m_height + 0x7) >> 2);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(m_handleProgram);
		glUniform1i(glGetUniformLocation(m_handleProgram, "texSampler"), 0);
		glUniform1fv(glGetUniformLocation(m_handleProgram, "weights"), 13, m_gaussianWeights);
		glUniform2fv(glGetUniformLocation(m_handleProgram, "offsets"), 13, m_gaussianOffsets);

		glBindTexture(GL_TEXTURE_2D, m_handleBackgroundTex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glBegin(GL_QUADS);

		glTexCoord2f(u0, v0);
		glVertex3f(rx0, ry0, DEPTH_FAR);

		glTexCoord2f(u1, v0);
		glVertex3f(rx1, ry0, DEPTH_FAR);

		glTexCoord2f(u1, v1);
		glVertex3f(rx1, ry1, DEPTH_FAR);

		glTexCoord2f(u0, v1);
		glVertex3f(rx0, ry1, DEPTH_FAR);

		glEnd();

		glUseProgram(0);
		glBindTexture(GL_TEXTURE_2D, 0);
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);

		glViewport(0, 0, m_width, m_height);
	}

	void GuiRenderer::drawBackgroundTexture(int x0, int y0, int x1, int y1) {
		glBindFramebuffer(GL_READ_FRAMEBUFFER, m_handleFBO);
		glBlitFramebuffer((x0 + 0x7) >> 2, (y0 - 0x7) >> 2, (x1 - 0x7) >> 2, (y1 + 0x7) >> 2, x0, y0, x1, y1, GL_COLOR_BUFFER_BIT, GL_LINEAR);
		glBindFramebuffer(GL_READ_FRAMEBUFFER, 0);
	}

	void GuiRenderer::drawLine(int x0, int y0, int x1, int y1, float depth) const {
		glBegin(GL_LINES);

		glVertex3f((GLfloat)x0, (GLfloat)y0, depth);
		glVertex3f((GLfloat)x1, (GLfloat)y1, depth);

		glEnd();
	}

	void GuiRenderer::drawRect(int x0, int y0, int x1, int y1, float depth, const bool filled,
		const Color4f &color, const Color4f &blend_color) const {
		auto draw = [](int x0, int y0, int x1, int y1, float depth) {
			glBegin(GL_QUADS);

			glVertex3f((GLfloat)x0, (GLfloat)y0, depth);
			glVertex3f((GLfloat)x1, (GLfloat)y0, depth);
			glVertex3f((GLfloat)x1, (GLfloat)y1, depth);
			glVertex3f((GLfloat)x0, (GLfloat)y1, depth);

			glEnd();
		};

		glBlendColor(blend_color.r, blend_color.g, blend_color.b, blend_color.a);
		glColor4fv((GLfloat*)&color);

		if (filled) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			draw(x0 - 1, y0, x1, y1 + 1, depth);
		}
		else {
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			draw(x0, y0, x1, y1, depth);
		}
	}

	void GuiRenderer::drawRoundedRect(int x0, int y0, int x1, int y1, float depth, float radius, const bool filled,
		const Color4f &color, const Color4f &blend_color) const {
		glBlendColor(blend_color.r, blend_color.g, blend_color.b, blend_color.a);
		glColor4fv((GLfloat*)&color);

		if (filled) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glBegin(GL_TRIANGLE_FAN);

			// Center vertex
			glVertex3f((x0 + x1) * 0.5f, (y0 + y1) * 0.5f, depth);
		}
		else {
			radius += 1;

			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glBegin(GL_LINE_STRIP);
		}

		const size_t quater_vertex_count = CIRCLE_VERTEX_COUNT / 4;

		glVertex3f((GLfloat)x0 + radius, (GLfloat)y0, depth);
		glVertex3f((GLfloat)x1 - radius, (GLfloat)y0, depth);
		for (size_t i = 0; i < quater_vertex_count; i++) {
			GLfloat x = x1 - radius + m_circleCoords[i * 2 + 0] * radius;
			GLfloat y = y0 + radius + m_circleCoords[i * 2 + 1] * radius;
			glVertex3f(x, y, depth);
		}
		glVertex3f((GLfloat)x1, (GLfloat)y0 + radius, depth);
		glVertex3f((GLfloat)x1, (GLfloat)y1 - radius, depth);
		for (size_t i = quater_vertex_count; i < 2 * quater_vertex_count; i++) {
			GLfloat x = x1 - radius + m_circleCoords[i * 2 + 0] * radius;
			GLfloat y = y1 - radius + m_circleCoords[i * 2 + 1] * radius;
			glVertex3f(x, y, depth);
		}
		glVertex3f((GLfloat)x1 - radius, (GLfloat)y1, depth);
		glVertex3f((GLfloat)x0 + radius, (GLfloat)y1, depth);
		for (size_t i = 2 * quater_vertex_count; i < 3 * quater_vertex_count; i++) {
			GLfloat x = x0 + radius + m_circleCoords[i * 2 + 0] * radius;
			GLfloat y = y1 - radius + m_circleCoords[i * 2 + 1] * radius;
			glVertex3f(x, y, depth);
		}
		glVertex3f((GLfloat)x0, (GLfloat)y1 - radius, depth);
		glVertex3f((GLfloat)x0, (GLfloat)y0 + radius, depth);
		for (size_t i = 3 * quater_vertex_count; i < 4 * quater_vertex_count; i++) {
			GLfloat x = x0 + radius + m_circleCoords[i * 2 + 0] * radius;
			GLfloat y = y0 + radius + m_circleCoords[i * 2 + 1] * radius;
			glVertex3f(x, y, depth);
		}

		glEnd();
	}

	void GuiRenderer::drawHalfRoundedRect(int x0, int y0, int x1, int y1, float depth, float radius, const bool filled,
		const Color4f &color, const Color4f &blend_color) const {
		glBlendColor(blend_color.r, blend_color.g, blend_color.b, blend_color.a);
		glColor4fv((GLfloat*)&color);

		if (filled) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glBegin(GL_TRIANGLE_FAN);

			// Center vertex
			glVertex3f((x0 + x1) * 0.5f, (y0 + y1) * 0.5f, depth);
		}
		else {
			radius += 1;

			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glBegin(GL_LINE_STRIP);
		}

		const size_t quater_vertex_count = CIRCLE_VERTEX_COUNT / 4;

		glVertex3f((GLfloat)x0 + radius, (GLfloat)y0, depth);
		glVertex3f((GLfloat)x1 - radius, (GLfloat)y0, depth);
		for (size_t i = 0; i < quater_vertex_count; i++) {
			GLfloat x = x1 - radius + m_circleCoords[i * 2 + 0] * radius;
			GLfloat y = y0 + radius + m_circleCoords[i * 2 + 1] * radius;
			glVertex3f(x, y, depth);
		}
		glVertex3f((GLfloat)x1, (GLfloat)y0 + radius, depth);
		glVertex3f((GLfloat)x1, (GLfloat)y1 - radius, depth);

		glVertex3f((GLfloat)x1, (GLfloat)y1, depth);

		glVertex3f((GLfloat)x1 - radius, (GLfloat)y1, depth);
		glVertex3f((GLfloat)x0 + radius, (GLfloat)y1, depth);

		glVertex3f((GLfloat)x0, (GLfloat)y1, depth);

		glVertex3f((GLfloat)x0, (GLfloat)y1 - radius, depth);
		glVertex3f((GLfloat)x0, (GLfloat)y0 + radius, depth);
		for (size_t i = 3 * quater_vertex_count; i < 4 * quater_vertex_count; i++) {
			GLfloat x = x0 + radius + m_circleCoords[i * 2 + 0] * radius;
			GLfloat y = y0 + radius + m_circleCoords[i * 2 + 1] * radius;
			glVertex3f(x, y, depth);
		}

		glEnd();
	}

	void GuiRenderer::drawCircle(int x0, int y0, float depth, int radius, bool filled, const Color4f &color) const {
		glBlendColor(0.0f, 0.0f, 0.0f, 1.0f);
		glColor4fv((GLfloat*)&color);

		if (filled) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glBegin(GL_TRIANGLE_FAN);

			// Center vertex
			glVertex3f((GLfloat)x0, (GLfloat)y0, depth);
		}
		else {
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glBegin(GL_LINE_STRIP);
		}

		for (size_t i = 0; i < CIRCLE_VERTEX_COUNT; i++) {
			GLfloat x = x0 + m_circleCoords[i * 2 + 0] * radius;
			GLfloat y = y0 + m_circleCoords[i * 2 + 1] * radius;
			glVertex3f(x, y, depth);
		}

		glEnd();
	}


	void GuiRenderer::drawString(int x0, int y0, float depth, const char *text, int length) const {
		glListBase(m_textListBase);

		glRasterPos3f((GLfloat)x0, (GLfloat)y0 + 10.f, depth);
		if (~length) {
			assert(length >= 0 && length <= (int)strlen(text));
			glCallLists(length, GL_UNSIGNED_BYTE, text);
		}
		else {
			glCallLists((GLsizei)strlen(text), GL_UNSIGNED_BYTE, text);
		}
	}

	void GuiRenderer::CalcGaussianBlurWeightsAndOffsets() {
		auto GaussianDistribution = [](GLfloat x, GLfloat y, GLfloat rho) {
			const GLfloat pi = 3.141592653589793238462643383279f;
			float g = 1.f / std::sqrtf(2.f * pi * rho * rho);
			g *= std::expf(-(x * x + y * y) / (2.f * rho * rho));

			return g;
		};

		GLfloat tu = 4.f / (GLfloat)m_width;
		GLfloat tv = 4.f / (GLfloat)m_height;

		GLfloat total_weight = 0.f;
		size_t index = 0;
		for (auto x : {-2, -1, 0, 1, 2}) {
			for (auto y : { -2, -1, 0, 1, 2 }) {
				if (std::abs(x) + std::abs(y) > 2)
					continue;

				// Get the unscaled Gaussian intensity for this offset
				m_gaussianOffsets[index * 2 + 0] = x * tu;
				m_gaussianOffsets[index * 2 + 1] = y * tv;
				m_gaussianWeights[index] = GaussianDistribution(GLfloat(x), GLfloat(y), 1.f);
				total_weight += m_gaussianWeights[index];

				++index;
			}
		}

		for (size_t i = 0; i < index; i++)
			m_gaussianWeights[i] /= total_weight;
	}

	// Immediate Mode GUI Implementation
	GuiStates *AyaGui::states;

	void AyaGui::Init() {
		states = new GuiStates;
		
		states->activeId = -1;
		states->movingId = -1;
		states->activeDialogId = -1;
		
		states->keyState.key = 0;
		states->keyState.funckey = FunctionKey::None;
		states->keyState.keymode = KeyMode::None;

		states->editingId = -1;
		states->scrollerInitY = 0;
	}

	void AyaGui::Release() {
		delete states;
		states = nullptr;

		GuiRenderer::deleteInstance();
	}

	void AyaGui::Resize(int width, int height) {
		states->screenWidth = width;
		states->screenHeight = height;

		GuiRenderer::instance()->resize(width, height);
	}

	void AyaGui::Vertical() {
		states->currentGrowthStrategy = GrowthStrategy::Vertical;
	}
	void AyaGui::Horizontal() {
		states->currentGrowthStrategy = GrowthStrategy::Horizontal;
	}

	void AyaGui::ExpandVertical(int margin) {
		states->currentPosY += margin;
	}
	void AyaGui::ExpandHorizontal(int margin) {
		states->currentPosX += margin;
	}
	void AyaGui::NextLine(int margin, int padding) {
		states->currentPosY += margin;
		states->currentPosX = padding;
	}
	void AyaGui::Target(int x, int y) {
		states->currentPosX = x;
		states->currentPosY = y;
	}

	void AyaGui::BeginFrame() {
		states->currentId = 0;
		states->currentDialogId = 0;
		states->hoveredId = -1;
	}

	void AyaGui::EndFrame() {
		states->globalMouseState.action = MouseAction::None;
		
		states->keyState.key = 0;
		states->keyState.funckey = FunctionKey::None;
		states->keyState.keymode = KeyMode::None;
	}

	void AyaGui::BeginDialog(LayoutStrategy layout, int &x, int &y, const char *title, 
		const int width, const int height,
		GrowthStrategy growth_strategy) {
		auto dialog_id(states->currentDialogId++);

		assert(layout == LayoutStrategy::Fixed || layout == LayoutStrategy::Floating);
		states->currentLayoutStrategy = layout;
		states->currentGrowthStrategy = growth_strategy;

		states->dialogWidth = width;
		states->dialogHeight = height;
		states->dialogPosX = x;
		states->dialogPosY = y;
		states->currentPosX = c_paddingLeft;
		if (layout == LayoutStrategy::Floating || title)
			states->currentPosY = c_titledDialogPaddingTop;
		else
			states->currentPosY = c_untitledDialogPaddingTop;
		states->widgetEndX = states->dialogWidth - c_paddingLeft;

		states->mouseState = states->globalMouseState;
		states->mouseState.x = states->globalMouseState.x - states->dialogPosX;
		states->mouseState.y = states->globalMouseState.y - states->dialogPosY;

		int mouse_x = states->mouseState.x;
		int mouse_y = states->mouseState.y;
		// When dialog is moving, logical frame is prev frame
		if (states->movingId == dialog_id && layout == LayoutStrategy::Floating) {
			mouse_x -= states->globalMouseState.x - states->prevGlobalMouseState.x;
			mouse_y -= states->globalMouseState.y - states->prevGlobalMouseState.y;
		}

		if (PtInRect(mouse_x, mouse_y, 0, 0, states->dialogWidth, states->dialogHeight)) {
			if (states->mouseState.action == MouseAction::LButtonDown) {
				states->activeDialogId = dialog_id;
				if (layout == LayoutStrategy::Floating && 
					PtInRect(mouse_x, mouse_y, 0, 0, states->dialogWidth, c_dialogTitleHeight)) {
					states->movingId = dialog_id;
				}
			}
		}
		if (states->mouseState.action == MouseAction::LButtonUp) {
			if (states->activeDialogId == dialog_id)
				states->activeDialogId = -1;
			if (layout == LayoutStrategy::Floating &&
				states->movingId == dialog_id)
				states->movingId = -1;
		}

		if (layout == LayoutStrategy::Floating &&
			states->movingId == dialog_id) {
			if (states->activeDialogId == dialog_id && 
				PtInRect(mouse_x, mouse_y, 0, 0, states->dialogWidth, c_dialogTitleHeight)) {
				x += states->globalMouseState.x - states->prevGlobalMouseState.x;
				y += states->globalMouseState.y - states->prevGlobalMouseState.y;
				states->dialogPosX = x;
				states->dialogPosY = y;
				states->mouseState.x = states->globalMouseState.x - states->dialogPosX;
				states->mouseState.y = states->globalMouseState.y - states->dialogPosY;
				
				states->prevGlobalMouseState = states->globalMouseState;
			}
			else
				states->movingId = -1;
		}
		if (layout == LayoutStrategy::Fixed &&
			states->movingId == dialog_id) {
			states->movingId = -1;
		}

		glClear(GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		glOrtho(0, states->screenWidth, 0, states->screenHeight, 1, -1);

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		// Render the blurred background texture
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glEnable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
		glDisable(GL_DEPTH_TEST);
		GuiRenderer::instance()->blurBackgroundTexture(states->dialogPosX, states->screenHeight - states->dialogPosY,
			states->dialogPosX + states->dialogWidth, states->screenHeight - (states->dialogPosY + states->dialogHeight));
		GuiRenderer::instance()->drawBackgroundTexture(states->dialogPosX, states->screenHeight - states->dialogPosY,
			states->dialogPosX + states->dialogWidth, states->screenHeight - (states->dialogPosY + states->dialogHeight));
		GuiRenderer::instance()->blurBackgroundTexture(states->dialogPosX, states->screenHeight - states->dialogPosY,
			states->dialogPosX + states->dialogWidth, states->screenHeight - (states->dialogPosY + states->dialogHeight));
		GuiRenderer::instance()->drawBackgroundTexture(states->dialogPosX, states->screenHeight - states->dialogPosY,
			states->dialogPosX + states->dialogWidth, states->screenHeight - (states->dialogPosY + states->dialogHeight));
		GuiRenderer::instance()->blurBackgroundTexture(states->dialogPosX, states->screenHeight - states->dialogPosY,
			states->dialogPosX + states->dialogWidth, states->screenHeight - (states->dialogPosY + states->dialogHeight));
		GuiRenderer::instance()->drawBackgroundTexture(states->dialogPosX, states->screenHeight - states->dialogPosY,
			states->dialogPosX + states->dialogWidth, states->screenHeight - (states->dialogPosY + states->dialogHeight));

		glTranslatef((GLfloat)states->dialogPosX, (GLfloat)states->screenHeight - states->dialogPosY, 0.0f);
		glScalef(1.0f, -1.0f, 1.0f);

		glLineWidth(1.0f);
		glDepthFunc(GL_LEQUAL);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_CONSTANT_ALPHA);
		glBlendEquation(GL_FUNC_ADD);

		GuiRenderer::instance()->drawRoundedRect(0,
			0,
			states->dialogWidth,
			states->dialogHeight,
			GuiRenderer::DEPTH_FAR,
			12.0f,
			true,
			{ 0.1f, 0.1f, 0.1f, 1.f },
			{ 0.0f, 0.0f, 0.0f, 0.2f });

		if (layout == LayoutStrategy::Floating) {
			GuiRenderer::instance()->drawHalfRoundedRect(0,
				0,
				states->dialogWidth,
				c_dialogTitleHeight,
				GuiRenderer::DEPTH_FAR,
				12.0f,
				true,
				{ 0.1f, 0.1f, 0.1f, 1.0f },
				{ 0.0f, 0.0f, 0.0f, 0.03f });
		}

		if (title) {
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			GuiRenderer::instance()->drawString(10, 6, GuiRenderer::DEPTH_FAR, title);
		}

		glEnable(GL_DEPTH_TEST);
	}

	void AyaGui::BeginSidebarDialog(LayoutStrategy layout,
		const int width, const int height,
		GrowthStrategy growth_strategy) {
		auto dialog_id(states->currentDialogId++);

		assert(layout == LayoutStrategy::DockLeft || layout == LayoutStrategy::DockRight);
		states->currentLayoutStrategy = layout;
		states->currentGrowthStrategy = growth_strategy;

		switch (layout) {
		case LayoutStrategy::DockRight:
			states->dialogWidth = c_sidebarWidth;
			states->dialogHeight = states->screenHeight;
			states->dialogPosX = states->screenWidth - states->dialogWidth;
			states->dialogPosY = 0;
			states->currentPosX = c_paddingLeft;
			states->currentPosY = c_sidebarPaddingTop;
			states->widgetEndX = states->dialogWidth - c_paddingLeft;
			break;

		case LayoutStrategy::DockLeft:
			states->dialogWidth = c_sidebarWidth;
			states->dialogHeight = states->screenHeight;
			states->dialogPosX = 0;
			states->dialogPosY = 0;
			states->currentPosX = c_paddingLeft;
			states->currentPosY = c_sidebarPaddingTop;
			states->widgetEndX = states->dialogWidth - c_paddingLeft;
			break;
		}

		states->mouseState = states->globalMouseState;
		states->mouseState.x = states->globalMouseState.x - states->dialogPosX;
		states->mouseState.y = states->globalMouseState.y - states->dialogPosY;

		if (states->mouseState.x >= 0 &&
			states->mouseState.x < states->dialogWidth &&
			states->mouseState.y > 0 &&
			states->mouseState.y <= states->dialogHeight) {
			if (states->mouseState.action == MouseAction::LButtonDown)
				states->activeDialogId = dialog_id;
		}
		if (states->mouseState.action == MouseAction::LButtonUp) {
			if (states->activeDialogId == dialog_id)
				states->activeDialogId = -1;
		}

		glClear(GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		glOrtho(0, states->screenWidth, 0, states->screenHeight, 1, -1);

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		// Render the blurred background texture
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glEnable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
		glDisable(GL_DEPTH_TEST);
		GuiRenderer::instance()->blurBackgroundTexture(states->dialogPosX, states->screenHeight - states->dialogPosY,
			states->dialogPosX + states->dialogWidth, states->screenHeight - (states->dialogPosY + states->dialogHeight));
		GuiRenderer::instance()->drawBackgroundTexture(states->dialogPosX, states->screenHeight - states->dialogPosY,
			states->dialogPosX + states->dialogWidth, states->screenHeight - (states->dialogPosY + states->dialogHeight));
		GuiRenderer::instance()->blurBackgroundTexture(states->dialogPosX, states->screenHeight - states->dialogPosY,
			states->dialogPosX + states->dialogWidth, states->screenHeight - (states->dialogPosY + states->dialogHeight));
		GuiRenderer::instance()->drawBackgroundTexture(states->dialogPosX, states->screenHeight - states->dialogPosY,
			states->dialogPosX + states->dialogWidth, states->screenHeight - (states->dialogPosY + states->dialogHeight));
		GuiRenderer::instance()->blurBackgroundTexture(states->dialogPosX, states->screenHeight - states->dialogPosY,
			states->dialogPosX + states->dialogWidth, states->screenHeight - (states->dialogPosY + states->dialogHeight));
		GuiRenderer::instance()->drawBackgroundTexture(states->dialogPosX, states->screenHeight - states->dialogPosY,
			states->dialogPosX + states->dialogWidth, states->screenHeight - (states->dialogPosY + states->dialogHeight));

		glTranslatef((GLfloat)states->dialogPosX, (GLfloat)states->screenHeight - states->dialogPosY, 0.0f);
		glScalef(1.0f, -1.0f, 1.0f);

		glLineWidth(1.0f);
		glDepthFunc(GL_LEQUAL);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_CONSTANT_ALPHA);
		glBlendEquation(GL_FUNC_ADD);

		// Draw blurred background
		
		glBlendColor(1.0f, 1.0f, 1.0f, 0.5f);
		glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
		glBegin(GL_QUADS);

		glVertex3f(0.0f, 0.0f, GuiRenderer::DEPTH_FAR);
		glVertex3f((GLfloat)states->dialogWidth, 0.0f, GuiRenderer::DEPTH_FAR);
		glVertex3f((GLfloat)states->dialogWidth, (GLfloat)states->dialogHeight, GuiRenderer::DEPTH_FAR);
		glVertex3f(0.0f, (GLfloat)states->dialogHeight, GuiRenderer::DEPTH_FAR);

		glEnd();
		glEnable(GL_DEPTH_TEST);
	}

	void AyaGui::EndDialog() {
		glPopAttrib();
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
	}

	bool AyaGui::HandleMouseEvent(const MouseEvent &mouse) {
		if (states->movingId == -1)
			states->prevGlobalMouseState = states->globalMouseState;
		states->globalMouseState = mouse;

		return states->activeDialogId != -1;
	}

	bool AyaGui::HandleKeyboardEvent(const KeyboardEvent &key) {
		states->keyState = key;

		return states->activeDialogId != -1;
	}

	void AyaGui::Text(const char *str, ...) {
		states->currentId++;

		va_list args;
		va_start(args, str);

		char buff[1024];
		int size = vsnprintf(buff, sizeof(buff) - 1, str, args);

		va_end(args);

		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		GuiRenderer::instance()->drawString(states->currentPosX, states->currentPosY + 3, GuiRenderer::DEPTH_MID, buff);

		if (states->currentGrowthStrategy == GrowthStrategy::Vertical) {
			states->currentPosY += c_textHeight + c_defaultMarginBottom;
			states->currentPosX = c_paddingLeft;
		}
		else {
			int line_length = 0;
			SIZE text_extent;
			for (int i = 0; i < size; i++) {
				GetTextExtentPoint32A(GuiRenderer::instance()->getHDC(), &buff[i], 1, &text_extent);
				line_length += text_extent.cx;
			}
			
			states->currentPosX += line_length + c_defaultMarginRight;
		}
	}

	void AyaGui::Text(Color4f color, const char *str, ...) {
		states->currentId++;

		va_list args;
		va_start(args, str);

		char buff[1024];
		int size = vsnprintf(buff, sizeof(buff) - 1, str, args);

		va_end(args);

		glColor4f(color.r, color.g, color.b, color.a);
		GuiRenderer::instance()->drawString(states->currentPosX, states->currentPosY + 3, GuiRenderer::DEPTH_MID, buff);

		if (states->currentGrowthStrategy == GrowthStrategy::Vertical) {
			states->currentPosY += c_textHeight + c_defaultMarginBottom;
			states->currentPosX = c_paddingLeft;
		}
		else {
			int line_length = 0;
			SIZE text_extent;
			for (int i = 0; i < size; i++) {
				GetTextExtentPoint32A(GuiRenderer::instance()->getHDC(), &buff[i], 1, &text_extent);
				line_length += text_extent.cx;
			}

			states->currentPosX += line_length + c_defaultMarginRight;
		}
	}

	void AyaGui::MultilineText(const char *str, ...) {
		states->currentId++;

		va_list args;
		va_start(args, str);

		char buff[4096];
		int size = vsnprintf(buff, sizeof(buff) - 1, str, args);

		va_end(args);

		std::vector<int> line_idx;
		std::string reformatted_str;
		line_idx.clear();
		line_idx.push_back(0);

		// Split Text into lines
		int line_length = 0;
		for (int i = 0; i < size; i++) {
			if (buff[i] == '\n') {
				reformatted_str += '\0';
				line_length = 0;
				line_idx.push_back(reformatted_str.length());
			}
			else {
				reformatted_str += buff[i];

				SIZE text_extent;
				GetTextExtentPoint32A(GuiRenderer::instance()->getHDC(), &buff[i], 1, &text_extent);
				line_length += text_extent.cx;

				if (line_length >= states->widgetEndX - states->currentPosX) {
					reformatted_str += '\0';
					line_length = 0;
					line_idx.push_back(reformatted_str.length());
				}
			}
		}

		// Render Text
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		for (size_t i = 0; i < line_idx.size(); i++) {
			GuiRenderer::instance()->drawString(states->currentPosX,
				states->currentPosY + i * c_multilineTextHeight,
				GuiRenderer::DEPTH_MID,
				reformatted_str.c_str() + line_idx[i]);
		}

		if (states->currentGrowthStrategy == GrowthStrategy::Vertical) {
			states->currentPosY += line_idx.size() * c_multilineTextHeight + c_defaultMarginBottom;
			states->currentPosX = c_paddingLeft;
		}
		else
			states->currentPosX += c_defaultMarginRight;
	}

	bool AyaGui::Button(const char *label, const int width, const int height, const bool banned) {
		bool triggered = false;
		int id(states->currentId++);

		int left = states->currentPosX;
		int right = states->currentPosX + width;
		right = right > states->widgetEndX ? states->widgetEndX : right;
		int top = states->currentPosY;
		int bottom = states->currentPosY + height;

		if (!banned) {
			bool in_rect = PtInRect(states->mouseState.x, states->mouseState.y, left, top, right, bottom);

			if (in_rect) {
				if (states->mouseState.action == MouseAction::LButtonDown)
					states->activeId = id;

				states->hoveredId = id;
			}

			if (states->mouseState.action == MouseAction::LButtonUp) {
				if (states->activeId == id) {
					states->activeId = -1;
					if (in_rect)
						triggered = true;
				}
			}
		}
		else {
			if (states->activeId == id)
				states->activeId = -1;
		}

		float btn_radius = 5.0f;
		if (banned) {
			GuiRenderer::instance()->drawRoundedRect(left, top, right, bottom,
				GuiRenderer::DEPTH_MID, btn_radius, true, { 1.0f, 1.0f, 1.0f, 0.3f });
			glColor4f(0.15f, 0.15f, 0.15f, 0.15f);
		}
		else if (states->hoveredId == id && states->activeId == id) {
			GuiRenderer::instance()->drawRoundedRect(left + 1, top + 1, right - 1, bottom - 1,
				GuiRenderer::DEPTH_MID, btn_radius, true, { 1.0f, 1.0f, 1.0f, 0.65f });
			glColor4f(0.15f, 0.15f, 0.15f, 0.15f);
		}
		else if (states->hoveredId == id && states->activeId == -1 || states->activeId == id) {
			GuiRenderer::instance()->drawRoundedRect(left, top, right, bottom,
				GuiRenderer::DEPTH_MID, btn_radius, true, { 1.0f, 1.0f, 1.0f, 0.5f });
			glColor4f(0.15f, 0.15f, 0.15f, 0.15f);
		}
		else {
			GuiRenderer::instance()->drawRoundedRect(left, top, right, bottom,
				GuiRenderer::DEPTH_MID, btn_radius, false, { 1.0f, 1.0f, 1.0f, 0.5f });
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		}

		SIZE text_extent;
		GetTextExtentPoint32A(GuiRenderer::instance()->getHDC(), label, strlen(label), &text_extent);
		glBlendColor(0.0f, 0.0f, 0.0f, 0.0f);
		GuiRenderer::instance()->drawString((right + left - text_extent.cx) / 2,
			(top + bottom - text_extent.cy) / 2 + 4, 
			GuiRenderer::DEPTH_MID, label);

		if (states->currentGrowthStrategy == GrowthStrategy::Vertical) {
			states->currentPosY += height + c_defaultMarginBottom;
			states->currentPosX = c_paddingLeft;
		}
		else {
			states->currentPosX += right - left + c_defaultMarginRight;
		}

		return triggered;
	}

	void AyaGui::Line() {
		glLineWidth(1.0f);
		glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
		if (states->currentGrowthStrategy == GrowthStrategy::Horizontal) {
			states->currentGrowthStrategy = GrowthStrategy::Vertical;
			states->currentPosY += c_defaultMarginBottom + c_lineMarginBottom;
			states->currentPosX = c_paddingLeft;
		}

		GuiRenderer::instance()->drawLine(5, states->currentPosY, states->dialogWidth - 5, states->currentPosY, GuiRenderer::DEPTH_MID);
		states->currentPosY += c_lineMarginBottom;
	}

	void AyaGui::ComboBox(const char *label, const std::vector<std::string> items, int &selected, int width, const bool banned) {
		if (label) Text(label);

		if (states->currentGrowthStrategy == GrowthStrategy::Vertical)
			states->currentPosY -= c_defaultMarginBottom / 2;
		else
			states->currentPosX -= c_defaultMarginRight / 2;

		int id(states->currentId++);
		if (width + states->currentPosX > states->widgetEndX)
			width = states->widgetEndX - states->currentPosX;
		int frame_left = states->currentPosX;
		int frame_top = states->currentPosY;
		int frame_right = states->currentPosX + width;
		int frmae_bottom = states->currentPosY + c_comboBoxHeight;

		static bool list_down_current_frame;
		list_down_current_frame = false;

		if (!banned) {
			if (PtInRect(states->mouseState.x, states->mouseState.y, frame_left, frame_top, frame_right, frmae_bottom)) {
				if (states->mouseState.action == MouseAction::LButtonDown) {
					if (states->activeId != id)
						states->activeId = id;
					else if (states->activeId == id)
						states->activeId = -1;

					list_down_current_frame = true;
				}

				states->hoveredId = id;
			}
		}
		else {
			if (states->activeId == id)
				states->activeId = -1;
		}

		Color4f button_color = !banned ? (states->activeId == id || states->hoveredId == id && states->activeId == -1 ? 
			Color4f(1.0f, 1.0f, 1.0f, 0.65f) : 
			Color4f(1.0f, 1.0f, 1.0f, 0.5f)) : Color4f(1.0f, 1.0f, 1.0f, 0.3f);

		GuiRenderer::instance()->drawRect(frame_left, frame_top, frame_right, frmae_bottom, GuiRenderer::DEPTH_MID, false, button_color);
		GuiRenderer::instance()->drawRect(frame_right - c_comboBoxHeight, frame_top + 1, frame_right - 1, frmae_bottom - 1, GuiRenderer::DEPTH_MID, true, button_color);
		
		glBlendColor(0.0f, 0.0f, 0.0f, 0.0f);
		if (!banned)
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		else
			glColor4f(1.0f, 1.0f, 1.0f, 0.65f);

		if (selected >= 0 && selected < int(items.size()))
			GuiRenderer::instance()->drawString(frame_left + 3, frame_top + 5, GuiRenderer::DEPTH_MID, items[selected].c_str());
		else
			GuiRenderer::instance()->drawString(frame_left + 5, frame_top + 5, GuiRenderer::DEPTH_MID, "...");

		if (states->activeId == id) {
			int drop_left = states->currentPosX;
			int drop_top = states->currentPosY + c_comboBoxHeight;
			int drop_right = drop_left + width - c_comboBoxHeight;
			int drop_bottom = drop_top + 1 + int(items.size()) * c_comboBoxItemHeight;

			if (states->mouseState.action == MouseAction::LButtonDown) {
				if (PtInRect(states->mouseState.x, states->mouseState.y, drop_left, drop_top, drop_right, drop_bottom))
					selected = (states->mouseState.y - drop_top) / c_comboBoxItemHeight;

				if (!list_down_current_frame) {
					states->activeId = -1;
					states->hoveredId = id;
					states->mouseState.action = MouseAction::None;
				}
			}

			GuiRenderer::instance()->drawRect(drop_left, drop_top + 1, drop_right, drop_bottom, GuiRenderer::DEPTH_NEAR, true, { 0.25f, 0.25f, 0.25f, 1.0f });

			int hovered_idx = (states->mouseState.y - drop_top) / c_comboBoxItemHeight;
			if (hovered_idx < 0)
				hovered_idx = 0;
			if (hovered_idx >= int(items.size()))
				hovered_idx = int(items.size()) - 1;

			for (int i = 0; i < int(items.size()); i++) {
				if (i == hovered_idx) {
					GuiRenderer::instance()->drawRect(
						drop_left,
						drop_top + 2 + hovered_idx * c_comboBoxItemHeight,
						drop_right - 1,
						drop_top + 1 + (hovered_idx + 1) * c_comboBoxItemHeight,
						GuiRenderer::DEPTH_NEAR,
						true,
						{ 0.4f, 0.4f, 0.4f, 0.5f });

					glBlendColor(0.0f, 0.0f, 0.0f, 0.0f);
					glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
				}
				else {
					glBlendColor(0.0f, 0.0f, 0.0f, 0.0f);
					glColor4f(0.9f, 0.9f, 0.9f, 1.0f);
				}

				GuiRenderer::instance()->drawString(drop_left + 3, drop_top + 6 + i * c_comboBoxItemHeight, GuiRenderer::DEPTH_NEAR, items[i].c_str());
			}
		}

		if (states->currentGrowthStrategy == GrowthStrategy::Vertical) {
			states->currentPosY += c_comboBoxHeight + c_defaultMarginBottom;
			states->currentPosX = c_paddingLeft;
		}
		else
			states->currentPosX += width + c_defaultMarginBottom;
	}

	bool AyaGui::CheckBox(const char *label, bool &checked, const bool banned) {
		bool triggered = false;

		int id(states->currentId++);

		int box_left = states->currentPosX;
		int box_top = states->currentPosY;
		int box_right = box_left + c_checkBoxSize;
		int box_bottom = box_top + c_checkBoxSize;

		if (!banned) {
			if (PtInRect(states->mouseState.x, states->mouseState.y, box_left, box_top, box_right, box_bottom)) {
				if (states->mouseState.action == MouseAction::LButtonDown)
					states->activeId = id;
				if (states->mouseState.action == MouseAction::LButtonUp) {
					if (states->activeId == id) {
						states->activeId = -1;
						checked = !checked;
						triggered = true;
					}
				}

				states->hoveredId = id;
			}
			else {
				if (states->mouseState.action == MouseAction::Move)
					if (states->activeId == id)
						states->activeId = -1;
			}
		}
		else {
			if (states->activeId == id)
				states->activeId = -1;
		}

		Color4f color1 = banned ? Color4f(1.0f, 1.0f, 1.0f, 0.3f) :
			states->hoveredId == id && states->activeId == -1 ? Color4f(1.0f, 1.0f, 1.0f, 0.65f) : Color4f(1.0f, 1.0f, 1.0f, 0.5f);
		GuiRenderer::instance()->drawRect(box_left,
			box_top,
			box_right,
			box_bottom,
			GuiRenderer::DEPTH_MID,
			false,
			color1);

		Color4f color2 = checked ? color1 : states->hoveredId == id && states->activeId == -1 && !banned ? 
			Color4f(1.0f, 1.0f, 1.0f, 0.15f) : Color4f(1.0f, 1.0f, 1.0f, 0.1f);
		GuiRenderer::instance()->drawRect(box_left + 2,
			box_top + 2,
			box_right - 2,
			box_bottom - 2,
			GuiRenderer::DEPTH_MID,
			true,
			color2);

		if (!banned)
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		else
			glColor4f(1.0f, 1.0f, 1.0f, 0.65f);
		GuiRenderer::instance()->drawString(box_right + 7, box_top + 2, GuiRenderer::DEPTH_MID, label);

		if (states->currentGrowthStrategy == GrowthStrategy::Vertical) {
			states->currentPosY += c_checkBoxSize + c_defaultMarginBottom;
			states->currentPosX = c_paddingLeft;
		}
		else {
			SIZE text_extent;
			GetTextExtentPoint32A(GuiRenderer::instance()->getHDC(), label, strlen(label), &text_extent);
			states->currentPosX += 7 + c_checkBoxSize + text_extent.cx + c_defaultMarginRight;
		}

		return triggered;
	}

	bool AyaGui::RadioButton(const char *label, int active, int &current, const bool banned) {
		bool triggered = false;

		int id(states->currentId++);

		int box_left = states->currentPosX;
		int box_top = states->currentPosY;
		int box_right = box_left + c_radioButtonCircleDiameter;
		int box_bottom = box_top + c_radioButtonCircleDiameter;

		if (!banned) {
			if (PtInRect(states->mouseState.x, states->mouseState.y, box_left, box_top, box_right, box_bottom)) {
				if (states->mouseState.action == MouseAction::LButtonDown)
					states->activeId = id;
				if (states->mouseState.action == MouseAction::LButtonUp) {
					if (states->activeId == id) {
						states->activeId = -1;
						current = active;
						triggered = true;
					}
				}

				states->hoveredId = id;
			}
			else {
				if (states->mouseState.action == MouseAction::Move)
					if (states->activeId == id)
						states->activeId = -1;
			}
		}
		else {
			if (states->activeId == id)
				states->activeId = -1;
		}

		Color4f color1 = banned ? Color4f(1.0f, 1.0f, 1.0f, 0.3f) :
			states->hoveredId == id && states->activeId == -1 ? Color4f(1.0f, 1.0f, 1.0f, 0.65f) : Color4f(1.0f, 1.0f, 1.0f, 0.5f);
		GuiRenderer::instance()->drawCircle((box_left + box_right) / 2,
			(box_top + box_bottom) / 2,
			GuiRenderer::DEPTH_MID,
			c_radioButtonCircleDiameter / 2,
			false,
			color1);

		Color4f color2 = (current == active) ? color1 : states->hoveredId == id && states->activeId == -1 && !banned ? 
			Color4f(1.0f, 1.0f, 1.0f, 0.15f) : Color4f(0.0f, 0.0f, 0.0f, 0.0f);
		GuiRenderer::instance()->drawCircle((box_left + box_right) / 2,
			(box_top + box_bottom) / 2,
			GuiRenderer::DEPTH_MID,
			c_radioButtonCircleDiameter / 2 - 2,
			true,
			color2);

		if (!banned)
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		else
			glColor4f(1.0f, 1.0f, 1.0f, 0.65f);
		GuiRenderer::instance()->drawString(box_right + 7, box_top + 2, GuiRenderer::DEPTH_MID, label);

		if (states->currentGrowthStrategy == GrowthStrategy::Vertical) {
			states->currentPosY += c_checkBoxSize + c_defaultMarginBottom;
			states->currentPosX = c_paddingLeft;
		}
		else {
			SIZE text_extent;
			GetTextExtentPoint32A(GuiRenderer::instance()->getHDC(), label, strlen(label), &text_extent);
			states->currentPosX += 7 + c_checkBoxSize + text_extent.cx + c_defaultMarginRight;
		}

		return triggered;
	}

	void AyaGui::ColorBlock(float r, float g, float b, int size) {
		int block_left = states->currentPosX;
		int block_top = states->currentPosY;
		int block_right = block_left + size;
		int block_bottom = block_top + size;

		GuiRenderer::instance()->drawRect(block_left - 1, block_top - 1, block_right + 1, block_bottom + 1,
			GuiRenderer::DEPTH_MID, false, { 1.0f, 1.0f, 1.0f, 1.0f });
		GuiRenderer::instance()->drawRect(block_left, block_top, block_right, block_bottom,
			GuiRenderer::DEPTH_MID, true, { r, g, b, 1.0f });

		auto To0x = [](float val) {
			static const char* table[0x10] =
			{ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F" };

			uint32_t uint_val = uint32_t(val * 0xFF);
			return std::string(table[uint_val % 0x10]) + std::string(table[uint_val / 0x10]);
		};

		if (PtInRect(states->mouseState.x, states->mouseState.y, block_left, block_top, block_right, block_bottom)) {
			std::string encode = "#" + To0x(r) + To0x(g) + To0x(b);
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			GuiRenderer::instance()->drawString(states->mouseState.x + 15, states->mouseState.y + 15, GuiRenderer::DEPTH_NEAR, encode.c_str());
		}
	}

	void AyaGui::InputText(std::string &str, int width, const bool auto_select_all, const bool auto_clear_on_enter, const bool banned) {
		int id(states->currentId++);

		auto calc_prefix = [&]() {
			states->stringWidthPrefixSum.clear();
			states->stringWidthPrefixSum.push_back(0);

			for (auto c : states->stringBuffer) {
				SIZE text_extent;
				GetTextExtentPoint32A(GuiRenderer::instance()->getHDC(), &c, 1, &text_extent);
				states->stringWidthPrefixSum.push_back(text_extent.cx + states->stringWidthPrefixSum.back());
			}
		};

		if (states->currentPosX + width > states->widgetEndX)
			width = states->widgetEndX - states->currentPosX;
		int left = states->currentPosX;
		int top = states->currentPosY;
		int right = left + width;
		int bottom = top + c_inputTextDefaultHeight;

		if (!banned) {
			if (PtInRect(states->mouseState.x, states->mouseState.y, left, top, right, bottom)) {
				if (states->mouseState.action == MouseAction::LButtonDbClick || (states->mouseState.action == MouseAction::LButtonDown && auto_select_all)) {
					states->activeId = id;
					if (states->editingId != id) {
						states->editingId = id;
						states->stringBuffer = str;
					}

					calc_prefix();

					states->cursorPos = c_inputTextIndent + (states->stringBuffer.length() > 0 ? states->stringWidthPrefixSum.back() : 0);
					states->cursorIdx = states->stringBuffer.length();
					states->selectIdx = 0;
				}
				else if (states->mouseState.action == MouseAction::LButtonDown) {
					states->activeId = id;
					if (states->editingId != id) {
						states->editingId = id;
						states->stringBuffer = str;
					}

					calc_prefix();

					int dist_x = states->mouseState.x - (states->currentPosX + 3);
					int char_it = std::lower_bound(states->stringWidthPrefixSum.begin(), states->stringWidthPrefixSum.end(), dist_x) -
						states->stringWidthPrefixSum.begin();
					if (--char_it < 0) char_it = 0;

					states->cursorIdx = char_it;
					states->cursorPos = c_inputTextIndent + states->stringWidthPrefixSum[char_it];
					states->selectIdx = states->cursorIdx;
				}

				states->hoveredId = id;
			}
			else if (states->mouseState.action == MouseAction::LButtonDown || states->mouseState.action == MouseAction::LButtonDbClick) {
				if (states->editingId == id) {
					states->editingId = -1;
					str = states->stringBuffer;
				}
				if (states->activeId == id)
					states->activeId = -1;
			}

			if (states->mouseState.action == MouseAction::Move && states->mouseState.l_down && states->activeId == id) {
				int dist_x = states->mouseState.x - (states->currentPosX + 3);
				int char_it = std::lower_bound(states->stringWidthPrefixSum.begin(), states->stringWidthPrefixSum.end(), dist_x) -
					states->stringWidthPrefixSum.begin();
				if (--char_it < 0) char_it = 0;

				states->cursorIdx = char_it;
				states->cursorPos = c_inputTextIndent + states->stringWidthPrefixSum[char_it];
			}

			if (states->activeId == id && (states->keyState.funckey != FunctionKey::None || states->keyState.key != '\0')) {
				switch (states->keyState.funckey) {
				case FunctionKey::LeftArrow: {
					auto ori_idx = states->cursorIdx--;
					if (states->cursorIdx < 0) states->cursorIdx = 0;
					states->cursorPos += states->stringWidthPrefixSum[states->cursorIdx] - states->stringWidthPrefixSum[ori_idx];
					if (states->keyState.keymode != KeyMode::Shift) states->selectIdx = states->cursorIdx;
					break;
				}
				case FunctionKey::RightArrow: {
					auto ori_idx = states->cursorIdx++;
					if (states->cursorIdx > (int)states->stringBuffer.length()) states->cursorIdx = states->stringBuffer.length();
					states->cursorPos += states->stringWidthPrefixSum[states->cursorIdx] - states->stringWidthPrefixSum[ori_idx];
					if (states->keyState.keymode != KeyMode::Shift) states->selectIdx = states->cursorIdx;
					break;
				}
				case FunctionKey::UpArrow: {
					states->selectIdx = 0;
					break;
				}
				case FunctionKey::DownArrow: {
					states->selectIdx = states->stringBuffer.length();
					break;
				}
				case FunctionKey::Enter: {
					if (states->editingId == id && states->activeId == id) {
						str = states->stringBuffer;
						if (auto_clear_on_enter) {
							states->stringBuffer.clear();

							states->cursorIdx = states->selectIdx = 0;
							states->cursorPos = c_inputTextIndent;
							calc_prefix();
						}
						else {
							states->editingId = -1;
							states->activeId = -1;
						}
					}
					states->selectIdx = states->cursorIdx;
					break;
				}
				case FunctionKey::BackSpace: {
					if (states->cursorIdx != states->selectIdx) {
						auto min_idx = states->selectIdx;
						auto max_idx = states->cursorIdx;
						if (min_idx > max_idx) std::swap(min_idx, max_idx);
						states->stringBuffer.erase(min_idx, max_idx - min_idx);
						states->cursorIdx = min_idx;
						states->cursorPos = c_inputTextIndent + states->stringWidthPrefixSum[min_idx];
						calc_prefix();
					}
					else if (states->cursorIdx > 0) {
						int shift = states->stringWidthPrefixSum[states->cursorIdx] - states->stringWidthPrefixSum[states->cursorIdx - 1];
						states->stringBuffer.erase(states->cursorIdx - 1, 1);

						calc_prefix();

						states->cursorPos -= shift;
						states->cursorIdx--;
					}
					states->selectIdx = states->cursorIdx;
					break;
				}
				case FunctionKey::Delete: {
					if (states->cursorIdx != states->selectIdx) {
						auto min_idx = states->selectIdx;
						auto max_idx = states->cursorIdx;
						if (min_idx > max_idx) std::swap(min_idx, max_idx);
						states->stringBuffer.erase(min_idx, max_idx - min_idx);
						states->cursorIdx = min_idx;
						states->cursorPos = c_inputTextIndent + states->stringWidthPrefixSum[min_idx];
						calc_prefix();
					}
					else if (states->cursorIdx < (int)states->stringBuffer.length()) {
						int indent = states->stringWidthPrefixSum[states->cursorIdx + 1] - states->stringWidthPrefixSum[states->cursorIdx];
						states->stringBuffer.erase(states->cursorIdx, 1);

						calc_prefix();
					}
					states->selectIdx = states->cursorIdx;
					break;
				}
				case FunctionKey::Home: {
					states->cursorPos = c_inputTextIndent;
					states->cursorIdx = 0;
					states->selectIdx = states->cursorIdx;
					break;
				}
				case FunctionKey::End: {
					states->cursorPos = states->stringWidthPrefixSum.back() + c_inputTextIndent;
					states->cursorIdx = states->stringWidthPrefixSum.size() - 1;
					states->selectIdx = states->cursorIdx;
					break;
				}
				}

				if (states->keyState.keymode == KeyMode::Ctrl) {
					switch (states->keyState.key) {
					case 'A':
					case 'a':
						states->selectIdx = 0;
						states->cursorIdx = states->stringBuffer.length();
						states->cursorPos = states->stringWidthPrefixSum.back() + c_inputTextIndent;
						break;

					case 'C':
					case 'c':
						if (states->cursorIdx != states->selectIdx) {
							auto min_idx = states->selectIdx;
							auto max_idx = states->cursorIdx;
							if (min_idx > max_idx) std::swap(min_idx, max_idx);
							states->clipboard = states->stringBuffer.substr(min_idx, max_idx - min_idx);
						}
						break;

					case 'X':
					case 'x':
						if (states->cursorIdx != states->selectIdx) {
							auto min_idx = states->selectIdx;
							auto max_idx = states->cursorIdx;
							if (min_idx > max_idx) std::swap(min_idx, max_idx);
							states->clipboard = states->stringBuffer.substr(min_idx, max_idx - min_idx);

							states->stringBuffer.erase(min_idx, max_idx - min_idx);
							states->cursorIdx = states->selectIdx = min_idx;
							states->cursorPos = c_inputTextIndent + states->stringWidthPrefixSum[min_idx];
							calc_prefix();
						}
						break;

					case 'V':
					case 'v':
						if (states->clipboard.length()) {
							auto min_idx = states->selectIdx;
							auto max_idx = states->cursorIdx;
							if (min_idx > max_idx) std::swap(min_idx, max_idx);

							SIZE text_extent;
							GetTextExtentPoint32A(GuiRenderer::instance()->getHDC(), states->clipboard.c_str(), states->clipboard.length(), &text_extent);
							if (states->stringWidthPrefixSum.back() + text_extent.cx -
								(states->stringWidthPrefixSum[max_idx] - states->stringWidthPrefixSum[min_idx]) >= width - c_inputTextIndent)
								break;

							if (states->cursorIdx != states->selectIdx) {
								states->stringBuffer.erase(min_idx, max_idx - min_idx);
								states->stringBuffer.insert(min_idx, states->clipboard);
								states->cursorIdx = states->selectIdx = min_idx + states->clipboard.length();
							}
							else {
								states->stringBuffer.insert(states->cursorIdx, states->clipboard);
								states->cursorIdx = states->selectIdx = states->cursorIdx + states->clipboard.length();
							}

							calc_prefix();
							states->cursorPos = c_inputTextIndent + states->stringWidthPrefixSum[states->cursorIdx];
						}

						break;
					}
				}

				if (states->keyState.keymode == KeyMode::None && (states->keyState.key > 0x2F && states->keyState.key < 0x7F)) {
					if (states->cursorIdx != states->selectIdx) {
						auto min_idx = states->selectIdx;
						auto max_idx = states->cursorIdx;
						if (min_idx > max_idx) std::swap(min_idx, max_idx);
						states->stringBuffer.erase(min_idx, max_idx - min_idx);
						states->cursorIdx = min_idx;
						states->cursorPos = c_inputTextIndent + states->stringWidthPrefixSum[min_idx];
						calc_prefix();
					}

					SIZE text_extent;
					GetTextExtentPoint32A(GuiRenderer::instance()->getHDC(), &states->keyState.key, 1, &text_extent);

					if (states->stringWidthPrefixSum.back() + text_extent.cx < width - c_inputTextIndent) {
						states->stringBuffer.insert(states->cursorIdx, { states->keyState.key });

						calc_prefix();

						states->cursorPos += text_extent.cx;
						states->cursorIdx++;
						states->selectIdx = states->cursorIdx;
					}
				}
			}
		}
		else {
			if (states->activeId == id && states->editingId == id) {
				str = states->stringBuffer;

				states->cursorIdx = 0;
				states->selectIdx = 0;
				states->cursorPos = c_inputTextIndent;
			}
			if (states->activeId == id)
				states->activeId = -1;
			if (states->editingId == id)
				states->editingId = -1;
		}

		Color4f color = 
			banned ? Color4f(1.0f, 1.0f, 1.0f, 0.3f) :
			states->hoveredId == id && states->activeId == -1 || states->activeId == id ? Color4f(1.0f, 1.0f, 1.0f, 0.65f) : Color4f(1.0f, 1.0f, 1.0f, 0.5f);
		GuiRenderer::instance()->drawRect(left, top, right, bottom, GuiRenderer::DEPTH_MID, false, color);

		if (states->hoveredId == id && states->activeId == -1 || states->activeId == id) {
			glPushAttrib(GL_COLOR_BUFFER_BIT);
			glBlendFunc(GL_DST_COLOR, GL_CONSTANT_ALPHA);
			GuiRenderer::instance()->drawRect(left, top, right, bottom, GuiRenderer::DEPTH_MID, true, { 0.6f, 0.6f, 0.6f, 1.0f });
			glPopAttrib();
		}

		std::string &rendered_str = states->activeId != id ? str : states->stringBuffer;

		if (states->selectIdx == states->cursorIdx || states->activeId != id) {
			if (!banned)
				glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			else
				glColor4f(1.0f, 1.0f, 1.0f, 0.65f);
			GuiRenderer::instance()->drawString(states->currentPosX + 3, states->currentPosY + 5, GuiRenderer::DEPTH_MID, rendered_str.c_str());
		}
		else {
			auto min_idx = states->selectIdx;
			auto max_idx = states->cursorIdx;
			if (min_idx > max_idx) std::swap(min_idx, max_idx);

			GuiRenderer::instance()->drawRect(states->currentPosX + c_inputTextIndent + states->stringWidthPrefixSum[min_idx],
				states->currentPosY + 3,
				states->currentPosX + c_inputTextIndent + states->stringWidthPrefixSum[max_idx],
				states->currentPosY + 16,
				GuiRenderer::DEPTH_MID,
				true,
				color);

			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			GuiRenderer::instance()->drawString(states->currentPosX + 3, states->currentPosY + 5, GuiRenderer::DEPTH_MID, rendered_str.c_str(), min_idx);
			GuiRenderer::instance()->drawString(states->currentPosX + 3 + states->stringWidthPrefixSum[max_idx],
				states->currentPosY + 5, GuiRenderer::DEPTH_MID, rendered_str.c_str() + max_idx);

			glColor4f(0.15f, 0.15f, 0.15f, 0.15f);
			glBlendColor(0.0f, 0.0f, 0.0f, 0.0f);
			GuiRenderer::instance()->drawString(states->currentPosX + 3 + states->stringWidthPrefixSum[min_idx],
				states->currentPosY + 5, GuiRenderer::DEPTH_MID, rendered_str.c_str() + min_idx, max_idx - min_idx);
		}

		if (states->activeId == id)
			GuiRenderer::instance()->drawLine(states->currentPosX + states->cursorPos, states->currentPosY + 3,
				states->currentPosX + states->cursorPos, states->currentPosY + 16, GuiRenderer::DEPTH_MID);

		if (states->currentGrowthStrategy == GrowthStrategy::Vertical) {
			states->currentPosY += c_inputTextDefaultHeight + c_defaultMarginBottom;
			states->currentPosX = c_paddingLeft;
		}
		else {
			states->currentPosX += width + c_defaultMarginRight;
		}
	}

	bool AyaGui::InputDigit(const char *label, int &digit, const bool banned) {
		if (label) Text(label);

		auto x0 = states->currentPosX, y0 = states->currentPosY;
		auto prev_digit = digit;
		
		states->currentPosX = x0 + 62;
		if (Button("-", 20, 18, banned)) --digit;

		states->currentPosX = x0 + 86;
		states->currentPosY = y0;
		if (Button("+", 20, 18, banned)) ++digit;

		states->currentPosX = x0;
		states->currentPosY = y0;
		char buf[32];
		_itoa_s(digit, buf, 10);

		std::string str(buf);
		InputText(str, 60, true, false, banned);

		digit = atoi(str.c_str());
		return digit != prev_digit;
	}

	void AyaGui::Scroller(int limit, int actual, float &lin) {
		int id(states->currentId++);

		if (actual <= limit)
			return;

		states->scrollerActive = true;
		states->currentPosX = c_paddingLeft;

		const int bar_base = states->currentPosY;
		const int diff = 2;
		const int inner_base = bar_base + diff;

		float ratio = float(limit) / float(actual);
		int scroller_len = int(limit * ratio);
		int scroller_start = int(inner_base + (bar_base - inner_base + limit - diff - scroller_len) * lin);

		const int scroller_base = inner_base + scroller_len / 2;
		const int scroller_end = inner_base + limit - scroller_len / 2;

		int scroller_pos = scroller_base + int((scroller_end - scroller_base) * lin);

		int bar_left = states->dialogWidth - c_scrollerMargin;
		int bar_top = bar_base;
		int bar_right = bar_left + c_scrollerWidth;
		int bar_bottom = bar_top + limit;

		auto SetScroller = [&](int pos) {
			scroller_pos = pos;
			if (scroller_pos < scroller_base) scroller_pos = scroller_base;
			if (scroller_pos > scroller_end) scroller_pos = scroller_end;
			lin = float(scroller_pos - scroller_base) / (scroller_end - scroller_base);
			lin = lin < 0.0f ? 0.0f : (lin > 1.0f ? 1.0f : lin);
		};

		if (PtInRect(states->mouseState.x, states->mouseState.y,
			bar_left, bar_top, bar_right, bar_bottom)) {
			if (states->mouseState.action == MouseAction::LButtonDown) {
				states->activeId = id;

				int offset = states->mouseState.y - scroller_pos;
				if (offset < 0) offset = -offset;

				if (offset > scroller_len / 2)
					states->scrollerBottonDownOffset = 0;
				else
					states->scrollerBottonDownOffset = states->mouseState.y - scroller_pos;
			}

			if (states->mouseState.action == MouseAction::LButtonUp) {
				SetScroller(states->mouseState.y - states->scrollerBottonDownOffset);

				if (states->activeId == id)
					states->activeId = -1;
			}

			states->hoveredId = id;
		}

		if (states->mouseState.action == MouseAction::Move && states->mouseState.l_down) {
			if (states->activeId == id) {
				SetScroller(states->mouseState.y - states->scrollerBottonDownOffset);
			}
		}

		if (states->mouseState.action == MouseAction::LButtonUp)
			if (states->activeId == id)
				states->activeId = -1;

		int area_left = 0;
		int area_top = bar_base;
		int area_right = states->dialogWidth;
		int area_bottom = bar_base + limit;

		if (PtInRect(states->mouseState.x, states->mouseState.y,
			area_left, area_top, area_right, area_bottom)) {
			switch (states->keyState.funckey) {
			case FunctionKey::Home:
				if (states->activeId == id || states->activeId == -1)
				SetScroller(scroller_base);
				break;
			case FunctionKey::End:
				if (states->activeId == id || states->activeId == -1)
				SetScroller(scroller_end);
				break;
			case FunctionKey::PageUp:
				states->activeId = id;
				SetScroller(scroller_pos - c_pageControlHeight);
				break;
			case FunctionKey::PageDown:
				states->activeId = id;
				SetScroller(scroller_pos + c_pageControlHeight);
				break;
			case FunctionKey::UpArrow:
				states->activeId = id;
				SetScroller(scroller_pos - c_arrowControlHeight);
				break;
			case FunctionKey::DownArrow:
				states->activeId = id;
				SetScroller(scroller_pos + c_arrowControlHeight);
				break;
			}
		}

		Color4f color = states->hoveredId == id && states->activeId == -1 || states->activeId == id ?
			Color4f(1.0f, 1.0f, 1.0f, 0.65f) : Color4f(1.0f, 1.0f, 1.0f, 0.5f);

		GuiRenderer::instance()->drawRoundedRect(states->dialogWidth - c_scrollerMargin + 1,
			bar_base,
			states->dialogWidth - c_scrollerWidth + 1,
			bar_base + limit,
			GuiRenderer::DEPTH_MID,
			diff * 2,
			false,
			color);

		GuiRenderer::instance()->drawRoundedRect(states->dialogWidth - c_scrollerMargin + diff,
			scroller_start,
			states->dialogWidth - c_scrollerWidth - 1,
			scroller_start + scroller_len,
			GuiRenderer::DEPTH_MID,
			diff,
			true,
			color);
	}

	void AyaGui::BeginScroller(int area_height, int &content_height, float &scroller) {
		glEnable(GL_SCISSOR_TEST);
		glScissor(states->dialogPosX,
			states->screenHeight - (states->dialogPosY + states->currentPosY + area_height),
			states->dialogWidth,
			area_height);

		Scroller(area_height, content_height, scroller);

		int offset = int(scroller * (content_height - area_height));
		if (offset < 0) offset = 0;
		states->scrollerInitY = states->currentPosY - offset;
		states->scrollerOriginY = states->currentPosY;
		states->currentPosY = states->scrollerInitY;
	}

	void AyaGui::EndScroller(int area_height, int &content_height, float &scroller) {
		content_height = states->currentPosY - states->scrollerInitY;
		states->currentPosY = states->scrollerOriginY + area_height + c_defaultMarginBottom;

		if (states->scrollerActive) {
			states->currentPosX = c_paddingLeft;
			states->scrollerActive = false;
		}

		glDisable(GL_SCISSOR_TEST);
	}

	bool AyaGui::CollapsingHeader(const char *label, bool &show) {
		int id(states->currentId++);

		int head_left = states->currentPosX;
		int head_top = states->currentPosY;
		int head_right = states->widgetEndX;
		int head_bottom = states->currentPosY + (show ? c_headerTextHeight : c_headerHeight);

		bool in_rect = PtInRect(states->mouseState.x, states->mouseState.y, head_left, head_top, head_right, head_bottom);

		if (in_rect) {
			if (states->mouseState.action == MouseAction::LButtonDown)
				states->activeId = id;

			states->hoveredId = id;
		}

		if (states->mouseState.action == MouseAction::LButtonUp) {
			if (states->activeId == id) {
				states->activeId = -1;
				if (in_rect)
					show = !show;
			}
		}

		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		GuiRenderer::instance()->drawString(states->currentPosX, states->currentPosY, GuiRenderer::DEPTH_MID, label);

		Color4f color = states->hoveredId == id && states->activeId == -1 || states->activeId == id ?
			Color4f(1.0f, 1.0f, 1.0f, 1.0f) : Color4f(1.0f, 1.0f, 1.0f, 0.5f);
		glColor4fv((float*)&color);
		GuiRenderer::instance()->drawLine(states->currentPosX, states->currentPosY + c_headerTextHeight + 1, 
			states->widgetEndX, states->currentPosY + c_headerTextHeight + 1, GuiRenderer::DEPTH_MID);

		if (!show)
			GuiRenderer::instance()->drawString(states->widgetEndX - 15, states->currentPosY + c_headerTextHeight + 6, GuiRenderer::DEPTH_MID, "...");

		states->currentGrowthStrategy = GrowthStrategy::Vertical;
		states->currentPosY += (!show ? c_headerHeight : c_headerTextHeight) + c_defaultMarginRight;

		return show;
	}

	bool AyaGui::PtInRect(int x0, int y0, int left, int top, int right, int bottom) {
		return x0 >= left && y0 >= top && x0 < right && y0 < bottom;
	}
}