import subprocess
import shlex
from abc import abstractmethod

from typing import Union


class Language(object):

    @staticmethod
    @abstractmethod
    def run(target) -> str: pass

    @staticmethod
    @abstractmethod
    def check(target, inputfile, answer=None) -> bool: pass


class Python(Language):
    @staticmethod
    def run(target) -> bool:
        if isinstance(target, str):
            cp = subprocess.run(shlex.split(
                f'python3.7 {target}'), capture_output=True)
            return len(cp.stdout) != b''
        return False

    @staticmethod
    def check(target, input_path, answer=None) -> Union[bool, str]:
        if isinstance(input_path, str) and isinstance(target, str):
            with open(input_path, encoding='utf-8') as f:
                output = subprocess.check_output(
                    shlex.split(f'python3.7 {target}'), stdin=f)
            if answer:
                return output.decode() == answer
            else:
                return output.decode()
        return False


class Cpp(Language):
    pass
