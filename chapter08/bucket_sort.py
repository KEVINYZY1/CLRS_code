import random


def bucket_sort(arr):
    small, big, length = min(arr), max(arr), len(arr)
    item = (big - small + 1) / length
    tmp = [[] for _ in range(length)]
    for value in arr:
        index = int((value - small) // item)
        tmp[index].append(value)
    for i, l in enumerate(tmp):
        tmp[i] = sorted(l)
    index = 0
    for l in tmp:
        for i in l:
            arr[index] = i
            index += 1
    return arr


if __name__ == '__main__':
    arr = [random.randint(0, 100000) for _ in range(1000)]
    assert sorted(arr) == bucket_sort(arr)
