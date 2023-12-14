from math import *
import numpy as np
import matplotlib.pyplot as plt

def f2(x):
    return 9*x + pow(2, x) - 7


def half_divide():
    n = 0
    a = 0
    b = 1
    c = (a + b) / 2
    eps = 0.0001

    while (b - a) >= 2 * eps:
        if f2(a) * f2(c) < 0:
            b = c
        else:
            if f2(b) * f2(c) < 0:
                a = c
            else:
                if f2(c) == 0:
                    break
        c = (a + b) / 2
        n += 1
        print(n, a, b, c)



def f(x):
    return -5*(x**3) + x**2 - x + 3

def df(x):
    return -15*(x)**2 + 2*x - 1

def ddf(x):
    return 2 * (1-15*x)

def combin_method():
    
    n : int = 0
    a = -1
    b = 1
    data = []
    eps = 0.001 # tolerance
    

    while abs(b - a) > eps:
        if f(a) * ddf(a) > 0:
            d = a - f(a) / df(a)
            c = (a * f(b) - b * f(a)) / (f(b) - f(a))
            a = d
            b = c
        elif f(b) * ddf(b) > 0:
            d = b - f(b) / df(b)
            c = (a * f(b) - b * f(a)) / (f(b) - f(a))
            b = d
            a = c
        else:
            print("calculation impossible...")
            return

        n += 1
        data.append([n, a, b, (a + b) / 2])


    result_data = np.array(data)


    print("Iteration |   a   |    b   |  (a+b)/2")
    for row in result_data:
        print(f"{row[0]} | {row[1]:.4} | {row[2]:.4} | {row[3]:.4}")

    x_vals = np.linspace(-1, 1, 100)
    plt.plot(x_vals, f(x_vals), label="f(x)")
    plt.axhline(0, color="black", linewidth=0.5, linestyle="--")
    plt.title("Function graph f(x)")
    plt.xlabel("x")
    plt.ylabel("f(x)")
    plt.legend()
    plt.show()
    

