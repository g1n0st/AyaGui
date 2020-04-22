#ifndef AYA_GUI_H
#define AYA_GUI_H

#include <math.h>
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

	class GUIRenderer {
	private:
		static GUIRenderer *mp_instance;

		GLint m_tex_list_base;
		GLint m_width, m_height;

		// Font style render related
		HFONT m_font;
		HDC m_HDC;

		GLuint m_handle_program;
		GLuint m_handle_bg_tex;
		GLuint m_handle_FBO;
		GLuint m_handle_color_RBO;

		// Gaussian blur weights and offsets
		static const int BLUR_SAMPLE = 13;
		GLfloat m_gaussian_weights[BLUR_SAMPLE];
		GLfloat m_gaussian_offsets[BLUR_SAMPLE * 2];

		// Precomputed coordinates for circle
		static const int CIRCLE_VERTEX_COUNT = 12;
		GLfloat m_circle_coords[CIRCLE_VERTEX_COUNT];
		
		static const GLchar *vert_shader_source;
		static const GLchar *blur_frag_shader_source;

	public:
		static const GLfloat DEPTH_FAR;
		static const GLfloat DEPTH_MID;
		static const GLfloat DEPTH_NEAR;

	private:
		GUIRenderer();
		~GUIRenderer();

	public:
		static __forceinline GUIRenderer* instace() {
			if (!mp_instance)
				mp_instance = new GUIRenderer;
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

	};
}

#endif