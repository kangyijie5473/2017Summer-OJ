class Solution {
public:
    /*
     * @param : the given number
     * @return: whether whether there're two integers
     */
    bool checkSumOfSquareNumbers(int num) {
        if(num < 0)
            return false;

        set<int> nb;
        for(int i = 0; i * i <= num && i*i>=0; i++){ //当num很大时这里会死循环 i*i溢出 要>=0做限制
            nb.insert(i*i);
        }
        //或者这样
        // int sb = sqrt(num);
        // for(int i = 0; i <= sb;i++)
        //     nb.insert(i*i);
        for(auto i : nb){
            if(nb.find(num - i) != nb.end())
                return true;
        }
        return false;
    }
};