#ifndef SCENE_HPP
#define SCENE_HPP

#include <string>

template<typename T, typename... Args>
void bgf::Scene::addChild(const std::string &name, Args... args)
{
    if (children.find(name) != children.end())
        throw std::invalid_argument("Children with name `" + name + "` already exists in this scene!");
    children[name] = std::make_shared<T>(args...);
}

template<typename T>
std::shared_ptr<T> bgf::Scene::getChild(const std::string &name)
{
    return std::static_pointer_cast<T>(children[name]);
}

#endif
