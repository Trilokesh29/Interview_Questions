cmake_minimum_required(VERSION 3.10.2)

project(RockPaperScissors)


set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")

set(INTERFACE_FILES
  View/Interface/IView.h
  Controller/Interface/IController.h
)

set(IMPL_FILES
  View/Src/View.h
  View/Src/View.cpp
  Controller/Src/Controller.h
  Controller/Src/Controller.cpp
)

include_directories(
    Controller/Interface
    View/Interface
    .
)

add_executable(${PROJECT_NAME}
  main.cpp
  ${INTERFACE_FILES}
  ${IMPL_FILES}
)
