#include <iostream>
#include <vector>

using namespace std;

void printSolution(const vector<vector<int>> &board)
{
    int n = board.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] == 1)
            {
                cout << "Q ";
            }
            else
            {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<vector<int>> &board, int row, int col)
{
    int n = board.size();

    for (int i = 0; i < row; ++i)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j < n; --i, ++j)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

int cnt = 0;
void solveNQueens(vector<vector<int>> &board, int row)
{
    int n = board.size();
    if (row == n)
    {
        printSolution(board);
        cnt++;
        return;
    }

    for (int col = 0; col < n; ++col)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1;
            solveNQueens(board, row + 1);
            board[row][col] = 0;
        }
    }
}

void nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    solveNQueens(board, 0);
    if (cnt == 0)
    {
        cout << "No solutions exist for given board size" << endl;
        return;
    }
    cout << "Total Number of Solutions : " << cnt << endl;
}

int main()
{
    int n;
    cout << "Enter Board Size : ";
    cin >> n;
    nQueens(n);
    return 0;
}
