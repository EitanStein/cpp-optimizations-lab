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

    struct ConstructWithRegularCtor{
        Lifetime l;
        ConstructWithRegularCtor(Lifetime l) : l(std::move(l)) {}
    };

    struct WithoutInitializerList{
        Lifetime l;
        WithoutInitializerList(Lifetime&& other) {
            l = std::move(other);
        }
    };

    struct InitializerListOrdered{
        Lifetime l1;
        Lifetime l2;
        Lifetime l3;
        InitializerListOrdered() : l1([](){std::puts("l1 init list"); return 1;}()),  // l1 init to ctor
                                   l2([](){std::puts("l2 init list"); return 1;}()),  // l2 init to ctor
                                   l3([](){std::puts("l3 init list"); return 1;}()) {} // l3 init to ctor
    };

    struct InitializerListNotOrdered{
        Lifetime l1;
        Lifetime l2;
        Lifetime l3;
        InitializerListNotOrdered() : l3([](){std::puts("l3 init list"); return 1;}()), 
                                      l2([](){std::puts("l2 init list"); return 1;}()), 
                                      l1([](){std::puts("l1 init list"); return 1;}()) {}
                                      // ignores init list order and initializes in the declaration order
                                      // l1 init to ctor
                                      // l2 init to ctor
                                      // l3 init to ctor
                                      // same as InitializerListOrdered
    };

    void lifetimeClassDemo(){
        puts("\ndemo with classes:\n");
        {
            std::puts("sending to ConstructWithoutMove constrctor: Lifetime{}");
            ConstructWithoutMove without_move(Lifetime{}); // 1 ctor 1 copy ctor - same as without_move({})
        }
        std::puts("");
        {
            std::puts("sending to ConstructWithMove constrctor: Lifetime{}");
            ConstructWithMove with_move(Lifetime{}); // 1 ctor 1 move ctor - same as with_move({})
        }
        std::puts("");
        {
            std::puts("sending to ConstructWithRegularCtor constrctor: lvalue l");
            Lifetime l;
            ConstructWithRegularCtor regular_ctor(l); // 1 ctor 2 move ctors
        }
        std::puts("");
        {
            std::puts("sending to ConstructWithRegularCtor constrctor: Lifetime{}");
            ConstructWithRegularCtor regular_ctor(Lifetime{}); // 1 ctor 1 move ctor - same as regular_ctor({})
        }
        std::puts("");
        {
            std::puts("sending to WithoutInitializerList constrctor: Lifetime{}");
            WithoutInitializerList no_init(Lifetime{}); // 2 ctor and move assign - same as no_init({})
        }
        std::puts("");
        {
            std::puts("sending to InitializerListOrdered");
            InitializerListOrdered init_list{};
            
        }
        std::puts("");
        {
            std::puts("sending to InitializerListNotOrdered");
            InitializerListNotOrdered init_list{};
            
        }
        std::puts("");
    }
};


