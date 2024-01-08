CXX = g++
CXXFLAGS = -std=c++20

LIB_DIR = lib
TEST_DIR = Test
BUILD_DIR = build

SRC_FILES = $(wildcard $(LIB_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(LIB_DIR)/%.cpp, $(LIB_DIR)/%.o, $(SRC_FILES))

all: $(BUILD_DIR)/isZero_Test

$(LIB_DIR)/%.o: $(LIB_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/isZero_Test: $(TEST_DIR)/isZero_Test.cpp $(OBJ_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@ $(OBJ_FILES)

clean:
	rm -f $(OBJ_FILES)
	rm -rf $(BUILD_DIR)
