#pragma once

#include "lifetime.hpp"
#include <utility>
#include <expected>
#include <string_view>
#include <tuple>

#include <optional>

namespace complex_return_type {
    std::optional<std::pair<int, Lifetime>> getLife1(){
        puts("Lifetime l; return std::pair{1, std::move(l)};");
        Lifetime l;
        return std::pair{1, std::move(l)};
    }

    std::optional<std::pair<int, Lifetime>> getLife2(){
        puts("return std::optional<std::pair<int, Lifetime>>{1, Lifetime{}};");
        return std::optional<std::pair<int, Lifetime>>{{1, Lifetime{}}};
    }

    std::optional<std::pair<int, Lifetime>> getLife3(){
        puts("return std::optional<std::pair<int, Lifetime>>{std::in_place, 1, Lifetime{}};");
        return std::optional<std::pair<int, Lifetime>>{std::in_place, 1, Lifetime{}};
    }

    std::optional<std::pair<int, Lifetime>> getLife4(){
        puts("return std::optional<std::pair<int, Lifetime>>{std::in_place, std::piecewise_construct, std::forward_as_tuple(1), std::forward_as_tuple()};");
        return std::optional<std::pair<int, Lifetime>>{std::in_place, std::piecewise_construct, std::forward_as_tuple(1), std::forward_as_tuple()};
    }

    std::optional<std::pair<int, Lifetime>> getLife5(){
        puts("return std::optional<std::pair<int, Lifetime>>{std::in_place, 1, std::move(l)};");
        Lifetime l;
        return std::optional<std::pair<int, Lifetime>>{std::in_place, 1, std::move(l)};
    }

    std::optional<std::pair<int, Lifetime>> getLife6(){
        puts("return std::optional<std::pair<int, Lifetime>>{std::in_place, 1, l};");
        Lifetime l;
        return std::optional<std::pair<int, Lifetime>>{std::in_place, 1, l};
    }


    void lifetime_and_complex_return_type_demo(){
        puts("\nlifetime_and_lambda_demo2");
        puts("complex return type std::optiona<std::pair>\n");

        puts("std::optional<std::pair<int, Lifetime>> opt_l = getLife1(); :");
        {
            std::optional<std::pair<int, Lifetime>> opt_l = getLife1();
        }
        puts("");

        puts("std::optional<std::pair<int, Lifetime>> opt_l = getLife2(); :");
        {
            std::optional<std::pair<int, Lifetime>> opt_l = getLife2();
        }
        puts("");

        puts("std::optional<std::pair<int, Lifetime>> opt_l = getLife3(); :");
        {
            std::optional<std::pair<int, Lifetime>> opt_l = getLife3();
        }
        puts("");

        puts("std::optional<std::pair<int, Lifetime>> opt_l = getLife4(); :");
        {
            std::optional<std::pair<int, Lifetime>> opt_l = getLife4();
        }
        puts("");

        puts("std::optional<std::pair<int, Lifetime>> opt_l = getLife5(); :");
        {
            std::optional<std::pair<int, Lifetime>> opt_l = getLife5();
        }
        puts("");

        puts("std::optional<std::pair<int, Lifetime>> opt_l = getLife6(); :");
        {
            std::optional<std::pair<int, Lifetime>> opt_l = getLife6();
        }
        puts("");
    }

}
