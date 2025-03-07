#include <bg_framework.h>

class Dot : public bgf::Sprite
{
public:
	Dot(const bgf::Vector2 &position, const std::string &texture) : Sprite(position, texture) {}

	void move(const bgf::Vector2 &delta)
	{
		clear();
		position += delta;
	}
};

int main()
{
	const auto scene = bgf::Renderer::addScene("main", bgf::Vector2{160, 40});
	scene->addChild<Dot>("dot", bgf::Vector2{10, 10}, "dot");

	while (true)
	{
		switch (bgf::Event::getInput())
		{
			case bgf::Event::KEY_Q: scene->close(); return 0;
			case bgf::Event::KEY_UP:
				scene->getChild<Dot>("dot")->move({0, -1}); break;
			case bgf::Event::KEY_DOWN:
				scene->getChild<Dot>("dot")->move({0, 1}); break;
			case bgf::Event::KEY_RIGHT:
				scene->getChild<Dot>("dot")->move({1, 0}); break;
			case bgf::Event::KEY_LEFT:
				scene->getChild<Dot>("dot")->move({-1, 0}); break;
			default: break;
		}

		bgf::Event::update();
		scene->render();
	}
}
