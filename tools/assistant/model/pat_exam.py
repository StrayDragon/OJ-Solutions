from dataclasses import dataclass, field, asdict
from model import Serializable

# 题目样例

"""
{"problemSetProblems":[
    {
    *   "id": "994805528788582400", => 'no'
    *   "label": "1001",
    *   "score": 20,
        "deadline": "1970-01-01T00:00:00Z",
    *   "acceptCount": 11050,
    *   "submitCount": 42977,
    *   "title": "A+B Format",
        "type": "PROGRAMMING",
        "compiler": "NO_COMPILER",
        "problemStatus": "NO_PROBLEM_STATUS"
    },
    ...]}
('*' 号标注为需要序列化的信息)
此外还有需要计算的量:
    *   difficulty
    *   accept_rate
    *   local_update_time
其他信息:
    *   level (甲/乙级)
    *   memory_limitation
    *   time_limitation
"""


@dataclass
class PATExam(Serializable):
    """Model : PAT习题"""

    def to_json(self) -> dict:
        return asdict(self)

    @classmethod
    def from_json(cls, json_obj: dict):
        exam = cls(
            _id=json_obj['id'],
            label=json_obj['label'],
            score=json_obj['score'],
            accept_count=json_obj['acceptCount'],
            submit_count=json_obj['submitCount'],
            title=json_obj['title'],
            level='甲级',  # FIXME:假的数据
            memory_limitation=0,  # FIXME:假的数据
            time_limitation=0,  # FIXME:假的数据
        )
        return exam

    _id: str
    label: str
    score: int
    difficulty: str = field(init=False)
    accept_count: int
    submit_count: int
    accept_rate: float = field(init=False)
    title: str
    level: str
    memory_limitation: int
    time_limitation: int
    local_update_time: str = field(init=False)

    def __post_init__(self):
        # 初始化 self.difficulty
        difficult_selector = {
            '甲级': {15: 'Easy', 20: 'Medium', 25: 'Hard'},
            '乙级': {20: 'Easy', 25: 'Medium', 30: 'Hard'},
        }
        self.difficulty = difficult_selector[self.level][self.score]

        # 初始化 self.accept_rate
        self.accept_rate = "%2.f%%" % float(self.accept_count / self.submit_count)

        # 初始化 self.local_update_time
        import datetime
        self.local_update_time = str(datetime.date.today())
