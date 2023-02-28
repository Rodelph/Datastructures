add_library(LinkedList
            src/LinkedList.hpp
            src/testLL.cpp
            )

target_include_directories(LinkedList PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "Export compile commands")
set(CPACK_PROJECT_NAME DS)
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

add_executable(DSLL src/testLL.cpp)

target_link_libraries(DSLL PUBLIC LinkedList)