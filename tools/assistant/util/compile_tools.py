import subprocess
import shutil
from abc import abstractmethod


class Language(object):

    @abstractmethod
    def compile_and_run(self, instruction: str) -> str: pass

    @staticmethod
    @abstractmethod
    def check(target_path, inputfile, outputfile) -> bool:
        pass


class Python(Language): pass


class Cpp(Language): pass
