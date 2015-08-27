SRC = src
INCLUDE = include
BIN = bin
TEST = test

CC = g++
CXXFLAGS += -std=c++11 -Wall
CXXFLAGS += -O3 -DNDEBUG
CXXFLAGS += -lgsl
CXXFLAGS += -lm
CXXOPENMP = -fopenmp
CLANG := $(shell g++ -v 2>&1 | grep clang | cut -d " " -f 2)
ifeq ($(CLANG), LLVM)
	CXXOPENMP = 
	CXXFLAGS += -DNOMP
endif

LDFLAGS +=
LIBS +=



OBJ = $(BIN)/vro.o $(BIN)/variant.o $(BIN)/info.o
all: 
	make obj
	make test_reader
	make test_splitter
	make test_variant
	make test_metainfo

obj:
	$(CC) -c -I/usr/local/Cellar/gsl/1.16/include/gsl -I$(INCLUDE)/variant_file_reader.h 		-o $(BIN)/vro.o 			$(SRC)/variant_file_reader.cpp
	$(CC) -c -I/usr/local/Cellar/gsl/1.16/include/gsl -I$(INCLUDE)/variant.h 					-o $(BIN)/variant.o			$(SRC)/variant.cpp
	$(CC) -c -I/usr/local/Cellar/gsl/1.16/include/gsl -I$(INCLUDE)/info.h 						-o $(BIN)/info.o			$(SRC)/info.cpp

clean:
	rm -f $(BIN)/* 

test_reader: $(OBJ)
	$(CC)  $(CXXFLAGS) $(OBJ) -I/usr/local/Cellar/gsl/1.16/include/gsl $(TEST)/reader.cpp 		-o $(BIN)/test_reader

test_splitter: $(OBJ)
	$(CC)  $(CXXFLAGS) $(OBJ) -I/usr/local/Cellar/gsl/1.16/include/gsl $(TEST)/splitString.cpp 	-o $(BIN)/test_splitter

test_variant: $(OBJ)
	$(CC)  $(CXXFLAGS) $(OBJ) -I/usr/local/Cellar/gsl/1.16/include/gsl $(TEST)/variant.cpp 		-o $(BIN)/test_variant

test_metainfo: $(OBJ)
	$(CC)  $(CXXFLAGS) $(OBJ) -I/usr/local/Cellar/gsl/1.16/include/gsl $(TEST)/metainfo.cpp		-o $(BIN)/test_metainfo
