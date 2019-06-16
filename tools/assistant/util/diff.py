import pathlib
import pprint
pp = pprint.PrettyPrinter(indent=4)


target_path = '/home/straydragon/GitHubRepo/OJ/PTA/PAT_A/Cpp11'
compare_path = '/home/straydragon/GitHubRepo/OJ/PTA/PAT_A/Python3'

targets = [str(filename)[str(filename).rfind('/')+1:str(filename).find('.')]
           for filename in pathlib.Path(target_path).glob('*.cc')
           if 'AC' in str(filename)]
compares = [str(filename)[str(filename).rfind('/')+1:str(filename).find('.')]
            for filename in pathlib.Path(compare_path).glob('*.py')
            if 'AC' in str(filename)]

# pp.pprint(targets)

# pp.pprint(compares)

target_not_finish_exams = sorted(
    filter(lambda exam: exam not in targets, compares))

pp.pprint(target_not_finish_exams)
