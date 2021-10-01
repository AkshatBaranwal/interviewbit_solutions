class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        if(n==0) return {{}};
        if(n==1) return {{1}};
        vector<vector<int>>ans(n,vector<int>(n));

        int c=0;
        
        int l=0, r=n-1, t=0, b=n-1;

        while(c<n*n){
          
          for(int i=l;i<=r;i++){
          ans[t][i]= (++c);
          }

          t++;

          if(c>n*n) break;

          for(int i=t;i<=b;i++){
          ans[i][r]= (++c);
          }

          r--;

          if(c>n*n) break;

          for(int i=r;i>=l;i--){
          ans[b][i]= (++c);
          }

          b--;

          if(c>n*n) break;

          for(int i=b;i>=t;i--){
          ans[i][l]= (++c);
          }

          l++;


        }

        return ans;
        
    }
};