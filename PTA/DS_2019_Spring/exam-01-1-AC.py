def max_sub_sequence_sum_On3(nums: list, length: int) -> int:
    max_sum = 0
    for i in range(length):
        for j in range(i, length):
            tmp_sum = 0
            for k in range(i, j):
                tmp_sum += nums[k]

            if max_sum < tmp_sum:
                max_sum = tmp_sum
    return max_sum


def max_sub_sequence_sum_On2(nums: list, length: int) -> int:
    max_sum = 0
    for i in range(length):
        tmp_sum = 0
        for j in range(i, length):
            tmp_sum += nums[j]

            if max_sum < tmp_sum:
                max_sum = tmp_sum
    return max_sum


def max_sub_sequence_sum_Onlogn(nums: list, length: int) -> int:
    # assert False, 'RecursionError: maximum recursion depth exceeded in comparison'

    def divide_and_conquer(nums: list, left: int, right: int):
        # 基准条件
        if left == right:
            return nums[left] if nums[left] > 0 else 0
        # 分 (divide)
        middle = (left + right) // 2
        max_left_sum = divide_and_conquer(nums, left, middle)
        max_right_sum = divide_and_conquer(nums, middle+1, right)

        # 治 (conquer)
        max_left_border_sum = 0
        left_border_sum = 0
        for i in range(middle, left - 1, -1):
            left_border_sum += nums[i]
            if max_left_border_sum < left_border_sum:
                max_left_border_sum = left_border_sum

        max_right_border_sum = 0
        right_border_sum = 0
        for i in range(middle+1, right + 1):
            right_border_sum += nums[i]
            if max_right_border_sum < right_border_sum:
                max_right_border_sum = right_border_sum
        return max(max(max_left_sum, max_right_sum), max_left_border_sum+max_right_border_sum)
    return divide_and_conquer(nums, 0, length-1)


def max_sub_sequence_sum_On(nums: list, length: int) -> int:
    max_sum = 0
    tmp_sum = 0
    for i in range(length):
        tmp_sum += nums[i]
        if max_sum < tmp_sum:
            max_sum = tmp_sum
        elif tmp_sum < 0:
            tmp_sum = 0
    return max_sum


k = int(input())
if k <= 100000 and k >= 1:
    nums = [int(s_num) for s_num in str(input()).split()]
    print(max_sub_sequence_sum_Onlogn(nums, k))
