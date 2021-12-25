#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
struct node {
	vector<int>child;
}Node[maxn];
int sum[maxn] = {0};
int dfs(int root) {
	for(int i = 0; i < Node[root].child.size(); i++) {
		sum[root] = sum[root] + dfs(Node[root].child[i]);
	}
	return sum[root] + 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	int a[n + 1];
	for(int i = 2; i <= n; i++) {
		cin >> a[i];
		Node[a[i]].child.push_back(i);
	}
	int m;
	cin >> m;
	dfs(1);
	while(m--) {
		int root;
		cin >> root;
		cout << sum[root] + 1 << "\n";
	}
	
	return 0;
} 
