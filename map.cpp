/*
 * This file create the map
 * Yingjie He
 * CS-3150
 */

#include <string>
#include "dungeonScene.h"
#include <iostream>
using namespace std;


//Game map
string map[15][35] =
        {
                {"|", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "|"},
                {"S", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", " ", " ", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "|"},
                {"|", "*", "*", "*", "*", "*", " ", " ", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", " ", " ", " ", " ", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "|"},
                {"|", "*", "*", "*", "*", "*", " ", " ", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", " ", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "|"},
                {"|", "*", "*", "*", "*", " ", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", " ", " ", "*", "*", "*", "*", "*", "*", "*", "*", " ", " ", " ", "|"},
                {"|", "*", "*", "*", " ", " ", "*", "*", "*", "*", "*", "*", "*", "*", "*", " ", " ", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", " ", "*", " ", " ", "*", "|"},
                {"|", "*", "*", "*", " ", " ", " ", "*", "*", "*", "*", "*", "*", "*", "*", " ", " ", " ", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", " ", " ", " ", "*", "*", "|"},
                {"|", "*", "*", "*", " ", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", " ", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", " ", "*", " ", "*", "*", "|"},
                {"|", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", " ", "*", "*", "*", "*", "*", " ", "*", "*", "*", "*", "|"},
                {"|", "*", " ", " ", " ", " ", " ", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", " ", " ", "*", "*", "*", "*", "*", "*", "*", "*", "*", "|"},
                {"|", "*", " ", " ", " ", " ", " ", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", " ", " ", " ", "*", "*", "*", "*", "*", "*", "*", "*", "|"},
                {"|", "*", " ", " ", "*", "*", "*", "*", "*", "*", "*", "*", " ", "*", "*", " ", "*", "*", "*", "*", "*", "*", "*", " ", " ", " ", " ", "*", "*", "*", "*", "*", "*", "*", "|"},
                {"|", "*", " ", " ", "*", "*", "*", "*", "*", "*", "*", "*", " ", " ", "*", " ", " ", "*", "*", "*", "*", "*", "*", "*", " ", " ", "*", "*", "*", "*", "*", "*", "*", " ", "|"},
                {"|", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", " ", " ", " ", " ", " ", "*", "*", "*", "*", "*", "*", "*", " ", " ", "*", "*", "*", "*", "*", "*", "*", " ", "E"},
                {"|", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "|"},
        };

int dungeonTile[15][35];

int map_row = sizeof(map) / sizeof(map[0]);
int map_col = sizeof(map[0]) / sizeof(map[0][0]);

POTION potion;
TRAP trap;
MASTER master;
TREASURE treasure;

void showMap() {
    for (int i = 0; i < map_row; ++i) {
        for (int j = 0; j < map_col; ++j) {
            cout << map[i][j];
        }
        cout << endl;
    }
}

int createTile() {
    srand((unsigned int) time(NULL));
    for (int i = 0; i < map_row; ++i) {
        for (int j = 0; j < map_col; ++j) {
            if (map[i][j] == "*") {
                dungeonTile[i][j] = rand() % 18 + 1;
            }
        }
    }

    for (int i = 0; i < sizeof(dungeonTile) / sizeof(dungeonTile[0]); ++i) {
        for (int j = 0; j < sizeof(dungeonTile[0]) / sizeof(dungeonTile[0][0]); ++j) {
            //set to the potion
            if (dungeonTile[i][j] == 1) {
                potion = improve_hitPoints;
                dungeonTile[i][j] = potion;
            } else if (dungeonTile[i][j] == 2) {
                potion = improve_resistance;
                dungeonTile[i][j] = potion;
            } else if (dungeonTile[i][j] == 3) {
                potion = reduce_hitPoints;
                dungeonTile[i][j] = potion;
            }
                //set to the trap
            else if (dungeonTile[i][j] == 4) {
                trap = disorderly_arrows;
                dungeonTile[i][j] = trap;
            } else if (dungeonTile[i][j] == 5) {
                trap = flamethrower_strafed;
                dungeonTile[i][j] = trap;
            } else if (dungeonTile[i][j] == 6) {
                trap = laser_shooting;
                dungeonTile[i][j] = trap;
            }
                //set to the master
            else if (dungeonTile[i][j] == 7) {
                master = super_dragon;
                dungeonTile[i][j] = master;
            } else if (dungeonTile[i][j] == 8) {
                master = zombie;
                dungeonTile[i][j] = master;
            } else if (dungeonTile[i][j] == 9) {
                master = demon_skeleton;
                dungeonTile[i][j] = master;
            } else if (dungeonTile[i][j] == 10) {
                master = leader_demon;
                dungeonTile[i][j] = master;
            }
                //set to the treasure room
            else if (dungeonTile[i][j] == 11) {
                treasure = gold;
                dungeonTile[i][j] = treasure;
            } else if (dungeonTile[i][j] == 12) {
                treasure = super_gun;
                dungeonTile[i][j] = treasure;
            } else if (dungeonTile[i][j] == 13) {
                treasure = flamethrower;
                dungeonTile[i][j] = treasure;
            } else if (dungeonTile[i][j] == 14) {
                treasure = cannon;
                dungeonTile[i][j] = master;
            } else if (dungeonTile[i][j] == 15) {
                treasure = laser_sword;
                dungeonTile[i][j] = treasure;
            }
        }


    }
}

bool isOutBorder(int current_x, int current_y) {
    if (map[current_y][current_x] == "|" || map[current_y][current_x] == "-") {
        return false;
    } else {
        return true;
    }
}

