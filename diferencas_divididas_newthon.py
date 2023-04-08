import numpy as np
def dif_div(x, y):
    c = [y[0]]
    for i in range(len(y) - 1):
        for j in range(n - i - 1):
            y[j] = (y[j + 1] - y[j]) / (x[j + i + 1] - x[j])
        c.append(y[0])
    return c

def build_poly(t, x, coef):
    def poly(t):
        n = len(x)
        ans = coef[0]
        for i in range(n - 1):
            p = coef[i + 1]
            for j in range(i + 1):
                p *= (t - x[j]);
            ans += p;
        return ans
    return poly

def f(x):
    return np.cos(x)**3 + 2 * (np.cos(x)**2) + 1

n = int(input())
x = []
y = []
for i in range(n):
    t = float(input())
    x.append(t)
    y.append(f(t))

coef = dif_div(x, y)
for i in coef:
    print("%.15f" % i, end=",")
print()





