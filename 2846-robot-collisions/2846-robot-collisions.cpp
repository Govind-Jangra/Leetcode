	class Solution {
		public:
			vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h, string d) {
				vector<int> r=p;
				int n=p.size();
				vector<tuple<int,int,char>> v;
				for(int i=0;i<n;i++) v.push_back({p[i],h[i],d[i]});
				sort(v.begin(),v.end());

				stack<pair<int,int>> st;
				int a,b; char c;
				vector<pair<int,int>> temp;
				for(int i=0;i<n;i++){
					tie(a,b,c)=v[i];
					if(c=='R')
						st.push({a,b});
					else{
						if(st.empty()) temp.push_back({a,b});
						else{
							while(!st.empty()){
								if(st.top().second>b){
									st.top().second--;
									b=0;
									break;
								}
								else if(st.top().second==b){
									st.pop();
									b=0;
									break;
								}
								else{
									b--;
									st.pop();
								}
							}
							if(b) temp.push_back({a,b});
						}
					}
				}

				while(!st.empty()){
					temp.push_back(st.top());
					st.pop();
				}

				map<int,int> m;
				for(auto i:temp) m[i.first]=i.second;

				vector<int> ans;
				for(int i=0;i<n;i++){
					if(m[r[i]]) ans.push_back(m[r[i]]);
				}
				return ans;
			}
		};