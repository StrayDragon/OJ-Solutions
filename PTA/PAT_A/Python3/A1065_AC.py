n = int(input())
for case_cnt in range(1, n+1):
    a, b, c = map(int, input().split())
    print("Case #{}: true".format(case_cnt) if a+b > c
          else "Case #{}: false".format(case_cnt))
