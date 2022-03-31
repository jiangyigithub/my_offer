# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
from ds import ListNode
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        # switch the position of node
        cur = head
        pre = None
        while(cur):
            temp = cur.next # unlink cur,backup element to temp, index rest element by temp 
            cur.next = pre
            pre = cur 
            cur = temp
        # self.printLinked(pre)
        return pre

def listNodeToString(node):
    if not node:
        return "[]"
    result = ""
    while node:
        result += str(node.val) + ", "
        node = node.next
    return "[" + result[:-2] + "]"

def main():
    node1 = ListNode(1)
    node2 = ListNode(2)
    node3 = ListNode(3)
    node1.next = node2
    node2.next = node3
    head = node1
    ret = Solution().reverseList(head)
    out = listNodeToString(ret)
    print(out)

if __name__ =='__main__':
    main()
