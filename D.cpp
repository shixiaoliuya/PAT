#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
struct Node{
	int time;
	int y;
	int p;
}node[1010];
int dis[1010][1010], n, vis[1010];
void floyd(){
	for(int k = 0; k <= n; ++k)
		for(int i = 0; i <= n; ++i)
			for(int j = 0; j <= n; ++j)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
int main() {
	int m, k, start, u, v, w, maxp = INT_MIN, mintime = INT_MAX;
	scanf("%d%d", &n, &m);
	fill(dis[0], dis[0] + 1010 * 1010, inf);
	for(int i = 0; i <= n; ++i) dis[i][i] = 0;
	int x, y;
	scanf("%d:%d", &x, &y);
	start = x * 60 + y;
	for(int i = 1; i <= n; ++i){
		scanf("%d:%d", &x, &y);
		node[i].time = x * 60 + y;
		scanf("%d%d", &node[i].y, &node[i].p);
	}
	while(m--) {
		scanf("%d%d%d", &u, &v, &w);
		dis[u][v] = dis[v][u] = min(dis[u][v], w);
	}
	floyd();
	scanf("%d", &k);
	while(k--) {
		memset(vis, 0, sizeof vis);
		int now = start, pay = 0;
		bool flag = true;
		x = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &y);
			if(!flag) continue;
			if(vis[y] || dis[x][y] == inf) flag = false;
			if(now + dis[x][y] <= node[y].time) {
				pay += node[y].y;
			}
			else {
				pay += node[y].y - node[y].p;
			}
			now += dis[x][y];
			vis[y] = 1;
			x = y;
		}
		if(!flag) continue;
		now += dis[x][0];
		if(pay > maxp) {
			maxp = pay;
			mintime = now;
		}
		else if(pay == maxp && now < mintime) {
			mintime = now;
		}
	}
	printf("%d %02d:%02d", maxp, (mintime/60) % 24, mintime % 60);
	
	return 0;
} 
