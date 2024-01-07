CXX = g++
CXXFLAGS = -std=c++20

##Comment out the following two lines if you are not using Homebrew
CRYPTOPP_INCLUDE_DIR = /opt/homebrew/Cellar/cryptopp/8.9.0/include
CRYPTOPP_LIB_DIR = /opt/homebrew/Cellar/cryptopp/8.9.0/lib

LIB_DIR = lib
TEST_DIR = Test
BUILD_DIR = build

SRC_FILES = $(wildcard $(LIB_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(LIB_DIR)/%.cpp, $(LIB_DIR)/%.o, $(SRC_FILES))

all: $(BUILD_DIR)/Keccak_Test

$(LIB_DIR)/%.o: $(LIB_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(CRYPTOPP_INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/Keccak_Test: $(TEST_DIR)/Keccak_Test.cpp $(OBJ_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(CRYPTOPP_INCLUDE_DIR) $< -o $@ $(OBJ_FILES) -L$(CRYPTOPP_LIB_DIR) -lcryptopp

clean:
	rm -f $(OBJ_FILES)
	rm -rf $(BUILD_DIR)
