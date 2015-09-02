add_subdirectory (inpreader)
add_subdirectory (demo)


find_package(Doxygen)
if(DOXYGEN_FOUND)
	configure_file(${inpreader_SOURCE_DIR}/Doxyfile.in ${inpreader_BINARY_DIR}/Doxyfile @ONLY)
	add_custom_target(doc ${DOXYGEN_EXECUTABLE} ${inpreader_BINARY_DIR}/Doxyfile
	WORKING_DIRECTORY ${inpreader_BINARY_DIR}
)
endif(DOXYGEN_FOUND)