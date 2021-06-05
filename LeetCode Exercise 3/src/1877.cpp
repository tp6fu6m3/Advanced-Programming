class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int out = 0, size = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<size/2;i++){
            out = max(out, nums[i]+nums[size-i-1]);
        }
        return out;
    }
};