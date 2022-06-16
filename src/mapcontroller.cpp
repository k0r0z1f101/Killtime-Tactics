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

//		_mapPosition = { -32.0f, 0.0f, -32.0f };          // Set model position
		_mapPosition = { 0.0f, 0.0f, 0.0f };          // Set model position


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

//		m.transform = MatrixTranslate(_positions[i].x, _positions[i].y, _positions[i].z);
//		DrawModelEx(m, (Vector3){0} , (Vector3){ 1.0f, 0.0f, 0.0f }, 0.0f, (Vector3){ 1.0f, 1.0f, 1.0f }, WHITE);
//		UpdateMeshBuffer(m.meshes[0], 0, m.meshes[0].vertices, sizeof(float) * m.meshes[0].vertexCount * 3, 0);
//		DrawMesh(m.meshes[0], m.materials[0], m.transform);

//		_mapModel.transform = MatrixTranslate(_mapPosition.x, _mapPosition.y, _mapPosition.z);
		DrawModel(_mapModel, _mapPosition, 1.0f, WHITE);
		UpdateMeshBuffer(_mapModel.meshes[0], 0, _mapModel.meshes[0].vertices, sizeof(float) * _mapModel.meshes[0].vertexCount * 3, 0);
//		DrawMesh(_mapModel.meshes[0], _mapModel.materials[0], _mapModel.transform);
	}

	Mesh& MapController::GetMesh()
	{
		return _mapModel.meshes[0];
	}

	Model& MapController::GetModel()
	{
		return _mapModel;
	}
}
