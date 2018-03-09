class Solution {
public:
    /**
     * @param x: the wall's height
     * @return: YES or NO
     */
    string isBuild(int x) {
        // write you code here
        string yes = "YES";
        string no = "NO";
        vector<int> table(10000,0);
        table[0] = 2;
        table[1] = 2;
        table[2] = 2;
        table[3] = 1;
        table[4] = 2;
        table[5] = 2;
        table[6] = 1;
        table[7] ==1;
        if(dp(x,table))
            return yes;
        else
            return no;
    }
    int dp(int x, vector<int> &table){
        if(x <= 7)
            return table[x] == 1? 1 : 0;
        if(table[x] == 1)
            return 1;
        if(table[x] == 2)
            return 0;
        if(dp(x-3,table) || dp(x-7,table))
            return table[x] = 1;
        else{
            table[x] = 2;
            return 0;
        }
    }
};