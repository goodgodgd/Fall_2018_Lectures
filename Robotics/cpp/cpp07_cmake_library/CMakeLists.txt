cmake_minimum_required(VERSION 3.0)

# 프로젝트 명과 버전 설정
project("myqt5" VERSION 1.1)

# 빌드 옵션 설정
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_BUILD_TYPE Release)
# set(CMAKE_VERBOSE_MAKEFILE true)
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/devel)
message("install prefix ${CMAKE_INSTALL_PREFIX}")
# http://egloos.zum.com/program/v/1373351
# https://stackoverflow.com/questions/5311515/gcc-fpic-option
# https://devanix.tistory.com/169
add_compile_options(-Wall -std=c++14 -O2 -fPIC)

# 외부 라이브러리 설정
find_package(Qt5Core REQUIRED)
message("=== find package(Qt5Core) generated Qt5Core_DIR=${Qt5Core_DIR}, Qt5Core_CONFIG=${Qt5Core_CONFIG}")
message("=== find package(Qt5Core) loaded Qt5Core_INCLUDE_DIRS=${Qt5Core_INCLUDE_DIRS}")
include_directories(${Qt5Core_INCLUDE_DIRS})
# include_directories("/opt/Qt5.11.1/5.11.1/gcc_64/include")
# link_directories("/opt/Qt5.11.1/5.11.1/gcc_64/lib")
link_libraries(Qt5Core)

# source, target 설정
set(LIB_SRC_FILE myqt5.cpp)
set(OUTPUT_SHARED_LIB "${CMAKE_PROJECT_NAME}")
set(OUTPUT_STATIC_LIB "${CMAKE_PROJECT_NAME}_stat")
set(OUTPUT_EXEC "${CMAKE_PROJECT_NAME}_app")

# target 추가
add_library(${OUTPUT_SHARED_LIB} SHARED ${LIB_SRC_FILE})
add_library(${OUTPUT_STATIC_LIB} STATIC ${LIB_SRC_FILE})
# https://stackoverflow.com/questions/17511496/how-to-create-a-shared-library-with-cmake
set_target_properties(${OUTPUT_SHARED_LIB} PROPERTIES VERSION ${PROJECT_VERSION} PUBLIC_HEADER myqt5.h)
set_target_properties(${OUTPUT_STATIC_LIB} PROPERTIES VERSION ${PROJECT_VERSION} PUBLIC_HEADER myqt5.h)

link_libraries(${OUTPUT_SHARED_LIB})
add_executable(${OUTPUT_EXEC} main.cpp)

install(TARGETS ${OUTPUT_SHARED_LIB} ${OUTPUT_STATIC_LIB} ${OUTPUT_EXEC}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION include
        )

