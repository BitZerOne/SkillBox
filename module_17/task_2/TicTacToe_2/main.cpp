#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void printArray(char arr[][3], int rowsCount);
bool checkWinner(char arr[][3], int rowsCount);

int main()
{
    cout << "TicTacToe v.2.0" << endl;

    char field[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};
    int rowsNum = sizeof(field) / sizeof(field[0]);
    bool status = true;
    int counter = 1;
    do{
        char sumbol;
        std::string player;

        cout << "Please enter the coordinate of the cell!" << endl;
        if(counter % 2 != 0){
            player = "Player_1: ";
            sumbol = 'X';
        }else {
            player = "Player_2: ";
            sumbol = 'O';
        }
        cout << player;
        int row, column;
        cin >> row >> column;
        while(row < 0 || row > 3 || column < 0 || column > 3 || field[row][column] != ' '){
            cout << endl << "WARNING! \"Cell is busy or coordinates are incorrect\"!" << endl;
            cout << "Please enter the coordinate of the cell!" << endl;
            cout << player;
            cin >> row >> column;
        }

        ++counter;
        field[row][column] = sumbol;
        printArray(field, rowsNum);

        if(checkWinner(field, rowsNum)){
            cout << endl << "**** " << sumbol << " Winner! ****" << endl;
            status = false;

        }

    }while(status && counter < 10);

    if(status){
       cout << endl << "****dead heat!****" << endl;
    }


    return 0;
}

void printArray(char arr[][3], int rowsCount){

    int columnsCount = sizeof(arr[0]) / sizeof(arr[0][0]);
    for(int i =0; i < rowsCount; i++)
    {
        for (int j = 0; j < columnsCount; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWinner(char arr[][3], int rowsCount){
    if(arr[0][0] != ' ' && arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2])return true;
    if(arr[0][2] != ' ' && arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0])return true;

    for(int i =0; i < rowsCount; i++)
    {
        if((arr[i][0] != ' ' && arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2])
                || (arr[0][i] != ' ' && arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i])){
            return true;
        }
    }
    return false;

}
