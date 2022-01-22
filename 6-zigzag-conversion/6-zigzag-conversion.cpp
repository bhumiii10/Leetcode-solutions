class Solution {
public:
    string convert(string s, int n ) {
        vector<vector<char>> list(n);
        if( n == 1 ){ return s ; }
        int k = 0;
        bool positive = true ;
        for( int i = 0 ; i < s.length() ; i++ ){
            list[k].push_back(s[i]);
            if( positive ) { k++ ; }
            else{ k--; }
            if( k == -1 ){ positive = true; k+=2; }
            if( k == n ){ positive = false; k-=2; }
        }
        
        string res;
        for( int i = 0 ; i < list.size() ; i++ ){
            for( int j = 0 ; j < list[i].size() ; j++ ){
                res += list[i][j] ;
            }
        }
        return res;
    }
};