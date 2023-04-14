class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        n=len(matrix)
        m=len(matrix[0])
        res=0
        mat=[0]*(m+1)
        for i in range(0,n):
            st=[]
            for j in range(0,m+1):
                if(j==m or matrix[i][j]=='0'):
                    mat[j]=0
                else:
                    mat[j]+=1
                while(len(st) and mat[st[-1]]>mat[j]):
                    h=mat[st.pop()]
                    if(len(st)): w=(j-st[-1]-1)
                    else :w=j
                    res=max(res,h*w)
                #print(res)
                st.append(j)
            #print(mat)
        return res
            
        
        
        
        
                
                    
                    
                    