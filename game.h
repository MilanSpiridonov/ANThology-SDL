#pragma once
#include <SDL.h>

namespace Tmpl8 {

	class Surface;
	class Game
	{
	public:
		void SetTarget(Surface* surface) { screen = surface; }
		void Init();
		void Shutdown();
		void Tick(float deltaTime);
		void MouseUp(int button) { /* implement if you want to detect mouse button presses */ }
		bool MouseDown(int x) {
			SDL_PumpEvents();
			switch (x) {
			case 0:
				if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
					return true;
					break;
				}
				else return false;
			case 1:
				if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT)) {
					return true;
					break;
				}
				else return false;
			}

			/* implement if you want to detect mouse button presses */
		}
		void MouseMove(int x, int y) { /* implement if you want to detect mouse movement */ }
		void KeyUp(int key) { /* implement if you want to handle keys */ }
		bool KeyDown(char Key) {
			const Uint8* state = SDL_GetKeyboardState(NULL);
			switch (Key) {
			case 'a':
				if (state[SDL_SCANCODE_A])
					return true;
				else return false;
				break;
			case 'd':
				if (state[SDL_SCANCODE_D])
					return true;
				else return false;
				break;
			case 's':
				if (state[SDL_SCANCODE_S])
					return true;
				else return false;
				break;
			case 'w':
				if (state[SDL_SCANCODE_W])
					return true;
				else return false;
				break;
			}
			/* implement if you want to handle keys */
		}
	private:
		Surface* screen;
	};

}; // namespace Tmpl8
