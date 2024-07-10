using namespace std;
#include <string>
#include <map>

int longestPalindrome(string s)
{
    // solution:
    // create a map of type <char, int> to keep track of the characters and number of times it appears
    // create an integer variable to keep track of the longest palindrome string
    // create a boolean flag to determine whether or not there are odd character instances
    map<char, int> mp;
    int longest = 0;
    bool flag = false;

    // add the occurrence of the current character onto the map
    for (char c : s)
    {
        mp[c]++;
    }

    // iterate through the map and update the longest palindrome length
    for (auto &it : mp)
    {
        // get the occurrences of the current char
        int occurrences = it.second;

        // conduct a check to see whether or not the length is even or odd
        // add the occurrences value iff it is even
        if (occurrences % 2 == 0)
        {
            longest += occurrences;
        }
        // subtract one from the occurrences iff it is odd
        // this is necessary to prevent any failed test cases that may arise with other odd
        // characters within the string.
        // ex: "abccccdd", this would only take into account either a or b and not both, giving us
        // the correct longest length of 7
        else
        {
            longest += occurrences - 1;
            flag = true;
        }
    }

    // add one to take into account the odd occurrences if flag is true
    return flag == true ? longest + 1 : longest;
}