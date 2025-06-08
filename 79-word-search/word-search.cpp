class Solution {
public:
        
    bool func(int idx, int i, int j, vector<vector<char>> &board, string &word,vector<vector<bool>>&v)
{
    if (idx != word.size() && word[idx] != board[i][j])
    {
        // cout << "false" << endl;
        return false;
    }

    if (idx != word.size() && word[idx] == board[i][j])
    {
        v[i][j]=true;
        // cout << "idx+1" << endl;
        idx += 1;
    }

    if (idx == word.size())
    {
        // cout << "true" << endl;
        return true;
    }

    // cout << "idx:" << idx << endl
    //      << "char:" << board[i][j] << endl;

    if (i + 1 < board.size() && !v[i+1][j] && func(idx, i + 1, j, board, word,v))
        return true;
    if (j + 1 < board[0].size() && !v[i][j+1] && func(idx, i, j + 1, board, word,v))
        return true;
    if (i - 1 >= 0 && !v[i-1][j] && func(idx, i - 1, j, board, word,v))
        return true;
    if (j - 1 >= 0 && !v[i][j-1] && func(idx, i, j - 1, board, word,v))
        return true;
    v[i][j]=false;
    return false;
}


    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>>v(board.size(),vector<bool>(board[0].size(),false));
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (word[0] == board[i][j])
            {
                // v.insert({i,j});
                if (func(0, i, j, board, word,v))
                    return true;
            }
        }
    }

    return false;
        

    }
};