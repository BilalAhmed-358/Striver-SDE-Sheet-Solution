class Solution:
    def sortColors(self, nums: List[int]) -> None:
        low=0;
        mid=0;
        high=len(nums)-1;
        for i in range(mid,len(nums)):
            if(mid > high):
                break
            if(nums[mid] == 0):
                nums[low],nums[mid] = nums[mid],nums[low]
                mid+=1
                low+=1
                # print("first block")
                # print("Iteration",i,nums)
                # print("low:",low," mid:",mid," high:",high," i:",i," nums[i]:",nums[i])
            elif(nums[mid] == 1):
                mid+=1
                # print("second block")
                # print("Iteration",i,nums)
                # print("low:",low," mid:",mid," high:",high," i:",i," nums[i]:",nums[i])


            elif(nums[mid] == 2):
                nums[high],nums[mid] = nums[mid],nums[high]
                high-=1
                # print("third block")
                # print("Iteration",i,nums)
                # print("low:",low," mid:",mid," high:",high," i:",i," nums[i]:",nums[i])
