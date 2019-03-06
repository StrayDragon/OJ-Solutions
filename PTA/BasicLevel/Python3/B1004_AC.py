n = int(input())

students = []
for _ in range(n):
    info = list(input().split())
    students.append((info[0], info[1], int(info[2])))

students.sort(key=lambda t: (None, None, t[2]))

print(students[-1][0], students[-1][1])
print(students[0][0], students[0][1])
