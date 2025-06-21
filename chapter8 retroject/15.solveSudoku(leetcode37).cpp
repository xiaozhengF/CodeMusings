#include <vector>
using namespace std;
class Solution
{
public:
    bool isValid(int row, int col, char c, vector<vector<char>> &board)
    {
        for (int i = 0; i < board[row].size(); i++)
        {
            if (board[row][i] == c)
                return false;
        }
        for (int j = 0; j < board.size(); j++)
        {
            if (board[j][col] == c)
                return false;
        }
        int startRow = (row / 3) * 3, startCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[startRow + i][startCol + j] == c)
                    return false;
            }
        }
        return true;
    }
    bool backTracking(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isValid(i, j, c, board))
                        {
                            board[i][j] = c;
                            bool result = backTracking(board);
                            if (result)
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        backTracking(board);
    }
};