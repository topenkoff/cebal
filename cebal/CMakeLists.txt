add_executable(cebal main.cpp)
add_subdirectory(core)
target_link_libraries(cebal PUBLIC core)
target_include_directories(
    cebal
    PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/core"
)
