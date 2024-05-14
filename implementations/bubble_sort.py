'''Bubble Sort'''

N = int(input())
A = list(map(int, input().split()))

for i in range(N):
    for j in range(N-1-i):
        if A[j] > A[j+1]:
            A[j], A[j+1] = A[j+1], A[j]

print(A)
