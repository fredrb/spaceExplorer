cmake_minimum_required(VERSION 3.6)
project(star_explorer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lglut -lGLU -lGL -std=c++11")

set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${dir}/bin")

set(SOURCE_FILES main.cpp src/Game.cpp src/Game.h
        src/GameCallback.h src/GameCallback.cpp
        src/file/IFileReader.h
        src/file/PTMFileReader.cpp src/file/PTMFileReader.h
        src/common/SpriteLoader.cpp src/common/SpriteLoader.h
        src/render/Image.cpp src/render/Image.h
        src/render/Animation.cpp src/render/Animation.h src/render/Layer.cpp src/render/Layer.h src/GameObject.cpp src/GameObject.h src/game/Movement.cpp src/game/Movement.h
        src/render/Text.cpp src/render/Text.h
        src/game/Timer.cpp src/game/Timer.h
        src/screen/Play.cpp src/screen/Play.h
        src/screen/Start.cpp src/screen/Start.h
        src/screen/GameOver.cpp src/screen/GameOver.h)

add_executable(star_explorer ${SOURCE_FILES})
