​1. The brute force solution would be

```cpp
// Brute force solution

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> myMatrix(matrix);
        for(int i=0; i<matrix.size();i++)
        {
            for (int j=0; j< matrix[i].size() ; j++)
            {
                if(matrix[i][j] == 0 && myMatrix[i][j]==0)
                {
                    workerFunc(matrix, i, j);                                                                   PrintMatrix(matrix);
                    cout<<endl;

                }
            }
        }       
    }
    
    
    void workerFunc(vector<vector<int>>& matrix, int i, int j)
    {
        for(int k=0; k<matrix.size();k++)
            matrix[k][j]=0;
        
        for(int l=0; l<matrix[i].size();l++)
            matrix[i][l]=0;
    }
    
    void PrintMatrix(vector<vector<int>>& matrix)
    {
        for(int i=0; i<matrix.size();i++)
        {
            for (int j=0; j< matrix[i].size() ; j++)
            {
                cout<<matrix[i][j]<<" ";
                
            }
            cout<<endl;
        } 
    }
};

```

2. But it will give you TLE, since it isn't optimized
3. Aik or idea ye hai k jab bhi koi zero mil jae tou uss sy related column or row k sab elements ko -1 mark kr dein and then later the elements can be changed to 0 in O(n) time
4. But the problem with this approach is that if there is a -1 in the original matrix it will act as a false +ve or wo bhi 0 mark ho jae ga
5. To counter this, we make an optimized solution and keep 2 arrays
```cpp

vector<int> trackRows(matrix.size());        
vector<int> trackCols(matrix[0].size());
        
```
6. Now we traverse through the matrix or agar koi 0 mil jae tou uss k corresponding tracing vector ki row or column ko 1 mark kr dety hein
```cpp


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
```
7. And once we are done marking we make 2 functions and that access each row and column jis mei koi zero ho and they make each element of that column/row to zero
```cpp
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
```
8. The final optimized code with the complexity of O(m*n)+O(n)+O(n)+O(n)+O(n)=O(n^2)

```cpp
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
```
