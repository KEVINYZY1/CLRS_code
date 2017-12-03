class Node:
    def __init__(self, data=None, lchild=None, rchild=None, parent=None):
        self.data = data
        self.lchild=lchild
        self.rchild=rchild
        self.parent = parent


class BinaryTree:
    def __init__(self):
        self.root = Node()

    def is_empty(self):
        return self.root.data is None

    def add_node(self, data):
        assert data is not None
        node = Node(data)
        if self.is_empty():
            self.root = node
        else:
            queue = [self.root]

            while queue:
                tree_node = queue.pop(0)
                if tree_node.lchild is None:
                    node.parent = tree_node
                    tree_node.lchild = node
                    return
                elif tree_node.rchild is None:
                    node.parent = tree_node
                    tree_node.rchild = node
                    return
                else:
                    queue.extend([tree_node.lchild, tree_node.rchild])

    def in_order_loop_no_stack(self, show=False):  # 中序遍历： 左 中 右
        result = []
        if self.is_empty():
            return result
        left = right = False
        node = self.root
        while not (node is self.root and left is True and right is True):
            # 每次遍历输入的node要求：left, right记录着node左右是否被访问过信息。
            if right is True:  # 如果右边访问过，则左右访问过，确定父节点的left和right信息，然后向上走
                left = right = False
                if node.parent.lchild is node:
                    left = True
                if node.parent.rchild is node:
                    left = right = True
                node = node.parent
            else:  # 如果需要往下走
                while node.lchild is not None and left is False:  # 优先访问左边的未访问结点
                    node = node.lchild
                if show:
                    print(node.data)  # 往左走到头，输出结点值
                result.append(node.data)
                if node.rchild is not None:  # 右边有结点，向右走，并确定left right值
                    node = node.rchild
                    left = right = False
                else:  # 到了叶子结点
                    left = right = False
                    if node.parent.lchild is node:  # 顺着上个while下来的，本叶结点是父节点的左结点
                        left = True
                    if node.parent.rchild is node:  # 顺着最外层while下来的，本叶结点是父节点的右节点
                        left = right = True
                    node = node.parent
        return result


if __name__ == '__main__':
    tree = BinaryTree()
    for i in range(1, 11):
        tree.add_node(i)
    in_order_result = tree.in_order_loop_no_stack()
    assert in_order_result == [8, 4, 9, 2, 10, 5, 1, 6, 3, 7]
