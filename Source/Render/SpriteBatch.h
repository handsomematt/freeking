#pragma once

#include "Vector.h"
#include "Color.h"
#include "Matrix4x4.h"
#include <map>
#include <memory>
#include <stack>
#include <string>
#include <vector>

namespace Freeking
{
	class Texture2D;
	class VertexBinding;
	class VertexBuffer;
	class Shader;
	class Font;
	class TextureSampler;

	class SpriteBatch
	{
	public:

		static std::shared_ptr<SpriteBatch> Debug;

		SpriteBatch(size_t = 1000);

		void Flush(const Matrix4x4&, float = 1.0f);
		void Clear();
		void DrawText(const Font*, const std::string&, const Vector2f&, const LinearColor&, float);
		void Draw(Texture2D*, const Vector2f&, float, const LinearColor&);
		void Draw(Texture2D*, const Vector2f&, const Vector2f&, const LinearColor&);
		void Draw(Texture2D*, const Vector2f&, const Vector2f&, float, const LinearColor&);
		void Draw(Texture2D*, const Vector2f&, const Vector2f&, const Vector2f&, const Vector2f&, const LinearColor&, bool = false);
		void Draw9Slice(Texture2D*, const Vector2f&, const Vector2f&, const Vector4f&, const LinearColor&, bool = true);
		void Draw9Slice(Texture2D*, const Vector2f&, const Vector2f&, const Vector2f&, const Vector2f&, const Vector4f&, const LinearColor&, bool = true);

		void EnableClipping(bool clipping) { _clipping = clipping; }
		void SetClippingRect(const Vector4f& clippingRect) { _clippingRect = clippingRect; }

		size_t GetDrawCallCount() const { return _drawCallCount; }

	private:

		static std::shared_ptr<Shader> GetSpriteShader();
		static std::shared_ptr<Shader> GetTextShader();

		struct Sprite
		{
			Sprite(Texture2D*, const Vector2f&, const Vector2f&, float, const LinearColor&);
			Sprite(Texture2D*, const Vector2f&, const Vector2f&, const Vector2f&, const Vector2f&, const LinearColor&);

			Texture2D* _texture;
			Vector2f _position;
			Vector2f _size;
			Vector2f _uv1;
			Vector2f _uv2;
			LinearColor _colour;
			float _angle;
		};

		struct Slice
		{
			Vector2f _uv1;
			Vector2f _uv2;
			Vector2f _drawPosition;
			Vector2f _drawSize;
		};

		struct NineSliceProperties
		{
			NineSliceProperties(
				const Vector2f&,
				const Vector2f&,
				const Vector2f&,
				const Vector2f&,
				const Vector2f&);

			void GetTopLeftSlice(Slice&) const;
			void GetTopRightSlice(Slice&) const;
			void GetBottomLeftSlice(Slice&) const;
			void GetBottomRightSlice(Slice&) const;
			void GetTopMidSlice(Slice&) const;
			void GetBottomMidSlice(Slice&) const;
			void GetLeftMidSlice(Slice&) const;
			void GetRightMidSlice(Slice&) const;
			void GetMidSlice(Slice&) const;

			const Vector2f _glyphSize;
			const Vector2f _topLeftSlicePx;
			const Vector2f _bottomRightSlicePx;
			const Vector2f _topLeftSlice;
			const Vector2f _bottomRightSlice;
			const Vector2f _drawPosition;
			const Vector2f _drawSize;
		};

		void DrawSprites(const Matrix4x4&, float, const std::shared_ptr<Shader>&, std::vector<SpriteBatch::Sprite>&);
		void DrawSlice(Texture2D*, const Slice&, const LinearColor&);
		static void TransformUV(Vector2f&, const Vector2f&, const Vector2f&, const Vector2f&);
		static void TransformUVs(Slice&, const Vector2f&, const Vector2f&, const Vector2f&);
		bool IsSpriteInsideClippingRect(const Vector2f&, const Vector2f&);

		std::vector<Sprite> _spritesToDraw;
		std::vector<Sprite> _textToDraw;
		bool _clipping;
		Vector4f _clippingRect;
		size_t _drawCallCount;
		size_t _maxSpriteCount;
		std::vector<float> _vertexData;
		std::unique_ptr<VertexBuffer> _vertexBuffer;
		std::unique_ptr<VertexBinding> _vertexBinding;
	};
}
