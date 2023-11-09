cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

#set( CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe" )
set( PROJECT_NAME Course_Project )
project(${PROJECT_NAME} )

# include(PrintVariables.cmake)

# print_variables()

set(CMAKE_CXX_STANDART 17)

add_subdirectory(external/sfml)

add_executable(
    ${PROJECT_NAME} 
    main.cpp
    src/Bonus/Bonus.h
    src/Buttom/Buttom.h
    src/Enemy/Enemy.h
    src/Game/Game.h
    src/Levels/Levels.h
    src/Game_interface/Game_interface.h
    src/Health_points/Health_points.h
    src/Menu/Menu.h
    src/Physics/Physics.h
    src/Player/Player.h
    src/stdafx/stdafx.h
    src/Window/Window.h

    src/Buttom/Buttom.cpp
    src/Enemy/Enemy.cpp
    src/Game/Game.cpp
    src/Levels/Levels.cpp
    src/Game_interface/Game_interface.cpp
    src/Health_points/Health_points.cpp
    src/Menu/Menu.cpp
    src/Physics/Physics.cpp
    src/Player/Player.cpp
    src/stdafx/stdafx.cpp
    src/Window/Window.cpp
    src/Bonus/Bonus.cpp

    )


target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL  OFF CACHE BOOL "" FORCE)



target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-audio sfml-network sfml-system)



# set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

# add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_directory
#     ${CMAKE_SOURCE_DIR}/res/ $<TARGET_FILE_DIR:${PROJECT_NAME}>/res/)
