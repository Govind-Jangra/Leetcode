class Solution {
public:
int M=1e9+7;
  	vector<string> totalString;
	void generate(string temp, char prev, int m){
    
		if(m==0){
			totalString.push_back(temp);
			return;
		}

		string colors = "RGB";
		for(auto &color: colors){
			if(color!=prev)
				generate(temp+color, color, m-1);
		}

	}


	int dp[250][1001];
	long long noOfWays(int i, int col, vector<vector<int>> &adj){

		if(col==0) return 1;
		else if(dp[i][col]!=-1) return dp[i][col];

		int ways = 0;
		for(auto v: adj[i]){
			ways = (ways + noOfWays(v, col-1, adj)) % M;
		}

		return dp[i][col] = ways;
	}

	public:
	int colorTheGrid(int m, int n) {
	
		generate("", '*', m);

		int X = totalString.size();
		vector<vector<int>> adj(X);

		for(int i=0;i<X;i++){
			for(int j=0;j<X;j++){

				bool flag = true;
				for(int k=0;k<m;k++){
					if(totalString[i][k]==totalString[j][k]){
						flag = false; break;
					}
				}
				if(flag)
					adj[i].push_back(j);

			}
		}

	
		memset(dp, -1, sizeof(dp));
		int ans = 0;
		for(int i=0;i<X;i++){
			ans = (ans + noOfWays(i, n-1, adj)) % M;
		}

		return ans;

	}
};