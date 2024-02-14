cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)

#set( CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe" )
set( CMAKE_CXX_COMPILER "/usr/bin/g++" )

project(Course_Project )

set(CMAKE_CXX_STANDART 17)

# add_subdirectory(external/sfml)
# include_directories(texture)

include_directories(
    # "${CMAKE_CURRENT_SOURCE_DIR}/vendor/candle/include"
    # "${CMAKE_CURRENT_SOURCE_DIR}/vendor/tmxlite/include"
    # "${CMAKE_CURRENT_SOURCE_DIR}/vendor/effolkronium/include"
    # "${CMAKE_CURRENT_SOURCE_DIR}/src/bagla-engine/gui/"
    # "${CMAKE_CURRENT_SOURCE_DIR}/src/bagla-engine/audio/"
    # "${CMAKE_CURRENT_SOURCE_DIR}/src/bagla-engine/map/"
    # "${CMAKE_CURRENT_SOURCE_DIR}/src/bagla-engine/parallax/"
    # "${CMAKE_CURRENT_SOURCE_DIR}/src/bagla-engine/resource/"
    # "${CMAKE_CURRENT_SOURCE_DIR}/src/bagla-engine/state/"
    # "${CMAKE_CURRENT_SOURCE_DIR}/src/bagla-engine/animation/"
    # "${CMAKE_CURRENT_SOURCE_DIR}/src/bagla-engine/particles/"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/"
)


file(GLOB SOURCES
    src/*.h
    src/*.cpp
    # src/bagla-engine/audio/*.h
    # src/bagla-engine/audio/*.cpp
    # src/bagla-engine/gui/*.h
    # src/bagla-engine/gui/*.cpp
    # src/bagla-engine/map/*.h
    # src/bagla-engine/map/*.cpp
    # src/bagla-engine/resource/*.h
    # src/bagla-engine/resource/*.cpp
    # src/bagla-engine/parallax/*.h
    # src/bagla-engine/parallax/*.cpp
    # src/bagla-engine/state/*.h
    # src/bagla-engine/animation/*.h
    # src/bagla-engine/animation/*.cpp
    # src/bagla-engine/particles/*.h
    # src/bagla-engine/particles/*.cpp
)

add_executable(Course_Project ${SOURCES})


# add_executable(
#     ${PROJECT_NAME} 
#     main.cpp

#     src/Game/Game.h
#     src/Game/Game.cpp

#     src/Game/GameState.h
#     src/Game/GameState.cpp

#     src/GUI/Button/Button.h
#     src/GUI/Button/Button.cpp

#     src/GUI/Game_interface/Game_interface.h
#     src/GUI/Game_interface/Game_interface.cpp

#     src/GUI/Health_Bar/Health_Bar.h
#     src/GUI/Health_Bar/Health_Bar.cpp

#     src/GUI/Menu/Menu.h
#     src/GUI/Menu/Menu.cpp

#     src/GUI/Menu/Label.h
#     src/GUI/Menu/Label.cpp

#     src/GUI/Menu/Widget.h

#     src/GUI/Number_of_Coins/Number_of_Coins.h
#     src/GUI/Number_of_Coins/Number_of_Coins.cpp

#     src/Level_source/Bonus/Bonus.h
#     src/Level_source/Bonus/Bonus.cpp

#     src/Level_source/Enemy/Enemy.h
#     src/Level_source/Enemy/Enemy.cpp

#     src/Level_source/Levels/Levels.h
#     src/Level_source/Levels/Levels.cpp

#     src/Level_source/Platforms/Platforms.h
#     src/Level_source/Platforms/Platforms.cpp

#     src/Player/Player/Player.h
#     src/Player/Player/Player.cpp

#     src/Player/Physics/Physics.h
#     src/Player/Physics/Physics.cpp

#     src/Player/Health_Points/Health_Points.h
#     src/Player/Health_Points/Health_Points.cpp

#     src/Player/Hitbox/Hitbox.h
#     src/Player/Hitbox/Hitbox.cpp

#     src/stdafx/stdafx.h
#     src/stdafx/stdafx.cpp

#     src/State/State.h

#     src/resource/FontHolder.h
#     src/resource/MapHolder.h
#     src/resource/MusicHolder.h
#     src/resource/ResourceHolder.h
#     src/resource/ResourceManager.cpp
#     src/resource/ResourceManager.h
#     src/resource/SoundBufferHolder.h
#     src/resource/TextureHolder.h
#     src/resource/FontHolder.h
#     src/resource/FontHolder.h
#     src/resource/FontHolder.h

#     )

# target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-audio sfml-network sfml-system)
target_link_libraries(Course_Project PRIVATE sfml-system sfml-network sfml-graphics sfml-window sfml-audio)


target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL  OFF CACHE BOOL "" FORCE)






# set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

# add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_directory
#     ${CMAKE_SOURCE_DIR}/res/ $<TARGET_FILE_DIR:${PROJECT_NAME}>/res/)
