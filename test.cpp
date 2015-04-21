//
//  main.cpp
//  test
//
//  Created by 葛京 on 15/4/19.
//  Copyright (c) 2015年 葛京. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]!=word[0])
                    continue;
                vector<vector<bool>> rec(board.size(), vector<bool>(board[0].size(), false));
                if(searchHelper(board, word, 0, rec, i, j))
                    return true;
            }
        return false;
    }
    
    bool searchHelper(vector<vector<char> > &board, string word, int index, vector<vector<bool>> &rec, int i, int j){
        if(index==word.length())
            return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[index] || rec[i][j]==true)
            return false;
        rec[i][j]=true;
        cout<<board[i][j]<<"  "<<i<<"  "<<j<<endl;
        if(searchHelper(board, word, index+1, rec, i-1, j) || searchHelper(board, word, index+1, rec, i, j-1) || searchHelper(board, word, index+1, rec, i+1, j) || searchHelper(board, word, index+1, rec, i, j+1))
            return true;
        rec[i][j]=false;
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<char>> board;
    board.push_back(vector<char>({'A', 'B', 'C', 'E'}));
    board.push_back(vector<char>({'S', 'F', 'E', 'S'}));
    board.push_back(vector<char>({'A', 'D', 'E', 'E'}));
    Solution s;
    if(s.exist(board, "ABCESEEEFS"))
        std::cout << "Hello, World!\n";
    char a;
    return 0;
}


