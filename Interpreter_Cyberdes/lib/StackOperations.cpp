// StackOperations.cpp
#include "StackOperations.h"

int getLastStackValue(const std::vector<int>& stack) {
    if (!stack.empty()) {
        return stack.back();
    }
    return 0;
}
