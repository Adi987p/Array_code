//https://leetcode.com/problems/reverse-pairs/
class Solution {
public:
int merge(vector<int>& arr, int low, int high, int mid)
    {
        vector<int>temp;
        int right = mid+1;
        int left = low;
        int count = 0;
        
        while(left<=mid && right<=high)
        {
            if(arr[right]<arr[left])
            {
                temp.push_back(arr[right]);
                right++;
            }
            else
            {
                temp.push_back(arr[left]);
                left++;
            }
        }
        
        while(left<=mid)
        {
            temp.push_back(arr[left++]);
        }
        while(right<=high)
        {
            temp.push_back(arr[right++]);
        }
        
        for(int i = low;i<=high;i++)
        {
            arr[i]=temp[i-low];
        }
        
        return count;
    }
    
    int CountReverse(vector<int>& nums, int low,int mid, int high)
    {
        int count = 0;
        int right = mid+1;

        for(int i=low;i<=mid;i++)
        {
            while(right<=high && nums[i]>2*1ll*nums[right])
                right++;
            count = count + (right - (mid+1));
        }
        return count;
    }
int mergesort(vector<int>& arr, int low, int high)
{
        int count = 0;
        if(low>=high)
            return count;
            
        int mid = (high+low)/2;
        
        count+=mergesort(arr,low,mid);
        count+=mergesort(arr,mid+1,high);
        count+=CountReverse(arr,low,mid,high);
        merge(arr,low,high,mid);
        
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        return mergesort(nums,0,n-1);
    }
};
