#include "libeasyargv.h"

int main(int argc, char** argv) {
    add_param_empty("-a");
    add_param_integer("-n");
    add_param_empty("-v");
    collect_params(argc, argv);
    if(is_param_included("-v", argc, argv)) dump_params();
    if(is_param_included("-n", argc, argv)) std::cout << "n equal to " << param_value("-n") << '\n';
    return 0;
}