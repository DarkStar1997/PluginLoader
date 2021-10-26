project(PluginTest
    DESCRIPTION "Plugin Test"
    LANGUAGES C CXX
    )

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

find_program(CCACHE_PROGRAM ccache)

if(CCACHE_PROGRAM)
    MESSAGE("CCACHE support enabled")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK "${CCACHE_PROGRAM}")
endif()

set(CMAKE_BUILD_TYPE "RELEASE")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE 1)

set(LIB "pluginloader")
set(EXE "run")

add_subdirectory(src)

add_executable(${EXE} main.cpp)
target_include_directories(${EXE} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${EXE} PRIVATE ${LIB} fmt)
