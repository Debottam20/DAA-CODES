#include<stdio.h>
int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int knapsack(int capacity, int weight[], int point[], int n)
{
    int i,w;
    int knap[n+1][capacity+1];
    for (i = 0; i <= n; i++)
    {
        for(w = 0; w <= capacity; w++)
        {
            if (i==0 || w==0)
            {
                knap[i][w] = 0;
            }
            else if(weight[i-1] <= w)
            {
                knap[i][w] = max((point[i-1]+knap[i-1][w-weight[i-1]]) , knap[i-1][w]);
            }
            else
            {
                knap[i][w] = knap[i-1][w];
            }
        }
    }

    return knap[n][capacity];
}
int main()
{
    int point[100],weight[100],capacity,size,i;
    printf("Enter the max capacity:\n");
    scanf("%d",&capacity);
    printf("Enter the max size:\n");
    scanf("%d",&size);
    printf("Enter the points:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &point[i]);
    }
    printf("Enter the weights:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &weight[i]);
    }
    printf("The solution is : %d", knapsack(capacity, weight, point, size));
    
    return 0;
}