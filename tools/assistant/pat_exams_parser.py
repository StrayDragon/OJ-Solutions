import requests

PAT_A_EXAMS_LIST_URL = r'https://pintia.cn/api/problem-sets/994805342720868352/problems?type=PROGRAMMING'

# TODO:https://python3-cookbook.readthedocs.io/zh_CN/latest/c06/p02_read-write_json_data.html


class JSONObject(object):
    def __init__(self, d):
        self.__dict__ = d


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
