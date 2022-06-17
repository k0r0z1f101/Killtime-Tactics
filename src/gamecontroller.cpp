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
	    _models.push_back(LoadModel("resources/model/mirio2.obj"));                    // Load the animated model mesh and basic data
//		Texture2D texture = LoadTexture("resources/model/texture/body.obj");         // Load model texture and set material
//		SetMaterialTexture(&model.materials[0], MATERIAL_MAP_DIFFUSE, texture);     // Set model material map texture

		_positions.push_back({ 0.0f, 0.0f, 0.0f });           // Set test model position
		_positions.push_back({ 3.0f, 0.0f, 0.0f });            // Set test model position

		_actors.push_back(Actor("Jean"));
		_actors.push_back(Actor("Roger"));

		_battle = BattleController(_actors);
	    SetTargetFPS(60);

	    _hotkey = -1;


	    //test for custom mouse cursor
	    _cursor = (Sprite) {
	    	.texture = LoadTexture("resources/pointer/unarmed48.png"),
			.rect = {0.0f, 0.0f, 48.0f, 48.0f},
	    	.position = {0.0f, 0.0f},
	    };

	    HideCursor();
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

        	DrawTextureRec(_cursor.texture, _cursor.rect, _cursor.position, WHITE);

        EndDrawing();
	}

	void GameController::DrawModels()
	{
		int i = {};
    	for(auto& m : _models)
    	{
    		m.transform = MatrixTranslate(_positions[i].x, _positions[i].y, _positions[i].z);
    		DrawModelEx(m, (Vector3){0} , (Vector3){ 1.0f, 0.0f, 0.0f }, 0.0f, (Vector3){ 1.0f, 1.0f, 1.0f }, WHITE);
    		UpdateMeshBuffer(m.meshes[0], 0, m.meshes[0].vertices, sizeof(float) * m.meshes[0].vertexCount * 3, 0);
    		DrawMesh(m.meshes[0], m.materials[0], m.transform);
    		++i;
    	}
	}

	void GameController::DrawMode3D()
	{
		BeginMode3D(_camera);

    		_map.RenderMap();

    		DrawModels();

    		DrawPlane(_moveTilePos, { 1.0f, 1.0f }, RED);

		EndMode3D();
	}

	Actor& GameController::UpdateContextMenu()
	{
		//3d position of mouse cursor
		Ray mouseRay = GetMouseRay(GetMousePosition(), _camera);
		RayCollision mouseCollision = GetRayCollisionMesh(mouseRay, _map.GetModel().meshes[0], _map.GetModel().transform);

		cout << "Mouse Ray: " << mouseCollision.point.x << ", " << mouseCollision.point.y << ", " << mouseCollision.point.z << endl;
		cout << "Mouse Ray: " << mouseCollision.distance << endl;
		cout << "Mouse Ray: " << mouseCollision.hit << endl;
		cout << "Mouse Ray: " << mouseCollision.normal.x << ", " << mouseCollision.normal.y << ", " << mouseCollision.normal.z << endl;
		_moveTilePos = mouseCollision.point;


		size_t i = {};
		for(auto& m : _models)
		{
			cout << "model ------------" << endl;
			// Check collision between ray and mesh
			RayCollision newRay = GetRayCollisionMesh(GetMouseRay(GetMousePosition(), _camera), m.meshes[0], m.transform);
			if(newRay.hit)
			{
				cout << "hit! #" << i << endl;
				break;
			}
			++i;
		}
		//find actions possible by actor on target, build and display context menu
		cout << _actors.size() << endl;
		if(i < _actors.size())
		{
			string name = _actors[i].GetName();
			cout << "target: " << name << endl;
			vector<OffensiveActions> offActions = _battle.GetCurrentInitiative().GetContextActions();
			cout << "attacker: " << _battle.GetCurrentInitiative().GetName() << endl;
			for(auto& oa : offActions)
			{
				cout << "action: " << offensiveActionsName[oa] << endl;
			}
			_menus.push_back(ContextMenu(_actors[i].GetPosition(), offActions));
			return _actors[i];
		}
	}

	void GameController::UpdateUI()
	{
		_cursor.position = (Vector2){ .x = GetMousePosition().x, .y = GetMousePosition().y };

        if(IsKeyPressed(KEY_ZERO)) _hotkey = 0;
        if(IsKeyPressed(KEY_ONE)) _hotkey = 1;
        if(IsKeyPressed(KEY_TWO)) _hotkey = 2;
        if(IsKeyPressed(KEY_THREE)) _hotkey = 3;

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))	// Select model on mouse click, open context menu
        {
			Actor& target = UpdateContextMenu();
        	if(_hotkey == 1 || _hotkey == 2 || _hotkey == 3)
        		_battle.GetCurrentInitiative().UseAttackAction(OffensiveActions(_hotkey), target);
		}

        if(_hotkey != -1)
    	    _cursor = (Sprite) {
    	    	.texture = ACTION_CURSORS[_hotkey],
    			.rect = CURSOR_SIZE,
    	    	.position = GetMousePosition(),
    	    };

        unsigned int i = {};
        vector<unsigned int> indexToRemove = {};
        for(auto& m : _menus)
        {
        	if(m.UpdateMenu() > LIFESPAN)
        	{
        		indexToRemove.push_back(i);
//        		m.~ContextMenu();
        	}
        	++i;
        }
        for(auto& i : indexToRemove)
        	_menus.erase(_menus.begin() + i);
	}

	void GameController::Update()
	{
		if(IsKeyPressed(KEY_F3))
			_battle.NextInitiative();

		_songPlayer.updateStream();

		UpdateMainCamera();	// Update camera

		UpdateUI();			//Update mouse and menus
	}

	void GameController::TestBattle()
	{
		_battle.UnitTest();
	}
}
