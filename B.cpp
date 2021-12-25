#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
struct Node {
	int data;
	int next;
}node[maxn];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	int Next[n], prenode = 0, sum[n+1] = {0};
	for(int i = 0; i < n; i++) {
		cin >> Next[i];
		if(Next[i] != -1)sum[Next[i]]++;
	}
	for(int i = 0; i < n; i++) {
		if(sum[i] == 0) prenode = i;//找到第一个节点 
	}
	int num = 0, ans[n+1] = {0};
	while(num < n) {
		node[num].data = prenode;
		ans[node[num].data] = num + 1;
		node[num].next = Next[node[num].data];
		prenode = node[num].next;
		num++;
	}
	//for(int i=0;i<num;i++) cout << node[i].data << " " << node[i].next << endl;
	cout << ans[0];
	for(int i = 1; i < num; i++) cout << " " << ans[i];
	
	return 0;
} 
