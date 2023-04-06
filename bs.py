import numpy as np
import sys
def f(x):
    return np.log(x * x + 2) * np.exp(np.pi - x) - 3;


a, b = map(float, input().split(" "))

delta = 3.61034e-7
w = 0

if f(a) * f(b) >= 0:
    print("bosta")
    sys.exit(0)
if f(a) > f(b):
    w = 1

cnt = 0
def bs(l, r):
    mid = (l + r) / 2.0
    global cnt
    cnt += 1
    print("%.15f" % mid, "%.15f" % f(mid), cnt);
    if abs(f(mid)) < delta:
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