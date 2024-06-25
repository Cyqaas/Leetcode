class Solution {
public:
    string removeNonAlphanumeric(string s)
    {
        // iterate through the whole string and erase any characters that are 
        // not alphanumeric
        for (int i = 0; i < s.size(); i++)
        {
            if (isalnum(s[i]) == 0) 
            {
                s.erase(i, 1);
                i--; 
            }
        }
        return s;
    }

    bool isPalindrome(string s) {
        // problem breakdown: 
        // remove the non-alphanumeric characters within the string
        // split the string into two pointers, one at the beginning and 
        // the other at the end. Check each string and ensure they are equal

        // one approach: remove the non-alphanumeric characters before looping
        // second approach: ignore the non-alphanumeric characters during loop

        //initialize necessary variables and transform clean string to lowercase
        string cString = removeNonAlphanumeric(s);
        transform(cString.begin(), cString.end(), cString.begin(), ::tolower);
        int i = 0;
        int j = cString.size() - 1;

        // iterate through half the string size since we are using two pointers
        for (; i < cString.size() / 2; i++) 
        {
            if (cString.at(i) != cString.at(j)) 
            {
                return false;
            }
            
            // update the second pointer
            j--;
        }

        return true;
    }
};
