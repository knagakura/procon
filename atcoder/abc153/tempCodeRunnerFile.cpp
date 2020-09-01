N+1){
        rep(j,H+1){
            if(dp[i][j] == INFLL)cerr << -1 << " ";
            else cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }