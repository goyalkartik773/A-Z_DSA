#include<iostream>
#include<vector>
using namespace std;
bool is_safe(vector<vector<char>>& board,int row,int col,int num,int n)
{
// row check
    for(int i=0; i<n; i++)
    {
        if(board[row][i]-'0'==num)
            return false;
    }
// col check
    for(int i=0; i<n; i++)
    {
        if(board[i][col]-'0'==num)
            return false;
    }
// big matrix check
    int x = (row/3)*3;
    int y = (col/3)*3;
//(x,y) is the starting positon of big matrix
    for(int i=x; i<x+3; i++)
    {
        for(int j=y; j<y+3; j++)
        {
            if(board[i][j]-'0'==num)
                return false;
        }
    }
    return true;
}
bool sudoko_solver(vector<vector<char>>& board,int row,int col,int n)
{
    if(row==n) // puri sudoko solve hogaya
    return true;
    if(col == n)
    return sudoko_solver(board,row+1,0,n); // ek puri row fill hogayi move to the next row
    if(board[row][col]!='.')
    {
        // continue to the next position
      return  sudoko_solver(board,row,col+1,n);
    }
    else
    {
        // position kahali hai fill karega isme
        for(int i=1; i<=n; i++)
        {
            // backtracking approach 1 sai lekar 9 tak sare no dalana ka try karegea
            if(is_safe(board,row,col,i,n))
            {
                // agar 1 to 9 mai sai ith no place karnna safe hai to place it first
                board[row][col]='0'+i;
                if(sudoko_solver(board,row,col+1,n))
                    return true;
                board[row][col]='.';
            }
        }
    }
    return false;
}
int main()
{
    vector<vector<char>> board =
    {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    bool flag =sudoko_solver(board,0,0,9);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

