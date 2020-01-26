// Link https://leetcode.com/problems/rotate-image
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    int size = matrix.size();
    int temp, temp2;
    for (int i=0; i<size/2; i++){
        for (int j=i; j<=(size-2-i); j++){
        temp = matrix[j][size-1-i];
        matrix[j][size-1-i] = matrix[i][j];
        temp2 = matrix[size-1-i][size-1-j];
        matrix[size-1-i][size-1-j] = temp;
        temp = matrix[size-1-j][i];
        matrix[size-1-j][i] = temp2;
        matrix[i][j] = temp;
        }
    }  
    
    }
};