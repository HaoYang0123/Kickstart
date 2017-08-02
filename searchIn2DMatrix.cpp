class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        return searchMatrix(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1, target);
    }
    
    bool searchMatrix(vector<vector<int>> & matrix, int startI, int startJ, int endI, int endJ, int target) {
        if(startI < 0 || startI >= matrix.size() || startJ < 0 || startJ >= matrix[0].size()) return false;
        if(endI < 0 || endI >= matrix.size() || endJ < 0 || endJ >= matrix[0].size()) return false;
        if(startI > endI || startJ > endJ) return false;
        if(matrix[startI][startJ] == target) return true;
        
        int diagDist = min(endI - startI, endJ - startJ); //使用从(startI, startJ)的对角线形式进行二分查找
        int sI = startI, sJ = startJ, eI = startI + diagDist, eJ = sJ + diagDist;
        int pI = 0, pJ = 0;
        while(sI <= eI && sJ <= eJ) {
            pI = (sI + eI) / 2;
            pJ = (sJ + eJ) / 2;
            if(target > matrix[pI][pJ]) {
                sI = pI + 1;
                sJ = pJ + 1;
            }
            else if(target < matrix[pI][pJ]) {
                eI = pI - 1;
                eJ = pJ - 1;
            }
            else return true; //在对角线上直接找到了target,则直接返回true
        }
        //cout<<matrix[sI][sJ]<<endl;
        //在对角线上并没有找到target，而且matrix[sI][sJ]表示为对角线上第一个大于target的元素
        //则使用(sI, sJ)将原始矩阵[(startI, startJ), (endI, endJ)]分割成左下角和右上角两个部分进行查找
        //其中左下角表示为[(sI, startJ), (endI, sJ - 1)]，右上角表示为[(startI, sJ), (sI - 1, endJ)]
        return searchMatrix(matrix, sI, startJ, endI, sJ - 1, target) || searchMatrix(matrix, startI, sJ, sI - 1, endJ, target);
    }
};
