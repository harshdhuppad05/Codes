class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> row(9), column(9), block(9);
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(board[i][j] == '.')continue;
                int num = board[i][j]-'0';
                if(row[i].find(num)!= row[i].end()){
                    cout<<i<<" "<<j<<endl;
                    cout<<1;
                    return false;
                }
                else if(column[j].find(num)!= column[j].end()){
                    cout<<i<<" "<<j<<endl;
                    cout<<2;
                    return false;
                }
                else if(block[(i/3)*3 + (j/3)].find(num)!= block[(i/3)*3 + (j/3)].end()){
                    cout<<num<<endl;
                    cout<<i<<" "<<j<<endl;
                    cout<<3;
                    return false;
                }
                else {
                    row[i].insert(num);
                    column[j].insert(num);
                    block[(i/3)*3 + (j/3)].insert(num);
                }
            }
        }
        return true;
    }
};
