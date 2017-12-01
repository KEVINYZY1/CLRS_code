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
    if start == end:
        return arr[start]
    pivot_index = partition(arr, start, end)
    k = pivot_index - start + 1  # pivot在当前子序列第几大
    if i == k:  # 若相同，则返回
        return arr[pivot_index]
    elif i < k:  # 若pivot值更大，则在更小的子序列中寻找
        end = pivot_index - 1
    else:  # 若pivot值更小，则在更大的子序列中寻找，此时对应的i值也应该变化
        start = pivot_index + 1
        i = i - k
    return quick_selection(arr, start, end, i)


if __name__ == '__main__':
    sequence = list({random.randint(0, 1000) for _ in range(500)})
    sorted_sequence = sorted(sequence)
    for index, correct in enumerate(sorted_sequence):
        rank = index + 1
        value = quick_selection(sequence, 0, len(sequence)-1, rank)
        assert correct == value
