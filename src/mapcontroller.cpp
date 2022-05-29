#include "mapcontroller.h"

namespace controller
{
	MapController::MapController()
	{
		_mapImage = LoadImage("resources/maps/maptest.png");	// Load cubicmap image (RAM)
		_cubicmap = LoadTextureFromImage(_mapImage);       		// Convert image to texture to display (VRAM)

		_mapMesh = GenMeshCubicmap(_mapImage, Vector3{ 1.0f, 1.0f, 1.0f });
		_mapModel = LoadModelFromMesh(_mapMesh);

		// NOTE: By default each cube is mapped to one part of texture atlas
		_mapTexture = LoadTexture("resources/maps/cubicmap_atlas.png");    			// Load map texture
		_mapModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _mapTexture;	// Set map diffuse texture

		_mapPosition = { -32.0f, 0.0f, -32.0f };          // Set model position

		UnloadImage(_mapImage);     	// Unload cubesmap image from RAM, already uploaded to VRAM
	}

	MapController::~MapController()
	{
		UnloadTexture(_cubicmap);    	// Unload cubicmap texture
		UnloadTexture(_mapTexture);     // Unload map texture
		UnloadModel(_mapModel);         // Unload map model
	}

	void MapController::RenderMap()
	{
		DrawModel(_mapModel, _mapPosition, 1.0f, WHITE);
	}
}
