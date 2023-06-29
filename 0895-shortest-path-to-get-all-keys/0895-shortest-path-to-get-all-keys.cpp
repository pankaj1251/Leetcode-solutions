class Solution {
public:
    bool vis[32][32][64] ;
int ans ;
pair<int,int> dir[4] ;
int req_val = -1;

int shortestPathAllKeys(vector<string>& grid) {
    ans = -1;
    dir[0] = make_pair(0,-1) ;
    dir[1] = make_pair(0,1) ;
    dir[2] = make_pair(-1,0) ;
    dir[3] = make_pair(1,0) ;
    int starti,startj,n=grid.size(),m=grid[0].size() ;
    req_val=-1 ; // this would store the condition of bit_mask variable when we have all keys
    
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            
            if( islower(grid[i][j]) ){
                
                req_val = max( req_val , ( 1 << (  grid[i][j] - 'a' + 1) ) - 1  ) ; // (all ones)
                
            }
            
            if( grid[i][j] == '@' )starti=i,startj=j ;
            
        }
    }
    
    int ans = 0 ;
    
    queue< pair< pair<int,int> , pair<int,int> > > Q ; // first pair for i,j and second pair for { bit_mask , steps }
    
    Q.push( make_pair( make_pair(starti,startj) , make_pair(0,0) ) ) ;
    
    while( !Q.empty() ){
        
        pair< pair<int,int> , pair<int,int> > P = Q.front() ;
        
        Q.pop() ;
        
        int i = P.first.first , j = P.first.second ;
        
        int bit_mask = P.second.first ;
        
        int steps = P.second.second ;
        
        if( i < 0 || i >= n || j < 0 || j >= m )continue ;
        
        if( vis[i][j][bit_mask] )continue ;
        
        if( grid[i][j] == '#' )continue ;
        
        if( isupper(grid[i][j]) )
            
            if( !( bit_mask & ( 1 << ( grid[i][j] - 'A' )  ) ) ) // if we don't have key for it we would stop this path
                continue ;
        
        if( islower( grid[i][j] ) )
            bit_mask = bit_mask | ( 1 << (grid[i][j]-'a') ) ;// we updated the bit mask variable 
        
        
        if( bit_mask == req_val )return steps ; // we reached the ideal condition we wanted
        
        vis[i][j][bit_mask] = 1 ;
        
        
        for(int i1=0;i1<4;i1++)
        {
            Q.push(  make_pair( make_pair( i + dir[i1].first , j + dir[i1].second ) , make_pair(bit_mask,steps+1) ) ) ;
        }
        
        
    }
    
    
    return -1 ; // we failed to match the ideal condition anywhere , so not possible
    
}

};