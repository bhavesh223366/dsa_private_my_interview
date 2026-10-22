class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> asc(n), desc, rev(nums.rbegin(), nums.rend());
        iota(asc.begin(), asc.end(), 0);
        desc.assign(asc.rbegin(), asc.rend());
        int best = INT_MAX;

        auto test = [&](vector<int> a, int target, vector<int>& goal, int cost) {
            int j = find(a.begin(), a.end(), target) - a.begin();
            rotate(a.begin(), a.begin() + j, a.end());
            if (a == goal) best = min(best, cost + j);
        };

        test(nums, 0, asc, 0);
        test(rev, 0, asc, 1);
        test(nums, n - 1, desc, 1);
        test(rev, n - 1, desc, 2);

        return best == INT_MAX ? -1 : best;
    }
};