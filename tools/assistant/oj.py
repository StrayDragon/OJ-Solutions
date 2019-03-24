# TODO:准备开始写一个统一各个语言编译/执行入口和检测输出一致性的裁判程序
import click
import os
import string

REPO_ROOT = r'/home/straydragon/GitHubRepo/OJ'

supported_oj_platforms = ['PTA']


class Language(object):
    pass


class Python(Language):
    pass


class Cpp(Language):
    pass


class OfflineJudge(object):
    def __init__(self, repo_root, debug=True):
        self.repo_root = repo_root
        self.debug = debug


@click.group()
@click.option('-t', '--target', 'repo_path', envvar='REPO_ROOT')
@click.pass_context
def cli(ctx, repo_path, debug):
    ctx.obj = OfflineJudge(repo_path, debug)
    pass


def retrieve_supported_platform():
    cwd = os.getcwd()
    repo_root = cwd[:cwd.find('OJ') + 2]
    dirs = os.listdir('../../')
    return list(
        map(
            lambda d: os.path.join(repo_root, d),
            filter(
                lambda d: d[0] in string.ascii_uppercase,
                filter(
                    lambda d: os.path.isdir(os.path.join(repo_root, d)),
                    dirs
                )
            )
        )
    )


def test_status():
    pass


if __name__ == '__main__':
    targets = retrieve_supported_platform()
    for target in targets:
        for d in filter(lambda d: os.path.isdir(os.path.join(REPO_ROOT, target, d)), os.listdir(target)):
            print(os.listdir(os.path.join(REPO_ROOT, target, d)))
            print(os.path.join(REPO_ROOT, target, d))
