class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count_0=0, count_1=0, count_2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                count_0++;
            else if(nums[i]==1)
                count_1++;
            else
                count_2++;
        }
        
        // cout<<count_0<<count_1<<count_2<<endl;
        for(int i=0;i<count_0;i++)
            nums[i]=0;
        
        
        for(int i=count_0;i<count_1+count_0;i++)
            nums[i]=1;
        
        for(int i=count_1+count_0;i<count_2+count_1+count_0;i++)
            nums[i]=2;
    }
};