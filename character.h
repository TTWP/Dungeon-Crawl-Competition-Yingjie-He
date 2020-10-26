/*
 * Yingjie He
 * CS-3150
 * 10/25/2020
 * Dungeon Crawl Competition
 */

#ifndef DUNGEON_CRAWL_COMPETITION_CHARACTER_H
#define DUNGEON_CRAWL_COMPETITION_CHARACTER_H

#include <string>

using namespace std;
extern int battle_round;
static int steps;

struct hero {
    string name;
    int hit_points;
    int current_x;
    int current_y;
    int tile_position;
    int resistance;
    int attack;
    int wealth;
};

struct master {
    string name;
    int attack;
    int hit_points;
};

bool isHeroAlive(hero *h, struct master *m);

bool isMasterAlive(hero *h, struct master *m);

void delay(int second);

void printHeroInfor(hero *h);

#endif //DUNGEON_CRAWL_COMPETITION_CHARACTER_H
