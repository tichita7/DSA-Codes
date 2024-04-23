  #include <bits/stdc++.h>
  #include<vector>
  #include<string>
  using namespace std;

  
  class Solution{
    bool isSafe(int x, int y,vector<vector<int>> &m, int n, vector<vector<int>> visited ){
        if( (x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]==0 && m[x][y]==1  ){
            return true;
        }
        else{
            return false;
        }
    }
    private:
    void solve(vector<vector<int>> &m, int n, int x, int y,vector<vector<int>> visited, vector<string> &ans, string path ){
        //base case, you have reached x and y
        if( x == n-1 && y == n-1 ){
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        //4 choices: D, L, R, U
        //down
        int newx = x+1;
        int newy = y;
        if(isSafe( newx, newy, m, n,  visited)){
           path.push_back('D');
            solve(m, n, newx, newy, visited, ans, path);
            path.pop_back(); //backtracking
        }
        
        //left
         newx = x;
         newy = y-1;
        if(isSafe( newx, newy, m,n, visited)){
            path.push_back('L');
            solve(m, n, newx, newy, visited, ans, path);
            path.pop_back(); //backtracking
        }
        
        //right
         newx = x;
        newy = y+1;
        if(isSafe( newx, newy, m, n, visited)){
            path.push_back('R');
            solve(m, n, newx, newy, visited, ans, path);
            path.pop_back(); //backtracking
        }
        
        //up
        newx = x-1;
        newy = y;
        if(isSafe( newx, newy, m,n,  visited)){
            path.push_back('U');
            solve(m, n, newx, newy, visited, ans, path);
            path.pop_back(); //backtracking
        }
        
        visited[x][y] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
          int srcx = 0;
        int srcy = 0;
        vector<vector<int>> visited = m;
        if(m[0][0] == 0){
            return ans;
        }
        
        
        for(int i  =0; i<n; i++){
            for(int j = 0; j<n; j++){
                visited[i][j] = 0;
            }
        }
        string path = "";
        solve(m, n, srcx, srcy, visited, ans, path);
        sort(ans.begin(), ans.end());
        return ans;
    }
};