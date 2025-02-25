#ifndef MAIN_LOOP_H
#define MAIN_LOOP_H

#include <memory>

/* Befry Engine includes */
#include "scene.h"

namespace befry
{
	class MainLoop
	{
	protected:
		static int game_fps;
		static std::shared_ptr<Scene> current_scene;

	public:
		static void update();

		/* Setters */
		static void setFPS(const int& fps);
		static void setScene(std::shared_ptr<Scene> scn);

		/* Getters */
	};
}

#endif
