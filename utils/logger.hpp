#pragma once
#include <print>
#include <source_location>


#define CALL_AND_PRINT(func_call) \
    ([]() { \
        std::println("\n[Executing function]: {}", #func_call); \
        return func_call; \
    }())
