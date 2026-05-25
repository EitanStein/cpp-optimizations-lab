#include "lifetime_lambda_lab.hpp"
#include "lifetime_complex_return_type_lab.hpp"
#include "lifetime_RVO_lab.hpp"






int main(){
    RVO_lab::lifetime_and_RVO_demo();
    lambda_lab::lifetime_and_lambda_demo();
    complex_return_type::lifetime_and_complex_return_type_demo();

    return 0;
}