import numpy as np
import sys

def f(x):
    n = 130869380
    t = n / 4
    d = 1.41e-10
    y = 1 + n * np.exp(-d * (n + 1) * x)
    return t - (n + 1) / y


a, b = map(float, input().split(" "))

delta = 3.61034e-7

if f(a) * f(b) >= 0:
    print("bosta")
    sys.exit(0)

w = 0
if f(a) > f(b):
    w = 1

cnt = 0
def bs(l, r):
    mid = (l + r) / 2.0
    global cnt
    cnt += 1
    print("iter:", cnt, "%.15f" % mid, "%.15f" % f(mid))
    if cnt == 20:
        return mid
    if f(mid) < 0:
        if w == 1:
            return bs(l, mid)
        else:
            return bs(mid , r)
    if w == 1:
        return bs(mid, r)
    else:
        return bs(l, mid)

print(bs(a, b))
