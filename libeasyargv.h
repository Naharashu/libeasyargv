#ifndef LIB_EASYARGV
#define LIB_EASYARGV

#include <string>
#include <vector>
#include <cstdint>
#include <iostream>

enum class type_argv : uint8_t {
    empty,
    integer,
    string
};

struct flag {
    std::string name="";
    type_argv type=type_argv::empty;
    std::string value="none";
    bool checked=false;
};



void add_param_empty(const std::string &name);
void add_param_string(const std::string &name);
void add_param_integer(const std::string &name);

void collect_params(int argc, char** argv);

std::vector<bool> check_flags( int argc, char** argv);

bool is_param_included(const std::string &name, int argc, char** argv);

void dump_params();

std::string param_value(const std::string &name);

#endif