def nextBigNumber(n):
    num1 = bin(n).count('1')
    while True:
        n = n + 1
        if num1 == bin(n).count('1'):
            break
    return n

#아래 코드는 테스트를 위한 출력 코드입니다.
print(nextBigNumber(78))

#count라는 string 내장함수를 사용하면 문자열 안에 원하는 문자가 몇개 있는지 자동으로 세준다.
#그래서 bin(n).count('1')을 하면 2진수로 변환된 string에서 1의 갯수를 세준다.
#따라서 그냥 1씩 더해가면서 그때그때 마다의 2진수 변환값의 1을 세주면 된다.
