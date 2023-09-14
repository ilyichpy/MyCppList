FLAGS=-lstdc++ -std=c++17
GTEST=-lgtest -lpthread
SOURCE=containers/s21*/*.tpp
HEADERS=containers/s21*/*.h
OBJECTS=objects/s21*.o
TESTS=tests/*_test.cc
EXECUTABLE=container.out
UNAME:=$(shell uname -s) # определяем ОС
ifeq ($(UNAME),Linux ) # Linux
	GXX=g++
	OPEN_CMD=xdg-open # команда для открытия отчета
	ADD_LIB=-lm -lrt -lpthread -lsubunit # дополнительные библиотеки
	BREW=/home/darkwolf/homebrew
	SYSTEM=-D OS_LINUX
endif
ifeq ($(UNAME),Darwin ) # MacOS
	GXX=gcc -Wall -Werror -Wextra -std=c++17
	OPEN_CMD=open
	ADD_LIB=
	BREW=${HOME}/homebrew
	SYSTEM=-D OS_MAC
endif

all: clean test

style:
	clang-format -style=google -i $(TESTS) $(SOURCE) $(HEADERS)

test: clean
	$(GXX) $(SYSTEM) $(TESTS) tests/main.cc -lstdc++ $(ADD_LIB) -o $(EXECUTABLE) $(GTEST)
	./$(EXECUTABLE)

mem: test
	ifeq($(shell uname -s), Linux)
	valgrind -s --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --tool=memcheck ./$(EXECUTABLE)
	else
	leaks --atExit -- ./$(EXECUTABLE)

clean:
	rm -rf *.a objects $(EXECUTABLE) *.o
