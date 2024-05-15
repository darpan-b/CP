'''Quick Sort'''

N = int(input())
A = list(map(int, input().split()))

# set last element as pivot

def partition(A, lo, hi):
    pivot = A[hi]
    hi_ptr = -1
    for i in range(lo, hi):
        if A[i] <= pivot:
            # swap
            if hi_ptr != -1:
                A[i], A[hi_ptr] = A[hi_ptr], A[i]
                hi_ptr += 1
        else:
            if hi_ptr == -1:
                hi_ptr = i
    if hi_ptr == -1:
        return hi
    else:
        A[hi_ptr], A[hi] = A[hi], A[hi_ptr]
        return hi_ptr

def quick_sort(A, lo, hi):
    if lo >= hi:
        return
    fixed_idx = partition(A, lo, hi)
    quick_sort(A, lo, fixed_idx-1)
    quick_sort(A, fixed_idx+1, hi)

quick_sort(A, 0, N-1)

print(A)

