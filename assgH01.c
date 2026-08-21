#include<stdio.h>
#include <math.h>
#include<time.h>

long long int H(int n);
long long int L(int n);

void both(int n, long long int *h, long long int *l);

void multiply(long long int A[2][2], long long intB[2][2],long long int C[2][2]);
void matrixPower(long long int A[2][2],int n, long long int result[2][2]);

//1
 long long int H(int n)
 {
    if(n==0)
      return 1;
    
    return 2 * H(n-1)+L(n-1);
 }

 //2
 long long int L(int n)
 {
    if(n==0)
      return 0;

    return H(n-1)+L(n-1);
 }
 //3
 void both(int n,long long int *h,long long int *l)
 {
    long long int h_prev,l_prev;
    if(n==0)
    {
        *h = 1;
        *l = 0;
        return;
    }
    both(n-1,&h_prev,&l_prev);

        *h = 2* h_prev + l_prev;
        *l = h_prev + l_prev;
 }
 //mat. mul
  void mul(long long int A[2][3],long long int B[2][2], long long int C[2][2])
  {
    C[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
    C[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
    C[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
    C[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1];

  }

  //5
   void mat_pow(long long int A[2][2],int n,long long int result[2][2])
   {
    long long int temp[2][2];

    if(n==0)
    {
        result[0][0]=1;
        result[0][1]=0;
        result[1][0]=0;
        result[1][1]=1;
    
        return;
    }
    
    mat_pow(A,n/2,temp);
    mul(temp,temp,result);

    if(n%2 !=0)
    {
        mul(result,A,temp);

        result[0][0]=temp[0][0];
        result[0][1]=temp[0][1];
        result[1][0]=temp[1][0];
        result[1][1]=temp[1][1];
    }
   }

   int main()
   {
    int n;
    long long int h,l;
    long long int h3,l3;
    long long int h4,l4;
    long long int h5,l5;

    clock_t start,end;
    double time_taken;

    printf("enter n:");
    scanf("%d",&n);
 //1.
  start = clock();

    h = H(n);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nQ 1");
    printf("\nH(%d) = %lld", n, h);
    printf("\nTime = %.9f seconds\n", time_taken);

    //2.
    start = clock();

    h = L(n);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nQ 2");
    printf("\nL(%d) = %lld", n, l);
    printf("\nTime = %.9f seconds\n", time_taken);

   //3.
start = clock();

    both(n,&h3,&l3);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nQ 3");
    printf("\nH(%d) = %lld", n, h3);
    printf("\nL(%d) = %lld", n, l3);
    printf("\nTime = %.9f seconds\n", time_taken);
 
    //4.
    start = clock();
    {
        long double s;
        long double a,b;
        long double H_val,L_val;
        
        s = sqrrt(5.0L);
        a = (3.0L - s) / 2.0L;
        b = (3.0L + s) / 2.0L;

        H_value =
            ((5.0L + s) / 10.0L) * powl(a, n + 1)
          + ((5.0L - s) / 10.0L) * powl(b, n + 1);

        L_value =
            (-(5.0L + 3.0L * s) / 10.0L) * powl(a, n + 1)
          + ((-5.0L + 3.0L * s) / 10.0L) * powl(b, n + 1);

        h4 = (long long int)llroundl(H_value);
        l4 = (long long int)llroundl(L_value);
    }

    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nQ 4");
    printf("\nH(%d) = %lld", n, h4);
    printf("\nL(%d) = %lld", n, l4);
    printf("\nTime = %.9f seconds\n", time_taken);

    {
        long long int A[2][2] =
        {
            {2, 1},
            {1, 1}
        };

        long long int result[2][2];

        start = clock();

        matrixPower(A, n, result);

        end = clock();

        h5 = result[0][0];
        l5 = result[1][0];

        time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("\nQ 5");
        printf("\nH(%d) = %lld", n, h5);
        printf("\nL(%d) = %lld", n, l5);
        printf("\nTime = %.9f seconds\n", time_taken);
    }

    return 0;

    }

   