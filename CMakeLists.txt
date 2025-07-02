cmake_minimum_required(VERSION 3.5...4.0)
project(tgbm_bot_run LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
include(FetchContent)
FetchContent_Declare(
  TGBM
  GIT_REPOSITORY https://github.com/bot-motherlib/TGBM.git
)
FetchContent_MakeAvailable(TGBM)

add_executable(bot_exec 
src/pass_generator.h
src/pass_generator.cpp
  src/main.cpp 
)
target_link_libraries(bot_exec PRIVATE tgbmlib)

add_custom_target(run
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target bot_exec
  COMMAND bot_exec ${BOT_TOKEN_ARG}
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  COMMENT "Building and launching bot_exec"
  DEPENDS bot_exec
)