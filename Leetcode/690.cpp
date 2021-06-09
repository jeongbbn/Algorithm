class Solution {
public:
    vector<int>adj[2005];
    
    int dfs(int node){
        int sum = 0;
        for(int i=1; i < adj[node].size(); i++){
            sum += dfs(adj[node][i]);
        }
        return adj[node][0] + sum;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        
        for(int i=0;i<employees.size(); i++){
            int x = employees[i]->id;
            vector<int>tmp = employees[i]->subordinates;
            adj[x].push_back(employees[i]->importance);
            for(int j=0;j<tmp.size(); j++){
                adj[x].push_back(tmp[j]);
            }
        }
        
        int ans = dfs(id);
        return ans;
    }
};
