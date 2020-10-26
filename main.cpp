/*
 * Yingjie He
 * CS-3150
 * 10/25/2020
 * Dungeon Crawl Competition
 */


#include <iostream>
#include <string>
#include <ctime>
#include "character.h"
#include "dungeonScene.h"
#include "map.cpp"


using namespace std;
enum POSITION {
    east, south, west, north
};


int main() {
    srand((unsigned int) time(NULL));

    cout << "\n"
            "   _____                                        _____                    _ \n"
            "  |  __ \\                                      / ____|                  | |\n"
            "  | |  | |_   _ _ __   __ _  ___  ___  _ __   | |     _ __ __ ___      _| |\n"
            "  | |  | | | | | '_ \\ / _` |/ _ \\/ _ \\| '_ \\  | |    | '__/ _` \\ \\ /\\ / / |\n"
            "  | |__| | |_| | | | | (_| |  __/ (_) | | | | | |____| | | (_| |\\ V  V /| |\n"
            "  |_____/ \\__,_|_| |_|\\__, |\\___|\\___/|_| |_|  \\_____|_|  \\__,_| \\_/\\_/ |_|\n"
            "                       __/ |                                               \n"
            "                      |___/                                                " << endl;

    cout << "Welcome to the Dungeon Crawl!" << endl;
    cout << "Please enter a hero: ";
    struct hero h1;

    cin >> h1.name;
    cout << endl;
    cout << "Once upon a time, demons from hell plagued the human world. "
            "They destroy the peace of the human world, "
            "\nkilling civilians everywhere and destroying buildings. Human society is suffering." << endl;
    cout << endl;

    delay(1);
    cout << "At this moment an army of human, armed with the most advanced weapons and the best fighters of the day, "
            "\nwas gathering in the distance, ready to fight the demons of hell for the last time. "
            "\nDrive them away to hell once and for all, and never to return." << endl;
    cout << endl;

    delay(1);
    cout << "The battle began, and it lasted for thirty days and thirty nights. "
            "\nThe end result is the triumph of human society，"
            "but when the demon retreats, it sets up a maze of traps, riches, and hidden demons. "
            "\nBecause it was so dangerous that no one dared go near it." << endl;
    cout << endl;

    delay(1);
    cout << "There was a hero named " << h1.name << "."
                                                    "\nWhile their troops were fighting demons, he accidentally got separated from their troops and eventually ended up in the maze. "
         << endl;
    cout << endl;

    delay(1);
    cout << "Whether " << h1.name << " can get out of the maze depends on how you direct him." << endl;
    cout << endl;

    delay(1);
    cout << "Let's start the game!" << endl;
    cout << "------------------------------------------" << endl;

    cout << "Here is the hero basic attributes" << endl;
    //Initializes the hero.
    h1.hit_points = 100;
    h1.current_y = 1;
    h1.current_x = 0;
    h1.attack = 20;
    h1.resistance = 20;
    h1.wealth = 5;
    printHeroInfor(&h1);
    createTile();


    cout
            << "Here is the map.(Notice: 'S' is the start point, and 'E' is the end point. You should move to the 'E'. That you can go home. '-' and '|' are the wall, don't move to it. You will pain if you move to it. '*' is the room.)"
            << endl;
    do {
        //showing map and direction
        showMap();
        POSITION position;
        string direction;
        //Record the user enter number
        while (direction != "N" && direction != "S" && direction != "E" && direction != "W") {
            //cout << direction << endl;
            cout << "Please enter the N,S,E,W to move the hero." << endl;
            cin >> direction;

            if (direction == "N") {
                position = north;
            } else if (direction == "S") {
                position = south;
            } else if (direction == "E") {
                position = east;
            } else if (direction == "W") {
                position = west;
            } else {
                cout << "Please enter the capital letters N or S or E or W !" << endl;
            }
        }

        //determine which direction
        switch (position) {
            case north:
                if (isOutBorder(h1.current_x, h1.current_y - 1)) {
                    if (map[h1.current_y][h1.current_x] != "S") {
                        map[h1.current_y][h1.current_x] = " ";
                    }
                    h1.current_y -= 1;
                } else {
                    cout << "You can't enter the 'N', because you touch the wall. Do you want to break the wall? "
                            "No, you can't do that!" << endl;
                    continue;
                }
                break;
            case south:
                if (isOutBorder(h1.current_x, h1.current_y + 1)) {
                    if (map[h1.current_y][h1.current_x] != "S") {
                        map[h1.current_y][h1.current_x] = " ";
                    }
                    h1.current_y += 1;
                } else {
                    cout << "You can't enter the 'S', because you touch the wall. Do you want to break the wall? "
                            "No, you can't do that!" << endl;
                    continue;
                }
                break;
            case west:
                if (isOutBorder(h1.current_x - 1, h1.current_y)) {
                    if (map[h1.current_y][h1.current_x] != "S") {
                        map[h1.current_y][h1.current_x] = " ";
                    }
                    h1.current_x -= 1;
                } else {
                    cout << "You can't enter the 'W', because you touch the wall. Do you want to break the wall? "
                            "No, you can't do that!" << endl;
                    continue;
                }
                break;
            case east:
                if (isOutBorder(h1.current_x + 1, h1.current_y)) {
                    if (map[h1.current_y][h1.current_x] != "S") {
                        map[h1.current_y][h1.current_x] = " ";
                    }
                    h1.current_x += 1;
                } else {
                    cout << "You can't enter the 'E', because you touch the wall. Do you want to break the wall? "
                            "No, you can't do that!" << endl;
                    continue;;
                }
                break;
        }


        map[h1.current_y][h1.current_x] = "H";
        steps++;
        cout << "The step " << steps << endl;
        //what inside for each room.
        if (dungeonTile[h1.current_y][h1.current_x] == improve_hitPoints) {
            potion = improve_hitPoints;
            potionValue(&h1, potion);
            dungeonTile[h1.current_y][h1.current_x] = 0;
        } else if (dungeonTile[h1.current_y][h1.current_x] == improve_resistance) {
            potion = improve_resistance;
            potionValue(&h1, potion);
            dungeonTile[h1.current_y][h1.current_x] = 0;
        } else if (dungeonTile[h1.current_y][h1.current_x] == reduce_hitPoints) {
            potion = reduce_hitPoints;
            potionValue(&h1, potion);
            dungeonTile[h1.current_y][h1.current_x] = 0;
        }
            //dungeonTile is trap
        else if (dungeonTile[h1.current_y][h1.current_x] == disorderly_arrows) {
            trap = disorderly_arrows;
            trapValue(&h1, trap);
            dungeonTile[h1.current_y][h1.current_x] = 0;
        } else if (dungeonTile[h1.current_y][h1.current_x] == flamethrower_strafed) {
            trap = flamethrower_strafed;
            trapValue(&h1, trap);
            dungeonTile[h1.current_y][h1.current_x] = 0;
        } else if (dungeonTile[h1.current_y][h1.current_x] == laser_shooting) {
            trap = laser_shooting;
            trapValue(&h1, trap);
            dungeonTile[h1.current_y][h1.current_x] = 0;
        }
            //dungeonTile is master
        else if (dungeonTile[h1.current_y][h1.current_x] == super_dragon) {
            master = super_dragon;
            masterValue(&h1, master);
            dungeonTile[h1.current_y][h1.current_x] = 0;
        } else if (dungeonTile[h1.current_y][h1.current_x] == zombie) {
            master = zombie;
            masterValue(&h1, master);
            dungeonTile[h1.current_y][h1.current_x] = 0;
        } else if (dungeonTile[h1.current_y][h1.current_x] == demon_skeleton) {
            master = demon_skeleton;
            masterValue(&h1, master);
            dungeonTile[h1.current_y][h1.current_x] = 0;
        } else if (dungeonTile[h1.current_y][h1.current_x] == leader_demon) {
            master = leader_demon;
            masterValue(&h1, master);
            dungeonTile[h1.current_y][h1.current_x] = 0;
        }
            // //dungeonTile is treasure
        else if (dungeonTile[h1.current_y][h1.current_x] == gold) {
            treasure = gold;
            treasureValue(&h1, treasure);
            dungeonTile[h1.current_y][h1.current_x] = 0;
        } else if (dungeonTile[h1.current_y][h1.current_x] == super_gun) {
            treasure = super_gun;
            treasureValue(&h1, treasure);
            dungeonTile[h1.current_y][h1.current_x] = 0;
        } else if (dungeonTile[h1.current_y][h1.current_x] == flamethrower) {
            treasure = flamethrower;
            treasureValue(&h1, treasure);
            dungeonTile[h1.current_y][h1.current_x] = 0;
        } else if (dungeonTile[h1.current_y][h1.current_x] == cannon) {
            treasure = cannon;
            treasureValue(&h1, treasure);
            dungeonTile[h1.current_y][h1.current_x] = 0;
        } else if (dungeonTile[h1.current_y][h1.current_x] == laser_sword) {
            treasure = laser_sword;
            treasureValue(&h1, treasure);
            dungeonTile[h1.current_y][h1.current_x] = 0;
        } else {
            cout << "This room not anything." << endl;
        }

        string option;
        while (option != "1" && option != "2") {
            cout << "1.Showing the Hero basic attributes"
                 << "\n2.To move forward"
                 << "\n(Please enter the number.)" << endl;
            cin >> option;
            if (option == "1") {
                printHeroInfor(&h1);
            }

        }


    } while (map[h1.current_y + 1][h1.current_x] != "E" || map[h1.current_y - 1][h1.current_x] != "E" ||
             map[h1.current_y][h1.current_x + 1] != "E" || map[h1.current_y][h1.current_x - 1] != "E");

    cout << "Congratulations! You made it through tough times to the finish line! You are win! Unbelievable！！！" << endl;

    return 0;


}
