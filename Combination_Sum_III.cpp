class Solution {
public:
    vector<vector<int>> comb;

    int sum(vector<int> nums)
    {
        int s=0;
        for(auto i: nums) s+=i;
        return s;
    }

    void rec(vector<int> nums, int k, int n, int q)
    {
        if(q > 9) return ;

        if(k == 0)
        {
            if(sum(nums) == n) comb.push_back(nums);
            return ;
        }
        vector<int> nm;
        int p = sum(nums);

        for(int i = q+1;i<=(n-p);i++)
        {
            nm = nums;
            nm.push_back(i);
            rec(nm, k-1,n,i);

        }

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        
        for(int i = 1;i<=n/2;i++)
        {
            rec(vector<int>{i}, k-1, n, i);
        }

        return comb;

    }
};
