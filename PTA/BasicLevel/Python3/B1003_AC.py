def check(text: str) -> bool:
    pos_P = text.find('P')
    pos_T = text.find('T')
    if pos_P == -1 or text.find('A') == -1 or pos_T == -1 or pos_P >= pos_T-1:
        return False

    for i in range(len(text)):
        if i == pos_P or i == pos_T:
            continue
        if text[i] != 'A':
            return False

    # count(A)_[left,mid,right]
    cnt_left = pos_P
    cnt_mid = pos_T - (pos_P + 1)
    cnt_right = len(text) - (pos_T + 1)

    while cnt_mid != 1:
        cnt_mid -= 1
        cnt_right = cnt_right - cnt_left

    if cnt_left != cnt_right:
        return False
    else:
        return True


n = int(input())
for _ in range(n):
    text = input()
    print("{}".format("YES" if check(text) else "NO"))
