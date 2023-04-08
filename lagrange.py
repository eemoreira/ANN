import numpy as np

def lagrange(x: list, y: list) -> list:
    # a lista coeffs contém y_i / denom_i
    # onde denom_i é o denominador de L_i
    n = len(x)
    coeffs = []
    for i in range(n):
        denom_i = np.prod([x[i] - x[j] for j in range(n) if j != i])
        coeffs.append(y[i] / denom_i)
    return coeffs

def build_poly(x, coeffs):
    n = len(x)
    def poly(t):
        comb = 0
        for i in range(n):
            numer = 1
            for j in range(n):
                if j != i:
                    numer *= (t - x[j])
            numer *= coeffs[i]
            comb += numer
        return comb
    return poly

def f(x):
    return np.cos(np.sin(np.log(x * x)))

x = []
y = []
n = int(input())
for i in range(n):
    t = float(input())
    x.append(t)
    y.append(f(t))
coefs = lagrange(x, y)
p = build_poly(x, coefs)
for i in coefs:
    print("%.10f" % i, end=",")
print()



