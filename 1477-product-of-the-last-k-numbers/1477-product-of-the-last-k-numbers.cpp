class ProductOfNumbers {
    vector<int> a;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        a.push_back(num);
    }
    
    int getProduct(int k) {
        int n = a.size();
        int ans = 1;
        for(int i=n-1; i>n-1-k; i--){
            ans = ans * a[i];
        }
        return ans;
    }
};

