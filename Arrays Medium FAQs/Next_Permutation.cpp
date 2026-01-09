#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> permute(vector<int>& arr) {
    vector<vector<int>> result;
    
    void backtrack(int start) {
        // TODO: Base case - check if we've filled all positions
        // If yes, save a COPY of the current array to result
        
        
        // TODO: Loop through all remaining elements (from start to end of array)
        
            // TODO: Swap current element with start position
            
            
            // TODO: Recurse to fill the next position
            
            
            // TODO: Backtrack - swap back to restore original order
            
    }
    
    // Start the recursion from position 0
    backtrack(0);
    return result;
}


// Test your function
int main() {
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> perms = permute(arr);
    
    // Print results
    for(auto& perm : perms) {
        cout << "[";
        for(int i = 0; i < perm.size(); i++) {
            cout << perm[i];
            if(i < perm.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}