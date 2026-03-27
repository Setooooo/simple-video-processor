cmake_minimum_required(VERSION 3.21)

project(simple_video_processor VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(LESSON_CODE_BUILD_SHARED_XLOG "Build xlog as a shared library" ON)
option(LESSON_CODE_BUILD_TEST_LOG "Build the test_log sample executable" ON)

set(PROJECT_OUTPUT_BIN_DIR "${CMAKE_BINARY_DIR}/bin")
set(PROJECT_OUTPUT_LIB_DIR "${CMAKE_BINARY_DIR}/lib")

set(XLOG_SOURCES
  src/xlog/LogConsoleOutput.cpp
  src/xlog/LogFac.cpp
  src/xlog/LogFileOutput.cpp
  src/xlog/LogFileThreadOutPut.cpp
  src/xlog/XConfig.cpp
  src/xlog/logger.cpp
  src/xlog/user_input.cpp
  src/xlog/xdir.cpp
  src/xlog/xexec.cpp
  src/xlog/xlog.cpp
  src/xlog/xlog_format.cpp
)

set(XLOG_HEADERS
  src/xlog/LogConsoleOutput.h
  src/xlog/LogFac.h
  src/xlog/LogFileOutput.h
  src/xlog/LogFileThreadOutPut.h
  src/xlog/XConfig.h
  src/xlog/logger.h
  src/xlog/log_format.h
  src/xlog/log_output.h
  src/xlog/user_input.h
  src/xlog/xdir.h
  src/xlog/xexec.h
  src/xlog/xlog.h
  src/xlog/xlog_format.h
)

if(LESSON_CODE_BUILD_SHARED_XLOG)
  add_library(xlog SHARED ${XLOG_SOURCES} ${XLOG_HEADERS})
  target_compile_definitions(xlog PRIVATE XLOG_EXPORTS)
else()
  add_library(xlog STATIC ${XLOG_SOURCES} ${XLOG_HEADERS})
  target_compile_definitions(xlog PUBLIC XLOG_STATIC)
endif()

target_include_directories(xlog PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/xlog")

set_target_properties(xlog PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_OUTPUT_LIB_DIR}"
  LIBRARY_OUTPUT_DIRECTORY "${PROJECT_OUTPUT_BIN_DIR}"
  RUNTIME_OUTPUT_DIRECTORY "${PROJECT_OUTPUT_BIN_DIR}"
)

add_executable(xvideo_edit
  src/xvideo_edit/fftask.cpp
  src/xvideo_edit/xtask_factory.cpp
  src/xvideo_edit/xvideo_edit.cpp
  src/xvideo_edit/xvideo_input.cpp
  src/xvideo_edit/fftask.h
  src/xvideo_edit/xtask.h
  src/xvideo_edit/xtask_factory.h
  src/xvideo_edit/xvideo_input.h
)

target_link_libraries(xvideo_edit PRIVATE xlog)

set_target_properties(xvideo_edit PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${PROJECT_OUTPUT_BIN_DIR}"
)

if(LESSON_CODE_BUILD_TEST_LOG)
  add_executable(test_log
    src/test_log/test_log.cpp
  )

  target_link_libraries(test_log PRIVATE xlog)

  set_target_properties(test_log PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_OUTPUT_BIN_DIR}"
  )
endif()
