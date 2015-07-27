include_directories (${inpreader_SOURCE_DIR}/src/inpreader)

set (lib_SOURCES
    keywords/node.cpp
    keywords/basekeyword.cpp
    keywords/heading.cpp
    keywords/keyword.cpp
    parser.cpp
    tokenizer.cpp
    tokens/token.cpp
    tokens/comment.cpp
    tokens/dataline.cpp
    tokens/keyword.cpp
)
add_library (inpreader ${lib_SOURCES})
