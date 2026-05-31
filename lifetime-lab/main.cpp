#include "lifetime_lambda_lab.hpp"
#include "lifetime_complex_return_type_lab.hpp"
#include "lifetime_RVO_lab.hpp"
#include "lifetime_class_lab.hpp"






int main(){
    RVOLab::lifetime_and_RVO_demo();
    LambdaLab::lifetime_and_lambda_demo();
    ComplexReturnType::lifetime_and_complex_return_type_demo();
    WithClassLab::lifetimeClassDemo();

    return 0;
}