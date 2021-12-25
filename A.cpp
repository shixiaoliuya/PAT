#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,m;
	cin >> n >> m;
	map<int,int>ans;
	while(m--) {
		int R[n + 1] = {0};
		double Max = 0;
		map<int,int>mp;
		for(int i = 1;i <= n; i++) {
			cin >> R[i];
			mp[R[i]]++;
		}
		for(auto &i:mp) Max = max(Max, (n - i.second * 1.0) / n);
		//cout << Max << endl;
		for(int i = 1; i <= n; i++) {
			if((n - mp[R[i]] * 1.0) / n == Max) ans[i]++;
			//cout << n-mp[R[i]] << "/" << n << " ";
		}
		//cout << endl << endl;
		//mp.clear();
	}
	int res = 0;
	for(auto &i:ans) if(i.second > res) res = i.second;
	for(auto &i:ans) if(i.second == res) cout << i.first;
	
	return 0;
} 
