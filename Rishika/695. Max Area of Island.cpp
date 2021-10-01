/*You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.
*/

class Solution {
public:
    int area(int i, int j, vector<vector<int>>&grid){
        if(i<0||i>=grid.size()||j<0||j>=grid[i].size()||grid[i][j]==0)
            return 0;
        
        grid[i][j]=0;

        return 1+area(i+1,j,grid)+area(i-1,j,grid)+area(i,j+1,grid)+area(i,j-1,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int ans=0;
        int valcurr=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    ans=max(area(i,j,grid),ans);
                }
            }
        }
        return ans;
    }
};
