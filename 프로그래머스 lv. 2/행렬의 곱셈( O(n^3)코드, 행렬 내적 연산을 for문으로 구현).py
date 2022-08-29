def productMatrix(A, B):
    answer = []
    for y1 in range(len(A)):#A행렬의 row가 가장 적게 반복한다.
        a=[]
        for x2 in range(len(B[0])): #B행렬의 col이 두번째로 적게 반복하게 된다.
            n = 0
            for x1 in range(len(A[0])):
                n += A[y1][x1] * B[x1][x2]
            a.append(n)
        answer.append(a)
    return answer
