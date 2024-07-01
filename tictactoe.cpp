#include <iostream>
#include <ctime> //for srand which is used to seed the random number generator
using namespace std;

//function prototypes
void Draw (char *space);
void PlayerMove (char *spaces, char player);
void ComputerMove (char *spaces, char computer);
bool CheckWin (char *spaces, char player, char computer);

int main()
{
    //create an array of 9 characters to represent the spaces on the board
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X'; //player is represented by 'X'
    char computer = 'O'; //computer is represented by 'O'
    bool run = true;
    bool isFull = false;

    Draw(spaces); //draw the board with the initial spaces

    while (run) { //while run is true
        PlayerMove (spaces, player); //player makes a move
        if (CheckWin (spaces, player, computer)) {
            run = false;
            break;
        }
        
        ComputerMove (spaces, computer); //computer makes a move
        Draw(spaces); //draw the board with the player's move
        if (CheckWin (spaces, player, computer)) {
            run = false;
            break;
        }
        
        for (int i = 0; i < 9; i++) {
            if (spaces[i] == ' ') {
                isFull = false;
                break;
            }
            else {
                isFull = true;
            }
        }

        if (isFull) {
            cout << "It's a tie!" << endl;
            run = false;
            break;
            
        }
    }
    return 0;
}

//function definitions

//function to draw the board with array of spaces
void Draw (char *spaces) {
    //display the board 
    cout << "     |     |     " << endl;
    cout << "   " << spaces[0] << " | " << spaces[1] << "   |   " << spaces[2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "   " << spaces[3] << " | " << spaces[4] << "   |   " << spaces[5] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "   " << spaces[6] << " | " << spaces[7] << "   |   " << spaces[8] << endl;
    cout << "     |     |     " << endl;
}
void PlayerMove (char *spaces, char player) {
    int move = -1;
    while (move < 0 || move > 9) {
        cout << "Enter a move (1-9): "; //prompt the player to enter a move
        cin >> move; //get the move from the player 
        move--; //decrement the move by 1 to match the index of the array and get out of the loop
        if (move < 0 || move > 8) {
            cout << "Invalid move. Move must be between 1 and 9." << endl; //if the move is not between 1 and 9, display an error message
            move = -1; //set move to -1 to prompt the player to enter a new move
        }
        else if (spaces[move] != ' ') {
            cout << "Invalid move. Space is already taken." << endl; //if the space is already taken, display an error message
            move = -1; //set move to -1 to prompt the player to enter a new move
        }
        else {
            spaces[move] = player; //set the space to the player's symbol
            break; //break out of the loop
        }
    }
}
void ComputerMove (char *spaces, char computer) {
    int move;
    if (spaces[0] == 'X') {
        if (spaces[1] == 'X' && spaces[2] == ' ') {
            spaces[2] = computer;
            return;
        }
        if (spaces[2] == 'X' && spaces[1] == ' ') {
            spaces[1] = computer;
            return;
        }
        if (spaces[3] == 'X' && spaces[6] == ' ') {
            spaces[6] = computer;
            return;
        }
        if (spaces[6] == 'X' && spaces[3] == ' ') {
            spaces[3] = computer;
            return;
        }
        if (spaces[4] == 'X' && spaces[8] == ' ') {
            spaces[8] = computer;
            return;
        }
        if (spaces[8] == 'X' && spaces[4] == ' ') {
            spaces[4] = computer;
            return;
        }
    }
    if (spaces[1] == 'X') {
        if (spaces[2] == 'X' && spaces[0] == ' ') {
            spaces[0] = computer;
            return;
        }
        if (spaces[4] == 'X' && spaces[7] == ' ') {
            spaces[7] = computer;
            return;
        }
    }
    if (spaces[2] == 'X') {
        if (spaces[1] == 'X' && spaces[0] == ' ') {
            spaces[0] = computer;
            return;
        }
        if (spaces[5] == 'X' && spaces[8] == ' ') {
            spaces[8] = computer;
            return;
        }
        if (spaces[4] == 'X' && spaces[6] == ' ') {
            spaces[6] = computer;
            return;
        }
    }

    if (spaces[3] == 'X') {
        if (spaces[0] == 'X' && spaces[6] == ' ') {
            spaces[6] = computer;
            return;
        }
        if (spaces[6] == 'X' && spaces[0] == ' ') {
            spaces[0] = computer;
            return;
        }
        if (spaces[4] == 'X' && spaces[5] == ' ') {
            spaces[5] = computer;
            return;
        }
    }
    if (spaces[4] == 'X') {
        if (spaces[0] == 'X' && spaces[8] == ' ') {
            spaces[8] = computer;
            return;
        }
        if (spaces[1] == 'X' && spaces[7] == ' ') {
            spaces[7] = computer;
            return;
        }
        if (spaces[2] == 'X' && spaces[6] == ' ') {
            spaces[6] = computer;
            return;
        }
        if (spaces[3] == 'X' && spaces[5] == ' ') {
            spaces[5] = computer;
            return;
        }
    }
    if (spaces[5] == 'X') {
        if (spaces[2] == 'X' && spaces[8] == ' ') {
            spaces[8] = computer;
            return;
        }
        if (spaces[3] == 'X' && spaces[4] == ' ') {
            spaces[4] = computer;
            return;
        }
    }
    if (spaces[6] == 'X') {
        if (spaces[0] == 'X' && spaces[3] == ' ') {
            spaces[3] = computer;
            return;
        }
        if (spaces[3] == 'X' && spaces[0] == ' ') {
            spaces[0] = computer;
            return;
        }
        if (spaces[4] == 'X' && spaces[2] == ' ') {
            spaces[2] = computer;
            return;
        }
    }
    if (spaces[7] == 'X') {
        if (spaces[1] == 'X' && spaces[4] == ' ') {
            spaces[4] = computer;
            return;
        }
        if (spaces[4] == 'X' && spaces[1] == ' ') {
            spaces[1] = computer;
            return;
        }
    }
    if (spaces[8] == 'X') {
        if (spaces[0] == 'X' && spaces[4] == ' ') {
            spaces[4] = computer;
            return;
        }
        if (spaces[2] == 'X' && spaces[5] == ' ') {
            spaces[5] = computer;
            return;
        }
        if (spaces[4] == 'X' && spaces[0] == ' ') {
            spaces[0] = computer;
            return;
        }
    }
    else {
        srand(time(0)); //seed the random number generator
        while (true) { //set while here to make sure the computer makes a move (in case the random move generated is already taken)
            move = rand() % 9; //generate a random move between 0 and 8
            if (spaces[move] == ' ') {
                spaces[move] = computer; //set the space to the computer's symbol
                break; //break out of the loop
            }
        }
    }
}
bool CheckWin (char *spaces, char player, char computer) {
    switch(spaces[0]) {
        case 'X': 
            if (spaces[1] == 'X' && spaces[2] == 'X') {
                cout << "Player wins!" << endl;
                return true;
            }
            if (spaces[3] == 'X' && spaces[6] == 'X') {
                cout << "Player wins!" << endl;   
                return true;
            }
            if (spaces[4] == 'X' && spaces[8] == 'X') {
                cout << "Player wins!" << endl;
                return true;
            }
            break;

        case 'O':
            if (spaces[1] == 'O' && spaces[2] == 'O') {
                cout << "Computer wins!" << endl;
                return true;
            }
            if (spaces[3] == 'O' && spaces[6] == 'O') {
                cout << "Computer wins!" << endl;
                return true;
            }
            if (spaces[4] == 'O' && spaces[8] == 'O') {
                cout << "Computer wins!" << endl;
                return true;
            }
            break;
        default:
            break;
    }
    switch(spaces[1]) {
        case 'X':
            if (spaces[4] == 'X' && spaces[7] == 'X') {
                cout << "Player wins!" << endl;
                return true;
            }
            break;
        case 'O':
            if (spaces[4] == 'O' && spaces[7] == 'O') {
                cout << "Computer wins!" << endl;
                return true;
            }
            break;
        default:
            break;
    }
    switch(spaces[2]) {
        case 'X':
            if (spaces[5] == 'X' && spaces[8] == 'X') {
                cout << "Player wins!" << endl;
                return true;
            }
            if (spaces[4] == 'X' && spaces[6] == 'X') {
                cout << "Player wins!" << endl;
                return true;
            }
            break;
        case 'O':
            if (spaces[5] == 'O' && spaces[8] == 'O') {
                cout << "Computer wins!" << endl;
                return true;
            }
            if (spaces[4] == 'O' && spaces[6] == 'O') {
                cout << "Computer wins!" << endl;
                return true;
            }
            break;
        default:
            break;
    }
    return 0; //return false if no win condition is met
}
