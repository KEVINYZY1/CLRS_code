import random
from chapter12.binary_tree import Node, BinaryTree, valid_node

RED = 'red'
BLACK = 'black'


class RBNode(Node):
    def __init__(self, key=None, color=RED,
                 left=None, right=None, parent=None):
        super().__init__(key, left, right, parent)
        self.color = color


class RBTree(BinaryTree):
    def __left_rotate(self, node):
        if not self.has_node(node):
            return
        y = node.right
        if y is None:
            return

        # mod y.left
        node.right = y.left
        if y.left is not None:
            y.left.parent = node

        # mod y
        y.parent = node.parent
        if node.parent is None:
            self.root = y
        elif node is node.parent.left:
            node.parent.left = y
        else:
            node.parent.right = y

        # mod node
        y.left = node
        node.parent = y

    def __right_rotate(self, node):
        if not self.has_node(node):
            return
        y = node.left
        if y is None:
            return

        # mod y.right
        node.left = y.right
        if y.right is not None:
            y.right.parent = node

        # mod y
        y.parent = node.parent
        if node.parent is None:
            self.root = y
        elif node is node.parent.left:
            node.parent.left = y
        else:
            node.parent.right = y

        # mod node
        y.right = node
        node.parent = y

    def __insert_fixup(self, node):
        while node.parent is not None and node.parent.color == RED:
            if node.parent is node.parent.parent.left:
                uncle = node.parent.parent.right
                if uncle is not None and uncle.color == RED:
                    node.parent.color = BLACK
                    uncle.color = BLACK
                    node.parent.parent.color = RED
                    node = node.parent.parent
                else:
                    if node is node.parent.right:
                        node = node.parent
                        self.__left_rotate(node)
                    node.parent.color = BLACK
                    node.parent.parent.color = RED
                    self.__right_rotate(node.parent.parent)
            else:
                uncle = node.parent.parent.left
                if uncle is not None and uncle.color == RED:
                    node.parent.color = BLACK
                    uncle.color = BLACK
                    node.parent.parent.color = RED
                elif node is node.parent.left:
                    node = node.parent
                    self.__right_rotate(node)
                node.parent.color = BLACK
                node.parent.parent.color = RED
                self.__left_rotate(node.parent.parent)
        self.root.color = BLACK

    def insert(self, key):
        node = RBNode(key)
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
        self.__insert_fixup(node)

    def search(self, key):
        x = self.root
        while x is not None and x.key != key:
            x = x.left if key < x.key else x.right
        return x


def assert_key_color(node, key, color):
    assert node.key == key
    assert node.color == color


if __name__ == '__main__':
    node_values = [41, 38, 31, 12, 19, 8]
    tree = RBTree()
    # test insert
    for value in node_values:
        tree.insert(value)

    root = tree.root
    assert_key_color(root, 38, BLACK)
    assert_key_color(root.left, 19, RED)
    assert_key_color(root.left.left, 12, BLACK)
    assert_key_color(root.left.left.left, 8, RED)
    assert_key_color(root.left.right, 31, BLACK)
    assert_key_color(root.right, 41, BLACK)
