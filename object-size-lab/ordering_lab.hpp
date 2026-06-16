#pragma once

#include <print>



namespace size_lab{
    struct Messy{
        int a;
        bool b;
        double c;
        char d;
        bool e;
    };

    struct Smaller{
        double a;
        int b;
        bool c;
        bool d;
        char e;
    };

    void check_different_ordered_struct_sizes(){
        std::println("check_different_ordered_struct_sizes:");

        std::println("sizeof(double) = {}", sizeof(double)); // 8 bytes
        std::println("sizeof(int) = {}", sizeof(int)); // 4 bytes
        std::println("sizeof(bool) = {}", sizeof(bool)); // 1 byte
        std::println("sizeof(char) = {}", sizeof(char)); // 1 byte

        Messy m;
        std::println("sizeof(Messy) = {}", sizeof(Messy)); // 24 bytes
        std::println("address(Messy) = {}", (void*)&m);
        std::println("address(int a) = {}", (void*)&m.a); // 4 bytes - start of Messy
        std::println("address(bool b) = {}", (void*)&m.b); // 1 + 3 padding
        std::println("address(double c) = {}", (void*)&m.c); // 8 bytes
        std::println("address(char d) = {}", (void*)&m.d); // 1 bytes
        std::println("address(bool e) = {}", (void*)&m.e); // 1 + 6 padding

        Smaller s;
        std::println("sizeof(Smaller) = {}", sizeof(Smaller)); // 16 bytes
        std::println("address(Smaller) = {}", (void*)&s);
        std::println("address(double a) = {}", (void*)&s.a); // 8 bytes - start of Smaller
        std::println("address(int b) = {}", (void*)&s.b); // 4 bytes
        std::println("address(bool c) = {}", (void*)&s.c); // 1 byte
        std::println("address(bool d) = {}", (void*)&s.d); // 1 byte
        std::println("address(char e) = {}", (void*)&s.e); // 1 + 1 padding
    }
    
}