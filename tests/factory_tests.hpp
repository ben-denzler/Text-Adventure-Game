#ifndef FACTORY_TESTS_HPP
#define FACTORY_TESTS_HPP

#include "gtest/gtest.h"
#include "../header/factory.hpp"
#include "../header/entity.hpp"

TEST(FactoryTests, RoguemouseCreation) {
    AbstractFactory* my_entity_factory = new EntityFactory();
}

TEST(FactoryTests, SwordsmouseCreation) {
    AbstractFactory* my_entity_factory = new EntityFactory();
}

TEST(FactoryTests, MonkmouseCreation) {
    AbstractFactory* my_entity_factory = new EntityFactory();
    Entity* enemy1 = my_entity_factory->createCharacter("Mickey Mouse", 3);
}

TEST(FactoryTests, EnemyCreation) {
    AbstractFactory* entityFactory = new EntityFactory();
    Entity* enemy1 = entityFactory->createEnemy(2);
}

#endif