//SPFA
#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
typedef long long ll;
#define INF 1000000000000
vector<ll> dist;
vector<vector<vector<ll>>> edges;

void spfa(ll n,ll s){
    deque<ll> q;
    vector<bool> inq(n);
    vector<ll> co(n); 
    q.push_back(s);
    inq[s]=0;
    ++co[s];
    while(!q.empty()){
        ll now=q.front();
        inq[now]=false;
        for(const auto& edge:edges[now]){
            ll new_dist=dist[now]+edge[1];
            if(dist[edge[0]]>new_dist){
                dist[edge[0]]=new_dist;
                if(!inq[edge[0]] and co[edge[0]]!=n-1){
                    q.push_back(edge[0]);
                    inq[edge[0]]=true;
                    ++co[edge[0]];
                }
            }
        }
        q.pop_front();
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
    t1=system_clock::now();spfa(n,0);t2=system_clock::now();
    cout<<duration_cast<milliseconds>(t2-t1).count()<<endl;
}