import pytest
from timer import Timer


def countdown(n):
    while n > 0:
        n -= 1


def test_timer_usage1():
    """Explicit start/stop"""
    t = Timer()
    t.start()
    countdown(1000000)
    t.stop()
    print(t.elapsed)


def test_timer_usage2():
    """As a context manager"""
    t = Timer()
    with t:
        countdown(1000000)
    print(t.elapsed)

    # Or
    with Timer() as _:
        print(_.elapsed)
