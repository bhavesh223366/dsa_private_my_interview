class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int small = -1, maxcount = 0, count = 0, current = nums[0];
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]%2 == 0){
                if(i>0 && (nums[i-1]!=nums[i])){
                    current = nums[i];
                    count = 0;
                }
                count++;
                if(count>maxcount){
                    maxcount = count;
                    small = nums[i];
                }
            }
        }
        return small;
    }
};