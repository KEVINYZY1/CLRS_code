from pprint import pprint


class BinaryTree:
    def __init__(self, data_list=None):
        self.data_list = data_list or list(range(1, 11))
        self.root = None
        self._build_tree()

    @staticmethod
    def get_node(data=None):
        return {
            'data': data,
            'left': None,
            'right': None
        }

    def _build_tree(self):
        assert len(self.data_list) > 0

        self.root = self.get_node(self.data_list.pop(0))

        for data in self.data_list:
            queue = [self.root]
            node = self.get_node(data)
            while queue:
                parent = queue.pop(0)
                if parent['left'] is None:
                    parent['left'] = node
                    break
                elif parent['right'] is None:
                    parent['right'] = node
                    break
                else:
                    queue.extend([parent['left'], parent['right']])

    def show(self):
        pprint(self.root)

    @classmethod
    def pre_order(cls, tree):
        if tree is None:
            return
        print(tree['data'], end=' ')
        cls.pre_order(tree['left'])
        cls.pre_order(tree['right'])

    @classmethod
    def in_order(cls, tree):
        if tree is None:
            return
        cls.in_order(tree['left'])
        print(tree['data'], end=' ')
        cls.in_order(tree['right'])

    @classmethod
    def post_order(cls, tree):
        if tree is None:
            return
        cls.post_order(tree['left'])
        cls.post_order(tree['right'])
        print(tree['data'], end=' ')

    @property
    def is_empty(self):
        return self.root is None

    def pre_order_loop(self):
        result = list()
        if self.is_empty:
            return result

        stack = [self.root]
        while stack:
            node = stack.pop()
            result.append(node['data'])
            if node['right'] is not None:
                stack.append(node['right'])
            if node['left'] is not None:
                stack.append(node['left'])
        return result

    def in_order_loop(self):
        result = list()
        if self.is_empty:
            return result

        node = self.root
        stack = list()
        while node or stack:
            while node is not None:
                stack.append(node)
                node = node['left']
            node = stack.pop()
            result.append(node['data'])
            node = node['right']
        return result

    def post_order_loop(self):
        """使用两个栈实现"""
        result = list()
        if self.is_empty:
            return result

        node = self.root
        stack = list()
        stack_tmp = list()
        stack_tmp.append(node)
        # 从辅助栈去除元素的顺序是 递归中右左，再用实际栈翻转。
        while stack_tmp:
            node = stack_tmp.pop()
            if node['left'] is not None:
                stack_tmp.append(node['left'])
            if node['right'] is not None:
                stack_tmp.append(node['right'])
            stack.append(node)
        while stack:
            result.append(stack.pop()['data'])
        return result

    def level_order(self):
        result = list()
        node = self.root
        if node is None:
            return result

        queue = list()
        queue.append(node)

        while queue:
            node = queue.pop(0)
            result.append(node['data'])
            if node['left'] is not None:
                queue.append(node['left'])
            if node['right'] is not None:
                queue.append(node['right'])
        return result


if __name__ == '__main__':
    binary_tree = BinaryTree()
    binary_tree.show()

    print('-------------------------')
    level_order_result = binary_tree.level_order()
    print(level_order_result)
    print('-------------------------')

    pre_order_result = binary_tree.pre_order_loop()
    print(pre_order_result)
    BinaryTree.pre_order(binary_tree.root)
    print('\n-------------------------')

    in_order_result = binary_tree.in_order_loop()
    print(in_order_result)
    BinaryTree.in_order(binary_tree.root)
    print('\n-------------------------')

    post_order_result = binary_tree.post_order_loop()
    print(post_order_result)
    BinaryTree.post_order(binary_tree.root)
    print('\n-------------------------')
