num_to_en = {'1': 'one', '2': 'two', '3': 'three', '4': 'four', '5': 'five',
             '6': 'six', '7': 'seven', '8': 'eight', '9': 'nine', '0': 'zero'}

digits = input()

result = str(sum(map(int, digits)))

print(num_to_en[result[0]], end='')

for digit in result[1:]:
    print('', num_to_en[digit], end='')
