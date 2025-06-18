#include <iostream>

/*
[capture-list](parameters) -> return_type {
    // function body
};

capture-list: A list of variables from the surrounding scope that the lambda function can access.
parameters: The list of input parameters, just like in a regular function. Optional.
return_type: The type of the value that the lambda function will return. This part is optional, and the compiler can deduce it in many cases.
function body: The code that defines the operation of the lambda function.
*/

int main(void)
{
    int multiplier = 3;

    // define lambda function
    auto times = [multiplier](int a) -> int
    {
        return a * multiplier;
    };

    // be used
    int result = times(5);  // result = 15
    std::cout << "Result = " << result << std::endl;

    return 0;
}
