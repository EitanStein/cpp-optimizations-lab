#include "lifetime.hpp"
#include <utility>
#include <expected>
#include <string_view>

void bad_move_example(){
    
    Lifetime x;
    x.member_data = 4;

    Lifetime y = std::move(x);
    std::puts("will call 2 dtors");
}


void move_using_RVO(){
    auto make_lifetime = [](const int val) -> Lifetime{
        Lifetime l;
        l.member_data = val;
        return l;
    };

    Lifetime x = make_lifetime(4);
}

std::expected<Lifetime, std::string_view> badExpectedReturn(){
    return Lifetime{};
}

void bad_expected_RVO(){
    std::expected<Lifetime, std::string_view> x = badExpectedReturn();
}

std::expected<Lifetime, std::string_view> goodExpectedReturn(){
    std::puts("using emplace for ctor");
    return {};
}

void good_expected_RVO(){
    std::expected<Lifetime, std::string_view> x = goodExpectedReturn();
}

int main(){
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

    return 0;
}