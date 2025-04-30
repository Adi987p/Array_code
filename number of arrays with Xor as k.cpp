//https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/0

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        unordered_map<int, int>m;
        int count =0;
        int Xor = 0;
        m[0]=1;
        
        for(int i=0;i<n;i++)
        {
            Xor = Xor^arr[i];
            
            int x = Xor^k;
            if(m.find(x)!=m.end())
            {
                count+=m[x];
            }
            m[Xor]++;
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
