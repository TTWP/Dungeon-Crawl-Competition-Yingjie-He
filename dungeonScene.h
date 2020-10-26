/*
 * Yingjie He
 * CS-3150
 * 10/25/2020
 * Dungeon Crawl Competition
 */

#ifndef DUNGEON_CRAWL_COMPETITION_DUNGEONSCENE_H
#define DUNGEON_CRAWL_COMPETITION_DUNGEONSCENE_H

enum POTION {
    improve_hitPoints = 20, improve_resistance, reduce_hitPoints
};
enum TRAP {
    disorderly_arrows = 30, flamethrower_strafed, laser_shooting
};
enum MASTER {
    super_dragon = 40, zombie, demon_skeleton, leader_demon
};
enum TREASURE {
    gold = 50, super_gun, flamethrower, cannon, laser_sword
};

extern POTION potion;
extern TRAP trap;
extern MASTER master;
extern TREASURE treasure;

void potionValue(hero *h, POTION potion_state);

void trapValue(hero *h, TRAP trap_state);

void masterValue(hero *h, MASTER master_state);

void treasureValue(hero *h, TREASURE treasure_state);


#endif //DUNGEON_CRAWL_COMPETITION_DUNGEONSCENE_H
