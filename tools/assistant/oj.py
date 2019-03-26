# TODO:准备开始写一个统一各个语言编译/执行入口和检测输出一致性的裁判程序
import click
import os
import string

REPO_ROOT = r'/home/straydragon/GitHubRepo/OJ'


class OfflineJudge(object):
    def __init__(self, repo_root, debug=True):
        self.repo_root = repo_root
        self.debug = debug


@click.group()
@click.option('-t', '--target', 'repo_path', envvar='REPO_ROOT')
@click.option('-d', '--debug', 'debug', default=True)
@click.pass_context
def cli(ctx, repo_path, debug):
    ctx.obj = OfflineJudge(repo_path, debug)
    pass


@cli.command('platforms')
def platform():
    targets = retrieve_supported_platform()
    # print(targets)
    # print(os.listdir(os.path.join(REPO_ROOT, targets[-1])))
    for target in targets:
        for exam_set in filter(lambda d: os.path.isdir(os.path.join(REPO_ROOT, target)),
                               os.listdir(os.path.join(REPO_ROOT, target))):
            print(os.path.join(REPO_ROOT, target, exam_set))
            print(os.listdir(os.path.join(REPO_ROOT, target, exam_set)))


def retrieve_supported_platform():
    cwd = os.getcwd()
    repo_root = cwd[:cwd.find('OJ') + 2]
    dirs = os.listdir('../../')
    return list(
        filter(
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


if __name__ == '__main__':
    cli()
