#include <fmt/core.h>
#include "Entity.hpp"
#include "Move.hpp"
#include "Digestion.hpp"

struct Animal : public Entity, public Move, public Digestion
{
    Animal()
    {
        age = 0;
        fmt::print("{} {}({}) called\n", __FILE__, __func__, __LINE__);
    }
    void greet()
    {
        fmt::print("{} {}({}) called\n", __FILE__, __func__, __LINE__);
        fmt::print("Animal says hello!\n");
    }
    void breathe()
    {
        fmt::print("{} {}({}) called\n", __FILE__, __func__, __LINE__);
        fmt::print("Animal is breathing\n");
    }
    void move()
    {
        fmt::print("{} {}({}) called\n", __FILE__, __func__, __LINE__);
        fmt::print("Animal is moving\n");
    }
    void digest()
    {
        fmt::print("{} {}({}) called\n", __FILE__, __func__, __LINE__);
    }
    void burp()
    {
        fmt::print("{} {}({}) called\n", __FILE__, __func__, __LINE__);
    }
    ~Animal()
    {
        fmt::print("{} {}({}) called\n", __FILE__, __func__, __LINE__);
    }
};

extern "C" void create(void **ptr)
{
    *ptr = new Animal();
}

extern "C" void destroy(void **ptr)
{
    delete (Animal*)*ptr;
}
