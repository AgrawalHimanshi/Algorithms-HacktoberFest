#include <iostream>
using namespace std;
bool ratinMaze(char maze[10][10],int sol[10][10],int i,int j,int m,int n){
    if(i==m && j==n){
        sol[m][n]=1;
        for(int r=0;r<=m;r++){
            for(int c=0;c<=n;c++){
                cout<<sol[r][c];
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    //mouse doesn't cross grid
    if(i>m || j>n)
    return false;

    if(maze[i][j]=='X'){
        return false;
    }
    //assume ans to be true
    sol[i][j]=1;
    bool rightpath=ratinMaze(maze,sol,i,j+1,m,n);
    bool downpath=ratinMaze(maze,sol,i+1,j,m,n);
    //backtrack to find all possible paths;
    sol[i][j]=0;
    if(rightpath || downpath ){
        return true;
    }
    return false;
}
int main() {
   char maze[10][10]={
                        "000X",
                        "0X00",
                        "00X0"
                        "0000"
                    };
int sol[10][10]={0};
int m=4,n=4;
ratinMaze(maze,sol,0,0,m-1,n-1);
return 0;
}
