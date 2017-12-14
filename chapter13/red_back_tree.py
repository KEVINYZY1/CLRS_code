import random
from chapter12.binary_tree import Node, BinaryTree, valid_node


class RedBlackTree(BinaryTree):
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

    @valid_node
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

    def left_rotate_test(self, node):
        self.__left_rotate(node)

    def right_rotate_for_test(self, node):
        self.__right_rotate(node)


if __name__ == '__main__':
    tree = RedBlackTree()
    node_num = 4
    node_values = list(range(node_num))
    random.shuffle(node_values)

    # test insert
    for value in node_values:
        tree.insert(value)
