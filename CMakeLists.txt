cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

#set( CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe" )
set( CMAKE_CXX_COMPILER "/usr/bin/g++" )

set( PROJECT_NAME Course_Project )
project(${PROJECT_NAME} )

# include(PrintVariables.cmake)

# print_variables()

set(CMAKE_CXX_STANDART 17)

# add_subdirectory(external/sfml)
# include_directories(texture)

add_executable(
    ${PROJECT_NAME} 
    main.cpp

    src/Level_source/Bonus/Bonus.h
    src/Level_source/Bonus/Bonus.cpp

    src/Level_source/Enemy/Enemy.h
    src/Level_source/Enemy/Enemy.cpp

    src/Level_source/Levels/Levels.h
    src/Level_source/Levels/Levels.cpp

    src/Level_source/Platforms/Platforms.h
    src/Level_source/Platforms/Platforms.cpp
    
    src/GUI_source/Game_interface/Game_interface.h
    src/GUI_source/Game_interface/Game_interface.cpp

    src/GUI_source/Health_Bar/Health_Bar.h
    src/GUI_source/Health_Bar/Health_Bar.cpp

    src/GUI_source/Number_of_Coins/Number_of_Coins.h
    src/GUI_source/Number_of_Coins/Number_of_Coins.cpp

    src/Player_source/Player/Player.h
    src/Player_source/Player/Player.cpp

    src/Player_source/Physics/Physics.h
    src/Player_source/Physics/Physics.cpp

    src/Player_source/Health_Points/Health_Points.h
    src/Player_source/Health_Points/Health_Points.cpp

    src/Game/Game.h
    src/Game/Game.cpp

    src/GUI_source/Primary_Menu/Primary_Menu.h
    src/GUI_source/Primary_Menu/Primary_Menu.cpp

    src/stdafx/stdafx.h
    src/stdafx/stdafx.cpp

    src/Window/Window.h
    src/Window/Window.cpp

)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-audio sfml-network sfml-system)


target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL  OFF CACHE BOOL "" FORCE)






# set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

# add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_directory
#     ${CMAKE_SOURCE_DIR}/res/ $<TARGET_FILE_DIR:${PROJECT_NAME}>/res/)
