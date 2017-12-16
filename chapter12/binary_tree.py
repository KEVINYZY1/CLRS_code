import random
from functools import wraps


class Node:
    def __init__(self, key=None, left=None, right=None, parent=None):
        self.key = key
        self.left = left
        self.right = right
        self.parent = parent


def valid_node(func):
    @wraps(func)
    def check_valid(*args, **kwargs):
        for node in args[1:]:
            if node is not None:
                assert isinstance(node, Node)
        return func(*args, **kwargs)
    return check_valid


class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        node = Node(key)
        y = None
        x = self.root
        while x is not None:
            y = x
            x = x.left if node.key < x.key else x.right

        node.parent = y
        if y is None:
            self.root = node
        else:
            setattr(y, 'left' if node.key < y.key else 'right', node)

    def search(self, key):
        x = self.root
        while x is not None and x.key != key:
            x = x.left if key < x.key else x.right
        return x

    @valid_node
    def has_node(self, node):
        if node is None:
            return False
        return self.search(node.key) is node

    @valid_node
    def minimum(self, node=None):
        node = node or self.root
        if node is None:
            return None
        x = node
        while x.left is not None:
            x = x.left
        return x

    @valid_node
    def maximum(self, node=None):
        node = node or self.root
        if node is None:
            return None
        x = node
        while x.right is not None:
            x = x.right
        return x

    @valid_node
    def successor(self, node=None):
        node = node or self.root
        if node is None:
            return None
        if node.right is not None:
            return self.minimum(node.right)
        x = node.parent
        while x is not None and x.right is node:
            node = x
            x = node.parent
        return x

    @valid_node
    def predecessor(self, node=None):
        node = node or self.root
        if node is None:
            return None
        if node.left is not None:
            return self.maximum(node.left)
        x = node.parent
        while x is not None and x.left is node:
            node = x
            x = node.parent
        return x

    def _transplant(self, old_node, new_node):
        if old_node is self.root:
            self.root = new_node
        elif old_node is old_node.parent.left:
            old_node.parent.left = new_node
        else:
            old_node.parent.right = new_node
        if new_node is not None:
            new_node.parent = old_node.parent

    @valid_node
    def delete(self, node):
        if not self.has_node(node):
            return
        if node.left is None:
            self._transplant(node, node.right)
        elif node.right is None:
            self._transplant(node, node.left)
        else:
            # TODO select the bigger height of successor and predecessor to del
            successor = self.minimum(node.right)
            if successor.parent is not node:
                self._transplant(successor, successor.right)
                successor.right = node.right
                successor.right.parent = successor
            self._transplant(node, successor)
            successor.left = node.left
            successor.left.parent = successor
        del node


if __name__ == '__main__':
    tree = BinaryTree()
    node_num = 10
    node_values = list(range(node_num))
    random.shuffle(node_values)

    # test insert
    for value in node_values:
        tree.insert(value)

    # test minimum, maximum
    min_node = tree.minimum()
    max_node = tree.maximum()
    assert min_node.key == min(node_values)
    assert max_node.key == max(node_values)

    # test successor, predecessor
    asc, desc = [], []
    while min_node is not None:
        asc.append(min_node.key)
        min_node = tree.successor(min_node)
    while max_node is not None:
        desc.append(max_node.key)
        max_node = tree.predecessor(max_node)
    assert asc == sorted(node_values)
    assert desc == sorted(node_values, reverse=True)

    # test search
    tobe_removed_key = random.choice(node_values)
    node_values.pop(node_values.index(tobe_removed_key))
    tobe_removed_node = tree.search(tobe_removed_key)
    assert tobe_removed_node.key == tobe_removed_key

    # test delete
    tree.delete(tobe_removed_node)
    asc = list()
    min_node = tree.minimum()
    while min_node is not None:
        asc.append(min_node.key)
        min_node = tree.successor(min_node)
    assert asc == sorted(node_values)
