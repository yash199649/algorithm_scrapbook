def ways(costs):
    n = len(costs) #no. of houses
    k = len(costs[0])  #no. of colors
    if(n<1):
        return -1
    elif n==1:
        return min(costs[0])
    C = [[float["inf"] for j in range(k)]for i in range(n)]
    C[0] = costs[0]
    for i in range(1,n):
        for j in range(0,k):
            for m in range(0,k):
                if m !=j:
                    C[i][j] = min(C[i-1][k]+costs[i][j],C[i][j])
    return min(C[n-1])

print ways([[13,2,10],[10,13,5],[13,4,9]])