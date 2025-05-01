//https://leetcode.com/problems/find-missing-and-repeated-values/
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n = grid.size();
        int Xor =0;
        for(int i =0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                Xor = Xor^grid[i][j];
            }
        }

        for(int i =0;i<n*n;i++)
        {
                Xor = Xor^(i+1);
        }

        int bitnum=0;

        while(1)
        {
            if((Xor & (1<<bitnum))!=0)
                break;
            else
                bitnum++;
        }

        int zero = 0;
        int one = 0;
        for(int i =0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if((grid[i][j] & (1<<bitnum))!=0)
                    one = one ^ grid[i][j];
                else
                    zero = zero ^ grid[i][j];
            }
        }

        for(int i =0;i<n*n;i++)
        {
            if(((i+1) & (1<<bitnum))!=0)
                    one = one ^ (i+1);
                else
                    zero = zero ^ (i+1);
        }

        int cnt=0;
         for(int i =0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]==zero)
                    cnt++;
            }
        }

        if(cnt == 2)
            return {zero, one};
        else
            return {one, zero};

    }
};
