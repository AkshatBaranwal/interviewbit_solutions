int Solution::maximalRectangle(vector<vector<int> > &grid){
        
        int n = grid.size();
        if(n==0)
            return 0;
        int m = grid[0].size();
        
        vector<vector<int>> matrix;
        matrix.assign(n, vector<int>(m,0));
        
        for(int i=0; i<n; i++)for(int j=0; j<m; j++) matrix[i][j]= (grid[i][j]=='1');
        
        for(int i=0; i<n; i++)
        {
            for(int j=1; j<m; j++)
                matrix[i][j]+= matrix[i][j-1];
        }
        
        int ans = 0;
        
        for(int curstart =0; curstart<m; curstart++)
        {
            for(int curend=curstart; curend<m; curend++)
            {
                int len = curend-curstart+1;
                int cnt = 0;
                int temp = 0;
                
                for(int i=0; i<n; i++)
                {
                    int sum = matrix[i][curend] - ((curstart)?matrix[i][curstart-1]: 0);
                    if(sum==len)
                        cnt++,
                        temp = max(temp,cnt);
                    else
                        cnt=0;
                }
                
                temp = max(temp,cnt);
                ans = max(ans, temp*len);
            }
        }
        
        return ans;
        
    }
