import sys

transcripts = [0 for _ in range(100010)]
n = int(input())
for line in sys.stdin:
    sch, sco = map(int, line.split())
    transcripts[sch] += sco

k, score = 1, -1
for i in range(1, n+1):
    if transcripts[i] > score:
        score = transcripts[i]
        k = i

print(k, score)
