#ifndef FACTORY_TESTS_HPP
#define FACTORY_TESTS_HPP

#include "gtest/gtest.h"
#include "../header/factory.hpp"
#include "../header/entity.hpp"

TEST(FactoryTests, RoguemouseCreation) {
    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    AbstractFactory* my_entity_factory = new EntityFactory();
    Entity* character1 = my_entity_factory->createCharacter("Benjamin", 1);
    
    EXPECT_TRUE(character1->getName() == "Benjamin");
    EXPECT_TRUE(character1->getType() == "Roguemouse");
    EXPECT_TRUE(character1->getHealth() == 100);
    EXPECT_TRUE(character1->getAttack() == 20);
    EXPECT_TRUE(character1->getDefense() == 5);
    ASSERT_TRUE(character1->getInventory() != nullptr);
    EXPECT_TRUE(character1->getInventory()->getSize() == 3);
    ASSERT_TRUE(character1->getCurrentArmor() != nullptr);
    EXPECT_TRUE(character1->getCurrentArmor()->getName() == "Leather Elbowpads");
    ASSERT_TRUE(character1->getCurrentWeapon() != nullptr);
    EXPECT_TRUE(character1->getCurrentWeapon()->getName() == "Sharpened Spoon");

    std::cout.rdbuf(sbuf);
}

TEST(FactoryTests, SwordsmouseCreation) {
    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    AbstractFactory* my_entity_factory = new EntityFactory();
    Entity* character1 = my_entity_factory->createCharacter("ADD NAME", 2);     // Pass in name and type (user choice)
    EXPECT_TRUE(character1->getName() == "ADD NAME");
    EXPECT_TRUE(character1->getType() == "Swordmouse");
    EXPECT_TRUE(character1->getHealth() == 50);
    EXPECT_TRUE(character1->getAttack() == 75);
    EXPECT_TRUE(character1->getDefense() == 10);
    ASSERT_TRUE(character1->getInventory() != nullptr);
    EXPECT_TRUE(character1->getInventory()->getSize() == 3);
    ASSERT_TRUE(character1->getCurrentArmor() != nullptr);
    EXPECT_TRUE(character1->getCurrentArmor()->getName() == "Mini Green Tunic");
    ASSERT_TRUE(character1->getCurrentWeapon() != nullptr);
    EXPECT_TRUE(character1->getCurrentWeapon()->getName() == "Wooden Toothpick");

    std::cout.rdbuf(sbuf);
}

TEST(FactoryTests, MonkmouseCreation) {
    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    AbstractFactory* my_entity_factory = new EntityFactory();
    Entity* character1 = my_entity_factory->createCharacter("Mickey Mouse", 3);
    
    EXPECT_TRUE(character1->getName() == "Mickey Mouse");
    EXPECT_TRUE(character1->getType() == "Monkmouse");
    EXPECT_TRUE(character1->getHealth() == 45);
    EXPECT_TRUE(character1->getAttack() == 30);
    EXPECT_TRUE(character1->getDefense() == 15);
    ASSERT_TRUE(character1->getInventory() != nullptr);
    EXPECT_TRUE(character1->getInventory()->getSize() == 3);
    ASSERT_TRUE(character1->getCurrentArmor() != nullptr);
    EXPECT_TRUE(character1->getCurrentArmor()->getName() == "Torn Robe");
    ASSERT_TRUE(character1->getCurrentWeapon() != nullptr);
    EXPECT_TRUE(character1->getCurrentWeapon()->getName() == "Words of Wisdom");

    std::cout.rdbuf(sbuf);
}

TEST(FactoryTests, EnemyCreation) {
    stringstream buffer;
    streambuf *sbuf = cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());

    AbstractFactory* my_entity_factory = new EntityFactory();
    
    Entity* enemy1 = my_entity_factory->createEnemy(1);
    // EXPECT_TRUE((enemy1->getName() == "Bird") || (enemy1->getName() == "Cat") || (enemy1->getName() == "Dinosaur"));
    EXPECT_TRUE((enemy1->getHealth() >= 5) && (enemy1->getHealth() <= 15));
    EXPECT_TRUE((enemy1->getAttack() >= 5) && (enemy1->getAttack() <= 15));
    EXPECT_TRUE((enemy1->getDefense() >= 5) && (enemy1->getDefense() <= 15));

    Entity* enemy2 = my_entity_factory->createEnemy(2);
    // EXPECT_TRUE((enemy2->getName() == "Bird") || (enemy2->getName() == "Cat") || (enemy2->getName() == "Dinosaur"));
    EXPECT_TRUE(enemy2->getHealth() >= 10 && enemy2->getHealth() <= 30 );
    EXPECT_TRUE(enemy2->getAttack() >= 10 && enemy2->getAttack() <= 30 );
    EXPECT_TRUE(enemy2->getDefense() >= 10 && enemy2->getDefense() <= 30 );

    Entity* enemy3 = my_entity_factory->createEnemy(3);
    // EXPECT_TRUE((enemy3->getName() == "Bird") || (enemy3->getName() == "Cat") || (enemy3->getName() == "Dinosaur"));
    EXPECT_TRUE((enemy3->getHealth() >= 15) && (enemy3->getHealth() <= 45));
    EXPECT_TRUE((enemy3->getAttack() >= 15) && (enemy3->getAttack() <= 45));
    EXPECT_TRUE((enemy3->getDefense() >= 15) && (enemy3->getDefense() <= 45));

    Entity* enemy4 = my_entity_factory->createEnemy(4);
    // EXPECT_TRUE((enemy4->getName() == "Bird") || (enemy4->getName() == "Cat") || (enemy4->getName() == "Dinosaur"));
    EXPECT_TRUE(enemy4->getHealth() >= 20 && enemy4->getHealth() <= 60 );
    EXPECT_TRUE(enemy4->getAttack() >= 20 && enemy4->getAttack() <= 60 );
    EXPECT_TRUE(enemy4->getDefense() >= 20 && enemy4->getDefense() <= 60 );

    Entity* enemy5 = my_entity_factory->createEnemy(5);
    // EXPECT_TRUE((enemy5->getName() == "Bird") || (enemy5->getName() == "Cat") || (enemy5->getName() == "Dinosaur"));
    EXPECT_TRUE(enemy5->getHealth() >= 25 && enemy5->getHealth() <= 75 );
    EXPECT_TRUE(enemy5->getAttack() >= 25 && enemy5->getAttack() <= 75 );
    EXPECT_TRUE(enemy5->getDefense() >= 25 && enemy5->getDefense() <= 75 );
    
    std::cout.rdbuf(sbuf);
}

#endif