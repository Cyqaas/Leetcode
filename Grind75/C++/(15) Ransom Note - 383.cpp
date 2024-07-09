bool canConstruct(string ransomNote, string magazine)
{   
    // possible solution: 
    // iterate through the whole ransom note, locating every character within magazine and if 
    // we stumble across a character that is not in magazine -> return false. Otherwise, delete the 
    // current iteration of the character in both ransomNote and magazine. 
    char currChar = ' ';
    size_t pos = 0; 

    // conduct the first check 
    if (ransomNote.size() == 1 && magazine.size() == 1)
        return ransomNote == magazine; 

    // iterate through the whole ransom note and magazine length
    while (ransomNote != "" && magazine != "")
    {
        // grab the firstmost character for comparison and find its position in magazine
        currChar = ransomNote.at(0);
        pos = magazine.find(currChar);

        // conduct a check and return false if the character could not be found in the magazine
        if (pos == string::npos)
            return false;

        // otherwise, delete the char in the ransomNote and magazine
        ransomNote.erase(0, 1);
        magazine.erase(pos, 1);
    }


    // return false if there are any characters within the ransom note that were not in the magazine
    if (ransomNote != "" && magazine == "")
    {
        return false;
    }

    return true;
}
