CC = g++
OUT = -o bin/run

SRC = src/file/*.cpp \
      src/render/*.cpp \
      src/game/*.cpp \
      src/common/*.cpp \
      src/screen/*.cpp \
      src/*.cpp

MAIN = main.cpp

_FLAGS_ = --std=c++11 -lGLU -lGL -lglut

build :
	$(CC) $(SRC) $(MAIN) $(OUT) $(_FLAGS_)

.PHONY : build
