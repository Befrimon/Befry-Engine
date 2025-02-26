#include <befry_engine.h>

int main()
{
	auto scene = befry::Event::addScene("main", {80, 40});
	scene->addChild<befry::Dot>("dot", befry::Vector2{10, 10});

	while (true)
	{
		switch (befry::Event::getInput())
		{
			case befry::Event::KEY_Q: return 0;
			case befry::Event::KEY_UP:
				scene->getChild<befry::Dot>("dot")->move({0, -1}); break;
			case befry::Event::KEY_DOWN:
				scene->getChild<befry::Dot>("dot")->move({0, 1}); break;
			case befry::Event::KEY_RIGHT:
				scene->getChild<befry::Dot>("dot")->move({1, 0}); break;
			case befry::Event::KEY_LEFT:
				scene->getChild<befry::Dot>("dot")->move({-1, 0}); break;
		}

		befry::Event::update();
	}
}
