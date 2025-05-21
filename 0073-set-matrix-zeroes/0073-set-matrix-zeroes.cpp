class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
        int headerRow=0,headerCol=0;
        int n=nums.size(),m=nums[0].size();
        for(int i=0;i<m;i++) 
            if(nums[0][i]==0) headerRow=1;

         for(int i=0;i<n;i++) 
            if(nums[i][0]==0) headerCol=1;  

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(nums[i][j]==0){
                    nums[i][0]=0;
                    nums[0][j]=0;
                }
            }
        }  

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(nums[i][0]==0) nums[i][j]=0;
                if(nums[0][j]==0) nums[i][j]=0;
            }
        }

        if(headerRow)
        for(int i=0;i<m;i++) 
            nums[0][i]=0;

        if(headerCol)
         for(int i=0;i<n;i++) 
            nums[i][0]=0;  

    }
};