add_library(core STATIC thread_pool.cpp)
target_link_libraries(core PUBLIC fmt)
