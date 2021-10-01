// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

class Solution {
public:
    bool wordsearch(vector<vector<char>>&board, string word, int i, int j, int count){
        if(count==word.size())
            return true;
        
        //boundary conditions
        
        if(i<0||i>=board.size()||j<0||j>=board[0].size()||board[i][j]!=word[count])
            return false;
        
        char temp=board[i][j];
        board[i][j]=' ';
        bool found=wordsearch(board,word,i+1,j,count+1)
                    ||wordsearch(board,word,i,j+1,count+1)
                    ||wordsearch(board,word,i-1,j,count+1)
                    ||wordsearch(board,word,i,j-1,count+1);
        
        board[i][j]=temp;
        return found;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        //find the first letter
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]&&wordsearch(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
};
