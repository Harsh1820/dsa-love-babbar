#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void transpose(vector<vector<int>>& matrix , int row , int col){
        for(int i = 0; i<row ; i++){
            for(int j = 0 ; j<i ; j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
        return ;
}
    
    
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        transpose(matrix , row , col);
        for(int i = 0 ; i<row ; i++){
            reverse(matrix[i].begin() , matrix[i].end());
        }
        return ;
        
    }
};