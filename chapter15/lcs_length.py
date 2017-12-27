MEMO = dict()


def memoized_lcs(x, y):
    key = (len(x), len(y))
    if key in MEMO:
        return MEMO[key]
    if 0 in key:
        lcs = 0
    else:
        if x[-1] == y[-1]:
            lcs = 1 + memoized_lcs(x[:-1], y[:-1])
        else:
            lcs = max(memoized_lcs(x[:-1], y), memoized_lcs(x, y[:-1]))
    MEMO[key] = lcs
    return lcs


def bottom_up_lcs(x, y):
    results = [[0] * (len(y)+1) for _ in range(len(x)+1)]
    for i in range(1, len(x)+1):
        for j in range(1, len(y)+1):
            if x[i-1] == y[j-1]:
                results[i][j] = results[i-1][j-1] + 1
            elif results[i-1][j] >= results[i][j-1]:
                results[i][j] = results[i-1][j]
            else:
                results[i][j] = results[i][j-1]
    return results


def get_results(results, x, y):
    assert len(x) + 1 == len(results)
    assert len(y) + 1 == len(results[0])
    answer = []
    i = len(results) - 1
    j = len(results[0]) - 1
    while True:
        if i == 0 or j == 0:
            return answer
        item = results[i][j]
        if results[i-1][j] == item:
            i -= 1
            continue
        if results[i][j-1] == item:
            j -= 1
            continue
        assert results[i-1][j-1] + 1 == item
        assert x[i-1] == y[j-1]
        answer.insert(0, x[i-1])
        i -= 1
        j -= 1


def convert2result(memo):
    x, y = max(memo.keys())
    results = [[0] * (y+1) for _ in range(x+1)]
    for (i, j), v in memo.items():
        results[i][j] = v
    return results


def longest_sub_sequence_increase(x):
    y = sorted(x)
    print(get_results(bottom_up_lcs(x, y), x, y))


if __name__ == '__main__':
    X = [int(i) for i in '10010101']
    Y = [int(i) for i in '010110110']
    right = [int(i) for i in '101010']
    result = bottom_up_lcs(X, Y)
    assert get_results(result, X, Y) == right

    lcs_length = memoized_lcs(X, Y)
    assert lcs_length == len(right)
    result = convert2result(MEMO)
    assert get_results(result, X, Y) == right

    longest_sub_sequence_increase([1, 5, -1, 2, 3, 4, -5, -10, 8, 59, 6, 4])
