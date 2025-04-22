//https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
class Solution {
public:
    bool check(vector<int>& nums) {
        
        int pos=1;
        int n = nums.size();

        while(pos<n && nums[pos]>=nums[pos-1])
            pos++;

        if(pos == n) return true;
        if(nums[pos]>nums[0]) return false;
        if(pos == n-1) return true;

        pos+=1;

        while(pos<n && nums[pos] <=nums[0] && nums[pos]>=nums[pos-1])
            pos++;

        return pos==n;
    }
};
