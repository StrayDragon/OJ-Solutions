class Testee(object):
    def __init__(self, id_score: tuple, local_num: int):
        self.id, self.score = id_score
        self.local_num = local_num
        self.local_rank = -1
        self.final_rank = -1

    def __lt__(self, other):
        if self.score != other.score:
            return self.score > other.score
        else:
            return self.id < other.id

    def __repr__(self):
        return '%013d %d %d %d' % (
            self.id, self.final_rank, self.local_num, self.local_rank
        )


n = int(input())

ranklists = []
for local_num in range(1, n+1):
    k = int(input())
    local_ranklists = []
    for _ in range(k):
        t = Testee(map(int, input().split()), local_num)
        local_ranklists.append(t)
    local_ranklists.sort()
    local_ranklists[0].local_rank = 1
    for i in range(1, len(local_ranklists)):
        if local_ranklists[i].score == local_ranklists[i-1].score:
            local_ranklists[i].local_rank = local_ranklists[i-1].local_rank
        else:
            local_ranklists[i].local_rank = i+1
    ranklists.extend(local_ranklists)

ranklists.sort()
ranklists[0].final_rank = 1
for i in range(1, len(ranklists)):
    if ranklists[i].score == ranklists[i-1].score:
        ranklists[i].final_rank = ranklists[i-1].final_rank
    else:
        ranklists[i].final_rank = i+1

print(len(ranklists))
for testee in ranklists:
    print(testee)
