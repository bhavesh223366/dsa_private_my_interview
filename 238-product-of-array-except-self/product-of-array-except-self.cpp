class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n, 1);
        // vector<int> prefix(n,1);
        // vector<int> suffix(n,1);

        // brute force approach
        // for(int i = 0; i < n; i++) {

        //     for(int j = 0; j < n; j++) {

        //         if(i != j) {
        //             ans[i] *= nums[j];
        //         }
        //     }
        // }

        // building prefix array
        // for(int i = 1; i < n; i++) {
        //     prefix[i] = prefix[i-1] * nums[i-1];
        // }

        // building suffix array
        // for(int i = n-2; i >= 0; i--) {
        //     suffix[i] = suffix[i+1] * nums[i+1];
        // }

        // multiplying prefix and suffix
        // for(int i = 0; i < n; i++) {
        //     ans[i] = prefix[i] * suffix[i];
        // }
        // MORE OPTIMAL USING THE ARRAY 0(N) AND 0(1) SPACE COMPLEXITYY 

        // Step 1: Accumulate the prefix products directly into ans
        // ans[i] will store the product of all elements to the left of i
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // Step 2: Multiply by suffix products on the fly from right to left
        int suffix = 1;
        for (int j = n - 1; j >= 0; j--) {
            ans[j] *= suffix;     // Multiply current prefix product with the total suffix product
            suffix *= nums[j];    // Update the suffix product for the next element to the left
        }
        return ans;
    }
};