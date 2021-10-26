#include <PluginLoader.hpp>
#include <dlfcn.h>
#include <fmt/core.h>

PluginLoader::PluginLoader(const std::filesystem::path lib_path)
{
    plugin_path = lib_path;
    plugin = dlopen(plugin_path.c_str(), RTLD_LAZY | RTLD_GLOBAL);
    if(!plugin)
    {
        fmt::print("{}({}): {}\n", __func__, __LINE__, dlerror());
        exit(EXIT_FAILURE);
    }
    dlerror();
}

void* PluginLoader::LoadSymbol(const std::string &sym_name)
{
    void* symbol = dlsym(plugin, sym_name.c_str());
    char* error;
    if ((error = dlerror()) != NULL)  {
        fmt::print("{}({}): {}\n", __func__, __LINE__, error);
        exit(EXIT_FAILURE);
    }
    return symbol;
}

PluginLoader::~PluginLoader()
{
    dlclose(plugin);
}
