def convert(lines):
    res = ""
    lines = lines.split('\n')
    for line in lines[:-1]:
        res += f'"$LINE_COMMENT {line}",\n'
    res += f'"$LINE_COMMENT {lines[-1]}\n"'
    return res


s = """"""
print(convert(s))
