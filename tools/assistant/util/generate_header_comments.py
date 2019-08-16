import json
import pathlib
from collections import namedtuple
from typing import Dict

Exam = namedtuple('Exam', ['id_', 'title', 'difficulty',
                           'score', 'tag', 'keyword', 'status', 'from_', ])


def parse_and_retrieve_exams():
    exams: Dict[str, Exam] = {}
    with open("../data/pat-a-exams-2019-08-16.json", 'r', encoding='utf8') as f:
        tmp = json.load(f)
        def _get_difficulty(
            score): return 'Easy' if score == 20 else 'Medium' if score == 25 else 'Hard'
        for problem in tmp['problemSetProblems']:
            exams[problem['label']] = Exam(
                id_=problem['label'],
                title=problem['title'],
                difficulty=_get_difficulty(problem['score']),
                score=problem['score'],
                tag='TODO',
                keyword='TODO',
                status='AC',
                from_='PAT (Advanced Level) Practice',
            )
    return exams


def assemble_comment(exam: Exam):
    comment: str = '// ---\n'
    for field in exam._fields:
        comment += "// %-11s: %s\n" % (field.strip('_'),
                                       getattr(exam, field))
    comment += '// ---\n'
    comment += '\n'
    return comment


def main():
    exams: Dict[str, Exam] = parse_and_retrieve_exams()
    # TODO
    targets_dir = '/home/straydragon/GitHubRepo/OJ/PTA/PAT_A/Cpp11' 
    # targets_dir = '/home/straydragon/Desktop/test'

    target_paths = [filename
                    for filename in pathlib.Path(targets_dir).glob('*.cc')
                    if 'AC' in str(filename)]

    for target_path in target_paths:
        target_id_ = target_path.name.split('_')[0][1:]
        with open(target_path, 'r+', encoding='utf8') as f:
            olddata = f.read()
            f.seek(0)
            f.write(assemble_comment(exams[target_id_]))
            f.write(olddata)


if __name__ == "__main__":
    main()
