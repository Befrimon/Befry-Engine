#include "event.h"

#include <iostream>

#ifdef __linux__
	#include <unistd.h>
#elif _WIN32
	#include <windows.h>
#endif

int bgf::Event::game_fps = 5;
std::future<int> bgf::Event::input = async(std::launch::async, getchar);
int bgf::Event::input_res = -1;

void bgf::Event::update()
{
	#ifdef __linux__
		sleep(1.0 / game_fps);
	#elif _WIN32
		Sleep(1.0 / game_fps);
	#endif

	/* Input handler */
	if (input_res != -1) input_res = -1;
	if (!input.valid()) input = async(std::launch::async, getchar);
	if (input.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
	{
		int res = input.get();
		if (res == 27)
			switch (getchar() + getchar())
			{
				case 156: input_res = KEY_UP; break;
				case 157: input_res = KEY_DOWN; break;
				case 158: input_res = KEY_RIGHT; break;
				case 159: input_res = KEY_LEFT; break;
			}
		else if (res >= 97 && res <= 122) input_res = res - 97;
		else if (res >= 65 && res <= 90) input_res = res - 65;
	}
}

/* Setters */
void bgf::Event::setFPS(const int& fps)
{
	game_fps = fps;
}

/* Getters */
int bgf::Event::getInput()
{
	return input_res;
}

int bgf::Event::getFPS()
{
	return game_fps;
}


