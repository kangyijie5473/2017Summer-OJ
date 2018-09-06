class ZigzagIterator2 {
public:
    /*
    * @param vecs: a list of 1d vectors
    */ZigzagIterator2(vector<vector<int>>& vecs) {
        // do intialization if necessary
        now_index = -1;
        int max_col = 0;
        int row = vecs.size();
        for (int i = 0; i < row; i++)
            if (vecs[i].size() > max_col)
                max_col = vecs[i].size();
                
        for (int i = 0; i < max_col; i++) {
            for (int j = 0; j < row; j++) {
                if (vecs[j].size() <= i)
                    continue;
                else
                    v.push_back(vecs[j][i]);
            }
        }
    }

    /*
     * @return: An integer
     */
    int next() {
        // write your code here
        return v[++now_index];
    }

    /*
     * @return: True if has next
     */
    bool hasNext() {
        // write your code here
        return now_index + 1 < v.size();
    }
private:
    vector<int> v;
    int now_index;
};

/**
 * Your ZigzagIterator2 object will be instantiated and called as such:
 * ZigzagIterator2 solution(vecs);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */