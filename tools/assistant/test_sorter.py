from typing import List, Tuple

import configparser

import pytest

fake_c_cpp_exam_describe = r"""
// ---
// id = B1031
// title = 查验身份证
// score = 15
// categories = 字符串
// tags = kmp, string
// ---
"""

fake_py_exam_describe = r"""
# ---
# id = B1031
# title = 查验身份证
# score = 15
# categories = 字符串
# tags = kmp, string
# ---
"""


class ExamAnnotation(object):
    """控制向相应的练习文件中写入或提取题目相关信息的类"""
    border = '---'

    @staticmethod
    def resolve_info(file_str: str, *, comment_symbol: str) -> List[Tuple]:
        lines = file_str.split(comment_symbol)
        info: str = '[Info]\n'
        for line in lines:
            if line.strip() == ExamAnnotation.border:
                continue
            else:
                info += line
        exam_info_parser = configparser.ConfigParser()

        exam_info_parser.read_string(info)
        return list(exam_info_parser.items('Info'))

    @staticmethod
    def insert_info(file_path, *, comment_symbol: str):
        if isinstance(file_path, str):
            f = open(file_path, 'r+', encoding='utf-8')
            context = f.read()
            f.seek(0, 0)

            info = f"""# ---
# id = B1031
# title = 查验身份证
# score = 15
# categories = 字符串
# tags = kmp, string
# ---
"""

            f.write(info + context)
            f.close()
        else:
            f = file_path
            context = f.read()
            f.seek(0, 0)

            info = f"""# ---
# id = B1031
# title = 查验身份证
# score = 15
# categories = 字符串
# tags = kmp, string
# ---
"""

            f.write(info + context)


def test_extract_exam_description():
    expect = [('id', 'B1031'), ('title', '查验身份证'), ('score', '15'), ('categories', '字符串'), ('tags', 'kmp, string')]

    c_cc_actual = ExamAnnotation.resolve_info(fake_c_cpp_exam_describe, comment_symbol='//')
    assert c_cc_actual == expect, "C或C++注释信息提取失败"

    py_actual = ExamAnnotation.resolve_info(fake_py_exam_describe, comment_symbol='#')
    assert py_actual == expect, "Python注释信息提取失败"


@pytest.mark.skip("不太会tempfile这个模块(其实是IO FILE 整个都不太熟悉(逃")
def test_write_exam_description():
    # FIXME:这里的测试应该使用tempfile模块提供的临时文件机制,以保持单测性质
    ExamAnnotation.insert_info('file_test.py', comment_symbol='#')

    with open('file_test.py', 'r') as f:
        assert ExamAnnotation.border in f.read()
