#include <Gui/AyaGui.h>

#include <exception>
#include <functional>
#include <iostream>

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

	const GLchar* GuiRenderer::vert_shader_source = R"(
		    varying vec2 texCoord;
			void main() {
				gl_Position = gl_Vertex;
				texCoord = gl_MultiTexCoord0.xy;
			})";
	const GLchar* GuiRenderer::blur_frag_shader_source = R"(
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
		m_handle_program = glCreateProgram();

		// Background Tex
		glGenTextures(1, &m_handle_bg_tex);
		glBindTexture(GL_TEXTURE_2D, m_handle_bg_tex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 16);

		glGenFramebuffers(1, &m_handle_FBO);
		glGenRenderbuffers(1, &m_handle_color_RBO);

		m_text_list_base = glGenLists(128);
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
		wglUseFontBitmaps(m_HDC, 0, 128, m_text_list_base);
		SelectObject(m_HDC, old_font);
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

		GLint handle_vertex_shader = LoadShader(GL_VERTEX_SHADER, vert_shader_source);
		GLint handle_blur_frag_shader = LoadShader(GL_FRAGMENT_SHADER, blur_frag_shader_source);
		glAttachShader(m_handle_program, handle_vertex_shader);
		glAttachShader(m_handle_program, handle_blur_frag_shader);

		
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
				throw std::exception(status_buffer);

			delete[] status_buffer;
		};
		
		ExcuteAndCheck(glLinkProgram, m_handle_program);
		ExcuteAndCheck(glValidateProgram, m_handle_program);

		// Calculate circle coordinates
		const GLfloat phi_itvl = 0.57119866428905331608411697877809f;
		GLfloat phi = 0.0f;
		for (size_t i = 0; i < CIRCLE_VERTEX_COUNT - 1; ++i) {
			m_circle_coords[i * 2 + 0] = std::sinf(phi);
			m_circle_coords[i * 2 + 1] = -std::cosf(phi);
			phi += phi_itvl;
		}
		m_circle_coords[2 * CIRCLE_VERTEX_COUNT - 2] = m_circle_coords[0];
		m_circle_coords[2 * CIRCLE_VERTEX_COUNT - 1] = m_circle_coords[1];
	}

	GuiRenderer::~GuiRenderer() {
		glDeleteProgram(m_handle_program);
		glDeleteTextures(1, &m_handle_bg_tex);
		glDeleteFramebuffers(1, &m_handle_FBO);
		glDeleteRenderbuffers(1, &m_handle_color_RBO);
	}

	void GuiRenderer::resize(int width, int height) {
		m_width = width;
		m_height = height;

		// Init background texture
		glBindRenderbuffer(GL_RENDERBUFFER, m_handle_color_RBO);
		glRenderbufferStorageMultisample(GL_RENDERBUFFER, 0, GL_RGBA, (width + 0x7) >> 2, (height + 0x7) >> 2);
		glBindRenderbuffer(GL_RENDERBUFFER, 0);

		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, m_handle_FBO);
		glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, m_handle_color_RBO);
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);

		CalcGaussianBlurWeightsAndOffsets();
	}

	void GuiRenderer::blurBackgroundTexture(int x0, int y0, int x1, int y1) {
		glBindTexture(GL_TEXTURE_2D, m_handle_bg_tex);
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

		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, m_handle_FBO);

		glViewport(0, 0, (m_width + 0x7) >> 2, (m_height + 0x7) >> 2);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(m_handle_program);
		glUniform1i(glGetUniformLocation(m_handle_program, "texSampler"), 0);
		glUniform1fv(glGetUniformLocation(m_handle_program, "weights"), 13, m_gaussian_weights);
		glUniform2fv(glGetUniformLocation(m_handle_program, "offsets"), 13, m_gaussian_offsets);

		glBindTexture(GL_TEXTURE_2D, m_handle_bg_tex);
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
		glBindFramebuffer(GL_READ_FRAMEBUFFER, m_handle_FBO);
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
			GLfloat x = x1 - radius + m_circle_coords[i * 2 + 0] * radius;
			GLfloat y = y0 + radius + m_circle_coords[i * 2 + 1] * radius;
			glVertex3f(x, y, depth);
		}
		glVertex3f((GLfloat)x1, (GLfloat)y0 + radius, depth);
		glVertex3f((GLfloat)x1, (GLfloat)y1 - radius, depth);
		for (size_t i = quater_vertex_count; i < 2 * quater_vertex_count; i++) {
			GLfloat x = x1 - radius + m_circle_coords[i * 2 + 0] * radius;
			GLfloat y = y1 - radius + m_circle_coords[i * 2 + 1] * radius;
			glVertex3f(x, y, depth);
		}
		glVertex3f((GLfloat)x1 - radius, (GLfloat)y1, depth);
		glVertex3f((GLfloat)x0 + radius, (GLfloat)y1, depth);
		for (size_t i = 2 * quater_vertex_count; i < 3 * quater_vertex_count; i++) {
			GLfloat x = x0 + radius + m_circle_coords[i * 2 + 0] * radius;
			GLfloat y = y1 - radius + m_circle_coords[i * 2 + 1] * radius;
			glVertex3f(x, y, depth);
		}
		glVertex3f((GLfloat)x0, (GLfloat)y1 - radius, depth);
		glVertex3f((GLfloat)x0, (GLfloat)y0 + radius, depth);
		for (size_t i = 3 * quater_vertex_count; i < 4 * quater_vertex_count; i++) {
			GLfloat x = x0 + radius + m_circle_coords[i * 2 + 0] * radius;
			GLfloat y = y0 + radius + m_circle_coords[i * 2 + 1] * radius;
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
			GLfloat x = x1 - radius + m_circle_coords[i * 2 + 0] * radius;
			GLfloat y = y0 + radius + m_circle_coords[i * 2 + 1] * radius;
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
			GLfloat x = x0 + radius + m_circle_coords[i * 2 + 0] * radius;
			GLfloat y = y0 + radius + m_circle_coords[i * 2 + 1] * radius;
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
			GLfloat x = x0 + m_circle_coords[i * 2 + 0] * radius;
			GLfloat y = y0 + m_circle_coords[i * 2 + 1] * radius;
			glVertex3f(x, y, depth);
		}

		glEnd();
	}


	void GuiRenderer::drawString(int x0, int y0, float depth, const char *text, int length) const {
		glListBase(m_text_list_base);

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
				m_gaussian_offsets[index * 2 + 0] = x * tu;
				m_gaussian_offsets[index * 2 + 1] = y * tv;
				m_gaussian_weights[index] = GaussianDistribution(GLfloat(x), GLfloat(y), 1.f);
				total_weight += m_gaussian_weights[index];

				++index;
			}
		}

		for (size_t i = 0; i < index; i++)
			m_gaussian_weights[i] /= total_weight;
	}

	// Immediate Mode GUI Implementation
	GuiStates *AyaGui::states;

	void AyaGui::Init() {
		states = new GuiStates;
		
		states->active_id = -1;
		states->moving_id = -1;
		states->active_dialog_id = -1;
		
		states->key_state.key = 0;
		states->key_state.funckey = FunctionKey::None;
		states->key_state.keymode = KeyMode::None;

		states->editing_id = -1;
		states->scroller_init_y = 0;
		states->console_scroller = 1.0f;
	}

	void AyaGui::Release() {
		delete states;
		states = nullptr;

		GuiRenderer::deleteInstance();
	}

	void AyaGui::Resize(int width, int height) {
		states->screen_width = width;
		states->screen_height = height;

		GuiRenderer::instance()->resize(width, height);
	}

	void AyaGui::BeginFrame() {
		states->current_id = 0;
		states->current_dialog_id = 0;
		states->hovered_id = 0;
	}

	void AyaGui::EndFrame() {
		states->global_mouse_state.action = MouseAction::None;
		
		states->key_state.key = 0;
		states->key_state.funckey = FunctionKey::None;
		states->key_state.keymode = KeyMode::None;
	}

	void AyaGui::BeginDialog(LayoutStrategy layout, int &x, int &y, const char *title, const int width, const int height) {
		auto dialog_id(states->current_dialog_id++);

		assert(layout == LayoutStrategy::Fixed || layout == LayoutStrategy::Floating);
		states->current_layout_strategy = layout;
		states->current_growth_strategy = GrowthStrategy::Vertical;

		states->dialog_width = width;
		states->dialog_height = height;
		states->dialog_pos_x = x;
		states->dialog_pos_y = y;
		states->current_pos_x = sidebar_padding_left;
		if (layout == LayoutStrategy::Floating || title)
			states->current_pos_y = titled_dialog_padding_top;
		else
			states->current_pos_y = untitled_dialog_padding_top;
		states->widget_end_x = states->dialog_width - sidebar_padding_top;

		states->mouse_state = states->global_mouse_state;
		states->mouse_state.x = states->global_mouse_state.x - states->dialog_pos_x;
		states->mouse_state.y = states->global_mouse_state.y - states->dialog_pos_y;

		auto PtInRect = [](int ptx, int pty, int x0, int y0, int x1, int y1) {
			return (ptx >= x0 && ptx < x1 && pty >= y0 && pty < y1);
		};

		int mouse_x = states->mouse_state.x;
		int mouse_y = states->mouse_state.y;
		// When dialog is moving, logical frame is prev frame
		if (states->moving_id == dialog_id && layout == LayoutStrategy::Floating) {
			mouse_x -= states->global_mouse_state.x - states->prev_global_mouse_state.x;
			mouse_y -= states->global_mouse_state.y - states->prev_global_mouse_state.y;
		}

		if (PtInRect(mouse_x, mouse_y, 0, 0, states->dialog_width, states->dialog_height)) {
			if (states->mouse_state.action == MouseAction::LButtonDown) {
				states->active_dialog_id = dialog_id;
				if (layout == LayoutStrategy::Floating && 
					PtInRect(mouse_x, mouse_y, 0, 0, states->dialog_width, dialog_title_height)) {
					states->moving_id = dialog_id;
				}
			}
		}
		if (states->mouse_state.action == MouseAction::LButtonUp) {
			if (states->active_dialog_id == dialog_id)
				states->active_dialog_id = -1;
			if (layout == LayoutStrategy::Floating &&
				states->moving_id == dialog_id)
				states->moving_id = -1;
		}

		if (layout == LayoutStrategy::Floating &&
			states->moving_id == dialog_id) {
			if (states->active_dialog_id == dialog_id && 
				PtInRect(mouse_x, mouse_y, 0, 0, states->dialog_width, dialog_title_height)) {
				x += states->global_mouse_state.x - states->prev_global_mouse_state.x;
				y += states->global_mouse_state.y - states->prev_global_mouse_state.y;
				states->dialog_pos_x = x;
				states->dialog_pos_y = y;
				states->mouse_state.x = states->global_mouse_state.x - states->dialog_pos_x;
				states->mouse_state.y = states->global_mouse_state.y - states->dialog_pos_y;
				
				states->prev_global_mouse_state = states->global_mouse_state;
			}
			else
				states->moving_id = -1;
		}
		if (layout == LayoutStrategy::Fixed &&
			states->moving_id == dialog_id) {
			states->moving_id = -1;
		}

		glClear(GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		glOrtho(0, states->screen_width, 0, states->screen_height, 1, -1);

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		// Render the blurred background texture
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glEnable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
		glDisable(GL_DEPTH_TEST);
		GuiRenderer::instance()->blurBackgroundTexture(states->dialog_pos_x, states->screen_height - states->dialog_pos_y,
			states->dialog_pos_x + states->dialog_width, states->screen_height - (states->dialog_pos_y + states->dialog_height));
		GuiRenderer::instance()->drawBackgroundTexture(states->dialog_pos_x, states->screen_height - states->dialog_pos_y,
			states->dialog_pos_x + states->dialog_width, states->screen_height - (states->dialog_pos_y + states->dialog_height));
		GuiRenderer::instance()->blurBackgroundTexture(states->dialog_pos_x, states->screen_height - states->dialog_pos_y,
			states->dialog_pos_x + states->dialog_width, states->screen_height - (states->dialog_pos_y + states->dialog_height));
		GuiRenderer::instance()->drawBackgroundTexture(states->dialog_pos_x, states->screen_height - states->dialog_pos_y,
			states->dialog_pos_x + states->dialog_width, states->screen_height - (states->dialog_pos_y + states->dialog_height));
		GuiRenderer::instance()->blurBackgroundTexture(states->dialog_pos_x, states->screen_height - states->dialog_pos_y,
			states->dialog_pos_x + states->dialog_width, states->screen_height - (states->dialog_pos_y + states->dialog_height));
		GuiRenderer::instance()->drawBackgroundTexture(states->dialog_pos_x, states->screen_height - states->dialog_pos_y,
			states->dialog_pos_x + states->dialog_width, states->screen_height - (states->dialog_pos_y + states->dialog_height));

		glTranslatef((GLfloat)states->dialog_pos_x, (GLfloat)states->screen_height - states->dialog_pos_y, 0.0f);
		glScalef(1.0f, -1.0f, 1.0f);

		glLineWidth(1.0f);
		glDepthFunc(GL_LEQUAL);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_CONSTANT_ALPHA);
		glBlendEquation(GL_FUNC_ADD);

		GuiRenderer::instance()->drawRoundedRect(0,
			0,
			states->dialog_width,
			states->dialog_height,
			GuiRenderer::DEPTH_FAR,
			8.0f,
			true,
			Color4f(0.1f, 0.1f, 0.1f, 1.f),
			Color4f(0.0f, 0.0f, 0.0f, 0.2f));

		if (layout == LayoutStrategy::Floating) {
			GuiRenderer::instance()->drawHalfRoundedRect(0,
				0,
				states->dialog_width,
				dialog_title_height,
				GuiRenderer::DEPTH_FAR,
				8.0f,
				true,
				Color4f(0.1f, 0.1f, 0.1f, 1.0f),
				Color4f(0.0f, 0.0f, 0.0f, 0.03f));
		}

		if (title) {
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
			GuiRenderer::instance()->drawString(10, 6, GuiRenderer::DEPTH_FAR, title);
		}

		glEnable(GL_DEPTH_TEST);
	}

	void AyaGui::BeginSidebarDialog(LayoutStrategy layout, const int width, const int height) {
		auto dialog_id(states->current_dialog_id++);

		assert(layout == LayoutStrategy::DockLeft || layout == LayoutStrategy::DockRight);
		states->current_layout_strategy = layout;
		states->current_growth_strategy = GrowthStrategy::Vertical;

		switch (layout) {
		case LayoutStrategy::DockRight:
			states->dialog_width = sidebar_width;
			states->dialog_height = states->screen_height;
			states->dialog_pos_x = states->screen_width - states->dialog_width;
			states->dialog_pos_y = 0;
			states->current_pos_x = sidebar_padding_left;
			states->current_pos_y = sidebar_padding_top;
			states->widget_end_x = states->dialog_width - sidebar_padding_top;
			break;

		case LayoutStrategy::DockLeft:
			states->dialog_width = sidebar_width;
			states->dialog_height = states->screen_height;
			states->dialog_pos_x = 0;
			states->dialog_pos_y = 0;
			states->current_pos_x = sidebar_padding_left;
			states->current_pos_y = sidebar_padding_top;
			states->widget_end_x = states->dialog_width - sidebar_padding_top;
			break;
		}

		states->mouse_state = states->global_mouse_state;
		states->mouse_state.x = states->global_mouse_state.x - states->dialog_pos_x;
		states->mouse_state.y = states->global_mouse_state.y - states->dialog_pos_y;

		if (states->mouse_state.x >= 0 &&
			states->mouse_state.x < states->dialog_width &&
			states->mouse_state.y > 0 &&
			states->mouse_state.y <= states->dialog_height) {
			if (states->mouse_state.action == MouseAction::LButtonDown)
				states->active_dialog_id = dialog_id;
		}
		if (states->mouse_state.action == MouseAction::LButtonUp) {
			if (states->active_dialog_id == dialog_id)
				states->active_dialog_id = -1;
		}

		glClear(GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		glOrtho(0, states->screen_width, 0, states->screen_height, 1, -1);

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		// Render the blurred background texture
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glEnable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
		glDisable(GL_DEPTH_TEST);
		GuiRenderer::instance()->blurBackgroundTexture(states->dialog_pos_x, states->screen_height - states->dialog_pos_y,
			states->dialog_pos_x + states->dialog_width, states->screen_height - (states->dialog_pos_y + states->dialog_height));
		GuiRenderer::instance()->drawBackgroundTexture(states->dialog_pos_x, states->screen_height - states->dialog_pos_y,
			states->dialog_pos_x + states->dialog_width, states->screen_height - (states->dialog_pos_y + states->dialog_height));
		GuiRenderer::instance()->blurBackgroundTexture(states->dialog_pos_x, states->screen_height - states->dialog_pos_y,
			states->dialog_pos_x + states->dialog_width, states->screen_height - (states->dialog_pos_y + states->dialog_height));
		GuiRenderer::instance()->drawBackgroundTexture(states->dialog_pos_x, states->screen_height - states->dialog_pos_y,
			states->dialog_pos_x + states->dialog_width, states->screen_height - (states->dialog_pos_y + states->dialog_height));
		GuiRenderer::instance()->blurBackgroundTexture(states->dialog_pos_x, states->screen_height - states->dialog_pos_y,
			states->dialog_pos_x + states->dialog_width, states->screen_height - (states->dialog_pos_y + states->dialog_height));
		GuiRenderer::instance()->drawBackgroundTexture(states->dialog_pos_x, states->screen_height - states->dialog_pos_y,
			states->dialog_pos_x + states->dialog_width, states->screen_height - (states->dialog_pos_y + states->dialog_height));

		glTranslatef((GLfloat)states->dialog_pos_x, (GLfloat)states->screen_height - states->dialog_pos_y, 0.0f);
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
		glVertex3f((GLfloat)states->dialog_width, 0.0f, GuiRenderer::DEPTH_FAR);
		glVertex3f((GLfloat)states->dialog_width, (GLfloat)states->dialog_height, GuiRenderer::DEPTH_FAR);
		glVertex3f(0.0f, (GLfloat)states->dialog_height, GuiRenderer::DEPTH_FAR);

		glEnd();
		glEnable(GL_DEPTH_TEST);
	}

	void AyaGui::EndDialog() {
		glPopAttrib();
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
	}

	bool AyaGui::HandleMouseEvent(const MouseEvent& mouse) {
		if (states->moving_id == -1)
			states->prev_global_mouse_state = states->global_mouse_state;
		states->global_mouse_state = mouse;

		return states->active_dialog_id != -1;
	}

	bool AyaGui::HandleKeyboardEvent(const KeyboardEvent& key) {
		states->key_state = key;

		return states->active_dialog_id != -1;
	}

}