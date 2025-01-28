add_executable(example2 src/main.cpp)

# target_link_libraries(example1 PRIVATE engine)

# Set the output directory for this executable
set_target_properties(example2 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)
