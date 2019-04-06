import re

__first_cap_re = re.compile(r'(.)([A-Z][a-z]+)')
__all_cap_re = re.compile(r'([a-z0-9])([A-Z])')


def camel_to_snake(name):
    s1 = __first_cap_re.sub(r'\1_\2', name)
    return __all_cap_re.sub(r'\1_\2', s1).lower()
