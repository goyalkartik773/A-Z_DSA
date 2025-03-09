#include<iostream>
#include<vector>
using namespace std;
bool can_place_queen(vector<vector<char>>& grid,int row,int col,int n)
{
// column check
    for(int i=row-1; i>=0; i--)
    {
        if(grid[i][col] == 'Q')
            return false;
    }
// left diagonal check
    for(int i=row-1,j=col-1; i>=0 && j>=0; i--,j--)
    {
        if(grid[i][j]=='Q')
            return false;
    }
// right diagonal check
    for(int i=row-1,j=col+1; i>=0 && j<n; i--,j++)
    {
        if(grid[i][j]=='Q')
            return false;
    }
    return true;
}
void place_queen(vector<vector<char>>& grid,int row,int n)
{
    if(row == n)
    {
        // solution mil gaya
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    for(int col = 0; col<n; col++)
    {
        if(can_place_queen(grid,row,col,n))
        {
            grid[row][col] = 'Q';
            place_queen(grid,row+1,n);
            grid[row][col] = '.';
        }
    }
    return;
}
int main()
{
    int rows = 8;
    int cols = 8;
    vector<vector<char>> grid(rows,vector<char>(cols,'.'));
    place_queen(grid,0,8);
}
