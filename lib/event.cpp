#include "main_loop.h"

#include <iostream>

#ifdef __linux__
	#include <unistd.h>
#elif _WIN32
	#include <windows.h>
#endif

int befry::Event::game_fps = 5;
std::shared_ptr<befry::Scene> befry::Event::current_scene = nullptr;

std::future<int> befry::Event::input = async(std::launch::async, getchar);
int befry::Event::input_res = -1;

void befry::Event::update()
{
	#ifdef __linux__
		sleep(1.0 / game_fps);
	#elif _WIN32
		Sleep(1.0 / game_fps);
	#endif

	std::cout << "\033[0;0f";
	if (current_scene) current_scene->render();

	if (input.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
	{
		int res = input.get();
		if (res == 27)
			switch (getchar() + getchar())
			{
				case 156: input_res = KEY_UP; break;
				case 157: input_res = KEY_DOWN; break;
				case 158: input_res = KEY_LEFT; break;
				case 159: input_res = KEY_RIGHT; break;
			}
		exit(0);
	}
}

/* Setters */
void befry::Event::setFPS(const int& fps)
{
	game_fps = fps;
}
void befry::Event::setScene(std::shared_ptr<Scene> scn)
{
	current_scene = scn;
}

/* Getters */
int befry::Event::getInput()
{
	return input_res;
}


