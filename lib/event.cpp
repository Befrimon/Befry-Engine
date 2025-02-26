#include "event.h"

#include <iostream>

#ifdef __linux__
	#include <unistd.h>
#elif _WIN32
	#include <windows.h>
#endif

int befry::Event::game_fps = 5;
std::unordered_map<std::string, std::shared_ptr<befry::Scene>> befry::Event::scenes;
std::string befry::Event::current_scene;

std::future<int> befry::Event::input = async(std::launch::async, getchar);
int befry::Event::input_res = -1;

std::shared_ptr<befry::Scene> befry::Event::addScene(std::string name, Vector2 size)
{
	if (scenes.find(name) != scenes.end())
		throw std::invalid_argument("Scene with name `" + name + "` already exists!");
	scenes[name] = std::make_shared<Scene>(Scene(size));
	if (current_scene.empty())
		current_scene = name;
	return scenes[name];
}

std::shared_ptr<befry::Scene> befry::Event::changeScene(std::string name)
{
	if (scenes.find(name) == scenes.end())
		throw std::invalid_argument("Scene with name `" + name + "` not found!");
	current_scene = name;
	return scenes[name];
}

std::shared_ptr<befry::Scene> befry::Event::getActiveScene()
{
	return scenes[current_scene];
}

void befry::Event::update()
{
	#ifdef __linux__
		sleep(1.0 / game_fps);
	#elif _WIN32
		Sleep(1.0 / game_fps);
	#endif

	if (!current_scene.empty()) scenes[current_scene]->render();

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
void befry::Event::setFPS(const int& fps)
{
	game_fps = fps;
}

/* Getters */
int befry::Event::getInput()
{
	return input_res;
}


