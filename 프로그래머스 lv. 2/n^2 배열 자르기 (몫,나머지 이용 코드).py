접근법
1 2 3
2 2 3
3 3 3 
1차원 배열-->  1 2 3 2 2 3 3 3 3 --> 값
배열의 번호--> 0 1 2 3 4 5 6 7 8 --> index
n = 3

index / n
(몫, 나머지) --> 값
(0,0) --> 1
(0,1) --> 2
(0,2) --> 3

(1,0) -->2
(1,1) -->2

(2,1) -->3
몫과 나머지 중 더 큰 값에 해당하는 것을 reference index로 넣어서 그 값을
answer의 left~right에 대해 각각 집어넣는다.

========내 코드===========
def solution(n, left, right):    
    answer = []
    
    reference = [0]*n #참고할 배열
    for i in range(0, n):
        reference[i] = i+1
        
    for j in range(int(left), int(right)+1):
        share = j // n #2차원 상에서의 행 좌표에 해당
        remain = j % n #2차원 상에서의 열 좌표에 해당
        
        if(share > remain):
            answer.append(reference[share])
        else:
            answer.append(reference[remain])
    
    return answer
