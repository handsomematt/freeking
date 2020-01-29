#pragma once

#include "AssetLibrary.h"
#include <glad/glad.h>

namespace Freeking
{
	class Texture2D;

	class TextureLibrary : public AssetLibrary<Texture2D>
	{
	protected:

		virtual void UpdateLoaders() override;
	};

	class Texture
	{
	public:

		virtual const GLuint GetHandle() const = 0;
	};

	class Texture2D : public Texture
	{
	public:

		static TextureLibrary Library;

		Texture2D() = delete;
		Texture2D(GLsizei width, GLsizei height, GLenum internalFormat, GLenum format, GLenum type, const void* data);
		~Texture2D();

		void Bind() const;
		void Bind(unsigned char slot) const;

		virtual const GLuint GetHandle() const override { return _handle; }
		const GLsizei GetWidth() const { return _width; }
		const GLsizei GetHeight() const { return _height; }

	private:

		GLuint _handle;
		GLsizei _width;
		GLsizei _height;
		GLenum _internalFormat;
		GLenum _format;
		GLenum _type;
	};
}
