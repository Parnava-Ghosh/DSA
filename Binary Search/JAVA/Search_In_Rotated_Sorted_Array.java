import java.util.Scanner;

public class Search_In_Rotated_Sorted_Array {

    public static int search(int[] nums, int k) {
        int length = nums.length;
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

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        int[] nums = new int[n];

        System.out.print("Enter elements: ");
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        System.out.print("Enter target: ");
        int k = sc.nextInt();

        int result = search(nums, k);

        System.out.println("Index: " + result);

        sc.close();
    }
}