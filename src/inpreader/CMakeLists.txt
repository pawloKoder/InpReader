include_directories (${inpreader_SOURCE_DIR}/src/inpreader)

set (lib_SOURCES
    keywords/node.cpp
    tokenizer.cpp
    tokens/token.cpp
    tokens/comment.cpp
    tokens/dataline.cpp
    tokens/keyword.cpp
)
add_library (inpreader ${lib_SOURCES})
