int climbStairs(int n)
{
    // Tabulation: bottom-up approach, stores the results of subproblems in a table, iterative
    // implementation, well suited for problems with a large set of inputs, used when the subproblems
    // do not overlap

    // base cases when n = 0 or 1
    if (n == 0 || n == 1)
        return 1;

    // initialize a vector dp of n+1 to get all values up to n
    vector<int> dp(n + 1);

    // ensure the base case values 0 and 1 are set to 1
    dp[0] = dp[1] = 1;

    // start at i = 2 since there is only 1 way to climb 0 or 1 set of stairs
    for (int i = 2; i <= n; i++)
    {
        // the current value of n is going to be one step and or taking two steps at a time
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];

    // Memoization: top-down approach, caches the results of function calls, recursive implementation,
    // well suited for problems with a relatively small set of inputs, used when the subproblems have
    // overlapping subproblems

    // Explanation:
    // There are two ways to climb steps, 1 or 2 steps at a time. Hence we have to get the previous,
    // n-1 and n-2 steps for the given value of n.
}
