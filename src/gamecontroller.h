#pragma once
#include "raylib.h"
#include "raymath.h"
#include "sound.h"
#include "actor.h"
#include "battle.h"
#include "mapcontroller.h"
#include "contextmenu.h"

#include <vector>

#define SCREEN_WIDTH 	1600
#define SCREEN_HEIGHT	900
#define CURSOR_SIZE 	{0.0f, 0.0f, 48.0f, 48.0f}

using namespace sound;

namespace controller
{
	class GameController
	{
		array<Texture2D,4> ACTION_CURSORS = { LoadTexture("resources/pointer/move48.png"), LoadTexture("resources/pointer/unarmed48.png"), LoadTexture("resources/pointer/sword48.png"), LoadTexture("resources/pointer/bow48.png") };

		//test for custom mouse cursor
		typedef struct Sprite {
			Texture2D texture;
			Rectangle rect;
			Vector2 position;
		} Sprite;

	private:
		vector<Actor> _actors;		//PCs and NPCs, monsters, traps, needed in the scene
		SongPlayer _songPlayer;		//random song player
		SamplePlayer _soundFX;		//sound player for Multi channel Sound
		BattleController _battle;	//battle controller
		MapController _map;			//map in play
		Camera _camera;				//camera
		vector<Model> _models;		//models loaded
		vector<Vector3> _positions; //position of models
		vector<ContextMenu> _menus;	//contextual menus
		Sprite _cursor;				//mouse cursor
		int _hotkey;				//current hotkey selected

	public:
		GameController();
		~GameController();

		void TestBattle();

		void UpdateMainCamera();
		void Draw();
		void DrawModels();
		void DrawMode3D();
		void UpdateUI();
		Actor& UpdateContextMenu();
		void Update();
	};
}
