#pragma once

#include "lifetime.hpp"
#include "../utils/logger.hpp"
#include <utility>
#include <expected>
#include <string_view>
#include <tuple>

#include <optional>

namespace ComplexReturnType {
    std::optional<std::pair<int, Lifetime>> getLife1(){
        Lifetime l; // 1 ctor
        return std::pair{1, std::move(l)}; // 2 move ctors
    }

    std::optional<std::pair<int, Lifetime>> getLife2(){
        return std::optional<std::pair<int, Lifetime>>{{1, Lifetime{}}}; // 1 ctor + 2 move ctors
    }

    std::optional<std::pair<int, Lifetime>> getLife3(){
        return std::optional<std::pair<int, Lifetime>>{std::in_place, 1, Lifetime{}}; // 1 ctor + 1 move ctor
    }

    std::optional<std::pair<int, Lifetime>> getLife4(){
        // 1 ctor (constructs in destination)
        return std::optional<std::pair<int, Lifetime>>{std::in_place, std::piecewise_construct, std::forward_as_tuple(1), std::forward_as_tuple()};
    }

    std::optional<std::pair<int, Lifetime>> getLife5(){
        Lifetime l; // ctor
        return std::optional<std::pair<int, Lifetime>>{std::in_place, 1, std::move(l)}; // move ctor
    }

    std::optional<std::pair<int, Lifetime>> getLife6(){
        Lifetime l; // ctor
        return std::optional<std::pair<int, Lifetime>>{std::in_place, 1, l}; // copy ctor
    }

    std::optional<std::pair<int, Lifetime>> getLife7(){
        Lifetime l; // ctor
        return std::optional<std::pair<int, Lifetime>>{{1, l}}; // copy ctor + move ctor
    }

    std::pair<int, Lifetime> getLife8(){
        return {1, {}}; // ctor + move ctor
    }

    std::pair<int, Lifetime> getLife9(){
        std::pair<int, Lifetime> named_pair; // ctor
        named_pair.first = 1;
        return named_pair; // NVRO
    }

    std::optional<Lifetime> getLife10(){
        Lifetime l; // ctor
        return l; // move ctor (into optional)
    }

    std::optional<Lifetime> getLife11(){
        std::optional<Lifetime> l;
        l.emplace(); // ctor
        return l; // NRVO
    }

    std::optional<std::pair<int, Lifetime>> getLife12(){
        std::optional<std::pair<int, Lifetime>> result;
        result.emplace(std::piecewise_construct, std::forward_as_tuple(1), std::forward_as_tuple()); // ctor
        return result; // NVRO
    }



    void lifetime_and_complex_return_type_demo(){
        puts("\nlifetime_and_lambda_demo2");
        puts("complex return type std::optiona<std::pair>\n");

        {
            std::optional<std::pair<int, Lifetime>> opt_l = CALL_AND_PRINT(getLife1());  
        }
        {
            std::optional<std::pair<int, Lifetime>> opt_l = CALL_AND_PRINT(getLife2());
        }
        {
            std::optional<std::pair<int, Lifetime>> opt_l = CALL_AND_PRINT(getLife3());
        }
        {
            std::optional<std::pair<int, Lifetime>> opt_l = CALL_AND_PRINT(getLife4());
        }
        {
            std::optional<std::pair<int, Lifetime>> opt_l = CALL_AND_PRINT(getLife5());
        }
        {
            std::optional<std::pair<int, Lifetime>> opt_l = CALL_AND_PRINT(getLife6());
        }
        {
            std::optional<std::pair<int, Lifetime>> opt_l = CALL_AND_PRINT(getLife7());
        }
        {
            std::pair<int, Lifetime> pair_l = CALL_AND_PRINT(getLife8());
        }
        {
            std::pair<int, Lifetime> pair_l = CALL_AND_PRINT(getLife9());
        }
        {
            std::optional<Lifetime> opt_l = CALL_AND_PRINT(getLife10());
        }
        {
            std::optional<Lifetime> opt_l = CALL_AND_PRINT(getLife11());
        }
        {
            std::optional<std::pair<int, Lifetime>> opt_l = CALL_AND_PRINT(getLife12());
        }
        
    }

}
