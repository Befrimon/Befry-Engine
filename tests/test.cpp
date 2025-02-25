#include <iostream>
#include <memory>
#include <befry_engine.h>


int main()
{
	befry::Scene scn({80, 40});

	scn.addChild(std::make_shared<befry::Dot>(befry::Dot("dot", {10, 10})));

	befry::MainLoop::setScene(std::make_shared<befry::Scene>(scn));
	befry::MainLoop::update();
}
