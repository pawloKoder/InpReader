include_directories (${inpreader_SOURCE_DIR}/src/inpreader)

set (lib_SOURCES
    keywords/assembly.cpp
    keywords/basekeyword.cpp
    keywords/boundary.cpp
    keywords/density.cpp
    keywords/elastic.cpp
    keywords/element.cpp
    keywords/elementset.cpp
    keywords/heading.cpp
    keywords/instance.cpp
    keywords/keyword.cpp
    keywords/material.cpp
    keywords/node.cpp
    keywords/nodeset.cpp
    keywords/part.cpp
    keywords/preprint.cpp
    keywords/static.cpp
    keywords/step.cpp
    keywords/surface.cpp
    parser.cpp
    tokenizer.cpp
    tokens/token.cpp
    tokens/comment.cpp
    tokens/dataline.cpp
    tokens/keyword.cpp
)
add_library (inpreader ${lib_SOURCES})
