class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // problem breakdown: 
        // help choosing stock where the value to buy is low (minimum)
        // and selling said stock where the value to buy is high (maximum)
        // conditions: 
        // must sell after the low's index (cannot move backwards in time)

        map<int, int> minMap; 
        map<int, int> maxMap;  
        int n = prices.size(); 
        int maxProfit = 0; 
        int currProfit = 0;
        int currPrice = 0;  

        // iterate through the whole vector of prices
        for (int i = 0; i < n; i++)
        {
            currPrice = prices[i];

            // initialize a minimum
            if (minMap.size() == 0) 
            {
                minMap.insert({i+1, currPrice});
            }
            // initialize a maximum if its greater than the minimum
            else if (maxMap.size() == 0 && currPrice > minMap.begin()->second) 
            {
                maxMap.insert({i+1, currPrice});
            } 
            // otherwise, compare current iteration to the minimum and clear
            // maximum if minimum is reset
            else if (currPrice < minMap.begin()->second) 
            {
                minMap.clear(); 
                maxMap.clear(); 
                minMap.insert({i+1, currPrice});
            }
            // or else, compare current iteration to the maximum for profit
            else if (currPrice > maxMap.begin()->second) 
            {
                maxMap.clear(); 
                maxMap.insert({i+1, currPrice});
            }

            // declare new max profit if necessary 
            currProfit = maxMap.begin()->second - minMap.begin()->second; 
            if (currProfit > maxProfit)
            {
                maxProfit = currProfit; 
            } 
        }

        // return the maxProfit
       return maxProfit; 
    }
};
