#include <iostream>
#include "../util/cmdopts.hpp"
#include "../engine/gircalph_engine.hpp"
#include "../algorithm/my_algorithm.hpp"

using namespace std;

typedef float vertex_data_type;
typedef float edge_data_type;


int main(int argc, char const ** argv) {
    cmdopts::system_init(argc, argv);
    gircalph_engine<float,float> engine;
    my_algorithm alg;
    engine.run(alg);
    return 0;
}