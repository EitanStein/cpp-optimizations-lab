#include <benchmark/benchmark.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <flat_map>
#include <random>

constexpr int NUM_QUERIES = 1024;
constexpr int SEED = 42;

[[nodiscard]] constexpr std::vector<int> init_queries(int max_num, int min_num=0){
    std::vector<int> query_arr(NUM_QUERIES);
    std::mt19937 rng(SEED);
    std::uniform_int_distribution<int> dist(0, max_num);

    for(auto& q : query_arr)
        q = dist(rng);

    return query_arr;
}

[[nodiscard]] constexpr std::vector<int> init_rand_vector(int size){
    std::vector<int> result(size);
    std::iota(result.begin(), result.end(), 0);

    std::mt19937 rng(SEED);
    std::shuffle(result.begin(), result.end(), rng);
    return result;
}

struct MyStruct{
    int x;
};

static void BM_vector_linear_lookup(benchmark::State& state){
    const int size = state.range(0);
    std::vector<MyStruct> arr;

    for(int val : init_rand_vector(size)){
        arr.emplace_back(val);
    }

    std::vector<int> query_arr = init_queries(size-1);

    for(auto _ : state){
        for(int q : query_arr){
            auto it = std::find_if(arr.begin(), arr.end(), [q](const MyStruct& arg){ return arg.x == q;});
            benchmark::DoNotOptimize(it);
        }
    }
}
BENCHMARK(BM_vector_linear_lookup)->RangeMultiplier(2)->Range(4,4096);



static void BM_vector_binary_search(benchmark::State& state){
    const int size = state.range(0);
    std::vector<MyStruct> arr;

    for(int val : std::views::iota(0, size)){
        arr.emplace_back(val);
    }

    std::vector<int> query_arr = init_queries(size-1);

    for(auto _ : state){
        for(int q : query_arr){
            auto it = std::lower_bound(arr.begin(), arr.end(), q, [](const MyStruct& arg, int q){ return arg.x < q;});
            benchmark::DoNotOptimize(it);
        }
    }
}
BENCHMARK(BM_vector_binary_search)->RangeMultiplier(2)->Range(4,4096);



static void BM_map(benchmark::State& state){
    const int size = state.range(0);
    std::map<int, size_t> my_map;

    for(int val : init_rand_vector(size)){
        my_map[val] = val*2;
    }

    std::vector<int> query_arr = init_queries(size-1);

    for(auto _ : state){
        for(int q : query_arr){
            auto result = my_map[q];
            benchmark::DoNotOptimize(result);
        }
    }
}
BENCHMARK(BM_map)->RangeMultiplier(2)->Range(4,4096);



static void BM_unordered_map(benchmark::State& state){
    const int size = state.range(0);
    std::unordered_map<int, size_t> my_map;

    for(int val : init_rand_vector(size)){
        my_map[val] = val*2;
    }

    std::vector<int> query_arr = init_queries(size-1);

    for(auto _ : state){
        for(int q : query_arr){
            auto result = my_map[q];
            benchmark::DoNotOptimize(result);
        }
    }
}
BENCHMARK(BM_unordered_map)->RangeMultiplier(2)->Range(4,4096);



static void BM_flat_map(benchmark::State& state){
    const int size = state.range(0);
    std::flat_map<int, size_t> my_map;

    for(int val : init_rand_vector(size)){
        my_map[val] = val*2;
    }

    std::vector<int> query_arr = init_queries(size-1);

    for(auto _ : state){
        for(int q : query_arr){
            auto result = my_map[q];
            benchmark::DoNotOptimize(result);
        }
    }
}
BENCHMARK(BM_flat_map)->RangeMultiplier(2)->Range(4,4096);


BENCHMARK_MAIN();