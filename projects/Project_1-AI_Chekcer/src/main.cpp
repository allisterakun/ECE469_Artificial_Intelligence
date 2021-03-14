#include <iostream>
#include "rang.hpp"
#include <ios>              //used to get stream size
#include <limits>           //used to get numeric limits
#include <ctype.h>
#include <string>
#include "Game.hpp"
#include "checker.hpp"

using namespace std;

int getGameMode();
void setTimeLimit(int gameMode, Game::info &gameinfo);
void setStartingPlayer(Game::info &gameinfo);
void loadGame(Game::info &gameinfo);
void beginGame(int gameMode, Game::info &gameinfo);

int main(){
    cout << "Welcome" << endl;

    Game::info gameinfo;

    //Getting game mode:
    //    [1]   Agent vs Human player, Human player in red
    //    [2]   Agent vs Human player, Human player in white
    //    [3]   Agent vs Agent
    //    [4] 	Human vs Human
    int gameMode = getGameMode();

    //Setting time limit if an agent is needed
    if(gameMode != 4) setTimeLimit(gameMode, gameinfo);
    
    //Setting starting player
    setStartingPlayer(gameinfo);

    //Load game from a file... Or not?
    loadGame(gameinfo);
    
    beginGame(gameMode, gameinfo);
    return 0;
}

int getGameMode(){
    int option = 0;
    cout << "  Please choose one option below:" << endl;
    cout << "\t[1]\tAgent vs Human player, Human player in " << rang::fg::black << rang::bgB::red << "red";
        cout << rang::fg::reset << rang::bg::reset  << endl;
    cout << "\t[2]\tAgent vs Human player, Human player in " << rang::fg::black << rang::bgB::gray << "white";
        cout << rang::fg::reset << rang::bg::reset  << endl;;
    cout << "\t[3]\tAgent vs Agent" << endl;
    cout << "\t[4]\tHuman vs Human" << endl;
    cout << ">: ";
    while (!option)
    {
        cin >> option;
        if(option < 1 || option > 4){
            cout << "Invalid input, please try again..." << endl;
            cout <<">: ";
            option = 0;
            cin.clear();
            cin.ignore(numeric_limits <streamsize> ::max(), '\n');
        }
    }
    cout << "You have chosen option [" << option << "]:";
    switch (option)
    {
    case 1:
        cout << "\tAgent vs Human player, Human player in " << rang::fg::black << rang::bgB::red << "red";
            cout << rang::fg::reset << rang::bg::reset  << endl;
        break;
    case 2:
        cout << "\tAgent vs Human player, Human player in " << rang::fg::black << rang::bgB::gray << "white";
            cout << rang::fg::reset << rang::bg::reset  << endl;;
        break;
    case 3:
        cout << "\tAgent vs Agent" << endl;
        break;
    case 4:
        cout << "\tHuman vs Human" << endl;
    default:
        break;
    }
    return option;
}

void setTimeLimit(int gameMode, Game::info &gameinfo){
    double timeLimit;
    cout << endl;
    cout << "Please enter a time limit for agent..." << endl;
    cout << ">: ";
    cin >> timeLimit;
    
    gameinfo.timeLimit = timeLimit;
    cout << "Time limit set to " << gameinfo.timeLimit << " seconds." << endl;
}

void setStartingPlayer(Game::info &gameinfo){
    int startingPlayer = 0;
    cout << endl;
    cout << "Please decide the player to start the game... \t (1 - [" <<  rang::fg::black << rang::bgB::red << "red";
            cout << rang::fg::reset << rang::bg::reset;
        cout << "] / 2 - [" << rang::fg::black << rang::bgB::gray << "white";
            cout << rang::fg::reset << rang::bg::reset;
        cout << "])" << endl;
    cout << ">: ";

    while (!startingPlayer)
    {
        cin >> startingPlayer;
        if(startingPlayer != 1 && startingPlayer != 2){
            cout << "Invalid input, please enter '1' or '2'" << endl;
            cout <<">: ";
            startingPlayer = 0;
            cin.clear();
            cin.ignore(numeric_limits <streamsize> ::max(), '\n');
        }
    }

    gameinfo.startingPlayer = startingPlayer - 1;
    cout << "Starting player is set to ";
    switch (startingPlayer)
    {
    case 1:
        cout << rang::fg::black << rang::bgB::red << "red";
            cout << rang::fg::reset << rang::bg::reset  << endl;
        break;
    case 2:
        cout << rang::fg::black << rang::bgB::gray << "white";
            cout << rang::fg::reset << rang::bg::reset  << endl;
        break;
    default:
        break;
    }
}

void loadGame(Game::info &gameinfo){
    char load = 0;
    string filePath;
    cout << endl;
    cout << "Would you like to load a saved game?\t[y/n]" << endl;
    cout << ">: ";
    
    while(!load){
        cin >> load;
        load = tolower(load);
        if(!(load == 'y' || load == 'n')){
            load = 0;
            cin.clear();
            cin.ignore(numeric_limits <streamsize> ::max(), '\n');
            cout << "Invalid input, please enter 'y' or 'n'" << endl;
            cout << ">: ";
        }
    }
    switch (load)
    {
    case 'y':
        Game::loadFromFile = true;
        cout << "Please enter file path... " << endl;
        cout << ">: ";
        cin >> filePath;
        Game::filePath = filePath;
        break;
    default:
        break;
    }
}

void beginGame(int gameMode, Game::info &gameinfo){
    int startingPlayer = gameinfo.startingPlayer;
    double timeLimit = gameinfo.timeLimit;
    Game::checker Checker = Game::checker();

    if(Game::loadFromFile){
        Checker.loadGame(Game::filePath);
    }

    switch (gameMode)
    {
    case 1:
        Checker.startGame(false, true, startingPlayer, timeLimit);
        break;

    case 2:
        Checker.startGame(true, false, startingPlayer, timeLimit);
        break;

    case 3:
        Checker.startGame(true, true, startingPlayer, timeLimit);
        break;

    case 4:
        Checker.startGame(false, false, startingPlayer, timeLimit);
        break;
    
    default:
        break;
    }
}
