/* 
Problem - Find Missing And Repeating 
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=2a42a2cd2dc711f137d5d782a743c675&pid=702678&user=sayihrudai

*/


class Solution:
    def findTwoElement( self,l, n): 
        # code here
        ans=[0]*2
        k=list(set(l))
        ans[1]=((n*(n+1))//2)-sum(k)
        ans[0]=sum(l)-sum(k)
        return(ans)

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 

    tc=int(input())
    while tc > 0:
        n=int(input())
        arr=list(map(int, input().strip().split()))
        ob = Solution()
        ans=ob.findTwoElement(arr, n)
        print(str(ans[0])+" "+str(ans[1]))
        tc=tc-1
# } Driver Code Ends

