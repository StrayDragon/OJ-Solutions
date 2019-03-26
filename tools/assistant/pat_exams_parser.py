import requests

PAT_A_EXAMS_LIST_URL = r'https://pintia.cn/api/problem-sets/994805342720868352/problems?type=PROGRAMMING'

# TODO:https://python3-cookbook.readthedocs.io/zh_CN/latest/c06/p02_read-write_json_data.html


class JSONObject(object):
    def __init__(self, d):
        self.__dict__ = d


# 题目样例
"""
{
"id": "994805528788582400",
"label": "1001",
"score": 20,
"deadline": "1970-01-01T00:00:00Z",
"acceptCount": 11050,
"submitCount": 42977,
"title": "A+B Format",
"type": "PROGRAMMING",
"compiler": "NO_COMPILER",
"problemStatus": "NO_PROBLEM_STATUS"
},
"""


def retrieve_all_exams(url: str) -> JSONObject:
    rsp = requests.get(PAT_A_EXAMS_LIST_URL)
    exams = rsp.json(object_hook=JSONObject) if rsp.status_code == 200 else {}
    return exams


def main():
    m = retrieve_all_exams(PAT_A_EXAMS_LIST_URL)
    print(type(m.problemSetProblems), len(m.problemSetProblems))
    print(type(m))


if __name__ == "__main__":
    main()
