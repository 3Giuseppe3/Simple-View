# # Compiler and flags

# CC = g++
# CFLAGS = -O0 -g3 -Wall -c -fmessage-length=0
# TARGET = SimpleView.exe

# # Directories
# SRC_DIR = src
# BUILD_DIR = build
# BIN_DIR = bin

# # Executable name

# CURVE_DIR := $(SRC_DIR)/curve
# GLSL_DIR := $(SRC_DIR)/glsl
# PIXMAP_DIR := $(SRC_DIR)/pixmap
# SURFACE_DIR := $(SRC_DIR)/surface
# SOLAR_DIR := $(SRC_DIR)/solar

# SRCS = $(wildcard $(SRC_DIR)/*.cpp) \
#        $(wildcard $(CURVE_DIR)/*.cpp) \
#        $(wildcard $(GLSL_DIR)/*.cpp) \
#        $(wildcard $(PIXMAP_DIR)/*.cpp) \
#        $(wildcard $(SURFACE_DIR)/*.cpp) \
#        $(wildcard $(SOLAR_DIR)/*.cpp)


# # Map .cpp -> .o (under build/)
# OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# # Default target
# all: $(TARGET)

# $(TARGET): $(BUILD_DIR) $(OBJS)
# 	$(CC) -o $(TARGET) $(OBJS) -lfreeglut -lopengl32 -lglu32 -lglew32

# $(BUILD_DIR):
# 	mkdir $(BUILD_DIR)

# # Compile step
# $(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
# 	@mkdir -p $(dir $@)
# 	$(CC) $(CFLAGS ) -c $< -o $@


# .PHONY: run
# run: $(TARGET)
# 	./$(TARGET)

# # Clean up build artifacts
# clean:
# 	rm -rf $(BUILD_DIR)
# 	rm $(TARGET)

# # Phony targets
# .PHONY: all clean


# Makefile for compiling all .cpp files in src and subfolders
CXX = g++
CXXFLAGS = -O0 -g3 -Wall -c -fmessage-length=0
TARGET = SimpleView.exe

# Directories
SRC_DIR = src
BUILD_DIR = build
CURVE_DIR := $(SRC_DIR)/curve
GLSL_DIR := $(SRC_DIR)/glsl
PIXMAP_DIR := $(SRC_DIR)/pixmap
SURFACE_DIR := $(SRC_DIR)/surface
SOLAR_DIR := $(SRC_DIR)/solar

SRCS = $(wildcard $(SRC_DIR)/*.cpp) \
       $(wildcard $(CURVE_DIR)/*.cpp) \
       $(wildcard $(GLSL_DIR)/*.cpp) \
       $(wildcard $(PIXMAP_DIR)/*.cpp) \
       $(wildcard $(SURFACE_DIR)/*.cpp) \
       $(wildcard $(SOLAR_DIR)/*.cpp)

# Map .cpp -> .o (under build/)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Phony targets
.PHONY: all run clean

# Default target
all: $(TARGET)

$(TARGET): $(BUILD_DIR) $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) -lfreeglut -lopengl32 -lglu32 -lglew32

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

# Compile step
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: run
run: $(TARGET)
	./$(TARGET)

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR)
	rm $(TARGET)
