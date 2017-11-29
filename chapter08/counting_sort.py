import random


def counting_sort(arr):
    small, big = min(arr), max(arr)

    tmp = [0] * (big - small + 1)
    for value in arr:
        value -= small
        tmp[value] += 1
    for index in range(len(tmp)-1):
        tmp[index+1] += tmp[index]

    sorted_arr = [0]*len(arr)
    for value in arr:
        value -= small
        index = tmp[value] - 1
        sorted_arr[index] = value + small
        tmp[value] -= 1
    return sorted_arr


if __name__ == '__main__':
    arr = [random.randint(0, 10000) for _ in range(1000)]
    assert sorted(arr) == counting_sort(arr)
