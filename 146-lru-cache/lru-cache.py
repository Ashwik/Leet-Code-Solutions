class ListNode:

    def __init__(self, key: int, val: int , prev=None, next=None):
        self.key = key
        self.val = val
        self.prev = prev
        self.next = next

class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.left_node = ListNode(0, 0, None, None)
        self.right_node = ListNode(0, 0,self.left_node, None)
        self.left_node.next = self.right_node
        self.map = {}

    def remove(self, cur_node: ListNode):
            prev_node = cur_node.prev
            next_node = cur_node.next
            prev_node.next = next_node
            next_node.prev = prev_node

    def add_to_front(self, cur_node: ListNode):
        prevnode = self.left_node
        nextnode = self.left_node.next
        
        cur_node.prev = prevnode
        cur_node.next = nextnode

        prevnode.next = cur_node
        nextnode.prev = cur_node
    
    
    def get(self, key: int) -> int:
        
        if key in self.map:
            node = self.map[key]
            self.remove(node)
            self.add_to_front(node)
            return node.val
        return -1

    def put(self, key: int, value: int) -> None:
        
        if(self.get(key) != -1):
            node = self.map[key]
            node.val = value
            return

        if(len(self.map)==self.capacity):
            node = self.right_node.prev
            self.remove(node)
            del self.map[node.key]
            
        
        node = ListNode(key,value)
        self.add_to_front(node)
        self.map[key] = node


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)