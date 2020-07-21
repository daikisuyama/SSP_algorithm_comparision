//ダイクストラ法
#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
typedef long long ll;
#define INF 1000000000000
vector<ll> dist;
vector<vector<vector<ll>>> edges;

void dijkstra(ll n,ll f){
    priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> q;
    q.push({0,f});
    while(!q.empty()){
        vector<ll> next=q.top();q.pop();
        if(dist[next[1]]<=next[0]) continue;
        dist[next[1]]=next[0];
        for(const auto& edge:edges[next[1]]){
            if(dist[edge[0]]<=next[0]+edge[1]) continue;
            q.push({next[0]+edge[1],edge[0]});
        }
    }
}

signed main(int args, char *argv[]){
    ifstream ifs(argv[1]);
    ll n,m;ifs>>n>>m;
    dist.resize(n);
    for(ll i=0;i<n;i++)dist[i]=INF;
    edges.resize(n);
    for(ll i=0;i<m;i++){
        ll a,b,c;ifs>>a>>b>>c;
        edges[a].push_back({b,c});
    }
    system_clock::time_point t1,t2;
    t1=system_clock::now();dijkstra(n,0);t2=system_clock::now();
    cout<<duration_cast<milliseconds>(t2-t1).count()<<endl;
}