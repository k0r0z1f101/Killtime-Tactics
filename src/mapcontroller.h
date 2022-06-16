#pragma once
#include "raylib.h"
#include "raymath.h"

namespace controller
{
	class MapController
	{
	private:
		Image _mapImage;
		Texture2D _cubicmap;
		Mesh _mapMesh;
		Model _mapModel;
		Texture2D _mapTexture;
		Vector3 _mapPosition;
	public:
		MapController();
		~MapController();

		void RenderMap();
		Mesh& GetMesh();
		Model& GetModel();
	};
}
