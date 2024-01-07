CXX = g++
CXXFLAGS = -std=c++20

## Comment out the following two lines if you are not using Homebrew
CRYPTOPP_INCLUDE_DIR = /opt/homebrew/Cellar/cryptopp/8.9.0/include
CRYPTOPP_LIB_DIR = /opt/homebrew/Cellar/cryptopp/8.9.0/lib

# GMP library directories 
# Comment out the following two lines if you are not using Homebrew
# Update these paths according to your GMP installation
GMP_INCLUDE_DIR = /opt/homebrew/Cellar/gmp/6.3.0/include
GMP_LIB_DIR = /opt/homebrew/Cellar/gmp/6.3.0/lib

LIB_DIR = lib
TEST_DIR = Test
BUILD_DIR = build

SRC_FILES = $(wildcard $(LIB_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(LIB_DIR)/%.cpp, $(LIB_DIR)/%.o, $(SRC_FILES))

all: $(BUILD_DIR)/CalculateBlockTargetHash_Test

$(LIB_DIR)/%.o: $(LIB_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(CRYPTOPP_INCLUDE_DIR) -I$(GMP_INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/CalculateBlockTargetHash_Test: $(TEST_DIR)/CalculateBlockTargetHash_Test.cpp $(OBJ_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(CRYPTOPP_INCLUDE_DIR) -I$(GMP_INCLUDE_DIR) -L$(CRYPTOPP_LIB_DIR) -L$(GMP_LIB_DIR) $< -o $@ $(OBJ_FILES) -lcryptopp -lgmp

clean:
	rm -f $(OBJ_FILES)
	rm -rf $(BUILD_DIR)
