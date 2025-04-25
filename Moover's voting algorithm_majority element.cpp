//https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int n = nums.size();

        int count = 0;
        int ele;

        for(int i=0;i<n;i++)
        {
            if(count == 0)
            {
                ele = nums[i];
                count++;
            }
            else if(nums[i]==ele)
                count++;
            else
                count--;
        }
        return ele;
    }
};
