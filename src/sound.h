#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <chrono>
#include <array>
#include <random>
#include <iomanip>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector;

#define MAX_SAMPLES               512
#define MAX_SAMPLES_PER_UPDATE   4096

namespace sound
{
	//Jukebox
	class SongPlayer
	{
#include <string>
		string songPlayPath; //path to the song being played
		vector<string> songPlayedOnce; //list of song already played since instanciation
		static const string spPATH; //path to the song folder
		Music songPlayed; //song being played; raylib CDT
		float songElapsedTime; //time passed in song since start of song in seconds
		float musicVolume; //volume of the music streams


	public:
		SongPlayer();
		void randomSongPath(); //return a random song path that hasn't played yet from the song folder
		void playSong(); //play the song in songPlayPath
		void playSongPath(string path); //play the song from path
		void updateStream(); //update the audio stream
		bool isSongPlaying(); //return true if the song is currently playing
		string getSongPlaying(); //return the path to the song playing
		void changeVolume(); //change volume of music
		void stopPlaying();
		~SongPlayer();
	};

	//sample players (short length sounds)
	class SamplePlayer
	{
		string samplePlayPath; //path to the sound being played
		static const string sapPATH; //path to the sound folder
		Sound samplePlayed; //sample being played
		float soundVolume; //volume of the sounds multichannel

	public:
		SamplePlayer();
		void playSample(string path);
		void changeVolume();
		~SamplePlayer();
	};
}
