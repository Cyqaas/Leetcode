class Solution {
public:
    bool isValid(string s) {
        // return false if the size of the string is 1 
        int n = s.size();

        if (n == 1 ) 
            return false;

        // use a stack to keep track of the parantheses
        stack<char> stck; 

        for (int i = 0; i < n; i++) 
        {
            // get the current character to add and or compare
            char curr = s.at(i);

            // add it onto the stack if it's an opening parantheses
            if (curr == '(' || curr == '{' || curr == '[')
            {
                stck.push(curr);
            }
            // with closing parantheses, grab the most recently added opening
            // parantheses and compare them to ensure they are the same type
            else 
            {
                // return false if we begin with a closing brace
                if (stck.size() == 0) 
                    return false;

                // top method is going to give reference to MRU char without
                // removing it from the stack
                char compare = stck.top(); 

                switch (compare) 
                {
                    case '(':
                        if (curr != ')') 
                            return false; 
                        break;
                    case '{':
                        if (curr != '}')    
                            return false; 
                        break;
                    case '[':
                        if (curr != ']') 
                            return false; 
                        break;
                }

                // remove the reference from the stack when we pass the check
                stck.pop(); 
            }
        } 

        // return false if there is anything left on the stack
        if (stck.size() != 0) 
            return false;

        // string has valid parantheses
        return true; 
    }
};
