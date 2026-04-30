#include "lifetime.hpp"
#include <utility>

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

int main(){
    std::puts("bad move example:");
    bad_move_example();
    std::puts("");

    std::puts("move_using_RVO:");
    move_using_RVO();
    std::puts("");

    return 0;
}