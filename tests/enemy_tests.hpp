#ifndef __ENEMY_TESTS_HPP__
#define __ENEMY_TESTS_HPP__

#include "gtest/gtest.h"
#include "../header/enemy.hpp"

TEST(EnemyTests, EnemyCreationLV1) {
    Entity* enemy = new Enemy("Spooky Skeleton!", 1);
    
    EXPECT_TRUE(enemy->getName() == "Spooky Skeleton!");
    EXPECT_TRUE((enemy->getHealth() >= 5) && (enemy->getHealth() <= 15));
    EXPECT_TRUE((enemy->getAttack() >= 5) && (enemy->getAttack() <= 15));
    EXPECT_TRUE((enemy->getDefense() >= 5) && (enemy->getDefense() <= 15));
}

TEST(EnemyTests, EnemyCreationLV2) {
    Entity* enemy = new Enemy("The Evil Smiley Face", 2);

    EXPECT_TRUE(enemy->getName() == "The Evil Smiley Face");
    EXPECT_TRUE(enemy->getHealth() >= 10 && enemy->getHealth() <= 30 );
    EXPECT_TRUE(enemy->getAttack() >= 10 && enemy->getAttack() <= 30 );
    EXPECT_TRUE(enemy->getDefense() >= 10 && enemy->getDefense() <= 30 );
}

TEST(EnemyTests, EnemyCreationLV3) {
    Entity* enemy = new Enemy("Dr. Doofenshmirtz Evil INC.", 3);
    
    EXPECT_TRUE(enemy->getName() == "Dr. Doofenshmirtz Evil INC.");
    EXPECT_TRUE((enemy->getHealth() >= 15) && (enemy->getHealth() <= 45));
    EXPECT_TRUE((enemy->getAttack() >= 15) && (enemy->getAttack() <= 45));
    EXPECT_TRUE((enemy->getDefense() >= 15) && (enemy->getDefense() <= 45));
}

TEST(EnemyTests, EnemyCreationLV4) {
    Entity* enemy = new Enemy("The Evil Smiley Face", 4);

    EXPECT_TRUE(enemy->getName() == "The Evil Smiley Face");
    EXPECT_TRUE(enemy->getHealth() >= 20 && enemy->getHealth() <= 60 );
    EXPECT_TRUE(enemy->getAttack() >= 20 && enemy->getAttack() <= 60 );
    EXPECT_TRUE(enemy->getDefense() >= 20 && enemy->getDefense() <= 60 );
}

TEST(EnemyTests, EnemyCreationLV5) {
    Entity* enemy = new Enemy("The Bird", 5);

    EXPECT_TRUE(enemy->getName() == "The Bird");
    EXPECT_TRUE(enemy->getHealth() >= 25 && enemy->getHealth() <= 75 );
    EXPECT_TRUE(enemy->getAttack() >= 25 && enemy->getAttack() <= 75 );
    EXPECT_TRUE(enemy->getDefense() >= 25 && enemy->getDefense() <= 75 );
}

// TEST(EnemyTests, EnemyDisplay) {
//     Entity* enemy = new Enemy("Spooky Skeleton", 1);
//     enemy->display();
//     Entity* enemy1 = new Enemy("Boots", 1);
//     enemy1->display();
//     Entity* enemy2 = new Enemy("Dora", 2);
//     enemy2->display();
//     Entity* enemy3 = new Enemy("The Map", 2);
//     enemy3->display();
//     Entity* enemy4 = new Enemy("Swiper No Swiping", 3);
//     enemy4->display();
//     Entity* enemy5 = new Enemy("Blues Clues", 4);
//     enemy5->display();
//     EXPECT_TRUE(true == true);
// }

TEST(EnemyTests, EnemyTakeDamage)
{
    Entity* enemy1 = new Enemy("hi", 1);
    enemy1->takeDamage(15);

    EXPECT_TRUE((enemy1->getHealth() <= 0) && (enemy1->getHealth() >= -10) );
}

TEST(EnemyTests, EnemyIsDead) {
    Entity* enemy = new Enemy("Boots", 1);

    EXPECT_FALSE(enemy->isDead());
    enemy->takeDamage(50);
    EXPECT_TRUE(enemy->isDead());
}

#endif