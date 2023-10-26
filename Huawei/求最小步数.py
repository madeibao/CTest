



def Solution(n:int)->int:
    ans = 0;
    if(n%3==0):
        return n//3
    elif n%3==2:
        return n//3+1
    else:
        if n==1:
            return 2
        else:
            return n//3+1

n = int(input())
print(Solution(n))