<h2><a href="https://leetcode.com/problems/set-matrix-zeroes/">73. Set Matrix Zeroes</a></h2><h3>Medium</h3><hr><div><p>Given an <code>m x n</code> integer matrix <code>matrix</code>, if an element is <code>0</code>, set its entire row and column to <code>0</code>'s.</p>

<p>You must do it <a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in place</a>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/17/mat1.jpg" style="width: 450px; height: 169px;">
<pre><strong>Input:</strong> matrix = [[1,1,1],[1,0,1],[1,1,1]]
<strong>Output:</strong> [[1,0,1],[0,0,0],[1,0,1]]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/17/mat2.jpg" style="width: 450px; height: 137px;">
<pre><strong>Input:</strong> matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
<strong>Output:</strong> [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[0].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>-2<sup>31</sup> &lt;= matrix[i][j] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<ul>
	<li>A straightforward solution using <code>O(mn)</code> space is probably a bad idea.</li>
	<li>A simple improvement uses <code>O(m + n)</code> space, but still not the best solution.</li>
	<li>Could you devise a constant space solution?</li>
</ul>
</div>

​​1. The brute force solution would be

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
