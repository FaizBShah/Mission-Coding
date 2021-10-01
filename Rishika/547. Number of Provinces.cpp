/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/

class Solution {
public:
    void bfs(vector<vector<int>>& isConnected, int node, vector<int>&visited){
        queue<int>q;
        q.push(node);
        
        while(!q.empty()){
            visited[q.front()]=1;
            node=q.front();
            q.pop();
            
            for(int i=0;i<isConnected.size();i++){
                if(isConnected[node][i]==1 && visited[i]==0)
                    q.push(i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>visited(isConnected.size()+1,0);
        int count=0;
        for(int i=0;i<isConnected.size();i++){
            if(visited[i]==0){
                bfs(isConnected,i,visited);
                count++;
            }
        }
        
        return count;
    }
};
