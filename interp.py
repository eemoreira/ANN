import numpy as np

def interpolate(x: list, y: list) -> list:
    A = []
    n = len(x)
    for xi in x:
        row = []
        for deg in range(n):
            if deg == 0:
                row.append(1)
            else:
                row.append(xi ** deg)
        A.append(row)
    B = y
    return np.linalg.solve(A, B)

def build_poly(coeffs):
    def poly(x):
        soma = coeffs[0]
        soma += sum(ck * x**k for k, ck in enumerate(coeffs[1:],1))
        return soma
    return poly

def f(x):
    return np.exp(-x * x) + np.cos(x) + 3

x = []
y = []
n = int(input())
for i in range(n):
    t = float(input())
    x.append(t)
    y.append(f(t))

coefs = interpolate(x, y)
p = build_poly(coefs)
n = int(input())

g = []
for i in range(n):
    t = float(input())
    g.append(abs(p(t) - f(t)))

for i in g:
    print("%.10f" % i, end = ",")

print()


