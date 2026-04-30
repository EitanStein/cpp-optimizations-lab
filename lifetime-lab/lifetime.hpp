#pragma once
#include <cstdio>

struct Lifetime
{
    Lifetime() {std::puts("liftime() // default ctor");}
    Lifetime(const Lifetime&) {std::puts("liftime(const Lifetime&) // copy ctor");}
    Lifetime(Lifetime&&) {std::puts("liftime(Lifetime&&) // move ctor");}

    Lifetime& operator=(const Lifetime&) {std::puts("operator=(const Lifetime&) // copy assign"); return *this;}
    Lifetime& operator=(Lifetime&&) {std::puts("operator=(Lifetime&&) // move assign"); return *this;}

    ~Lifetime() {std::puts("~liftime() // default dtor");}

    int member_data;
};
