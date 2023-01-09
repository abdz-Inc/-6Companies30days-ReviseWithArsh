class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        int i = 0, j = nums.size()-1, n = nums.size()-1, k = 0;
        int max = INT_MIN, rsum= 0, sum=0;

        for(int i = 0;i<=n;i++)
        {
            rsum+=i*nums[i];
            sum+=nums[i];
        }
        max = rsum;
        for(int i = nums.size()-1;i>0;i--)
        {
            rsum = rsum+sum - (n+1)*nums[i];
            if(rsum>max) max = rsum;
        }
        

        return max;

    }
};
