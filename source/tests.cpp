#include "gtest/gtest.h"
#include "../tests/armor_tests.hpp"
#include "../tests/weapon_tests.hpp"
#include "../tests/consumable_tests.hpp"
#include "../tests/inventory_tests.hpp"
#include "../tests/character_tests.hpp"
#include "../tests/enemy_tests.hpp"
#include "../tests/factory_tests.hpp"
#include "../tests/game_controller_tests.hpp"
#include "gamecontroller.cpp"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
