#pragma once
#include "raylib.h"
#include "sound.h"
#include "actor.h"
#include "battle.h"
#include "mapcontroller.h"

#define SCREEN_WIDTH 	1000
#define SCREEN_HEIGHT	800

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

		//test
		Model model;
		Vector3 position;

	public:
		GameController();
		~GameController();

		void TestBattle();

		void UpdateMainCamera();
		void Draw();
		void DrawMode3D();
		void Update();
	};
}
