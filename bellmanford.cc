//ベルマンフォード法
#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
typedef long long ll;
#define INF 1000000000000
vector<ll> dist;
vector<vector<vector<ll>>> edges;

void bellmanford(ll n){
    for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
            if(dist[j]!=INF){
                for(const auto& edge:edges[j]){
                    ll new_dist=dist[j]+edge[1];
                    if(dist[edge[0]]>new_dist)dist[edge[0]]=new_dist;
                }
            }
}

signed main(int args, char *argv[]){
    ifstream ifs(argv[1]);
    ll n,m;ifs>>n>>m;
    dist.resize(n);dist[0]=0;
    for(ll i=1;i<n;i++)dist[i]=INF;
    edges.resize(n);
    for(ll i=0;i<m;i++){
        ll a,b,c;ifs>>a>>b>>c;
        edges[a].push_back({b,c});
    }
    system_clock::time_point t1,t2;
    t1=system_clock::now();bellmanford(n);t2=system_clock::now();
    cout<<duration_cast<milliseconds>(t2-t1).count()<<endl;
}