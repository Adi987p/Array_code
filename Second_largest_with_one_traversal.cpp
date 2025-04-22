//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largest=arr[0];
        int secondlarge=-1;
        
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]>largest )
            {
                secondlarge = largest;
                largest = arr[i];
            }
            else if(arr[i]>secondlarge && arr[i]!=largest)
                secondlarge = arr[i];
        }
        
        return secondlarge;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
