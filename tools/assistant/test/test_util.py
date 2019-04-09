import os


def test_compile_tools_python_run():
    from util.compile_tools import Python
    is_ok = Python.run(os.path.join(os.getcwd(), 'testfile', 'fake_exam.py'))
    assert is_ok


def test_compile_tools_python_check():
    from util.compile_tools import Python
    result = Python.check(os.path.join(os.getcwd(), 'testfile', 'fake_exam.py'),
                          os.path.join(os.getcwd(), 'testfile', 'fake_exam.input'))
    if isinstance(result, bool):
        assert result
    else:
        print(result)
