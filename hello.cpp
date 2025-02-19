#include "nanobench.h"
#include <iostream>

int main() {
    ankerl::nanobench::Bench().run("Fibinachi", []{
        std::cout << "Hello World" << std::endl;
    });
}