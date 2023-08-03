include(FetchContent)
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 87c066a35b7cc70bb7d438a543c8b49b577e61f4
)
FetchContent_MakeAvailable(fmt)

add_executable(cebal main.cpp)
add_subdirectory(core)
target_link_libraries(cebal PUBLIC core)
target_link_libraries(cebal PUBLIC fmt)
target_include_directories(
    cebal
    PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/core"
)
