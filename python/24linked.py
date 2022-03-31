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
        pre = cur.next
        while(cur):
            # backup
            temp = cur.next
            cur.next = pre
            pre = cur
            cur = temp
            print(cur)
        return cur

def main():
    node1 = ListNode(1)
    node2 = ListNode(2)
    node3 = ListNode(3)
    node1.next = node2
    node2.next = node3
    head = node1
    Solution().reverseList(head)

if __name__ =='__main__':
    main()
