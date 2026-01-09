#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return {-1, -1};
        int start = 0, end = n - 1;
        vector<int> ans;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] > target) {
                end = mid - 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else if (nums[mid] == target) {
                int startTemp = mid, endTemp = mid;
                while (startTemp > 0 && nums[startTemp - 1] == nums[startTemp]) {
                    startTemp--;
                }
                ans.push_back(startTemp);
            
                while (endTemp < n - 1 && nums[endTemp + 1] == nums[endTemp]) {
                    endTemp++;
                }
                ans.push_back(endTemp);
                return ans;
            }
        }
        return {-1, -1};
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    vector<int> result1 = solution.searchRange(nums1, target1);
    cout << "Test 1: [" << result1[0] << ", " << result1[1] << "]" << endl;
    
    // Test case 2
    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    int target2 = 6;
    vector<int> result2 = solution.searchRange(nums2, target2);
    cout << "Test 2: [" << result2[0] << ", " << result2[1] << "]" << endl;
    
    // Test case 3
    vector<int> nums3 = {};
    int target3 = 0;
    vector<int> result3 = solution.searchRange(nums3, target3);
    cout << "Test 3: [" << result3[0] << ", " << result3[1] << "]" << endl;
    
    // Test case 4
    vector<int> nums4 = {1};
    int target4 = 1;
    vector<int> result4 = solution.searchRange(nums4, target4);
    cout << "Test 4: [" << result4[0] << ", " << result4[1] << "]" << endl;
    
    return 0;
}

/**Expected Output:**
```
Test 1: [3, 4]
Test 2: [-1, -1]
Test 3: [-1, -1]
Test 4: [0, 0]*/