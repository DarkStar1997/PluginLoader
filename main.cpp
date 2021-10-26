#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <PluginLoader.hpp>
#include "plugins/Entity.hpp"
#include "plugins/Move.hpp"
#include "plugins/Digestion.hpp"

int main()
{
    fmt::print(fg(fmt::color::red) | fmt::emphasis::strikethrough, "{:s}({:d}): Hello World\n", __func__, __LINE__);
    
    std::filesystem::path project_root = std::filesystem::canonical(__FILE__).parent_path();
    fmt::print("Project root: {}\n", project_root.string());

    PluginLoader loader(project_root / "plugins/build/libfoo.so");
    void (*display)() = (void(*)())loader.LoadSymbol("display");
    (*display)();
    
    PluginLoader loader1(project_root / "plugins/build/libfoo1.so");
    void (*display1)() = (void(*)())loader1.LoadSymbol("display");
    (*display1)();
    
    PluginLoader loader2(project_root / "plugins/build/libanimal.so");
    
    void *entity;
    
    void (*create)(void**) = (void(*)(void**))loader2.LoadSymbol("create");
    void (*destroy)(void**) = (void(*)(void**))loader2.LoadSymbol("destroy");
    (*create)(&entity);

    ((Entity*)(entity))->greet();
    ((Entity*)(entity))->age++;

    fmt::print("age = {}\n", ((Entity*)entity)->age);

    dynamic_cast<Move*>((Entity *)entity)->move();

    dynamic_cast<Digestion*>((Entity *)entity)->burp();
    dynamic_cast<Digestion*>((Entity *)entity)->digest();

    (*destroy)(&entity);
}
