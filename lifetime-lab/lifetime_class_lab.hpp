#include "lifetime.hpp"



namespace WithClassLab{
    struct ConstructWithoutMove{
        Lifetime l;
        ConstructWithoutMove(Lifetime&& l) : l(l) {}
    };

    struct ConstructWithMove{
        Lifetime l;
        ConstructWithMove(Lifetime&& l) : l(std::move(l)) {}
    };

    void lifetimeClassDemo(){
        puts("\ndemo with classes:\n");
        {
            std::puts("sending to ConstructWithoutMove constrctor: {}");
            ConstructWithoutMove without_move({});
        }
        {
            std::puts("sending to ConstructWithoutMove constrctor: Lifetime{}");
            ConstructWithoutMove without_move(Lifetime{});
        }

        {
            std::puts("sending to ConstructWithMove constrctor: {}");
            ConstructWithMove with_move({});
        }
        {
            std::puts("sending to ConstructWithMove constrctor: Lifetime{}");
            ConstructWithMove with_move(Lifetime{});
        }
    }
};


