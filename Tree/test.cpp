//h       inf  ind
vector<pair<int, pair<int, int>>> arr;
int SIZE = 2200 + 5;
vector<int> tree(SIZE);
class Solution {
public:

    void build(int st, int end, int tree_node, int sz){
        if(st == end){
            tree[tree_node] = 1;
            return;
        }
        
        int mid = (st + end)/2;
        
        build(st, mid, tree_node+1, sz);
        build(mid+1, end, tree_node + 2*(mid - st + 1), sz);
        
        tree[tree_node] = tree[tree_node + 1] + tree[tree_node + 2*(mid - st + 1)]; 
    }
    
    int query_and_up(int st, int end, int tree_node, int x){
        
        if(st == end){
            tree[tree_node] = 0;
            return st;
        }
        
        int mid = ( st + end )/2;
        
        if(tree[tree_node + 1] < x){
            x = x - tree[tree_node + 1];
            int ret = query_and_up(mid+1, end, tree_node + 2*(mid - st + 1), x);
            tree[tree_node] = tree[tree_node+1] + tree[tree_node + 2*(mid - st + 1)];
            return ret;
        }
        else{
            int ret = query_and_up(st, mid, tree_node + 1, x);
            tree[tree_node] = tree[tree_node+1] + tree[tree_node + 2*(mid - st + 1)];
            return ret;
        }

    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        arr.clear();
        tree.clear();
        int n = people.size();
        vector<vector<int>> ans(n);
        if(n==0) return ans;
        sort(people.begin(), people.end());
        for(int i=0;i<n;i++){
            arr.push_back({people[i][0], {people[i][1], i}});
        }
        
        int tmp_h = arr[0].first;
        int cnt = 0;
        for(int i=1;i<n;i++){
            int c_h = arr[i].first;
            if(c_h == tmp_h){
                arr[i].second.first -= (++cnt);
            }
            else{
                cnt = 0;
            }
            tmp_h = c_h;
        }
        
        
        int sz = 2*n-1;
        
        build(0, n-1, 0, sz);
        // for(int i=0;i<sz;i++) cout<<tree[i]<<" ";
        // cout<<endl;
       
        
        
        for(int i=0;i<n;i++){
            int f = people[i][0]; 
            int s = people[i][1];
            int x = arr[i].second.first + 1;
            // cout<<f<<" "<<s<<" "<<x;
            int a = query_and_up(0, n-1, 0, x);
            ans[a].push_back(f);
            ans[a].push_back(s);
            
            // cout<<" ans for this: "<<a<<endl;
        }
        
        return ans;
    }
};