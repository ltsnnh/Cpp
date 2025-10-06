#include <iostream>

/*
a lambda expression is an anonymous function that is defined in-place in the code, without needing a separate name
when to use lambda?
- when you need a short function that is not reused many times
- when passing callbacks to STL functions (std::sort, std::for_each, std::find_if, …)
- when writing multithreading (std::thread)
- when handling events (GUI, signal-slot…)

[capture-list](parameters) -> return_type {
    // function body
};

capture-list: a list of variables from the surrounding scope that the lambda function can access
parameters: the list of input parameters, just like in a regular function. Optional
return_type: the type of the value that the lambda function will return. This part is optional, and the compiler can deduce it in many cases
function body: the code that defines the operation of the lambda function
*/

int main(void) {
    int multiplier = 3;

    // define lambda function
    auto times = [multiplier](int a) -> int {
        return a * multiplier;
    };

    // be used
    int result = times(5);  // result = 15
    std::cout << "Result = " << result << std::endl;

    return 0;
}
