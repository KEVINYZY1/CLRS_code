MEMO = dict()
items = [(0, 0)]  # weight, value
total_capacity = 0


def bp_knapsack_problem(num, capacity):
    """
    :param num: 选取的第num个物品
    :param capacity: 此时背包剩余的容量
    :return 最大收益
    """
    key = (num, capacity)
    if key in MEMO:
        return MEMO[key]
    if 0 in key:
        result = 0, False
    else:
        weight, value = items[num]
        if weight > capacity:
            result = bp_knapsack_problem(num-1, capacity)
        else:
            with_me = value + bp_knapsack_problem(num-1, capacity - weight)[0]
            without_me = bp_knapsack_problem(num-1, capacity)[0]
            if with_me >= without_me:
                result = with_me, True
            else:
                result = without_me, False
    MEMO[key] = result
    return result


def parse_memo():
    result = []
    capacity = total_capacity
    for i, item in enumerate(items[::-1]):
        real_index = len(items) - 1 - i
        _, with_item = MEMO[(real_index, capacity)]
        if with_item:
            result.append((real_index, item))
            capacity -= item[0]
    return result


if __name__ == '__main__':
    items = [(12, 4), (2, 2), (1, 2), (1, 1), (4, 10)]  # (weight, value)
    total_capacity = 15
    income = bp_knapsack_problem(len(items) - 1, total_capacity)[0]
    solution = parse_memo()
    print(income, solution)
