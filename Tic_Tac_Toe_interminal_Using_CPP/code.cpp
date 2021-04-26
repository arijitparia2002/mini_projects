#include <iostream>
using namespace std;

class TicTacToe
{
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row_column_index[2];
    string player_nameX;
    string player_nameO;

public:
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
        {
            board[row_column_index[0]][row_column_index[1]] = inp;
            return 0;
        }
    }
    int decide_winner()
    {
        char win_char;
        int game_status = 0;
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
                win_char = board[i][0];
            else if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
                win_char = board[0][i];

            else if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
                win_char = board[1][1];
            else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
                win_char = board[1][1];
        }

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
        return game_status;
    }

    int set_value_in_slot(int slot, char input_char)
    {
        if (slot > 9)
        {
            cout << "Invalid input!!, Entere slot number between [1 to 9] " << endl
                 << endl;
            return 1;
        }

        if (put_x_o(input_char, slot))
        {
            cout << "This slot is already Taken !!" << endl
                 << endl;
            return 1;
        }
        return 0;
    }
    bool game_play()
    {
        bool if_game_done = false;
        char input_char;
        cout << " Welcome to <<TIC-TAC-TOE>> Gameplay [Made By__Arijit Paria]" << endl
             << endl;
        set_player_names();
        cout << endl;
        draw_board();

        //max 9 inputs
        for (int i = 1; i <= 9; i++)
        {
            int slot = 0;
            if (i % 2 == 0)
            {
                cout << "<<" << player_nameX << ">> It's your turn! | Enter Slot number : ";
                cin >> slot;
                input_char = 'X';
                cout << endl;
            }
            else
            {
                cout << "<<" << player_nameO << ">> It's your turn! | Enter Slot number : ";
                cin >> slot;
                input_char = 'O';
                cout << endl;
            }
            if (set_value_in_slot(slot, input_char))
            {
                i--;
                continue;
            }

            draw_board();

            if (decide_winner())
            {
                cout << "<< Thanks For Playing!! >>" << endl;
                break;
            }
            if (i == 9)
            {
                cout << "<< It's A draw !! >>" << endl;
            }
        }
        if_game_done = true;
        return if_game_done;
    }
};

int main()
{
    char input_user;
    while (1)
    {
        fflush(stdin);
        fflush(stdin);

        TicTacToe game;

        if (game.game_play())
        {
            cout << "Enter '0' to Play again, Enter '1' to Exit !" << endl;
            cin >> input_user;
            if (input_user == '0')
            {
                cout << "********************************************************************************************" << endl
                     << endl;
                continue;
            }
            else if (input_user == '1')
            {
                break;
            }
            else
            {
                cout << "Invalid Input! Exiting the game..." << endl;
                break;
            }
        }
    }

    return 0;
}
