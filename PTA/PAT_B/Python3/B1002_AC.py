num2hanzi = {'1': 'yi', '2': 'er', '3': 'san', '4': 'si',
             '5': 'wu', '6': 'liu', '7': 'qi', '8': 'ba', '9': 'jiu', '0': 'ling'}

digits = list(map(lambda x: int(x), input()))

digits_sum = 0
for digit in digits:
    digits_sum += digit

num_strs = str(digits_sum)

if len(num_strs) > 0:
    print(num2hanzi[num_strs[0]], end='')

for n in num_strs[1:]:
    print(' ' + num2hanzi[n], end='')
