add_library(Vector
            src/vector.hpp
            src/test.cpp
            )
            
target_include_directories(Vector PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
set(CPACK_PROJECT_NAME DS)
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

add_executable(DSV src/test.cpp)

target_link_libraries(DSV PUBLIC Vector)