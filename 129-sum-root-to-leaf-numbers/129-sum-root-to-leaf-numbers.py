# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def traverse(A,sum,k):
    p=k[:]
    p+=str(A.val)
    if A.left==None and A.right==None:
        sum[0]+=int(p)
    if A.left:
        traverse(A.left,sum,p)
    if A.right:
        traverse(A.right,sum,p)
    
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        sum=[0]
        traverse(root,sum,"")
        return sum[0]