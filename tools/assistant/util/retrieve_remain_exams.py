import json

with open(input("input problems state (.json) path:"), 'r', encoding='utf8') as f:
    problem_status = json.load(f)["problemStatus"]

unsolved = [p['label']
            for p in problem_status if p['problemSubmissionStatus'] != 'PROBLEM_ACCEPTED']
print(unsolved)
