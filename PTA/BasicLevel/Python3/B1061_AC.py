n, m = map(int, input().split())

scores = list(map(int, input().split()))

answers = list(map(int, input().split()))


for i in range(n):
    actuals = list(map(int, input().split()))
    result = 0
    for i, score in enumerate(scores):
        if actuals[i] == answers[i]:
            result += score
    print(result)
