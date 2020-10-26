/*
 * Yingjie He
 * CS-3150
 * 10/25/2020
 * Dungeon Crawl Competition
 */

#include <iostream>
#include <ctime>
#include "character.h"
#include "dungeonScene.h"

struct master dragon;
struct master mzombie;
struct master skeleton;
struct master ldemon;


void potionValue(hero *h, POTION potion_state) {
    srand((unsigned int) time(NULL));
    int improve_hit_points_value = rand() % 20 + 1;
    int improve_resistance_value = rand() % 15 + 1;
    int reduce_hit_points_value = rand() % 10 + 1;
    switch (potion_state) {
        case improve_hitPoints:
            h->hit_points += improve_hit_points_value;
            cout << "You get the potion! It can improve your hit points! It will improve " << improve_hit_points_value
                 << "." << endl;
            break;
        case improve_resistance:
            h->resistance += improve_resistance_value;
            cout << "You get the potion! It can improve your resistance! It will improve " << improve_resistance_value
                 << "." << endl;
            break;
        case reduce_hitPoints:
            h->hit_points -= reduce_hit_points_value;
            if (h->hit_points <= 0) {
                cout << "The hero was poisoned with poison. so sad!!!" << endl;
                exit(0);
            }
            cout << "You get the potion! Oh no.It can reduce your hit points. It will reduce "
                 << reduce_hit_points_value << "." << endl;
            break;
    }
}

void trapValue(hero *h, TRAP trap_state) {
    srand((unsigned int) time(NULL));
    int reduce_hit_points_value;
    int reduce_resistance_value = rand() % 10 + 1;
    switch (trap_state) {
        case disorderly_arrows:
            reduce_hit_points_value = rand() % 21 + 10;
            reduce_resistance_value = rand() % 10 + 1;

            if (h->hit_points - reduce_hit_points_value <= 0) {
                h->hit_points = 0;
                cout << "The hero was shot down gloriously by disorderly arrows. Game over!" << endl;
                exit(0);
            } else {
                h->hit_points -= reduce_hit_points_value;
            }

            if (h->resistance - reduce_resistance_value <= 0) {
                h->resistance = 0;
            } else {
                h->resistance -= reduce_resistance_value;
            }
            cout
                    << "Oh no! You meet the trap. This is the disorderly arrows. It will reduce your hit points and resistance. It will"
                       " reduce hit points value " << reduce_hit_points_value << " and resistance value "
                    << reduce_resistance_value << "." << endl;
            break;
        case flamethrower_strafed:
            reduce_hit_points_value = rand() % 31 + 20;
            reduce_resistance_value = rand() % 10 + 10;

            if (h->hit_points - reduce_hit_points_value <= 0) {
                h->hit_points = 0;
                cout << "The hero was shot down gloriously by flamethrower strafed. Game over!" << endl;
                exit(0);
            } else {
                h->hit_points -= reduce_hit_points_value;
            }

            if (h->resistance - reduce_resistance_value <= 0) {
                h->resistance = 0;
            } else {
                h->resistance -= reduce_resistance_value;
            }
            cout
                    << "Oh no! You meet the trap. This is the flamethrower strafed. It will reduce your hit points and resistance. It will"
                       " reduce hit points value " << reduce_hit_points_value << " and resistance value "
                    << reduce_resistance_value << "." << endl;
            break;
        case laser_shooting:
            reduce_hit_points_value = rand() % 31 + 30;
            reduce_resistance_value = rand() % 20 + 15;
            if (h->hit_points - reduce_hit_points_value <= 0) {
                h->hit_points = 0;
                cout << "The hero was shot down gloriously by laser shooting. Game over!" << endl;
                exit(0);
            } else {
                h->hit_points -= reduce_hit_points_value;
            }

            if (h->resistance - reduce_resistance_value <= 0) {
                h->resistance = 0;
            } else {
                h->resistance -= reduce_resistance_value;
            }
            cout
                    << "Oh no! You meet the trap. This is the flamethrower strafed. It will reduce your hit points and resistance. It will"
                       " reduce hit points value " << reduce_hit_points_value << " and resistance value "
                    << reduce_resistance_value << "." << endl;
            break;
    }
}

void masterValue(hero *h, MASTER master_state) {
    int roundNum = 1;
    switch (master_state) {
        case super_dragon:
            dragon.name = "Big dragon";
            dragon.hit_points = 50;
            dragon.attack = 20;
            cout
                    << "----------------------::::-============*##+==============*#*===========+##+=--+*:::::::::::---------\n"
                       "-----------------------:::-=============+##*+============##*==========+%#+===*+::::::::::::::-------\n"
                       "-------------------------:-===============*##*===========##*=========*%*====*=::::::::::::::::::----\n"
                       "---------------------------================+###=========+##*========#%*===**-:::::::::::::::::::----\n"
                       "---------------------------=================+###========+##+======+##*==+#=:::::::::::::::::::::::--\n"
                       "---------------------------==================+###=======*##+=====*##+++#*:::::::::::::::::::::::::::\n"
                       "--------------------------=====================###+=====###+===+###+*##-::::::::::::::::::::::::::::\n"
                       "--------------------------======================###+====###+==*##*+##*::::::::::::::::::::::::::::::\n"
                       "---------------------=**######**+++==============###+==+%##++###**##-:::::::::::::::::::::::::::::::\n"
                       "--------------------=======+++***######**+========*%####%##*###*##=:::::::::::::::::::::::::::::::::\n"
                       "--------------------------------====+++*####**++===*%###########*:::::::::::::::::::::::::::::::::::\n"
                       "---------------------------------==========+**####*#%%#########=::::::::...:::::::::::::::::::::::::\n"
                       "----------------------------------==============+**#%%#######+====*###**+=:.::::::::::::::::::::::::\n"
                       "-----------------------------------==================#%#######::=*%%%%%%%%%#+:::::::::::::::::::::::\n"
                       "------------------------------------===============*######*+=++*#%##%%##***=#-::::::::::::::::::::::\n"
                       "-------------------------------------============*######=::::-*#%%%%%%%%%#**+:::::::::::::::::::::::\n"
                       "-------------------------------------==========+######=:::-+*###%%%%%###*+=-::::::::::::::::::::::::\n"
                       "--------------------------------------======+*######=:::+#####%%%#+++-=::::::::::::::::...::::::::::\n"
                       "---------------------------------------====+#######-:::=####%%%#+==-::::::::::::::::::::....::::::::\n"
                       "----------------------------------------=====#####+--=+###%%%*+==-::::::::::::::::::::::::::::::::::\n"
                       "-------------------------------------+##*=====####**##%##%%%+==-::::::::::::::::::::::::::::::::::::\n"
                       "--------------------------------=+=+######===+%###%%%%%%%%%*==-:::::::::::::::::::::::::::::::::::::\n"
                       "-----------------------------==-*########*==*#%###%%%%%%%%%+==::::::::::::::::::::::::::::::::::::::\n"
                       "-----------------------------+####%%%#####*##%%%%%%%%%%%%%#==-::::::::::::::::::::::::::::::::::::::\n"
                       "----------------------------+*###%%########%%%%%%%%%%%%%%%*==--:::::::::::::::::::::::::::::::::::::\n"
                       "-------------------------==+*##%####%%%%%%%%%%%%%%%%%%%%%#==----::::::::::::::::::::::::::::::::::::\n"
                       "------------------------=*####%%###%%%%%%%%%%##%%%%%%%%%*==-------::::::::::::::::::::::::::::::::::\n"
                       "-------------------------+#%%%#####%%%%%%%%#=*%%%%%#**+==-----------::::::::::::::::::::::::::::::::\n"
                       "----------------------=+*####%####%%%%%%%%%=-+%%%%=------------------:::::::::::::::::::::::::::::::\n"
                       "-----------------------+#%%%####%%%%%%%%%%#--+%%%%=--------------------:::::::::::::::::::::::::::::\n"
                       "---------------------==+#%#####%%*+%%%%%%%=-=+#%%%+----------------------:::::::::::::::::::::::::::\n"
                       "--------------------=*#%%%###%%%%%%%%%%%%*--++#%%%#-----------------------::::::::::::::::::::::::::\n"
                       "-------------------==+#%####%#*%%%%%%##**--=*#%%%%%-------------------------::::::::::::::::::::::::\n"
                       "-----------------=#####%###%%=+%%%%#--------##%#%%#--------------------------:::::::::::::::::::::::"
                    << endl;

            cout << "You meet a big dragon. You should kill it, and go can move forward " << endl;
            cout << "The battle start!" << endl;

            while (isHeroAlive(h, &dragon) && isMasterAlive(h, &dragon)) {
                cout << "Round " << roundNum << endl;
                cout << "------------------------" << endl;
                delay(1);
                h->hit_points -= dragon.attack;
                cout << "Big dragon reduce you " << dragon.attack << " hit points." << endl;
                if (h->hit_points <= 0) {
                    break;
                }
                cout << "You leave " << h->hit_points << "." << endl;
                dragon.hit_points -= h->attack;
                cout << "You attack Big dragon " << h->attack << " hit points." << endl;
                if (dragon.hit_points <= 0) {
                    break;
                } else {
                    cout << "Big dragon leave " << dragon.hit_points << "." << endl;
                    cout << "------------------------" << endl;
                }
                roundNum++;
            }


            roundNum = 1;
            if (h->hit_points <= 0) {
                cout << "The hero fought the " << dragon.name << " with all his might and was killed. Game over!"
                     << endl;
                exit(0);
            } else if (dragon.hit_points <= 0) {
                cout << "Congratulations! You've killed " << dragon.name
                     << ". You're ready to move on to the next room." << endl;
            }
            break;
        case zombie:
            mzombie.name = "Evil Zombie";
            mzombie.hit_points = 10;
            mzombie.attack = 10;
            cout <<
                 "::++++**#######-::::::::::-==-:=-+*++==+==++**++=-::::::::::\n"
                 "..:++++**######-::::::::::---==+================++*+=:::::::\n"
                 "...:=++**#####=::::::::::..:+=-=====================+*+=+=--\n"
                 ".....:-==++=-::::::::::...=*--====++++++++=========++***-::.\n"
                 "........::::::::::::::....=**+=======++++++========++++*=.:.\n"
                 ".......:::::::::::::.....:-+**#+=============----==+++++#:..\n"
                 "......::::::::::::.......+: ..:++=========++++**+===++++*=..\n"
                 ".....::::::::::::.......-=.....:*=======+=: ...:=*+=+++++*:.\n"
                 "...::::::::::::.........:=-::::-+======+=.  ....:-*++++++#--\n"
                 "..::::::::::::..........:*#+=+**====++=*.......:::+++++**#:.\n"
                 ".:::::::::::.............++***+==*+=#*=*::+::::::.+*++++**--\n"
                 ":::::::::::.............:=+++==========++::::::::-#+++++*=-:\n"
                 ":::::::::..............:::--=*:-+++=====+#+----=*#*++++++::-\n"
                 "::::::::.............::::::::=--+%+=##+==+*#####*+++++*+::::\n"
                 "::::::.............::::::::::+#%%%#+#%##+++++++=**++*#*:::::\n"
                 ":::::............::::::::::=+=-%%%%%%##%#=++++=+**#%%%%+::::\n"
                 ":::............::::::::::::====+*##%#-:##=+++=+****%%%%%+:::\n"
                 "::............::::::::::::::+=++====+***==+++***+**###%%%=::\n"
                 "............::::::::::::::..-=+++++++++=*+***+==**########-:\n"
                 "==-:......:::::::::::::........:-=****##%%%%--=+*+#########:\n"
                 "===++=:.::::-::-:::::............=#%#*+#%%%#=-+*+*########%%\n"
                 "---==+++==+:*=+#:::..::.........:##%*#++#%++++#+**%########%\n"
                 "-----==+**#+#*##:.::.-+.:.....::+#%#####*+==+*++*###########\n"
                 "======-:-+*#####:.:*-+#==..:::::##*++##%+=-+*++**###########\n"
                 "-====: . .+*#####*=***##*+=*::-*#####+**=-+*+++**###########\n"
                 ".:====   :++###################+=*#####==-+*++**############\n" << endl;

            cout << "You meet a Evil Zombie. You should kill it, and go can move forward " << endl;
            cout << "The battle start!" << endl;
            cout << "------------------------" << endl;

            while (isHeroAlive(h, &mzombie) && isMasterAlive(h, &mzombie)) {
                cout << "Round " << roundNum << endl;
                cout << "------------------------" << endl;
                delay(1);
                h->hit_points -= mzombie.attack;
                cout << "Evil Zombie reduce you " << mzombie.attack << " hit points." << endl;
                if (h->hit_points <= 0) {
                    break;
                }
                cout << "You leave " << h->hit_points << " hit points" << endl;
                mzombie.hit_points -= h->attack;
                cout << "You attack Evil Zombie " << h->attack << " hit points." << endl;
                if (mzombie.hit_points <= 0) {
                    break;
                } else {
                    cout << "Evil Zombie leave " << mzombie.hit_points << "." << endl;
                    cout << "------------------------" << endl;
                }
                roundNum++;
            }
            roundNum = 1;
            if (h->hit_points <= 0) {
                cout << "The hero fought the " << mzombie.name << " with all his might and was killed. Game over!"
                     << endl;
                exit(0);
            } else if (mzombie.hit_points <= 0) {
                cout << "Congratulations! You've killed " << mzombie.name
                     << ". You're ready to move on to the next room." << endl;
            }
            break;
        case demon_skeleton:
            skeleton.name = "Demon skeleton";
            skeleton.hit_points = 15;
            skeleton.attack = 10;
            cout
                    << "..   ..   ..   ..   ..   ..   ..   ..   .. .:-======--::.   ..   ..   ..   ..   ..   ..   ..   ..   ...\n"
                       "                                        -==-:.........:-==:                                            \n"
                       "   ..   ..   ..   ..   ..   ..   ..   :+-:::...........  .-=.  ..   ..   ..   ..   ..   ..   ..   ..   \n"
                       "                                    .==:::::..........:.   .=:                                         \n"
                       "                                    -=:::::::...........    .+:             ..                         \n"
                       "   ..   ..   ..   ..   ..   ..   ...+:::::::::...........   ::+..   ..   .-=*+..   ..   ..   ..   ..   \n"
                       "                                   =-:::::---+***=-.......-+*:+.       .+*+--*-                        \n"
                       "                                   +::::::::=#%%%%%#+-...#%%%#-:       +=...-+*.                       \n"
                       "   ..   ..   ..   ..   ..   ..   ..+.:::::::*%%%%%%%%%=.-%%%%#--.   ..:*:..---*:   ..   ..   ..   ..   \n"
                       "                                  .+..:::::-#%%%%%%%%%=.-%%%%#--      +:..:--+-                        \n"
                       "                                   +....:::-#%%%%%%%%#:.:%%%%*-:     -=...--=+                         \n"
                       "   ..   ..   ..   ..   ..   ..   ..=:....::::-+*##%%#=..+-==-.=..   .*:..---+...   ..   ..   ..   ..   \n"
                       "                                   .+....::::....:--:..*%+....+     =-..:--*:                          \n"
                       "..   ..   ..   ..   ..   ..   ..   ..+:..:::::........-%%%:. --  ..:+..:--+-.   ..   ..   ..   ..   ...\n"
                       "   ..   ..   ..   ..   ..   ..   ..  .+.....::::..:....=+-...=:..  +:..--==   ..   ..   ..   ..   ..   \n"
                       "                                      :=.....:::::--:......:=:.   -=:.:-=+                             \n"
                       "..   ..   ..   ..   ..   ..   ..   ..  :+==--::--=:+-:.:..::-.   .+:.:--+. ..   ..   ..   ..   ..   ...\n"
                       "   ..   ..   ..   ..   ..   ..   ..  :-:+=--+=..:-.+:-======..-:.=-:.--+:..   ..   ..   ..   ..   ..   \n"
                       "                                      :=--===*--=--=-=+--.  .=++++=---+-                               \n"
                       "..   ..   ..   ..   ..   ..   ..   ..:==+===*=...=:...-..-: =+*++=-=+++:.  ..   ..   ..   ..   ..   ...\n"
                       "   ..   ..   ..   ..   ..   ..   .. .==+=++*+====+====+=::=+++--***+++=++..   ..   ..   ..   ..   ..   \n"
                       "                                      =:-**-=:...=:...-:--++-=.=..:=:-=+-                              \n"
                       "..   ..   ..   ..   ..   ..   ..   .. =. =  ==++===++==...-+++=:::--. ..   ..   ..   ..   ..   ..   ...\n"
                       "                                      =..=  =....=:...-    =++::-=-:                                   \n"
                       "                                      =::+=-.=--=*---=.    .+++-:-.                                    \n"
                       "..   ..   ..   ..   ..   ..   ..   ..=----.=---.:=:.-: ..  .-:##=-.   ..   ..   ..   ..   ..   ..   ...\n"
                       "                                    .=:::=.-==-:=.-:-=.        .                                       \n"
                    << endl;

            cout << "You meet a Demon skeleton. You should kill it, and can move forward " << endl;
            cout << "The battle start!" << endl;
            cout << "------------------------" << endl;

            while (isHeroAlive(h, &skeleton) && isMasterAlive(h, &skeleton)) {
                cout << "Round " << roundNum << endl;
                cout << "------------------------" << endl;
                delay(1);
                h->hit_points -= skeleton.attack;
                cout << "Demon skeleton reduce you " << skeleton.attack << " hit points." << endl;
                if (h->hit_points <= 0) {
                    break;
                }
                cout << "You leave " << h->hit_points << " hit points." << endl;
                skeleton.hit_points -= h->attack;
                cout << "You attack Demon skeleton " << h->attack << " hit points." << endl;
                if (skeleton.hit_points <= 0) {
                    break;
                } else {
                    cout << "Demon Skeleton leave " << skeleton.hit_points << "." << endl;
                    cout << "------------------------" << endl;
                }
                roundNum++;
            }
            roundNum = 1;
            if (h->hit_points <= 0) {
                cout << "The hero fought the " << skeleton.name << " with all his might and was killed. Game over!"
                     << endl;
                exit(0);
            } else if (mzombie.hit_points <= 0) {
                cout << "Congratulations! You've killed " << skeleton.name
                     << ". You're ready to move on to the next room." << endl;
            }
            break;
        case leader_demon:
            ldemon.name = "Leader Demon";
            ldemon.hit_points = 60;
            ldemon.attack = 40;
            cout
                    << "======================================================+*+===========*#+==+++===================================++\n"
                       "=======================================================*#+=========*#*==++=====================================++\n"
                       "=========---===========================================+##*=-+-=+*%##+=++======++++==========================++++\n"
                       "===========-----------==================================+#%%*==#%%%*=========+++=++==============+++++++++++++++=\n"
                       "=================-------==------::-=====================+%##++=*%%*=+#==========+============+++++++++++===+++===\n"
                       "========================------------===================+#%#******%#+##=======================+++++++++===========\n"
                       "==========================----==-----=======--::::::::::=*##*###%***#*+*+*+=======================+++++++========\n"
                       "-----============================--==--===--:---::......::-######*+*#*=+++**=++==================+++++++++=======\n"
                       "------------========================--------------:--===-+**##***++*#*+==+*#**==================+++++============\n"
                       "--------------===============-------------------:---*#####*+*#**+++++**++*++***#=========++======================\n"
                       "------------------------===+=-::::-----=------::---+*####*++##*#*#+=+*##**+*#**+*+====+****+=+++=++==============\n"
                       "------------------------++====::..::::------------*#*##*##*#%##*****+*#%%%##*+**++==++***********+===============\n"
                       "------------------------==:-==---------=--------=+*#####*%%****#*+*#####%%%##*****+=+*************+++============\n"
                       "------------------------==--=---=====++++=-----=+######%#*+***+******%%%+*#%%%###++++******+***++*+++++========++\n"
                       ":------------:::--:-----=---=---=---=*+=+=---====+#***#%*+*++++++*++=*%#====+#####*==*+****+*++===++===========++\n"
                       "::::::::::::::::-:=-::-===-==---+----+=-+----======++#%%*+++++==-===++#=====+##%%##**+*#++++**+==****+===========\n"
                       "-:::::::::::::::--===++====++++-=:::-=--=-----===**+#%%#=***+**##*#####*+====-=+##%##*+==+++***+******++=========\n"
                       "-::::::::::::::-=++=+++++==++++++=-:-+===-----=*%%###%%**####%%#####*###%======+**###**+*#*+++********+=========+\n"
                       "--::::::::.:--=++++=+++====+++++++++**+++=-===###%%%%@#+###%##########**#-----=****##%#**#**********++======+++*+\n"
                       "---::::::::--==+=+==+=+===+=*+*+**+***-=+-===##%%%%%%+=+%%%##%########***=-+=+*****#%#%%##%#++++++++==++*****++**\n"
                       ":::::::::-=--==+=+++=+=====+==++++++*+-==--=*#%%%%%+=--=%%###%%%%###******-*#*+*++##+++#*###++++====+********++**\n"
                       "::-::::---=-=++++========--==++++**+*+===--*#%%%%*==----#%####*#%#*##**#*#=+##+++=+*==*###%%======+++*=+=+**+++**\n"
                       ":::::::::-=-=++=====-=-=--==--==+++++++==-=++#%@@#=====**%######%#**#**###*+***=======+#%##+==+++++=++=-+-+++++++\n"
                       "::::::-----=-+++======--------==+==+*==+--=+*#%*====*#*%##%###%%%#***###*#*#+#+++++++++++++=====+======-==++++===\n"
                       ":::::::::--==+++==+=+=--::.-==+++++**==+--**##+=====##%#%%%%##%%%###******#####*#*****++++====================--=\n"
                       ":::::::::==:+++=++===::::.:=-+===+***==++##*++======*%####%%%%%@%###***##*#*#%###****++================-=---=--==\n"
                       "::.....:-===++=++=-:::::::-==+=+*+**+=*##+===========*####%%%%%@@%###**+***#####%%##++=========++++=======--=====\n"
                       "-:-:=-:-==-+++==-::----::.==+++*+++*###*============+####%#%%%@@@%###+**#########%##*++================+========+\n"
                       "***++++==---=-::---=----::==++++***###++++++======++######%%%%%@@@####**##*####%##%#############################%\n"
                       "*=+*+++++++=:.:-===+==-:-=++++++###*+++++==+=++=====#%###%%%%%@##@%####*####*###%##%####++*****++==+*#####*+==+++\n"
                       "+-=++==+==-.:--==+++==:-==++**#%%#*++++++==+++==+==*%%*#%%%%%%%++%@%#############%##%###=*###**+=---*####++*==+++\n"
                       "++++=====::::---=+++=-:==++*##%*=**++++++=++=-=+++=#%###%%%%%@*++#%@##%%##%%%**###*##%##+#*##**+=-::+**##*=+++=++\n"
                       "*+++====::::----==++=--+*#%%#*+==+++=++=--=-::=++++***#%%%%%%#=++*#%%##%%#%%%#**##+*##%###*******=-=*#*###*++++++\n"
                       "+++=+=--:::::::--==+=*###%%%*=+======-::::--:-+====+*#%%%%%%%+***###%###*#*#%%##+**=###%##******++=-=#*#*####***#\n"
                    << endl;

            cout << "You meet a Leader Demon. You should kill it, and go can move forward " << endl;
            cout << "The battle start!" << endl;
            cout << "------------------------" << endl;

            while (isHeroAlive(h, &ldemon) && isMasterAlive(h, &ldemon)) {
                cout << "Round " << roundNum << endl;
                cout << "------------------------" << endl;
                delay(1);
                h->hit_points -= ldemon.attack;
                cout << "Leader Demon reduce you " << ldemon.attack << " hit points." << endl;
                if (h->hit_points <= 0) {
                    break;
                }
                cout << "You leave " << h->hit_points << "." << endl;
                ldemon.hit_points -= h->attack;
                cout << "You attack Leader Demon " << h->attack << " hit points." << endl;
                if (ldemon.hit_points <= 0) {
                    break;
                } else {
                    cout << "Evil Zombie leave " << ldemon.hit_points << "." << endl;
                    cout << "------------------------" << endl;
                }
                roundNum++;
            }
            roundNum = 1;
            if (h->hit_points <= 0) {
                cout << "The hero fought the " << ldemon.name << " with all his might and was killed. Game over!"
                     << endl;
                exit(0);
            } else if (ldemon.hit_points <= 0) {
                cout << "Congratulations! You've killed " << ldemon.name
                     << ". You're ready to move on to the next room." << endl;
            }
            break;
    }
}

void treasureValue(hero *h, TREASURE treasure_state) {
    srand((unsigned int) time(NULL));
    int hit_points_value;
    int attack;
    int wealth = rand() % 100 + 1;
    switch (treasure_state) {
        case gold:
            h->wealth += wealth;
            cout << "You meet a treasure, you get the " << wealth << " gold." << endl;
            break;
        case super_gun:
            hit_points_value = rand() % 10 + 1;
            attack = rand() % 20 + 1;
            h->hit_points += hit_points_value;
            h->attack += attack;
            cout << "You meet a treasure, you get a super gun! It will give improve you " << hit_points_value
                 << " hit points and " << attack << " attack." << endl;
            break;
        case flamethrower:
            hit_points_value = rand() % 21 + 5;
            attack = rand() % 31 + 10;
            h->hit_points += hit_points_value;
            h->attack += attack;
            cout << "You meet a treasure, you get a flamethrower! It will give improve you " << hit_points_value
                 << " hit points and " << attack << " attack." << endl;
            break;
        case cannon:
            hit_points_value = rand() % 21 + 15;
            attack = rand() % 31 + 20;
            h->hit_points += hit_points_value;
            h->attack += attack;
            cout << "You meet a treasure, you get a cannon! It will give improve you " << hit_points_value
                 << " hit points and " << attack << " attack." << endl;
            break;
        case laser_sword:
            hit_points_value = rand() % 31 + 20;
            attack = rand() % 31 + 30;
            h->hit_points += hit_points_value;
            h->attack += attack;
            cout << "You meet a treasure, you get a laser sword! It will give improve you " << hit_points_value
                 << " hit points and " << attack << " attack." << endl;
            break;
    }
}

