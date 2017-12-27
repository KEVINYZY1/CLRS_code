import functools


PRICE = {
    1: 1,
    2: 5,
    3: 8,
    4: 9,
    5: 10,
    6: 17,
    7: 17,
    8: 20,
    9: 24,
    10: 30,
}
SOLUTION = dict()
MEMO = dict()


@functools.lru_cache()
def cut_rod(length):
    if length == 0:
        return 0
    income = -1
    end = min(max(PRICE.keys()), length)
    for i in range(1, end+1):
        result = PRICE[i] + cut_rod(length-i)
        if income < result:
            income = result
            SOLUTION[length] = i
    return income


def memoized_cut_rot(length):
    if length in MEMO:
        return MEMO[length]
    if length == 0:
        income = 0
    else:
        income = -1
        end = min(max(PRICE.keys()), length)
        for i in range(1, end+1):
            result = PRICE[i] + cut_rod(length-i)
            if income < result:
                income = result
                SOLUTION[length] = i
    MEMO[length] = income
    return income


def bottom_up_cut_rod(length):
    MEMO[0] = 0
    for i in range(1, length + 1):
        income = -1
        end = min(max(PRICE.keys()), i)
        for j in range(1, end+1):
            result = PRICE[j] + MEMO[i-j]
            if income < result:
                income = result
                SOLUTION[i] = j
        MEMO[i] = income
    return MEMO[length]


def print_solution():
    item = max(SOLUTION.keys())
    while item != 0:
        print('{} + '.format(SOLUTION[item]), end='')
        item = item - SOLUTION[item]
    print(0)


def reset_variable():
    global MEMO
    MEMO = dict()
    global SOLUTION
    SOLUTION = dict()


if __name__ == '__main__':
    assert cut_rod(9) == 25
    assert memoized_cut_rot(9) == 25
    assert bottom_up_cut_rod(9) == 25
    reset_variable()
    print(bottom_up_cut_rod(18))
    print_solution()
