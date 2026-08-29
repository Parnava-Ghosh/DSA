#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int k) {
    int length = nums.size();
    int left = 0, right = length - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Target found
        if (nums[mid] == k) {
            return mid;
        }

        // Left half is sorted
        if (nums[left] <= nums[mid]) {
            // Target lies in the sorted left half
            if (k >= nums[left] && k <= nums[mid]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        // Right half is sorted
        else {
            // Target lies in the sorted right half
            if (k >= nums[mid] && k <= nums[right]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }

    // Target not found
    return -1;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cout << "Enter target: ";
    cin >> k;

    int result = search(nums, k);

    cout << "Index: " << result << endl;

    return 0;
}