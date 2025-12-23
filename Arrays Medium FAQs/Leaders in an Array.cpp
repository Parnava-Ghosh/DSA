//Brute Force
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
      int n = nums.size();
      vector<int> leaderArr;
      for(int i=0;i<n-2;i++){
        bool Leader = true;
        for(int j=i+1;j<n-1;j++){
            if(nums[j] > nums[i]){
                Leader = false;
            }
        }
        if(Leader == true){
            curr.push_back(nums[i]);
        }
      }
    }
};

// Optimal Approach Space=O(N), Time=O(N)
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
      int n = nums.size();
      vector<int> curr;
      int max = INT_MIN;
      for(int i=n-1;i>=0;i--){
        if(nums[i] > max){
          curr.push_back(nums[i]);
          max = nums[i];
        }
      }
      reverse(curr.begin(), curr.end());
      return curr;
    }
};