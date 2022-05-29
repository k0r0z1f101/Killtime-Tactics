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

	    SetTargetFPS(60);
	}

	GameController::~GameController()
	{

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

		EndMode3D();
	}

	void GameController::Update()
	{
		if(IsKeyPressed(KEY_F3))
			_battle.NextInitiative();

		_songPlayer.updateStream();

		UpdateMainCamera();             // Update camera
	}
}
