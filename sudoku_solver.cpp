#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
bool canUse(vvi &v, int i, int j, int k)
{
    for (int x = 0; x < 9; x++)
        if (v[i][x] == k)
            return false;
    for (int x = 0; x < 9; x++)
        if (v[x][j] == k)
            return false;
    int a = i - i % 3;
    int b = j - j % 3;
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (v[row + a][col + b] == k)
                return false;
    return true;
}
void print(vvi &v)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
}
bool solve(vvi &v)
{
    int i = 0, j = 0;
    bool key = false;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (v[i][j] == 0)
            {

                key = true;
                break;
            }
        }
        if (key)
            break;
    }
    if (!key)
    {
        print(v);
        return true;
    }
    for (int k = 1; k <= 9; k++)
    {
        if (canUse(v, i, j, k))
        {
            v[i][j] = k;
            if (solve(v))
                return true;
            v[i][j] = 0;
        }
    }
    return false;
}
int main()
{
    cout << "For the 9x9 sudoku board, enter the initial state" << endl;
    cout << "Note: For empty spot, enter 0!" << endl
         << endl;
    vvi v(9, vi(9));
    for (int i = 0; i < 9; i++)
    {
        cout << "Enter the row " << i + 1 << ": ";
        for (int j = 0; j < 9; j++)
        {
            char x;
            cin >> x;
            if (x == '-')
                x = '0';
            v[i][j] = x - '0';
        }
    }
    cout << "One of the possible solutions is: " << endl;
    while (!solve(v))
        ;
    cout << endl
         << endl
         << endl;
}