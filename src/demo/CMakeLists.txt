include_directories (${inpreader_SOURCE_DIR}/src/inpreader)

set (demo_SOURCES
    main.cpp
)

add_executable (inpreaderdemo ${demo_SOURCES})
target_link_libraries (inpreaderdemo inpreader)