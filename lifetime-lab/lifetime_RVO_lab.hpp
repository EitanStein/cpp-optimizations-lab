#pragma once

#include "lifetime.hpp"
#include <utility>
#include <expected>
#include <string_view>

namespace RVOLab{
    void bad_move_example(){
        
        Lifetime x;
        x.member_data = 4;

        Lifetime y = std::move(x); // ctor and move ctor
    }


    void move_using_RVO(){
        auto make_lifetime = [](const int val) -> Lifetime{
            Lifetime l;
            l.member_data = val;
            return l; // NRVO
        };

        Lifetime x = make_lifetime(4); // one ctor
    }

    std::expected<Lifetime, std::string_view> badExpectedReturn(){
        return Lifetime{}; // multiple ctors from building since we build lifetime and then copy into the expected
        // the expected value is then returned with URVO
    }

    void bad_expected_RVO(){
        std::expected<Lifetime, std::string_view> x = badExpectedReturn();
    }

    std::expected<Lifetime, std::string_view> goodExpectedReturn(){
        std::puts("using emplace for ctor");
        return {}; // only a single ctor
    }

    void good_expected_RVO(){
        std::expected<Lifetime, std::string_view> x = goodExpectedReturn();
    }


    void lifetime_and_RVO_demo(){
        std::puts("bad move example:");
        bad_move_example();
        std::puts("");

        std::puts("move_using_RVO:");
        move_using_RVO();
        std::puts("");

        std::puts("bad_expected_RVO:");
        bad_expected_RVO();
        std::puts("");

        std::puts("good_expected_RVO:");
        good_expected_RVO();
        std::puts("");
    }
}
