import random


def partition(arr, start, end):
    pivot = random.choice(arr[start: end+1])
    left, right = list(), list()
    for i in arr[start: end+1]:
        if i < pivot:
            left.append(i)
        elif i > pivot:
            right.append(i)
    pivot_index = start + len(left)
    left.append(pivot)
    left.extend(right)
    arr[start: end+1] = left
    return pivot_index


def quick_selection(arr, start, end, i):
    """
    :param arr:     总序列
    :param start:   当前序列的开始位置
    :param end:     当前序列的结束位置
    :param i:       寻找当前序列中第i小的元素
    :return:        第i小的元素的值
    """
    while True:  # 使用条件 end >= start 也可以，但是统计量不可能出现这种情况
        if start == end:
            return arr[start]
        pivot_index = partition(arr, start, end)
        k = pivot_index - start + 1
        if i == k:
            return arr[pivot_index]
        elif i < k:
            end = pivot_index - 1
        else:
            start = pivot_index + 1
            i = i - k


if __name__ == '__main__':
    sequence = list({random.randint(0, 1000) for _ in range(500)})
    sorted_sequence = sorted(sequence)
    for index, correct in enumerate(sorted_sequence):
        rank = index + 1
        value = quick_selection(sequence, 0, len(sequence)-1, rank)
        assert correct == value
