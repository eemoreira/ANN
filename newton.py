import numpy as np
import sys

a = 15.44
b = 9.59
def f(x):
    return 12 * x * x - x * (4 * b + 4 * a) + a * b;

def df(x):
    return 4 * (6 * x - b - a)

ans = float(input())
for i in range(20):
    if f(ans) / df(ans) == 0:
        print("merda")
        sys.exit(0)
    ans -= f(ans) / df(ans)
    print(i + 1,"%.15f" % ans,"%.15f" % f(ans))

