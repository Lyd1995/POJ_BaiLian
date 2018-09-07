def findMax(matrix):
    max1=max(matrix[0])
    x,y=0,0
    for i in range(0,len(matrix)-1):
        temp=max(matrix[i])
        if temp > max1:
            max1,x=temp,i
    for j in range(0,len(matrix[x])-1):
        if max1==matrix[x][j]:
            y=j
            break
    matrix[x][y]=0
    return x,y,max1

def computerTime(x1,y1,x2,y2,t):
    t1=abs(x1-x2)+abs(y1-y2)      # 前往下一个点采摘所用的时间
    t2=x2+1                       # 返回时间
    t3=1                          # 采摘时间
    if t>=(t1+t2+t3):
        return (t-t1-t3)         # 返回剩余时间
    else:
        return (t-t1-t2-t3)

T=eval(input())
for f in range(T):
    num = input()
    list1 = num.split()
    M = int(list1[0])
    N = int(list1[1])
    K = int(list1[2])
    matrix = []
    for i in range(M):
        st = input()
        item = st.split()
        list2 = [eval(x) for x in item]
        matrix.append(list2)
    s = 0
    x0, y0 = -1, -1
    x1, y1, temp = findMax(matrix)
    K = computerTime(x0, y1, x1, y1, K)
    if K < 0:
        print(s)
    else:
        x0, y0 = x1, y1
        s = s + temp
        while K >= 0:
            x1, y1, temp = findMax(matrix)
            K = computerTime(x0, y0, x1, y1, K)
            x0, y0 = x1, y1
            if K < 0:
                print(s)
                break
            else:
                s = s + temp
