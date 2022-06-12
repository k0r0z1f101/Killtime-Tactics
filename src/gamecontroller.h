#pragma once
#include "raylib.h"
#include "raymath.h"
#include "sound.h"
#include "actor.h"
#include "battle.h"
#include "mapcontroller.h"
#include "contextmenu.h"

#define SCREEN_WIDTH 	1600
#define SCREEN_HEIGHT	900

using namespace sound;

namespace controller
{
	class GameController
	{
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

	public:
		GameController();
		~GameController();

		void TestBattle();

		void UpdateMainCamera();
		void Draw();
		void DrawModels();
		void DrawMode3D();
		void UpdateContextMenu();
		void Update();
	};
}
