#include <bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>> &matrix)
{
    int col0 = -1;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            { // mark ith row
                matrix[i][0] = 0;
                // mark jth column
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (matrix[i][j] != 0)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

    if (matrix[0][0] == 0)
        for (int i = 0; i < m; i++)
            matrix[0][i] = 0;
    if (col0 == 0)
        for (int i = 0; i < n; i++)
            matrix[i][0] = 0;
}
int main()
{
    vector<vector<int>> matrix{{1, 1, 1, 1}, {1, 0, 1, 0}, {1, 1, 1, 1}};
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    setZeroes(matrix);
    cout << "After setting zeroes\n";
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}