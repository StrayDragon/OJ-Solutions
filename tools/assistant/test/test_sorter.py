from typing import List, Tuple

import tempfile
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
    """负责监控/写入题目相关信息的类"""
    border = '---'

    @staticmethod
    def autofix():
        pass

    @staticmethod
    def check():
        pass

    @staticmethod
    def extract(file, *, comment_symbol: str):
        annotation = ""
        encounter = 0
        if isinstance(file, str):
            path = file
            with open(path, 'r', encoding='utf-8') as f:
                for line in f.readlines():
                    if line.startswith(f'{comment_symbol} ---'):
                        encounter += 1
                    if encounter == 1:
                        annotation += line
                    elif encounter >= 2:
                        break
                return ExamAnnotation.resolve(annotation, comment_symbol=comment_symbol)
        else:
            for line in file.readlines():
                if line.startswith(f'{comment_symbol} ---'):
                    encounter += 1
                if encounter == 1:
                    annotation += line
                elif encounter >= 2:
                    break
            return ExamAnnotation.resolve(annotation, comment_symbol=comment_symbol)

    @staticmethod
    def resolve(annotation: str, *, comment_symbol: str) -> List[Tuple]:
        lines = annotation.split(comment_symbol)
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
    def write(file, *, comment_symbol: str):
        if isinstance(file, str):
            f = open(file, 'r+', encoding='utf-8')
            context = f.read()
            f.seek(0, 0)
            # TODO: 需要确定ExamFile对象字段
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
            f = file
            f.seek(0)
            context = f.read()
            f.seek(0, 0)

            # TODO: 需要确定ExamFile对象字段
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

    c_cc_actual = ExamAnnotation.resolve(fake_c_cpp_exam_describe, comment_symbol='//')
    assert c_cc_actual == expect, "C或C++题解 相关信息提取失败"

    py_actual = ExamAnnotation.resolve(fake_py_exam_describe, comment_symbol='#')
    assert py_actual == expect, "Python题解 相关信息提取失败"

    with tempfile.TemporaryFile('r+', encoding='utf-8') as tmp:
        tmp.write("""// ---
// id = B1031
// title = 查验身份证
// score = 15
// categories = 字符串
// tags = kmp, string
// ---

#include <stdio.h>

//......""")
        tmp.seek(0)
        c_cc_file_actual = ExamAnnotation.extract(tmp, comment_symbol='//')
        assert c_cc_file_actual == expect, "C或C++题解 相关信息提取失败"


def test_write_exam_description():
    with tempfile.TemporaryFile('r+', encoding='utf-8') as tmp:
        tmp.write('源代码源代码源代码~')
        ExamAnnotation.write(tmp, comment_symbol='#')
        tmp.seek(0)
        assert ExamAnnotation.border in tmp.read()
