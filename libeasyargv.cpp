#include "libeasyargv.h"
#include <cstdlib>
#include <ios>
#include <stdexcept>
#include <string>

std::vector<flag> essential_flags;

std::vector<flag> flags;

void add_param_essential_empty(const std::string &name) {
    essential_flags.push_back(flag{name, type_argv::empty, "none"});
    flags.push_back(flag{name, type_argv::empty, "none"});
}
void add_param_essential_string(const std::string &name) {
    essential_flags.push_back(flag{name, type_argv::string, "none"});
    flags.push_back(flag{name, type_argv::string, "none"});
}
void add_param_essential_integer(const std::string &name) {
    essential_flags.push_back(flag{name, type_argv::integer, "none"});
    flags.push_back(flag{name, type_argv::integer, "none"});
}

void add_param_empty(const std::string &name) {
    flags.push_back(flag{name, type_argv::empty, "none"});
}
void add_param_string(const std::string &name) {
    flags.push_back(flag{name, type_argv::string, "none"});
}
void add_param_integer(const std::string &name) {
    flags.push_back(flag{name, type_argv::integer, "none"});
}

void collect_params(int argc, char** argv) {
    for(int i = 0;i<argc;i++) {
        for(auto &x : flags) {
            if(x.name==argv[i]) {
                if(argc<=i+1&&x.type!=type_argv::empty) {
                    throw std::runtime_error("Expected value for argument '"+x.name+"'\n");
                }
                switch(x.type) {
                    case type_argv::empty: break;
                    case type_argv::integer: {
                        char* endptr;
                        int64_t value = strtoll(argv[++i], &endptr, 0);
                        x.value=std::to_string(value);
                        break;
                    }
                    case type_argv::string: {
                        x.value=argv[++i];
                        break;
                    }
                }
                x.checked=true;
            }
        }
    }
}

std::vector<bool> check_essential(int argc, char **argv) {
    std::vector<bool> checked;
    for(auto &x : essential_flags) {
        for (int i = 0; i < argc; i++) {
            if (argv[i] == x.name) checked.emplace_back(true);
            else checked.emplace_back(false);
        }
    }
    return checked;
}
std::vector<bool> check_flags(int argc, char **argv) {
    std::vector<bool> checked;
    for(auto &x : flags) {
        for (int i = 0; i < argc; i++) {
            if (argv[i] == x.name) checked.emplace_back(true);
            else checked.emplace_back(false);
        }
    }
    return checked;
}

bool is_param_included(const std::string &name, int argc, char **argv)
{
    for (int i = 0; i < argc; i++) {
        if (argv[i] == name) return true;
    }
    return false;
}

void dump_params() {
    std::cout << "Types docs:\n";
    std::cout << "0 - empty flag\n1 - integer\n2 - string\n";
    for(auto &x : flags) {
        std::cout << x.name << ' ' << static_cast<int>(x.type) << ' ' << x.value << ' ' << std::boolalpha << x.checked << '\n';
    }
}