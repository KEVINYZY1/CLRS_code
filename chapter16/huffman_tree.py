from queue import PriorityQueue


class Node:
    def __init__(self, key, left=None, right=None):
        self.key = key
        self.left = left
        self.right = right

    def __lt__(self, other):
        return self.key < other.key


def get_huffman_tree(sequence):
    q = PriorityQueue()
    for i in sequence:
        q.put(Node(i))

    for i in range(len(sequence) - 1):
        a = q.get()
        b = q.get()
        q.put(Node(a.key + b.key, a, b))
    return q.get()


if __name__ == '__main__':
    s = [1, 1]
    for _ in range(6):
        s.append(s[-2] + s[-1])
    t = get_huffman_tree(s)
    assert t.left.key == s[-1]
    assert t.right.left.key == s[-2]
    assert t.right.right.left.key == s[-3]
