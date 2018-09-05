def main():
    while True:
        try:
            m = eval(input())
            s = input()

            result = best_add(m, s)
            print(result)
        except:
            break

def best_add(m,s):
    dp=[]
    dp.append([])
    dp[0].append("0000")
    for i in range(1,s.__len__()+1):
        dp.append([])
        for j in range(0,m+1):
            if j==0:
                dp[i].append(s[0:i])
                continue
            if i==j:
                break
            min_dp(dp,s,i,j)
    return dp[i][j]

def min_dp(dp,s,n,m):
    temp=[0]
    min=-1
    for i in range(1,n-m+1):
        temp.append(int(dp[n-i][m-1])+int(s[n-i:n]))
    for i in range(1,n-m+1):
        if min==-1:
            min=temp[i]
        else:
            if min>temp[i]:
                min=temp[i]
    dp[n].append(str(min))

main()


