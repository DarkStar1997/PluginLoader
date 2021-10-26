set(SOURCE_LIST
    PluginLoader.cpp
    )

add_library(${LIB} SHARED ${SOURCE_LIST})
target_include_directories(${LIB} PRIVATE ${PluginTest_SOURCE_DIR}/include)
target_link_libraries(${LIB} PRIVATE dl)
