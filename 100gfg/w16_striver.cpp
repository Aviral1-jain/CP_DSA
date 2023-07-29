#include <iostream>
using namespace std;

//https://ide.geeksforgeeks.org/FYBzssmmW3
void treeQueries() {
    // input 
    
    
    dfs(1);
    int q;
    cin >> q; 
    while(q--) {
        int num;
        cin >> num;
        vector<int> nodes;
        int deepest = 1; 
        for(int i = 0;i<num;i++) {
            int x;
            cin >> x;
            nodes.pb(x); 
            if(level[x] > level[deepest]) deepest = x; 
        }
        
        // figure out if every node lies on the path or at a distance of 1 
        int fl = 1; 
        for(int i = 0;i<num;i++) {
            int lc = lca(deepest, node[i]); 
            if(lc != node[i]) {
                int dist = dis(lc, node[i]); 
                if(dist > 1) {
                    fl = 0;
                    break; 
                }
            }
        }
        if(fl == 0) cout << "No"; 
        else cout << "Yes"; 
    }
    
}
int vis[1000005]; 
void bfs(int node) {
    vis[node] = 1; 
    queue<int> q;
    q.push(node); 
    
    while(!q.empty()) {
        int node = q.front(); 
        q.pop(); 
        
        for(auto it : adj[node]) {
            if(!vis[it]) {
                q.push(it); 
                vis[it] = 1; 
            }
        }
    }
}

void dfs(int node) {
    vis[node] = 1; 
    for(auto it : adj[node]) {
         if(!vis[it]) {
             dfs(it); 
         }
    }
    st.push(node); 
}

bool cycleDetectionUG(int node, int par) {
    vis[node] = 1; 
    for(auto it : adj[node]) {
        if(vis[it] == 0) {
            if(cycleDetectionUG(it, node) == true) return true; 
        } else if(it!=par) return true; 
    }
    return false; 
}

bool cycleDetectionDG(int node) {
    pathVis[node] = vis[node] = 1; 
    for(auto it : adj[node]) {
        if(vis[it] == 0) {
            if(cycleDetectionDG(it) == true) return true; 
        }
        else if(pathVis[it] == 1) {
            return true; 
        }
    }
    pathVis[node] = 0;
    return false; 
}

void cycle() {
    bool flag = false; 
    for(int i = 1;i<=n;i++) {
        if(!vis[i]) {
            flag = flag | cycleDetectionDG(i, 0); 
        }
    }
    if(flag == 1) cout << "yes";
    else cout << "no"; 
}
vector<int> adj[26];
bool vis[26]; 
stack<char> st; 
void topoSort(int node) {
    vis[node] = 1; 
    for(auto it : adj[node]) {
         if(!vis[it]) {
             dfs(it); 
         }
    }
    st.push(node + 'a'); 
}
void foxAndNames() {
    int n;
    cin >> n;
    vector<string> vec; 
    for(int i = 0;i<n;i++) {
        string s;
        cin >> s;
        
        vec.push_back(s); 
    }
    
    for(int i = 0;i<n-1;i++) {
        string s1 = vec[i]; 
        string s2 = vec[i+1]; 
        for(int j = 0;j<s1.size();j++) {
            // s1 = "rajiv", s2 = "raj"
            if(j>=s2.size()) {
               cout << "Impossible\n";  
               return;
            }
            // s1 = "raj", s2 = "rtr"
            if(s1[j] != s2[j]) {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a'); 
                break; 
            }
        }
    }
    bool flag = false; 
    for(int i = 0;i<=25;i++) {
        if(!vis[i]) {
            flag = flag | cycleDetectionDG(i); 
        }
    }
    if(flag) {
        cout << "Impossible";
        return;
    }
    
    // print the topo sort which will be your answer 
    
    for(int i = 0;i<=25;i++) {
        if(!vis[i]) {
            topoSort(i); 
        }
    }
    
    while(!st.empty()) {
        cout << st.top();
        st.pop(); 
    }
}

int tin[100005], mini[1000005]; 
int t = 1; 
void findBridges(int node, int par = 0) {
    vis[node] = 1; 
    tin[node] = mini[node] = t++; 
    
    for(auto it : adj[node]) {
        if(it == par) continue; 
        if(vis[it] == 0) {
            dfs(it, node); 
            mini[node] = min(mini[node], mini[it]); 
            if(mini[it] > tin[node]) {
                printBridge(it, node); 
            }
        }
        else {
            mini[node] = min(mini[node], tin[it]); 
        }
    }
}
vector<pair<int,int>> adj[100005]; 

void findShortes(int src, int n) {
    int dist[n+1]; 
    // assign to infinity 
    
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
    pq.push({0, src}); 
    
    while(!pq.empty()) {
        auto node = pq.top().second;
        auto dis = pq.top().first; 
        pq.pop(); 
        
        for(auto el : adj[node]) {
            int it = el.first;
            int wt = el.second; 
            if(dis + wt < dist[it]) {
                dist[it] = dis + wt; 
                pq.push({dist[it], it});
            }
        }
    }
    
    for(int i = 0;i<n;i++) {
        cout << dist[i] << " "; 
    }
}
void djisktra() {
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<m;i++) {
        int u, v, w;
        cin >> u >> v >> w; 
        adj[u].pb({v, w}); 
        adj[v].pb({u, w});
    }
    
    int src; 
    cin >> src;
    
    findShortes(src,n); 
}
















int main() {
	cout<<"GfG!";
	return 0;
}