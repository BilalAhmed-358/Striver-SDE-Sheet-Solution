class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        
        # Taking transpose of a the matrix
        for i in range(len(matrix)):
            for j in range (0,i):
                matrix[i][j],matrix[j][i] = matrix[j][i],matrix[i][j]
                
        # Now reversing each row
        
        for i in range(len(matrix)):
            matrix[i]=matrix[i][::-1]
        