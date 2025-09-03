#include <iostream>
using namespace std;

//------------------------------------------------//
//                                                //
// Structure Definitions                          //
//                                                //
//------------------------------------------------//

struct Player
{
    int win, loss, draw;
    string name, fullname;
    bool previousWinner;
    char piece;
    
};

//------------------------------------------------//
//                                                //
// Function Prototypes                            //
//                                                //
//------------------------------------------------//

void displayBoard(char board[]);
void playerStats(Player& one, Player& two,int& turn,int& turnkeeper);
void clearBoard(char board[],Player& one,Player& two);
bool checkWinner(char board[],Player& one, Player& two);
void printWinner(char board[],Player& one);
string splitName(Player& one);



int main()
{
    Player one;
    Player two;
    one.piece = 'o';
    two.piece = 'x';
    string answer = "yes";
    int turn, turnkeeper;
    char choice;
    char board[9];
    one.win = 0, one.loss  = 0,one.draw = 0;
    two.win = 0, two.loss  = 0,two.draw = 0;
    
    cout << "Enter the name of Player One(1): ";
    getline(cin,one.fullname);
    splitName(one);

    cout << "Enter the name of Player Two(2): ";
    getline(cin,two.fullname);
    splitName(two);

    cout << "Choose what player goes first (enter 1 or 2): ";
    cin >> turn;


    while (answer == "yes")
    {
        turnkeeper = 0;
        clearBoard(board, one, two);
        while (turnkeeper < 9 && !checkWinner(board, one, two)) 
        {
            if (turn %2 == 1) 
            {
               cout << one.name << " it's your turn: ";
               cin >> choice;
               cout << endl;
                for (int i = 0; i < 9; i++) 
                    {
                        if(board[i] == choice)
                        {
                            board[i] = one.piece; 
                        }
                    }
                    turn++;
                    turnkeeper++;
                    displayBoard (board);
                }

            else if (turn %2 == 0) 
             {
                cout << two.name << " it's your turn: ";
                cin >> choice;
                cout<< endl;
                for (int i = 0; i < 9; i++) 
                {
                    if(board[i] == choice)
                    {
                        board[i] = two.piece;
                    }
                }
                turn++;
                turnkeeper++;
                displayBoard(board);
            }
        } 
            playerStats(one, two, turn, turnkeeper);
            cout << "Do you want to continue? Type yes to continue or no to quit: ";
            cin >> answer;
    }

}

//------------------------------------------------//
//                                                //
// Displays Tic-Tac-Toe Board                     //
//                                                //
//------------------------------------------------//

void displayBoard(char board[])
{
    cout << "*---*---*---*\n"
         << "| " << board[0] << " | " << board[1] << " | " << board[2] << " | \n"
         << "*---+---+---*\n"
          << "| " << board[3] << " | " << board[4] << " | " << board[5] << " | \n"
         << "*---+---+---*\n"
          << "| " << board[6] << " | " << board[7] << " | " << board[8] << " | \n"
         << "*---*---*---*\n";
}


//------------------------------------------------//
//                                                //
// Displays Player Stats                          //
//                                                //
//------------------------------------------------//

void playerStats(Player& one, Player& two,int& turn,int& turnkeeper)
{
    if(one.previousWinner == true)
    {
        cout << one.name << " has won the game!\n";
        turn = 1;
                                                                
    } 
    
    else if(two.previousWinner == true) 
    {
        cout << endl << two.fullname << " has won the game!" << endl << endl;
        turn = 2;
    } 
    
    else if(turnkeeper == 9)
    {
        cout << "The game resulted in a draw.\n";
        one.draw++;
        two.draw++;
    }

    cout << one.fullname << " you have " << one.win << " wins, " << one.loss << " losses, and " << one.draw << " draws\n";
    cout << two.fullname << " you have " << two.win << " wins, " << two.loss << " losses, and  " << two.draw << " draws\n";
         
}


//------------------------------------------------//
//                                                //
// Initializes the Board                          //
//                                                //
//------------------------------------------------//

void clearBoard(char board[],Player& one,Player& two)
{
    one.previousWinner = false;
    two.previousWinner = false;
    
    char b2[9] = {'2','6','3','9','1','7','5','8','4'};
   
    for(int i = 0;i<9;i++)
    {
        board[i]=b2[i];
    }

     cout << "*---*---*---*\n"
         << "| " << board[0] << " | " << board[1] << " | " << board[2] << " | \n"
         << "*---+---+---*\n"
          << "| " << board[3] << " | " << board[4] << " | " << board[5] << " | \n"
         << "*---+---+---*\n"
          << "| " << board[6] << " | " << board[7] << " | " << board[8] << " | \n"
         << "*---*---*---*\n";
}


//------------------------------------------------//
//                                                //
// Checks for Winner & Increments Results         //
//                                                //
//------------------------------------------------//

bool checkWinner(char board[],Player& one, Player& two)
{
    char winner = ' ';
    for (int i = 0; i <= 6; i+=3) 
    {
        if(board[i] == board[i+1] && board[i] == board[i+2])
        {
            winner = board[i]; 
        }
    }

    for(int i = 0; i <=  2; i++) 
    {
        if(board[i] == board[i+3] && board[i] == board[i+6]) 
        {
            winner = board[i];
        }
    }

    if(board[0] == board[4] && board[0] == board[8])
    {
        winner = board[4];
    }
    
    if(board[2] == board[4] && board[2] == board[6])
    {
        winner = board[4];
    }

    if(winner == one.piece)
    {
        one.win++;
        two.loss++;
        one.previousWinner = true;
        return true;
    }

    else if(winner == two.piece)
    {
        two.win++;
        one.loss++;
        two.previousWinner = true; 
        return true;
    } 
    else 
    {
        return false;
    }
}


//------------------------------------------------//
//                                                //
// Prints Winner Case in Uppercase                //
//                                                //
//------------------------------------------------//

void printWinner(char board[],Player& one)
{
     for (int i = 0; i < 6; i+=3) 
    {
        if(toupper(board[i]) == toupper(board[i+1]) && toupper(board[i]) == toupper(board[i+2]))
        {
            board[i] = toupper(one.piece);
            board[i+1] = toupper(one.piece);
            board[i+2] = toupper(one.piece);
        }
    }

    for(int i = 0; i < 2; i++) 
    {
        if(toupper(board[i]) == toupper(board[i+3]) && toupper(board[i]) == toupper(board[i+6])) 
        {
            board[i] = toupper(one.piece);
            board[i+1] = toupper(one.piece);
            board[i+2] = toupper(one.piece);
        }
    }

    if(toupper(board[0]) == toupper(board[4]) && toupper(board[0]) == toupper(board[8]))
    {
            board[0] = toupper(one.piece);
            board[4] = toupper(one.piece);
            board[8] = toupper(one.piece);
    }
    
    if(toupper(board[2]) == toupper(board[4]) && toupper(board[2]) == toupper(board[6]))
    {
            board[2] = toupper(one.piece);
            board[4] = toupper(one.piece);
            board[6] = toupper(one.piece);
    }
 }


//------------------------------------------------//
//                                                //
// Splits name when necessary                     //
//                                                //
//------------------------------------------------//

string splitName(Player& one)
{   
    int spaceindex;
    spaceindex =  one.fullname.find(' ');
    one.name = one.fullname.substr(0,spaceindex);
    return one.name;
}