class DSU{
public:
    vector<int> parent,rank;
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findPar(int node){
        if(parent[node]==node) return node;
        return parent[node]=findPar(parent[node]);
    }
    void UnionByRank(int u,int v){
        int ult_pu=findPar(u);
        int ult_pv=findPar(v);
        if(ult_pu==ult_pv) return;
        
        if(rank[ult_pu]<rank[ult_pv]){
            parent[ult_pu]=ult_pv;
        }
        else if(rank[ult_pv]<rank[ult_pu]){
            parent[ult_pv]=ult_pu;
        }else{
            parent[ult_pv]=ult_pu;
            rank[ult_pu]++;
        }
    }
};
class Solution {
private:
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[0]<b[0];
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, 
                vector<vector<int>>& edges) {
        //new version of edges array including its index
        vector<vector<int>> newEdges;
        for(int i=0;i<edges.size();i++){
            int index=i;
            int u=edges[i][0];
            int v=edges[i][1];
            int d=edges[i][2];
            newEdges.push_back({d,index,u,v});
        }

        sort(newEdges.begin(),newEdges.end(),cmp);

        //calc MST weight
        int mstWt=0;
        DSU ds(n);
        for(int i=0;i<newEdges.size();i++){
            int d=newEdges[i][0];
            int index=newEdges[i][1];
            int u=newEdges[i][2];
            int v=newEdges[i][3]; 

            if(ds.findPar(u)!=ds.findPar(v)){
                ds.UnionByRank(u,v);
                mstWt+=d;
            }
        }

        //Check for each edge in the sorted array: ignore/force
        vector<vector<int>> ans(2);
        //ans[0] for critical edges
        //ans[1] for pseudo critical edges of MST

        for(int i=0;i<newEdges.size();i++){
            int d=newEdges[i][0];
            int index=newEdges[i][1];
            int u=newEdges[i][2];
            int v=newEdges[i][3]; 

            //ignore the edge b/w u and v
            DSU ds1(n);
            int currmstWt=0;
            for(auto edge: newEdges){
                if(edge[1]==index) continue;
                if(ds1.findPar(edge[2])!=ds1.findPar(edge[3])){
                    ds1.UnionByRank(edge[2],edge[3]);
                    currmstWt+=edge[0];
                }
            }
            //check for noOfComponents if>1 or currmstWt>mstWt : criticalEdge
            int noOfComponents=0;
            for(int i=0;i<n;i++){
                if(ds1.findPar(i)==i) noOfComponents++;
            }
            if(currmstWt>mstWt || noOfComponents>1){
                //it is a critical edge
                ans[0].push_back(index);
            }
            //not a critical edge
            else{
                //force the edge into mst (check for pseudo critical edge)
                DSU ds2(n);
                ds2.UnionByRank(u,v);
                int currmstWt=d; //adding the wt beforehand
                for(auto edge: newEdges){
                    if(edge[1]!=index && ds2.findPar(edge[2])!=ds2.findPar(edge[3])){
                        ds2.UnionByRank(edge[2],edge[3]);
                        currmstWt+=edge[0];
                    }
                }

                if(currmstWt==mstWt){//pseudo criticalEdge
                    ans[1].push_back(index);
                }
            }
        }

        return ans;
    }
};