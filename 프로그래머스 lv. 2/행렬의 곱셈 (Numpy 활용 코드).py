import numpy as np 
def solution(arr1, arr2): 
    return (np.matrix(arr1)*np.matrix(arr2)).tolist()
#matrix함수로 파라미터로 받은 arr1과 arr2를 배열에서 행렬로 만든다.
#*연산을 통해 자연스레 행렬 내적을 하고 tolist함수를 이용하여 행렬을 다시 배열로 바꾼다.
