#include <iostream>
using namespace std;

class TicTacToe
{
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row_column_index[2];

public:
    string player_nameX;
    string player_nameO;
    int game_status = 0;
    void set_player_names()
    {
        cout << "Enter the name of Player X :" << endl;
        getline(cin, player_nameX);
        cout << "Enter the name of Player O :" << endl;
        getline(cin, player_nameO);
    }
    void draw_board(void)
    {
        cout << "  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl
             << " -----------" << endl;
        cout << "  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl
             << " -----------" << endl;
        cout << "  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl
             << endl;
    }

    void find_row_column(int slot_num)
    {
        int row, column;
        //Find the row number[0 1 2]
        if (slot_num % 3 != 0)
            row = slot_num / 3;
        else
            row = (slot_num / 3) - 1;
        //Find column number[0 1 2]
        if (slot_num % 3 != 0)
            column = (slot_num % 3) - 1;
        else
            column = 2;
        //setting value
        row_column_index[0] = row;
        row_column_index[1] = column;
    }

    int put_x_o(char inp, int slot_num)
    {
        find_row_column(slot_num);
        if (board[row_column_index[0]][row_column_index[1]] == 'X' || board[row_column_index[0]][row_column_index[1]] == 'O')
            return 1;
        else
            board[row_column_index[0]][row_column_index[1]] = inp;
        return 0;
    }
    void decide_winner()
    {
        char win_char;
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
                win_char = board[i][0];
            else if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
                win_char = board[0][i];
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
            win_char = board[1][1];
        if (win_char == 'X')
        {
            cout << "Congratulations!! "
                 << "The Winner is <<" << player_nameX << ">>" << endl;
            game_status = 1;
        }
        if (win_char == 'O')
        {
            cout << "Congratulations!! "
                 << "The Winner is <<" << player_nameO << ">>" << endl;
            game_status = 1;
        }
    }
};
int gameplay()
{
    TicTacToe game;

    cout << " Welcome to <<TIC-TAC-TOE>> Gameplay [Made By__Arijit Paria]" << endl
         << endl;
    game.set_player_names();
    cout << endl;
    game.draw_board();

    int i = 0;
    int slot;
    char input_char;
    while (1)
    {

        if (i % 2 == 0)
        {
            cout << "<<" << game.player_nameX << ">> It's your turn! | Enter Slot number : ";
            input_char = 'X';
        }
        else
        {
            cout << "<<" << game.player_nameO << ">> It's your turn! | Enter Slot number : ";
            input_char = 'O';
        }
        cin >> slot;
        cout << endl;

        if (slot > 9)
        {
            cout << "Invalid input!!, Entere slot number between [1 to 9] " << endl
                 << endl;
            continue;
        }

        if (game.put_x_o(input_char, slot))
        {
            cout << "This slot is already Taken !!" << endl
                 << endl;
            continue;
        }
        game.draw_board();
        if (i > 3)
        {
            game.decide_winner();
            if (game.game_status)
            {
                cout << "<< Thanks For Playing!! >>" << endl;
                break;
            }
        }
        i++;
    }
    return 1;
}

int main()
{
    while (1)
    {
        char key;
        if (gameplay())
        {
            cout << endl
                 << "Press [SPACE] to play again | Press [ENTER] to exit!" << endl;
            cin >> key;
            if (key == ' ')
                continue;
            else if (key == '\n')
                break;
            else
            {
                cout << "Invalid Input ! Exiting the game ..." << endl;
                break;
            }
        }
    }

    return 0;
}