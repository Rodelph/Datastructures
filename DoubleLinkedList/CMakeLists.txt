add_library(DoubleLinkedList
			src/DoubleLinkedList.hpp
			src/testDLL.cpp
			)

target_include_directories(DoubleLinkedList PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
set(CPACK_PROJECT_NAME DS)
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

add_executable(DLL src/testDLL.cpp)
target_link_libraries(DLL PUBLIC DoubleLinkedList)