#include <iostream>
#include <vector>
#include <string>

using namespace std;
void printqueen(vector<vector<char>> queen)
{
    int n = queen.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << queen[i][j] << " ";
        }

        cout << endl;
    }

    cout << "...................." << endl;
}
bool isSafe(vector<vector<char>> solveNQueen, int rows, int cols)
{
    int n = solveNQueen.size();
    for(int i =0;i < n;i++){
         if (solveNQueen[rows][i] == 'Q')
        {
            return false;
        }
    }
    
    // check column above (vertically check)
    for (int i = 0; i < rows; i++)
    {
        if (solveNQueen[i][cols] == 'Q')
        {
            return false;
        }
    }
    
    // check left diagonal (up-left)
    for (int i = rows, j = cols; i >= 0 && j >= 0; i--, j--)
    {
        if (solveNQueen[i][j] == 'Q')
        {
            return false;
        }
    }

    // check right diagonal (up-right)
    for (int i = rows, j = cols; i >= 0 && j < n; i--, j++)
    {
        if (solveNQueen[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void solveQueens(vector<vector<char>>& solveNQueen, int rows)
{
    int n = solveNQueen.size();
    if (rows == n)
    {
        printqueen(solveNQueen);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(solveNQueen, rows, i))
        {
            solveNQueen[rows][i] = 'Q';
            solveQueens(solveNQueen, rows + 1);
            solveNQueen[rows][i] = '.';
        }
    }
}

int main()
{
    vector<vector<char>> solveNQueen;
    int n = 4;

    for (int i = 0; i < n; i++)
    {
        vector<char> temp;
        for (int j = 0; j < n; j++)
        {
            temp.push_back('.');
        }

        solveNQueen.push_back(temp);
    }
    solveQueens(solveNQueen, 0);
    return 0;
}