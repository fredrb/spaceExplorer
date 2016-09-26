CC = g++
OUT = -o bin/run

SRC = src/**/*.cpp
MAIN = main.cpp

_FLAGS_ = --std=c++11 -lGLU -lGL -lglut

build :
	g++ ./src/**/*.cpp main.cpp -o bin/run --std=c++14 -lglut -lGLU -lGL

build_test:
	$(CC) $(SRC) $(MAIN) $(OUT) $(_FLAGS_)

.PHONY : build
