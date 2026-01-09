// Brute Force Approach x
// T.C = O(N^2)
// S.C = O(N^2)

class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dummy(n, vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dummy[j][n-i-1] = matrix[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = dummy[i][j];
            }
        }
        return;
    }
};


// Optimal Approach
// T.C = O(N^2) S.C = O(1)

class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //Transpose Logic
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //Reverse
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        return;
    }
};