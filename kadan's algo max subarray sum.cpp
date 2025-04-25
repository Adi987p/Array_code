//https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum =0;
        int maxsum = INT_MIN;
        int n = nums.size();

    int start =0;
    int ansstart =-1;
    int ansend =-1;
        for(int i=0;i<n;i++)
        {
            if (sum==0)
                start = i;

            sum+=nums[i];

            if(sum>maxsum)
            {
                maxsum = sum;
                //if want to print the length
                ansstart = start;
                ansend = i;
            }

            if(sum<0)
            {
                sum =0;
            }
        }

        return maxsum;
    }
};
