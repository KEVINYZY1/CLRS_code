from functools import wraps
from recordclass import recordclass
from chapter12.binary_tree import Node, BinaryTree

RED = 'red'
BLACK = 'black'
NULL = recordclass('Node', ['key', 'color', 'left', 'right', 'parent'])(
    key=None, color=BLACK, left=None, right=None, parent=None
)


class RBNode(Node):
    def __init__(self, key=NULL, color=RED,
                 left=NULL, right=NULL, parent=NULL):
        super().__init__(key, left, right, parent)
        self.color = color


def valid_node(func):
    @wraps(func)
    def check_valid(*args, **kwargs):
        for node in args[1:]:
            if node is not None:
                assert isinstance(node, RBNode)
        return func(*args, **kwargs)
    return check_valid


class RBTree(BinaryTree):
    def __init__(self):
        super().__init__()
        self.root = NULL

    def __left_rotate(self, node):
        if not self.has_node(node):
            return
        y = node.right
        if y is NULL:
            return

        # mod y.left
        node.right = y.left
        if y.left is not NULL:
            y.left.parent = node

        # mod y
        y.parent = node.parent
        if node.parent is NULL:
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
        if y is NULL:
            return

        # mod y.right
        node.left = y.right
        if y.right is not NULL:
            y.right.parent = node

        # mod y
        y.parent = node.parent
        if node.parent is NULL:
            self.root = y
        elif node is node.parent.left:
            node.parent.left = y
        else:
            node.parent.right = y

        # mod node
        y.right = node
        node.parent = y

    def __insert_fixup(self, node):
        while node.parent is not NULL and node.parent.color == RED:
            if node.parent is node.parent.parent.left:
                uncle = node.parent.parent.right
                if uncle is not NULL and uncle.color == RED:
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
                if uncle is not NULL and uncle.color == RED:
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

    def __delete_fixup(self, node):
        while node is not self.root and node.color == BLACK:
            if node is node.parent.left:
                brother = node.parent.right
                if brother.color == RED:
                    brother.color = BLACK
                    node.parent.color = RED
                    self.__left_rotate(node.parent)
                    brother = node.parent.right
                if brother.left.color == BLACK and \
                        brother.right.color == BLACK:
                    brother.color = RED
                    node = node.parent
                else:
                    if brother.right.color == BLACK:
                        brother.left.color = BLACK
                        brother.color = RED
                        self.__right_rotate(brother)
                        brother = node.parent.right
                    brother.color = node.parent.color
                    node.parent.color = BLACK
                    brother.right.color = BLACK
                    self.__left_rotate(node.parent)
                    node = self.root
            else:
                brother = node.parent.left
                if brother.color == RED:
                    brother.color = BLACK
                    node.parent.color = RED
                    self.__right_rotate(node.parent)
                    brother = node.parent.left
                if brother.left.color == BLACK and \
                        brother.right.color == BLACK:
                    brother.color = RED
                    node = node.parent
                else:
                    if brother.left.color == BLACK:
                        brother.right.color = BLACK
                        brother.color = RED
                        self.__left_rotate(brother)
                        brother = node.parent.left
                    brother.color = node.parent.color
                    node.parent.color = BLACK
                    brother.left.color = BLACK
                    self.__right_rotate(node.parent)
                    node = self.root
        node.color = BLACK

    def insert(self, key):
        node = RBNode(key)
        y = NULL
        x = self.root
        while x is not NULL:
            y = x
            x = x.left if node.key < x.key else x.right

        node.parent = y
        if y is NULL:
            self.root = node
        else:
            setattr(y, 'left' if node.key < y.key else 'right', node)
        self.__insert_fixup(node)

    def search(self, key):
        x = self.root
        while x is not NULL and x.key != key:
            x = x.left if key < x.key else x.right
        return x

    @valid_node
    def delete(self, node):
        if not self.has_node(node):
            return
        if node is self.root:
            NULL.parent = None
            self.root = NULL
            del node
            return
        tobe_moved_node = node  # tobe_moved is node, also to be deleted.
        original_color = tobe_moved_node.color
        if node.left is NULL:
            tobe_fixed_node = node.right
            self._transplant(node, node.right)
        elif node.right is NULL:
            tobe_fixed_node = node.left
            self._transplant(node, node.left)
        else:
            # now tobe_moved_node is to be moved in tree.
            tobe_moved_node = self.minimum(node.right)
            original_color = tobe_moved_node.color
            tobe_fixed_node = tobe_moved_node.right
            if tobe_moved_node.parent is node:
                tobe_fixed_node.parent = tobe_moved_node  # set NULLNode.parent
            else:
                self._transplant(tobe_moved_node, tobe_moved_node.right)
                tobe_moved_node.right = node.right
                tobe_moved_node.right.parent = tobe_moved_node
            self._transplant(node, tobe_moved_node)
            tobe_moved_node.left = node.left
            tobe_moved_node.left.parent = tobe_moved_node
            tobe_moved_node.color = node.color
        del node
        if original_color == BLACK:
            self.__delete_fixup(tobe_fixed_node)


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

    tree.delete(tree.search(8))
    root = tree.root
    assert_key_color(root, 38, BLACK)
    assert_key_color(root.left, 19, RED)
    assert_key_color(root.left.left, 12, BLACK)
    assert_key_color(root.left.right, 31, BLACK)
    assert_key_color(root.right, 41, BLACK)

    tree.delete(tree.search(12))
    root = tree.root
    assert_key_color(root, 38, BLACK)
    assert_key_color(root.left, 19, BLACK)
    assert_key_color(root.left.right, 31, RED)
    assert_key_color(root.right, 41, BLACK)

    tree.delete(tree.search(19))
    root = tree.root
    assert_key_color(root, 38, BLACK)
    assert_key_color(root.left, 31,  BLACK)
    assert_key_color(root.right, 41, BLACK)

    tree.delete(tree.search(31))
    root = tree.root
    assert_key_color(root, 38, BLACK)
    assert_key_color(root.right, 41, RED)

    tree.delete(tree.search(41))
    root = tree.root
    assert_key_color(root, 38, BLACK)

    tree.delete(tree.search(38))
    assert tree.root == NULL
