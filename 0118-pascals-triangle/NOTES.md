## Variation 01
![](Pascal%20Triangle%20picture.png)

1. For such problem always take the data type as `long long`  since the values may be very big.
2. Simple sa sawal hai, number of rows given hongi, uss size ka pascal triangle return kr dena hai bs

3. Pascal triangle ki property hoti hai k har row ka first or last element 1 hota hai, or har element apny ooper waly 2 elements ka sum hota hai
4. for 2 number of rows, triagnle mei sirf 1 hi hongy usky bad with increase in size values bhi increase hoti jae gi
5. Here I catered for the first and last element being 1
   ```cpp

   for(int i=0;i<numRows ; i++)
        {
                pascal_triangle[i][0]=1;
                pascal_triangle[i][i]=1;  
        }
    ```

6. Here I've just values in each element with respect to their upper 2 elements. Pretty simple and self explanatory.
   ```cpp
    if(numRows > 2)
    {
        for(int i=0;i<numRows;i++)
        {
            for(int j=1; j<pascal_triangle[i].size()-1 ;j++)
            {
                
                pascal_triangle[i][j]=pascal_triangle[i-1][j-1]+pascal_triangle[i-1][j];
                
            }
        }   
    }
   ```
7. bas main trick yahi hai iss sawal ki k pascal triangle ki definition pata ho, baki halwa hai.
## Variation 02
1. Aik variation or bhi hai iss sawal ka, uss mei bs they will give you the row and column number in the pascal triangle and you have to tell the value, now the brute force solution would be to generate the whole triangle first and then return the value but iska aik shortcut bhi hai, simple combination waly formula mei value put krdo like this (r-1)C(C-1) or jo formula hota hai (n!/(r!*(n-r!))) bs uss sy calculate kr k value return krdo
   ![](Part%202.png)

2. nCr calculate krny ka bhi simple function iss trah shortcut mei ban skta hai without doing all the lengthy calculations, just run the loop till r, keep subtracting i from n in each iternation and keep dividing by r (agar samaj nahi aa raha tou take the cue from the pic below uss mei likha hua hai code poora)
   ![](pic%203.png)

## Variation 03

In this variation you will be given the number of the row (For Eg: they can say that only calculate the 4th row of the pascal triangle)

1. A simple idea would be just just run a for loop and use the function from variation 02 to calculate value of each element but uski time complexity will be O(n*r), because for each function call the variation 2 function takes O(r) complexity
2. To optimize this look at the following picture
   ![](pic%204.png)

3. If we can somehow manage to encode this pattern in our code, we can have O(n) complexity.
4. The formula would be 
   ![](pic%205.png)
5. Here `cols` have 0 based indexing and we will always begin from 1 column since column 0 and last column will always have value of 1.
6. In the numerator the `row` is subtracted from the `col` to get the value of our numerator and this pattern is visible seeing from the attached picture in step 2.


7. Using this logic u can also optimize the variation 1 solution like this
   ![](pic%206.png)
   The complexity of this code will be O(n*r) but ooper waly ki O(n*r)+O(r) thi tou uss hisab sy this one is much better and cleaner.