#ifndef PLUGINLOADER_HPP
#define PLUGINLOADER_HPP

#include <filesystem>

struct PluginLoader
{
    std::filesystem::path plugin_path;
    void *plugin;

    PluginLoader(const std::filesystem::path);
    ~PluginLoader();

    void* LoadSymbol(const std::string&);
};

#endif /* PLUGINLOADER_HPP */
