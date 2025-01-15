class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ones=0;
        while(num2){
            num2&=(num2-1);
            ones++;
        }
        int res=0;
        for(int i=31;i>=0 && ones>0;i--){
            if((num1>>i)&1){
                res|=(1<<i);
                ones--;
            }
        }
        for(int i=0;i<32 && ones>0;i++){
            if(((res>>i)&1)==0){
                res|=(1<<i);
                ones--;
            }
        }
        return res;
    }
};