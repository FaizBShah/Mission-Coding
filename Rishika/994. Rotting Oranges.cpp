/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/

class Solution {
public:
    bool isvalid(int i, int j, int r, int c){
        return (i>=0 &&j>=0 && i<r && j<c);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        pair<int,int>temp;
        int time=0;
        //1.process all the rotten oranges
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        
        //2.set a seperator
        
        q.push({-1,-1});
        
        //3.perform bfs
        
        while(!q.empty()){
            //set a flag to check the timeline
            bool flag=false;
            
            while(q.front().first!=-1 &&q.front().second!=-1){
                
                
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                //check right
                if(isvalid(x+1,y,grid.size(),grid[0].size()) && grid[x+1][y]==1){
                    if(!flag){
                        flag=true;
                        time++;
                    }
                    //make the orange rotten
                    grid[x+1][y]=2;
                    q.push({x+1,y});
                }
                //check left
                if(isvalid(x-1,y,grid.size(),grid[0].size()) && grid[x-1][y]==1){
                    if(!flag){
                        flag=true;
                        time++;
                    }
                    //make the orange rotten
                    grid[x-1][y]=2;
                    q.push({x-1,y});
                }
                //check top
                if(isvalid(x,y-1,grid.size(),grid[0].size()) && grid[x][y-1]==1){
                    if(!flag){
                        flag=true;
                        time++;
                    }
                    //make the orange rotten
                    grid[x][y-1]=2;
                    q.push({x,y-1});
                }
                //check bottom
                if(isvalid(x,y+1,grid.size(),grid[0].size()) && grid[x][y+1]==1){
                    if(!flag){
                        flag=true;
                        time++;
                    }
                    //make the orange rotten
                    grid[x][y+1]=2;
                    q.push({x,y+1});
                }
                
            }
            //pop the seperator
            q.pop();
            if(!q.empty()){
                q.push({-1,-1});
            }
        }
        //check whether all oranges are rotten
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        
        return time;
    }
};
