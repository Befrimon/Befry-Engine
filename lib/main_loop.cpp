#include "main_loop.h"

#ifndef __linux__
#include <unistd.h>
#elif _WIN32
#include <windows.h>
#endif

void befry::MainLoop::update(double delta = 1e6 / game_fps)
{
	#ifndef __linux__
		sleep(delta);
	#elif _WIN32
		Sleep(delta);
	#endif

	current_scene->render();
}

/* Setters */
void befry::MainLoop::setFPS(const int& fps)
{
	game_fps = fps;
}
void befry::MainLoop::setScene(std::shared_ptr<Scene> scn)
{
	current_scene = scn;
}


