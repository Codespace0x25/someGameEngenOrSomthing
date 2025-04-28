CC = clang++
BUILD = build
SRC = src
LIB_SRC = $(SRC)/lib
COMP_SRC = $(SRC)/ComponetLib
TARGET = $(BUILD)/engen.Linux
TARGET_WIN = $(BUILD)/engen.exe

CXXFLAGS = -O0 -g -Wall -std=c++17 -I$(SRC) 
SDL_LIBS := $(shell sdl2-config --cflags) $(shell sdl2-config --libs) -lSDL2_ttf -lSDL2_image

LIB_CPP = $(wildcard $(LIB_SRC)/*.cpp)
Game_CPP = $(wildcard $(SRC)/Game/*.cpp)
GameOBJ_CPP = $(wildcard $(SRC)/GameObject/*.cpp)
LIBSTD_CPP = $(wildcard $(LIB_SRC)/std/*.cpp)
COMP_CPP = $(wildcard $(COMP_SRC)/*.cpp)
MAIN_CPP = $(filter-out $(LIB_CPP) $(COMP_CPP), $(wildcard $(SRC)/*.cpp))

OBJ = $(patsubst $(SRC)/%.cpp,$(BUILD)/%.o,$(MAIN_CPP) $(LIB_CPP) $(LIBSTD_CPP) $(COMP_CPP) $(Game_CPP) $(GameOBJ_CPP))

.PHONY: all linux windows clean test

all: linux

$(BUILD):
	mkdir -p $(BUILD)

linux: $(TARGET)

$(TARGET): $(BUILD) $(OBJ)
	$(CC) $(OBJ) $(CXXFLAGS) $(SDL_LIBS) -o $@

# Compile .cpp to .o
$(BUILD)/%.o: $(SRC)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CXXFLAGS) $(SDL_LIBS) -c $< -o $@

clean:
	rm -rf $(BUILD)

test: $(TARGET)
	echo "run" | gdb ./$(TARGET)
