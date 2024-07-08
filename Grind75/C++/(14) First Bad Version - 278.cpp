// placeholder for the built in leetcode function call
bool isBadVersion(int n)
{
    return true;
}

int firstBadVersion(int n)
{
    // initialize the necessary variables
    int l = 0, r = n, minBadVersion = -1; 

    // iterate while the left is less than or equal to the right pivot,
    // terminating condition is left pivot being greater than the right 
    while (l <= r)
    {
        // find the middle point within the two pivots
        int mid = l + (r - l) / 2;

        // call the helper function to check if this version is bad
        if(isBadVersion(mid))
        {
            // update minimum bad version with the current mid AND update the right pivot (r = mid - 1)
            // so we can continue moving left to get the earliest bad version
            minBadVersion = mid; 
            r = mid - 1; 
        }
        else 
        {
            // update the left pivot since the earliest minimum is somewhere on the right side
            l = mid + 1; 
        }        
    }

    // return the earliest bad version found
    return minBadVersion;
}
