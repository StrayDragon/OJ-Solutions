MAGIC_NUM = 1000000007

left_cnt_P = [0 for _ in range(100010)]

s = input()

for i in range(len(s)):
    if i > 0: left_cnt_P[i] = left_cnt_P[i - 1]
    if s[i] == 'P': left_cnt_P[i] += 1

result = 0
right_num_T = 0
for i in range(len(s)-1,-1,-1):
    if s[i] == 'T': right_num_T += 1
    elif s[i] == 'A': result = (result + left_cnt_P[i]*right_num_T) % MAGIC_NUM

print(result)

