#include "libeasyargv.h"

int main(int argc, char** argv) {
    add_param_empty("-a");
    add_param_integer("-n");
    collect_params(argc, argv);
    dump_params();
    return 0;
}