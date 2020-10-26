/*
 * Yingjie He
 * CS-3150
 * 10/25/2020
 * Dungeon Crawl Competition
 */

#include <iostream>
#include "character.h"

bool isHeroAlive(hero *h, struct master *m) {
    if (h->hit_points <= 0) {
        return false;
    } else {
        return true;
    }
}

bool isMasterAlive(hero *h, struct master *m) {
    if (m->hit_points <= 0) {
        return false;
    } else {
        return true;
    }
}

void delay(int second) {
    time_t start_time, cur_time;
    time(&start_time);
    do {
        time(&cur_time);
    } while ((cur_time - start_time) < second);
}

void printHeroInfor(hero *h) {
    cout << "-----------------------" << endl;
    cout << "Name: " << h->name << endl;
    cout << "Hit Points: " << h->hit_points << endl;
    cout << "Attack: " << h->attack << endl;
    cout << "Resistance: " << h->resistance << endl;
    cout << "Wealth: " << h->wealth << endl;
    cout << "-----------------------" << endl;
}