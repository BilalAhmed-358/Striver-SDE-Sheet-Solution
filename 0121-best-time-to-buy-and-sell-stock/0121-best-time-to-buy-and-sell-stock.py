class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit=0
        min_element= sys.maxsize
        for i in range(len(prices)):
            min_element=min(min_element, prices[i])
            profit = prices[i] - min_element
            max_profit = max(max_profit,profit)
            # print(max_profit)
        
        return max_profit