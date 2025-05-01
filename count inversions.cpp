//https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to count inversions in the array.
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
                count += (mid-left+1);
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
    
    int mergesort(vector<int>& arr, int low, int high)
    {
        int count = 0;
        if(low>=high)
            return count;
            
        int mid = (high+low)/2;
        
        count+=mergesort(arr,low,mid);
        count+=mergesort(arr,mid+1,high);
        count+=merge(arr,low,high,mid);
        
        return count;
    }
    
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int n = arr.size();
        return mergesort(arr,0,n-1);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
