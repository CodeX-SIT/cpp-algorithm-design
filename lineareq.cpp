#include<bits/stdc++.h>
#define   SIZE   10
using namespace std;

int main()
{
	 float a[SIZE][SIZE], x[SIZE], ratio;
	 int i,j,k,n,c=0;

     /* Setting precision and writing floating point values in fixed-point notation. */
     cout<< setprecision(3)<< fixed;

	 /* Inputs */
	 /* 1. Reading number of unknowns */
	 cout<<"Enter number of unknowns: ";
	 cin>>n;

	 /* 2. Reading Augmented Matrix */
	 cout<<"Enter Coefficients of Augmented Matrix: "<< endl;
	 for(i=0;i<n;i++)
	 {
		  for(j=0;j<n+1;j++)
		  {
			   cout<<"a["<< i<<"]"<< j<<"]= ";
			   cin>>a[i][j];
		  }
	 }
    /* Applying Gauss Jordan Elimination */
     for(i=0;i<n;i++)
     {
          if (a[i][i] == 0)
        {
            c=1;
            while(c<n-i)
            {
                if (a[i+c][i] == 0)
                    c++;
                else
                    break;
            }
            if (c==n-i)
            {
                cout<<"NO SOLUTION";
                return 0;
            }
            
            for(int k=0;k<n+1;k++)
            {
                int swap = a[i][k];
                a[i][k] = a[i+c][k];
                a[i+c][k] = swap;
            }
        }
          for(j=0;j<n;j++)
          {
               if(i!=j)
               {
                    ratio = a[j][i]/a[i][i];
                    for(k=0;k<n+1;k++)
                    {
                        a[j][k] = a[j][k] - ratio*a[i][k];
                    }
               }
          }
     }
     /* Obtaining Solution */
     for(i=0;i<n;i++)
     {
        x[i] = a[i][n]/a[i][i];
     }

	 /* Displaying Solution */
	 cout<< endl<<"Solution: "<< endl;
	 for(i=0;i<n;i++)
	 {
	  	cout<<"x["<< i<<"] = "<< x[i]<< endl;
	 }

	 return(0);
}