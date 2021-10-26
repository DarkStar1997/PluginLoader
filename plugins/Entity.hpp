#ifndef ENTITY_HPP
#define ENTITY_HPP

struct Entity
{
    int age;
    virtual void greet() = 0;
    virtual void breathe() = 0;
};

#endif /* ENTITY_HPP */
