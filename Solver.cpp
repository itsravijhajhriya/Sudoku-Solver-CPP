#include <iostream>
#include <vector>
using namespace std;
bool isGood(vector<vector<int>> & Sudoku , int row , int col , int num ){
    for( int i =0; i<9 ; ++i){
        if(Sudoku[row][i]==num){
            return false;
        }
    }
    for( int i =0; i<9 ; ++i){
        if(Sudoku[i][col]==num){
            return false;
        }
    }
    int nrow = row- row%3;
    int ncol = col - col%3;
    for( int i=0 ; i<3; ++i){
        for( int j=0 ; j<3 ; ++j){
            if(Sudoku[i+nrow][ncol+j]==num){
                return false;
            }
        }
    }
    return true;
}
bool solver(vector<vector<int>> & Sudoku, int i , int j){
    if(i==9){
        return true;
    }

        if(Sudoku[i][j]!=0){
            return solver(Sudoku , i+ (j+1)/9 , (j+1)%9);
        }
        
        for(int m=1 ; m<10 ; ++m){
            if(isGood(Sudoku , i ,j , m)){
                Sudoku[i][j]=m;
                if(solver(Sudoku , i+ (j+1)/9 , (j+1)%9)){
                    return true;
                }
                Sudoku[i][j]=0;
            }
        }
     return false;
    
}
int main(){
     vector<vector<int>> Sudoku = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 7, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    bool ans = solver(Sudoku, 0 , 0);
    cout<<ans;
    cout<<endl;
    for( int i =0 ; i<9 ; ++i){
        for( int j=0 ; j<9 ; ++j){
            cout<<Sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
    
}