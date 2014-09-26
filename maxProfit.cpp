/*
Best Time to Buy and Sell Stock II Total Accepted: 23234 Total Submissions: 63155 My Submissions
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

*/

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int i = 0 ;
		int profit = 0;
		int cur ;
		if(prices.size() == 0){
			return 0;
		}
		cur = prices[0] ;

		
        for (i = 1; i < prices.size(); i++){
			int temp = cur ;
			cur = prices[i] ;
			if(cur > temp){
				profit += cur - temp ;
			}
		}
		return profit;
	}
};
