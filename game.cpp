#include "game.h"
#include "surface.h"
#include <cstdio> //printf
#include <random>
#include <sstream>
#include <string.h>
using namespace std;

namespace Tmpl8
{
	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()
	{

	}

	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{
	}

	static Sprite Ant(new Surface("assets/AntR.png"), 1);
	static Sprite Page(new Surface("assets/Ball.png"), 1);

	static int frame = 0;
	static int StartF = 0;
	static int Score = 0;
	
	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{
		if (StartF == 0)
		{
			Ant.SetSpd(1);
			Ant.SetPos(rand() % 750 + 50, rand() % 450 + 50 );
			Page.SetPos(rand() % 750 + 50, rand() % 450 + 50);
			//Spawn paper
		}
		StartF++;
		Ant.SetPos(Ant.GetPos('X'), Ant.GetPos('Y'));
		//<Basic input and movement :)>
		if (KeyDown('a'))
		{
			Ant.SetT(new Surface("assets/AntL.png"),1);
			Ant.SetDir('a');
		}
		else if (KeyDown('d'))
		{
			Ant.SetT(new Surface("assets/AntR.png"),1);
			Ant.SetDir('d');
		}
		else if (KeyDown('w'))
		{
			Ant.SetT(new Surface("assets/AntU.png"),1);
			Ant.SetDir('w');
		}
		else if (KeyDown('s'))
		{
			Ant.SetT(new Surface("assets/AntD.png"),1);
			Ant.SetDir('s');
		}
		Ant.Move();
		//</ Basic input and movement :) >

		// clear the graphics window
		screen->Clear(0);

		// draw a sprite		
		//This is for animation: Ant.SetFrame(frame);		
		Ant.Draw(screen, Ant.GetPos('X'), Ant.GetPos('Y'));
		Page.Draw(screen, Page.GetPos('X'), Page.GetPos('Y'));						
		screen->Print((char*)to_string(Score).c_str(), 30, 30, 0xffffff); // <--- Use as UI, showing player score and all that.
		if (Ant.OnTriggerEnter(Page.GetPos('X'), Page.GetPos('Y'), Page.GetWidth(), Page.GetHeight(),Score))
		{
			Ant.SetSpd(Ant.Spd() + .15f);
			Score++;
			Page.Collected(rand() % 750 + 50, rand() % 450 + 50);//printf("ga\n"); //TODO: Implement Collector system!	
		}
		if (++frame == 36) frame = 0;
	}
};
/*
* Todo:
* Make font bigger :)
* 
Changelog:
Added functionality to the MouseDown func.
Added voids GetPos/SetPos to sprites.
Added base movement.
Free ant sprite taken from - https://www.seekpng.com/ipng/u2q8o0w7o0w7q8y3_ant-pixel-art/;
Added Collision system, a collectable page that spawns and respawns at different positions, and a score counter.
*/
