from ctypes import *
libc = cdll.LoadLibrary("libc.so.6")
scanf = libc.scanf

n = int(input())

c_school = c_int()
c_score = c_int()

school, score = 0, 0
schools = []
report = {}
for _ in range(n):
    scanf(b"%d%d", byref(c_school), byref(c_score))
    school = c_school.value
    score = c_score.value
    
    if report.get(school):
        report[school] += score
    else:
        report[school] = score
        schools.append(school)

result = sorted(report.items(), key=lambda t: t[1], reverse=True)
print(result[0][0], result[0][1])
