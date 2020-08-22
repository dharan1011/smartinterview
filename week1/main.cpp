#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)        for (i = 0; i < n; ++i) 
#define REP(i,k,n)      for (i = k; i < n; ++i) 
#define REPR(i,k,n)     for (i = k; i >= n; --i)
#define w(x)            int x; cin>>x; while(x--)
#define mk(arr,n,type)  type *arr=new type[n];
#define inrange(i, a, b) ((i >= min(a, b)) && (i <= max(a, b)))
#define fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll              long long
typedef pair<int,int>   pii;
typedef pair<long,long> pl;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<pl>      vpl;
typedef vector<vi>      vvi;
const int mod = 1000000007;

void dfs(vector<int> grid[],vector<bool> vis,int src, int dest){
    if(src == dest){
        return ;
    }
    vis[src] = true;
    for(int child : grid[src]){
        if(!vis[child])
            dfs(grid, vis, child, dest);
    }
}

void bfs(vector<int> adj[], int src, int N){
    vector<int> dist(N, -1);
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

void modifiedBfs(vector<int> adj[], int src, int N){
    vector<bool> vis(N);
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
            int u = q.front(); q.pop();
            for(int v : adj[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[u] = true;
                }
            }
        }
    }
}

int main() {
    fast
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cout << "Hello, World";
    return 0;
}
