class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int mark=-1;
        vector<int> holder;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                mark=i;
                break;
                
            }
            
        }
        if(mark==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        
        for(int j=nums.size()-1;j>mark;j--)
        {
            if(nums[j]>nums[mark])
            {
                swap(nums[j],nums[mark]);
                break;
            }
        }
        reverse(nums.begin()+mark+1,nums.end());
        
    }
};