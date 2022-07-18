def solution(n, arr1, arr2):
    answer = []

    for i in range(0, len(arr1)):
        arr1[i] = format(arr1[i], 'b')


    for a in range(0, len(arr1)):
        if(len(arr1[a]) == n):
            continue
        else:
            arr1[a] = arr1[a].zfill(n)
