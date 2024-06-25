class Solution {
public:
    bool isAnagram(string s, string t) {
    // start time: 2:34pm 
    // end time: 2:40pm 
    
    // problem breakdown: 
    // compare two strings and determine if they contain the same letters
    // but are worded differently

    // possible solution(s):
    // gather the two strings, sort them alphabetically then compare the two
    // to see if they are equal

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t; 
    }
};
