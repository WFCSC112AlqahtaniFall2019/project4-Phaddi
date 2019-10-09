/* Class: TicTacToe
 * Author: Ryan Phadnis
 * Due on Oct 9 2019
 * CSC 112
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
#include <ctime>
using namespace std;

int main() {
    TicTacToe game; //object declaration
    int numPlayers;
    bool valid;
    int row;
    int col;
    int playerSel;

    cout << "How many players? (Enter 1 or 2)" << endl;
    cin >> numPlayers;
    if(numPlayers != 1 && numPlayers != 2)
    {
        cout << "Number of players has to be 1 or 2" << endl;
    }

    if(numPlayers == 2) //starting two player game
    {
        cout << "2 players selected" << endl;
        while(!game.isBoardFull() && !game.checkForWin()) //checks every turn to see if there is a winner / draw
        {
            game.printBoard();
            if(game.getCurrentPlayerNumber() == 1) //player 1's turn
            {
                cout << "It is X's turn to play" << endl;
                cout << "Enter row, column: " << endl;
                cin >> row;
                cin >> col;
                while(row > 3 || row < 1 || col > 3 || col < 1) //makes sure that the values entered are on the board
                {
                    cout << "Row and column values must be between 1 and 3" << endl;
                    cout << "It is X's turn to play" << endl;
                    cout << "Enter row, column: " << endl;
                    cin >> row;
                    cin >> col;
                }
                valid = true; //this boolean says if the selected spot on the board is already taken
                if(!game.placeMark(row - 1, col - 1))
                {
                    valid = false;
                }
                while(!valid)
                {
                    cout << "That spot is already filled, try again: " << endl;
                    cin >> row;
                    cin >> col;
                    valid = true;
                    if(!game.placeMark(row - 1, col - 1))
                    {
                        valid = false;
                    }
                }
                game.placeMark(row-1,col-1); //now that everything is checked, places the mark
            }
            else
            {
                cout << "It is O's turn to play" << endl; //now it is player 2's turn, everything will be the same as player 1
                cout << "Enter row, column: " << endl;
                cin >> row;
                cin >> col;
                while(row > 3 || row < 1 || col > 3 || col < 1)
                {
                    cout << "Row and column values must be between 1 and 3" << endl;
                    cout << "It is X's turn to play" << endl;
                    cout << "Enter row, column: " << endl;
                    cin >> row;
                    cin >> col;
                }
                valid = true;
                if(!game.placeMark(row - 1, col - 1))
                {
                    valid = false;
                }
                while(!valid)
                {
                    cout << "That spot is already filled, try again: " << endl;
                    cin >> row;
                    cin >> col;
                    valid = true;
                    if(!game.placeMark(row - 1, col - 1))
                    {
                        valid = false;
                    }
                }
                game.placeMark(row-1,col-1);
            }
            game.changePlayer(); //changes the player after the turn
        }
        if(game.checkForWin())  //checks for winner
        {
            game.printBoard();
            game.changePlayer();
            cout << "Player " << game.getCurrentPlayerNumber() << " wins!" << endl;
        }
        else // if no winner, but board is filled, must be a cats game
        {
            game.printBoard();
            cout << "Cats Game!" << endl;
        }
    }
    else
    {
        cout << "1 player selected" << endl; //one player game started
        srand(time(0));
        playerSel = rand() % 2; //human player is randomly given either X's or O's
        if(playerSel == 1)
        {
            game.changePlayer();
            cout << "You are player " << game.getCurrentPlayerNumber() << " playing as the O's" << endl;
        }
        else
        {
            cout << "You are player " << game.getCurrentPlayerNumber() << " playing as the X's" << endl;
        }
        if(game.getCurrentPlayerNumber() == 2) //makes it possible for computer to start, ensures that X goes first
        {
            game.changePlayer();
            cout << "X went first" << endl;
        }
        while(!game.isBoardFull() && !game.checkForWin()) //same requirements that the two player game has
        {
            if(game.getCurrentPlayerNumber() == 1 && playerSel != 1) //if human player is X and it is X's turn
            {
                game.printBoard();
                cout << "It is your turn, X's" << endl;
                cout << "Enter row, column: " << endl;
                cin >> row;
                cin >> col;
                while (row > 3 || col > 3 || row < 1 || col < 1) {
                    cout << "Row and column values must be between 1 and 3" << endl;
                    cin >> row;
                    cin >> col;
                }
                valid = true;
                if (game.placeMark(row - 1, col - 1) == false) {
                    valid = false;
                }
                while (valid == false) {
                    valid = true;
                    cout << "That spot is filled, try again" << endl;
                    cin >> row;
                    cin >> col;
                    if (game.placeMark(row - 1, col - 1) == false) {
                        valid = false;
                    }
                }
                game.placeMark(row-1,col-1);
            }
            else if (game.getCurrentPlayerNumber() == 2 && playerSel != 1) //if human player is O but it is X's turn
            {
                cout << "It is X's turn: " << endl;
                row = rand() % 3;
                col = rand() % 3;
                valid = true;
                if(!game.placeMark(row, col))
                {
                    valid = false;
                }
                while(!valid)
                {
                    row = rand() % 3;
                    col = rand() % 3;
                    valid = true;
                    if(!game.placeMark(row, col))
                    {
                        valid = false;
                    }
                }
                game.placeMark(row, col);
            }
            else if(game.getCurrentPlayerNumber() == 2 && playerSel == 1) //if human player is O and it is O's turn
            {
                game.printBoard();
                cout << "It is your turn, O's" << endl;
                cout << "Enter row, column: " << endl;
                cin >> row;
                cin >> col;
                while (row > 3 || col > 3 || row < 1 || col < 1) {
                    cout << "Row and column values must be between 1 and 3" << endl;
                    cin >> row;
                    cin >> col;
                }
                valid = true;
                if (game.placeMark(row - 1, col - 1) == false) {
                    valid = false;
                }
                while (valid == false) {
                    valid = true;
                    cout << "That spot is filled, try again" << endl;
                    cin >> row;
                    cin >> col;
                    if (game.placeMark(row - 1, col - 1) == false) {
                        valid = false;
                    }
                }
                game.placeMark(row-1,col-1);
            }
            else if(game.getCurrentPlayerNumber() == 1 && playerSel == 1) //if human player is X but it is O's turn
            {
                cout << "It is O's turn: " << endl;
                row = rand() % 3;
                col = rand() % 3;
                valid = true;
                if(!game.placeMark(row, col))
                {
                    valid = false;
                }
                while(!valid)
                {
                    row = rand() % 3;
                    col = rand() % 3;
                    valid = true;
                    if(!game.placeMark(row, col))
                    {
                        valid = false;
                    }
                }
                game.placeMark(row, col);
            }
            game.changePlayer();
        }
        if(game.checkForWin()) //same check for winner / cats game as two player game
        {
            game.printBoard();
            game.changePlayer();
            cout << "Player " << game.getCurrentPlayerNumber() << " wins!" << endl;
        }
        else
        {
            game.printBoard();
            cout << "Cats Game!" << endl;
        }
    }

    return 0;
}