#ifndef LIBASR_UTILS_H
#define LIBASR_UTILS_H

#include <string>
#include <libasr/containers.h>

namespace LFortran {

enum Platform {
    Linux,
    macOS_Intel,
    macOS_ARM,
    Windows,
    FreeBSD
};

Platform get_platform();

struct CompilerOptions {
    bool fixed_form = false;
    bool c_preprocessor = false;
    std::vector<std::string> c_preprocessor_defines;
    bool prescan = true;
    bool disable_main = false;
    bool symtab_only = false;
    bool show_stacktrace = false;
    bool use_colors = true;
    bool indent = false;
    bool tree = false;
    bool fast = false;
    bool openmp = false;
    bool generate_object_code = false;
    bool no_warnings = false;
    bool no_error_banner = false;
    std::string error_format = "human";
    bool new_parser = false;
    bool implicit_typing = false;
    bool implicit_interface = false;
    std::string target = "";
    std::string arg_o = "";
    bool emit_debug_info = false;
    bool emit_debug_line_column = false;
    std::string import_path = "";
    Platform platform;

    CompilerOptions () : platform{get_platform()} {};
};

bool read_file(const std::string &filename, std::string &text);
bool present(Vec<char*> &v, const char* name);
bool present(char** const v, size_t n, const std::string name);
int initialize();

} // LFortran

namespace LCompilers {

    struct PassOptions {
        std::string run_fun; // for global_stmts pass
        std::string runtime_library_dir;
        bool always_run; // for unused_functions pass
        bool inline_external_symbol_calls; // for inline_function_calls pass
        int64_t unroll_factor; // for loop_unroll pass
        bool fast; // is fast flag enabled.

        PassOptions(): always_run(false), inline_external_symbol_calls(true),
                       unroll_factor(32), fast(false)
        {}
    };

}

#endif // LIBASR_UTILS_H
