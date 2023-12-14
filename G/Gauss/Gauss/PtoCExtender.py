import numpy as np

def Qr():
    n = 3

    A = np.array([
        [2, 1, 2],
        [2, 5, 3],
        [2, 1, 5]
    ], dtype=float)

    Q = A.copy()
    R = np.zeros((n, n), dtype=float)
    tl = int(input())

    
    print("Q\n", Q, "\n")
    print("R\n", R, "\n")
    print("A\n", A, "\n")

    for t in range(tl + 1):
        
        Q = A.copy()
        R = np.zeros((n, n), dtype=float)
        for j in range(n):
            SQsum = np.sum(Q[:, j] ** 2)
            R[j, j] = np.sqrt(SQsum)

            Q[:, j] /= R[j, j]

            for k in range(j + 1, n):
                R[j, k] = np.dot(Q[:, j], Q[:, k])
                Q[:, k] -= Q[:, j] * R[j, k]

        A = np.dot(R, Q)

        print("Q\n", Q, "\n")
        print("R\n", R, "\n")
        print("A\n", A, "\n")

    for i in range(n):
        print(A[i, i])
