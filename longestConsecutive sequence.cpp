//https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size()==0) return 0;
        int longest = 1;
        unordered_set<int>s;

        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }

       
        for(auto i: s)
        {
            if(s.find(i-1)==s.end())
            {
                int count = 1;
                int x = i;
                while(s.find(x+1)!=s.end())
                {
                    x=x+1;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};
