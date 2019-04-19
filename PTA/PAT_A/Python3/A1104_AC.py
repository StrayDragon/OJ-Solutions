n = int(input())

nums = input().split()

sum_ = 0


for i in range(n):
    sum_ += float(nums[i]) * (i + 1) * (n - i)

print("%.2f" % sum_)
