#ifndef DIGESTION_HPP
#define DIGESTION_HPP

struct Digestion
{
    virtual void digest() = 0;
    virtual void burp() = 0;
};

#endif /* DIGESTION_HPP */
