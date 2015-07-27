include_directories (${inpreader_SOURCE_DIR}/src/inpreader)

set (lib_SOURCES
    keywords/basekeyword.cpp
    keywords/element.cpp
    keywords/heading.cpp
    keywords/keyword.cpp
    keywords/node.cpp
    parser.cpp
    tokenizer.cpp
    tokens/token.cpp
    tokens/comment.cpp
    tokens/dataline.cpp
    tokens/keyword.cpp
)
add_library (inpreader ${lib_SOURCES})
