#include "gamecontroller.h"

namespace controller
{
	GameController::GameController()
	{
	    InitAudioDevice();              // Initialize audio device
	    SetAudioStreamBufferSizeDefault(MAX_SAMPLES_PER_UPDATE);

		_songPlayer.randomSongPath();
		_songPlayer.playSong();

		_camera = { { 16.0f, 14.0f, 16.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };
		SetCameraMode(_camera, CAMERA_ORBITAL);  // Set an orbital camera mode


	    _models.push_back(LoadModel("resources/model/mirio2.obj"));                    // Load the animated model mesh and basic data
//		Texture2D texture = LoadTexture("resources/model/texture/body.obj");         // Load model texture and set material
//		SetMaterialTexture(&model.materials[0], MATERIAL_MAP_DIFFUSE, texture);     // Set model material map texture

		position = { 0.0f, 0.0f, 0.0f };            // Set model position


	    SetTargetFPS(60);
	}

	GameController::~GameController()
	{
		for(auto& m : _models)
			UnloadModel(m);         // Unload models
	}

	void GameController::UpdateMainCamera()
	{
    	UpdateCamera(&_camera);              // Update camera
	}

	void GameController::Draw()
	{
        BeginDrawing();

        	ClearBackground(BLACK);

        	DrawMode3D();

        EndDrawing();
	}

	void GameController::DrawMode3D()
	{
		BeginMode3D(_camera);

    		_map.RenderMap();

        	for(auto& m : _models)
        	{
        		DrawModelEx(m, position, (Vector3){ 1.0f, 0.0f, 0.0f }, 0.0f, (Vector3){ 1.0f, 1.0f, 1.0f }, WHITE);
        	}

		EndMode3D();
	}

	void GameController::Update()
	{
		if(IsKeyPressed(KEY_F3))
			_battle.NextInitiative();

		_songPlayer.updateStream();

		UpdateMainCamera();             // Update camera

		// Select model on mouse click, open context menu
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
        	for(auto& m : _models)
        	{
				// Check collision between ray and box
				BoundingBox newBounds = GetMeshBoundingBox(m.meshes[0]);
				RayCollision newRay = GetRayCollisionBox(GetMouseRay(GetMousePosition(), _camera), newBounds);
        	}
        }
	}

	void GameController::TestBattle()
	{
		_battle.UnitTest();
	}
}
