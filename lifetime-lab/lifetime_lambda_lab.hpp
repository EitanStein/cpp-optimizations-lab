#pragma once

#include "lifetime.hpp"
#include <utility>
#include <expected>
#include <string_view>

namespace LambdaLab {
    Lifetime getLife1() { return Lifetime{}; }
    Lifetime getLife2() { return getLife1(); }
    Lifetime getLife3() { return getLife2(); }

    void lifetime_and_lambda_demo(){
        puts("\nlifetime_and_lambda_demo\n");

        puts("get life 3:");
        {
            Lifetime l = getLife3();
        }
        puts("");

        puts("auto l = [](){return getLife3();}; :");
        {
            auto l = [](){return getLife3();};
        }
        puts("");

        puts("auto l = [life](){}; :");
        {
            Lifetime life;
            auto l = [life](){};
        }
        puts("");

        puts("auto l = [&life](){}; :");
        {
            Lifetime life;
            auto l = [&life](){};
        }
        puts("");

        puts("auto l = [lamb_life = life](){ return lamb_life;}; :");
        {
            Lifetime life;
            auto l = [lamb_life = life](){ return lamb_life;};
        }
        puts("");

        puts("Lifetime l = [lamb_life = life](){ return lamb_life;}(); :");
        {
            Lifetime life;
            Lifetime l = [lamb_life = life](){ return lamb_life;}();
        }
        puts("");

        puts("auto l = [lamb_life = std::move(life)](){return lamb_life;}; :");
        {
            Lifetime life;
            auto l = [lamb_life = std::move(life)](){return lamb_life;};
        }
        puts("");

        puts("Lifetime l = [lamb_life = std::move(life)](){return lamb_life;}(); :");
        {
            Lifetime life;
            Lifetime l = [lamb_life = std::move(life)](){return lamb_life;}();
        }
        puts("");

        puts("Lifetime l = [lamb_life = std::move(life)](){return Lifetime(lamb_life);}(); :");
        {
            Lifetime life;
            Lifetime l = [lamb_life = std::move(life)](){return Lifetime(lamb_life);}();
        }
        puts("");

        puts("Lifetime l = [lamb_life = std::move(life)](){return Lifetime(lamb_life);}(); Lifetime l2; :");
        {
            Lifetime life;
            Lifetime l = [lamb_life = std::move(life)](){return Lifetime(lamb_life);}();
            Lifetime l2;
        }
        puts("");

        puts("auto l = [](Lifetime lamb_life){return Lifetime(lamb_life);}; :");
        {
            auto l = [](Lifetime lamb_life){return Lifetime(lamb_life);};
        }
        puts("");

        puts("Lifetime l = [](Lifetime lamb_life){return Lifetime(lamb_life);}(life); :");
        {
            Lifetime life;
            Lifetime l = [](Lifetime lamb_life){return Lifetime(lamb_life);}(life);
        }
        puts("");

        puts("Lifetime l = [](Lifetime lamb_life){return lamb_life;}(life); :");
        {
            Lifetime life;
            Lifetime l = [](Lifetime lamb_life){return lamb_life;}(life);
        }
        puts("");

        puts("Lifetime l = [](Lifetime& lamb_life){return Lifetime(lamb_life);}(life); :");
        {
            Lifetime life;
            Lifetime l = [](Lifetime& lamb_life){return Lifetime(lamb_life);}(life);
        }
        puts("");

        puts("Lifetime l = [](Lifetime& lamb_life){return lamb_life;}(life); :");
        {
            Lifetime life;
            Lifetime l = [](Lifetime& lamb_life){return lamb_life;}(life);
        }
        puts("");
    }

}
