#include "main_loop.h"

#include <iostream>

#ifdef __linux__
	#include <unistd.h>
#elif _WIN32
	#include <windows.h>
#endif

int befry::MainLoop::game_fps = 5;
std::shared_ptr<befry::Scene> befry::MainLoop::current_scene = nullptr;

void befry::MainLoop::update()
{
	#ifdef __linux__
		sleep(1.0 / game_fps);
	#elif _WIN32
		Sleep(1.0 / game_fps);
	#endif

	std::cout << "\033[0;0f";
	if (current_scene) current_scene->render();

	update();
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


