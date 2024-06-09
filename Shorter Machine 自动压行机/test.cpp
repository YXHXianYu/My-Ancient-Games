#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#define REG register
#define LLI long long
#define DBL double
#define CHR char
#define BOL bool
const int MXN = 310;
const int MXM = 410;

inline int read() {
	int x=0;CHR ch=getchar();while(ch<45)ch=getchar();
	while(ch>45)x=10*x+ch-48,ch=getchar();return x;
}

int n, m, K;

struct Edge {int to, next;} e[MXM];
int tot = 1, last[MXN];
void addedge(int fm, int to) {
	e[++tot] = (Edge){to, last[fm]}, last[fm] = tot;
}

int mem[5][MXN],
	tag[MXN],
	f[MXN],
	g[MXN],
	ans = 1<<30;

void dfs(int k) {
	REG int i, j, u, v, ansv = 0, ansp;
	memset(f, 0, 4*(n+1));
	memset(g, 0, 4*(n+1));
	for(v = 1; v <= n; v++) {
		if(tag[v]) continue;
		for(j = last[v]; j; j = e[j].next) {
			u = e[j].to;
			if(tag[u]) continue;
			if(f[v] < f[u] + 1) f[v] = f[u] + 1, g[v] = u;
		}
		if(ansv < f[v] + 1) {
			ansv = f[v] + 1, ansp = v;
			if(k == K && ansv >= ans) return;
		}
	}
	ans = std::min(ans, ansv);
	if(k == K) return;
	for(j = 0, i = ansp; i; i = g[i])
		mem[k][++j] = i;
	for(i = 1; i <= j; i++)
		if(k + 1 < K || std::max(i - 1, ansv - i) < ans) {
			tag[mem[k][i]] = 1;
			dfs(k + 1);
			tag[mem[k][i]] = 0;
		}
}

int main() {
	//freopen("template.in", "r", stdin);
	//freopen("template.out", "w", stdout);
	REG int i, j, k, u, v, t = read();
	
	while(t--) {
		tot = 0; memset(last, 0, sizeof last);
		n = read(), m = read(), K = read();
		for(i = 1; i <= m; i++)
			addedge(read(), read());
		if(n == K) {printf("0\n");continue;}
		if(n == K - 1) {printf("1\n");continue;}
		ans = n;
		dfs(0);
		printf("%d\n", ans);
	}
	
	return 0;
}

