# Befry's Game Framework
*Open-source C++ framework for text-based games*

Befry Engine is ~~cross-platform~~ framework for building text-based games on C++. It works on Linux and ~~Windows~~ (in-dev)

## Installation
**Requirements:**
* C++17 compatible compiler
* Cmake 3.14 or higher

Clone the repo from GitHub:
```
git clone https://github.com/Befrimon/Befry-Engine.git
```
Build library with make
```
cd Befry-Engine
sudo make install
```
## How to use
**Simple example**
```C++
#include <bg_framework.h>

class Dot : public bgf::Sprite
{
public:
	Dot(const bgf::Vector2 &position, bgf::Texture texture) : Sprite(position, std::move(texture)) {}

	void move(const bgf::Vector2 &delta)
	{
		clear();
		position += delta;
	}
};

int main()
{
	auto scene = bgf::Renderer::addScene("main", bgf::Vector2{160, 40});
	scene->addChild<Dot>("dot", bgf::Vector2{10, 10}, bgf::Texture("dot"));

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
```
**Build your game**
```
g++ <game>.cpp -o <game> -lbefry_engine
```
