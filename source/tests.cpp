#include "gtest/gtest.h"
#include "../tests/weapon_tests.hpp"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}