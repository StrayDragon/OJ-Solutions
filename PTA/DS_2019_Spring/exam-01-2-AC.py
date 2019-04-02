def max_sub_sequence_sum_On(nums: list, length: int):
    max_sum = -1
    tmp_sum = 0
    begin = 0
    first = length-1
    last = length-1
    for i in range(length):
        tmp_sum += nums[i]
        if max_sum < tmp_sum:
            max_sum = tmp_sum
            first = begin
            last = i
        elif tmp_sum < 0:
            begin = i + 1
            tmp_sum = 0

    return (max_sum, first, last)


k = int(input())
if k <= 10000 and k >= 1:
    nums = [int(s_num) for s_num in str(input()).split()]
    max_sub_sum, lindex, rindex = max_sub_sequence_sum_On(nums, k)

    not_all_negatives = False
    for n in nums:
        if n >= 0:
            not_all_negatives = True
            break
    if not_all_negatives:
        if max_sub_sum < 0:
            print('0 %d %d' % (nums[lindex], nums[rindex]))
        else:
            print('%d %d %d' % (max_sub_sum, nums[lindex], nums[rindex]))
    else:
        print('0 %d %d' % (nums[0], nums[k-1]))
