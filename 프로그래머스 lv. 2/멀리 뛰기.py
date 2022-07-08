def solution(n):
    answer = 0
    
    Way = [1,2] 
    #거리가 1일 때는 (1) 1가지
    #거리가 2일 때는 (1,1) (2) 2가지
    #거리가 3일 때는 (1,1,1) (1,2) (2,1) 3가지
    #거리가 4일 때는 (1,1,1,1) (1,1,2) (2,2) 5가지
    #.... 쭉 이어져서 결국 a[n] = a[n-1]+a[n-2] 형태가 된다.
    
    if(n == 1):
        answer = 1
        return answer
    elif(n == 2):
        answer = 2
        return answer
    else:
        for i in range(2, n):
            Way.append(Way[i-1]+Way[i-2])
        last = len(Way)-1
        answer = Way[last]
        
    answer = answer % 1234567
    
    return answer
