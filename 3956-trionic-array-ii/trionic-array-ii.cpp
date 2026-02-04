class Solution {
public:
    typedef long long ll;
    int n;
    ll dp[100005][4];

    ll solve(int i, int trend, vector<int>& nums) {
        if (i == n)
            return (trend == 3 ? 0 : LLONG_MIN / 2);

        if (dp[i][trend] != -1)
            return dp[i][trend];

        ll res = LLONG_MIN / 2;

        // Skip only before starting
        if (trend == 0)
            res = solve(i + 1, 0, nums);

        // Take last element if already in final phase
        if (trend == 3)
            res = max(res, (ll)nums[i]);

        if (i + 1 < n) {
            int curr = nums[i];
            int next = nums[i + 1];

            if (trend == 0 && next > curr) {
                // start increasing
                res = max(res, curr + solve(i + 1, 1, nums));
            }
            else if (trend == 1) {
                if (next > curr)
                    res = max(res, curr + solve(i + 1, 1, nums));
                else if (next < curr)
                    res = max(res, curr + solve(i + 1, 2, nums));
            }
            else if (trend == 2) {
                if (next < curr)
                    res = max(res, curr + solve(i + 1, 2, nums));
                else if (next > curr)
                    res = max(res, curr + solve(i + 1, 3, nums));
            }
            else if (trend == 3 && next > curr) {
                res = max(res, curr + solve(i + 1, 3, nums));
            }
        }

        return dp[i][trend] = res;
    }

    ll maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, nums);
    }
};
