#include<iostream>
#include<vector>
using std::cout; using std::endl; using std::vector;

vector<int> spiralOrder(vector<vector<int>>& matrix);
int main(){

    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
                                //4 * 4 : {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}
                                //3 * 3 : {1, 2, 3}, {4, 5, 6}, {7, 8, 9}
                                //3 * 4 : {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}
                                //4 * 3 : {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            cout << matrix[i][j] << ", ";
        }
        cout << endl;
    }
    vector<int> res = spiralOrder(matrix);
    cout << "res.size() = " << res.size() << endl;//12
    for(int i = 0; i < res.size() - 1; i++){
        cout << res[i] << ", ";
    }
    cout << res[res.size() - 1] << endl;
    
    return 0;
}
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        cout << "row = " << row << "; col = " << col << endl;
        int left = 0; int right = col - 1;
        int top = 0; int bottom = row - 1;
        vector<int> res;//
        //res.resize(col * row);
        cout << "res.size() = " << res.size() << endl;//0
        if(matrix.empty()) return res; 
        //int num = 1;
        while(true){//true left <= right && top <= bottom这个不对num <= col * row 
            for(int i = left; i <= right; i++)  {res.push_back(matrix[top][i]); }//num++;
            top++;
            if(top > bottom) break;
            for(int i = top; i <= bottom; i++) {res.push_back(matrix[i][right]); }//num++;
            right--;
            if(right < left) break;
            for(int i = right; i >= left; i--) {res.push_back(matrix[bottom][i]); }//num++;
            bottom--;
            if(bottom < top) break;
            for(int i = bottom; i >= top; i--) {res.push_back(matrix[i][left]); }//num++;
            left++;
            if(left > right) break;
        }
        return res;

    }