#include<iostream>
using namespace std;


//Optimal Solution
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int k = j + 1;
                int l = n - 1;
                while (k < l) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    } else if (sum < target)
                        k++;
                    else if (sum > target)
                        l--;
                }
            }
        }
        return ans;
    }
};


//Brute force

//Using 4 loops for 4 differenet elemnts to point and T.C => O(N^4)


// Better Way

// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         // Size of the array
//         int n = nums.size(); 
        
//         // Set to store unique quadruplets
//         set<vector<int>> st; 

//         // Checking all possible quadruplets
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
                
//                 // Set to store elements seen so far in the loop
//                 set<long long> hashset; 
//                 for (int k = j + 1; k < n; k++) {
                    
//                     // Calculate the fourth element needed to reach target
//                     long long sum = nums[i] + nums[j];
//                     sum += nums[k];
//                     long long fourth = target - sum;
                    
//                     /* Find if fourth element exists in
//                     hashset (complements seen so far)*/
//                     if (hashset.find(fourth) != hashset.end()) {
                        
//                         // Found a quadruplet that sums up to target
//                         vector<int> temp = {nums[i], nums[j], nums[k], static_cast<int>(fourth)};
//                         // Sort the quadruplet to ensure uniqueness
//                         sort(temp.begin(), temp.end()); 
//                         st.insert(temp);
                        
//                     }
                    
//                     // Insert the kth element into hashset for future checks
//                     hashset.insert(nums[k]);
//                 }
//             }
//         }
        
//         // Convert set to vector (unique quadruplets)
//         vector<vector<int>> ans(st.begin(), st.end());
//         return ans;
//     }
// };




int main() {
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    
    // Create an instance of Solution class
    Solution sol;
    
    vector<vector<int>> ans = sol.fourSum(nums, target);  
    // Print the result
    cout << "The quadruplets are: \n";
    for (auto& it : ans) {
        cout << "[";
        for (auto& ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";   
    return 0;
}