import numpy as np

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
            if j % 100 == 0: yield arr

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
        if i % 10 == 0: yield arr

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
        if i % 20 == 0: yield arr

def quick_sort(arr, low, high):
    if low < high:
        pivot_idx = yield from _partition(arr, low, high)
        yield from quick_sort(arr, low, pivot_idx)
        yield from quick_sort(arr, pivot_idx + 1, high)

def _partition(arr, low, high):
    pivot = arr[low]
    i, j = low - 1, high + 1
    while True:
        i += 1
        while arr[i] < pivot: i += 1
        j -= 1
        while arr[j] > pivot: j -= 1
        if i >= j: return j
        arr[i], arr[j] = arr[j], arr[i]
        yield arr

def merge_sort(arr, start, end):
    if end - start > 1:
        mid = (start + end) // 2
        yield from merge_sort(arr, start, mid)
        yield from merge_sort(arr, mid, end)
        
        # Merge logic
        left = arr[start:mid].copy()
        right = arr[mid:end].copy()
        i = j = 0
        for k in range(start, end):
            if i < len(left) and (j >= len(right) or left[i] <= right[j]):
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
            yield arr

def shell_sort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
            yield arr
        gap //= 2

def cocktail_shaker_sort(arr):
    n = len(arr)
    swapped = True
    start, end = 0, n - 1
    while swapped:
        swapped = False
        for i in range(start, end):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                swapped = True
        if not swapped: break
        end -= 1
        for i in range(end - 1, start - 1, -1):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                swapped = True
        start += 1
        yield arr

def heap_sort(arr):
    n = len(arr)

    def heapify(n, i):
        largest = i
        l = 2 * i + 1
        r = 2 * i + 2

        if l < n and arr[i] < arr[l]:
            largest = l
        if r < n and arr[largest] < arr[r]:
            largest = r

        if largest != i:
            arr[i], arr[largest] = arr[largest], arr[i]
            yield arr
            yield from heapify(n, largest)

    for i in range(n // 2 - 1, -1, -1):
        yield from heapify(n, i)

    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        yield arr
        yield from heapify(i, 0)