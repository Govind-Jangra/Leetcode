class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map <int, int> m;

        for(int i=0;i<arr.size();i++){
            m[arr[i] * 2] = 0;
            if(arr[i] == 0){
                m[0] = i;
            }
        }

        for(int i=0;i<arr.size();i++){
            if(arr[i] == 0 && m[0] == i)
                continue;
            if(m.find(arr[i]) != m.end()){
                return true;
            }
        }
        return false;
    }
};