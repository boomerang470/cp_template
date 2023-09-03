//Size Optimization
struct DSU{
    map<int,int> parent;
    map<int,int> size;
    void make_set(int v){
        parent[v]=v;
        size[v]=1;
    }

    int find_parent(int v){
        if(v==parent[v]) return v;
        return parent[v]=find_parent(parent[v]);
    }

    void union_sets(int a,int b){
        a = find_parent(a);
        b = find_parent(b);

        if(a!=b){
            if(size[a]<size[b]) swap(a,b);
            parent[b]=a;
            size[a] += size[b];
        }
    }
};

//Rank optimization

struct DSU{
    map<int,int> parent;
    map<int,int> rank;

    void make_set(int v){
        parent[v]=v;
        rank[v]=0;
    }


    int find_parent(int v){
        if(v==parent[v]) return v;
        return parent[v]=find_parent(parent[v]);
    }

    void union_sets(int a,int b){
        a = find_parent(a);
        b = find_parent(b);

        if(a!=b){
            if(rank[a]<rank[b]) swap(a,b);
            parent[b]=a;
            if(rank[a]==rank[b]) rank[a]++;
        }
    }
};
