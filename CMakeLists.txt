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
  src/data/data.h
  src/data/data.cpp
  src/utils/utils.h
  src/utils/utils.cpp
  src/utils/formatter.h
  src/utils/formatter.cpp
  src/generator/pass_generator.h
  src/generator/pass_generator.cpp
  src/builder/phrase_builder.h
  src/builder/phrase_builder.cpp
  src/bot/main.cpp
)

target_include_directories(bot_exec PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/data
    ${CMAKE_CURRENT_SOURCE_DIR}/src/utils
    ${CMAKE_CURRENT_SOURCE_DIR}/src/generator
    ${CMAKE_CURRENT_SOURCE_DIR}/src/builder
    ${CMAKE_CURRENT_SOURCE_DIR}/src/bot
)

target_link_libraries(bot_exec PRIVATE tgbmlib)

add_custom_target(run
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target bot_exec
  COMMAND bot_exec ${BOT_TOKEN_ARG}
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  COMMENT "Building and launching bot_exec"
  DEPENDS bot_exec
)