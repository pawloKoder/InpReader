include_directories (${inpreader_SOURCE_DIR}/src/inpreader)

set (lib_SOURCES
    keywords/node.cpp
)
add_library (inpreader ${lib_SOURCES})
