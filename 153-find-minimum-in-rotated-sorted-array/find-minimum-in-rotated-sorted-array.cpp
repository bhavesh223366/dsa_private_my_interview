class Solution {
public:
    int findMin(vector<int>& nums) {

        int start = 0;
        int end = nums.size() - 1;

        while(start < end) {

            int mid = start + (end - start) / 2;

            // Minimum is in right half
            if(nums[mid] > nums[end]) {
                start = mid + 1;
            }

            // Minimum is in left half including mid
            else {
                end = mid;
            }
        }

        return nums[start];
    }
};