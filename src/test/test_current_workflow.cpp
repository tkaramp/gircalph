#include <iostream>
#include "../util/cmdopts.hpp"
#include "../engine/gircalph_engine.hpp"
using namespace std;

int main(int argc, char const ** argv) {
    cmdopts::system_init(argc, argv);
    gircalph_engine<float,float> engine;
    return 0;
}