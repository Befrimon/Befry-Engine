#ifndef SCENE_HPP
#define SCENE_HPP

#include <string>
#include <iostream>

template<typename T, typename... Args>
void bgf::Scene::addChild(const std::string &name, const Args &...args)
{
    if (children.find(name) != children.end())
        throw std::invalid_argument("Children with name `" + name + "` already exists in this scene!");
    children.insert({name.data(), std::make_shared<T>(args...)});
}

template<typename T>
std::shared_ptr<T> bgf::Scene::getChild(const std::string &name)
{
    return std::static_pointer_cast<T>(children[name]);
}

#endif
