class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
     
     // 是哦。。。我好想知道。你有没有在别人面前夸过我呢
     // 我也好希望你能问问我怎么样阿。。
    bool anagram(string s, string t) { //-70ms
        if(s.length() != t.length())
            return false;
            
        // plan1: Time: O(nlogn) Space: 0 622ms
        
        // sort(s.begin(),s.end(),[](const char a,const char b){return a > b;});
        // sort(t.begin(),t.end(),[](const char a,const char b){return a > b;});
        // if(s == t)
        //     return true;
        // else 
        //     return false;
        
        //plan2 : Time: O(n) Space O(1) 732ms
        int a[128] = {0}, b[128] = {0};
        int length = s.length();
        for(int i = 0; i < length; i++){
            a[s[i]]++,b[t[i]]++;
        }
        for(int i = 0; i < 128; i++){
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
};