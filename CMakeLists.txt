cmake_minimum_required(VERSION 3.15)
project(SimpleVideoProcessor VERSION 1.0.0 LANGUAGES CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 设置编译选项
if(MSVC)
    add_compile_options(/W4 /utf-8)
    # 注意: 如果遇到特定的C4996警告，建议针对性处理而不是全局禁用
    # add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 查找线程库
find_package(Threads REQUIRED)

# ================================================================================
# xlog 日志库（动态库）
# ================================================================================
add_library(xlog SHARED
    src/xlog/logger.cpp
    src/xlog/LogFac.cpp
    src/xlog/LogConsoleOutput.cpp
    src/xlog/LogFileOutput.cpp
    src/xlog/LogFileThreadOutPut.cpp
    src/xlog/xlog_format.cpp
    src/xlog/XConfig.cpp
    src/xlog/user_input.cpp
    src/xlog/xexec.cpp
    src/xlog/xdir.cpp
)

# 设置xlog的包含目录
target_include_directories(xlog 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/xlog>
        $<INSTALL_INTERFACE:include>
)

# xlog需要导出符号的宏定义
target_compile_definitions(xlog PRIVATE XLOG_EXPORTS)

# 链接线程库
target_link_libraries(xlog PRIVATE Threads::Threads)

# 设置xlog的输出名称
set_target_properties(xlog PROPERTIES
    OUTPUT_NAME "xlog"
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

# ================================================================================
# xvideo_edit 视频处理程序
# ================================================================================
add_executable(xvideo_edit
    src/xvideo_edit/xvideo_edit.cpp
    src/xvideo_edit/fftask.cpp
    src/xvideo_edit/xtask_factory.cpp
    src/xvideo_edit/xvideo_input.cpp
)

# 链接xlog库
target_link_libraries(xvideo_edit PRIVATE xlog)

# 设置包含目录
target_include_directories(xvideo_edit PRIVATE 
    src/xlog 
    src/xvideo_edit
)

# ================================================================================
# test_log 测试程序
# ================================================================================
add_executable(test_log
    src/test_log/test_log.cpp
)

target_link_libraries(test_log PRIVATE xlog)
target_include_directories(test_log PRIVATE src/xlog)

# ================================================================================
# 安装配置
# ================================================================================
install(TARGETS xlog xvideo_edit test_log
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

# 安装头文件
install(DIRECTORY src/xlog/
    DESTINATION include/xlog
    FILES_MATCHING PATTERN "*.h"
)

# ================================================================================
# 可选：启用测试
# ================================================================================
option(BUILD_TESTS "Build tests" OFF)
if(BUILD_TESTS)
    enable_testing()
    # 这里可以添加Google Test或其他测试框架
endif()

# ================================================================================
# 打印配置信息
# ================================================================================
message(STATUS "")
message(STATUS "========================================")
message(STATUS "  ${PROJECT_NAME} v${PROJECT_VERSION}")
message(STATUS "========================================")
message(STATUS "  CMAKE_BUILD_TYPE    : ${CMAKE_BUILD_TYPE}")
message(STATUS "  CMAKE_CXX_COMPILER  : ${CMAKE_CXX_COMPILER}")
message(STATUS "  CMAKE_CXX_STANDARD  : ${CMAKE_CXX_STANDARD}")
message(STATUS "  BUILD_TESTS         : ${BUILD_TESTS}")
message(STATUS "========================================")
message(STATUS "")
