CXX = g++
CXXFLAGS = -Wall -g -std=c++20 -I$(INC_DIR)

SRC_DIR = cpp
INC_DIR = hpp
OBJ_DIR = build

TARGET = ChiBebinam

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all: $(TARGET)
$(TARGET): $(OBJS)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(wildcard $(INC_DIR)/*.hpp)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
