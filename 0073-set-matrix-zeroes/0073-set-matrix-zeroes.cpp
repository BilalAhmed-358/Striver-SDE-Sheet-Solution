class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        // Declaring rows and column tracking vectors
        vector<int> trackRows(matrix.size());        
        vector<int> trackCols(matrix[0].size());

        // Traversing matrix and marking both vectors
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    trackRows[i]=1;
                    trackCols[j]=1;
                }
            }
        }
        
        //Converting rows to 0
        
        for(int i=0;i<trackRows.size();i++)
        {
            if(trackRows[i]==1)
                MakeRowZero(matrix,i);
                
        }
        
        //Converting Cols to 0
        
        for(int i=0;i<trackCols.size();i++)
        {
            if(trackCols[i]==1)
                MakeColZero(matrix,i);
        }
        
        
        
        
    }
    
    void MakeRowZero(vector<vector<int>>& matrix, int i)
    {
        for(int j=0;j<matrix[i].size();j++)
        {
            matrix[i][j]=0;
        }
    }
    
     void MakeColZero(vector<vector<int>>& matrix, int j)
    {
        for(int i=0;i<matrix.size();i++)
        {
            matrix[i][j]=0;
        }
    }
    
    
};