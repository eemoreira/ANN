import numpy as np
import sys
def f(x):
    return 2664644 - 1021673 * np.exp(x) - (np.exp(x) - 1) * 409818.0 / x
def df(x):
    return 1021673 * np.exp(x) - (np.exp(x) / x**2) * (409818*x - 409818)

ans = float(input())
for i in range(20):
    if f(ans) / df(ans) == 0:
        print("merda")
        sys.exit(0)
    ans -= f(ans) / df(ans)
    print(i + 1,"%.15f" % ans,"%.15f" % f(ans))

