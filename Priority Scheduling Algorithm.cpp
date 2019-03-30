/**
Title:- Priority Scheduling Algorithm
Purpose: CPU Scheduling Algorithm's Solutions
@author Md. Sadikul Islam Shuvo
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int process[100],burs[100],process2[100],burs2[100],wait[100],n,i,j,k,temp,comp[100],pri[100],pri2[100],cnt=0;
    double sum=0.0;
    cout<<"Enter The Process Number: ";
    cin>>n;
    cout<<"Enter The Burst/CPU Time and Priority: \n";
    for(i=0; i<n; i++)
    {
        cin>>burs[i]>>pri[i];
        process[i]=i+1;
    }

    for(i=0; i<n; i++)
    {
        process2[i]=process[i];
        burs2[i]=burs[i];
        pri2[i]=pri[i];
    }

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {

            if(pri[j]<pri[i])
            {
                temp=pri[i];
                pri[i]=pri[j];
                pri[j]=temp;
            }
        }
        for(k=0; k<n; k++)
        {
            if(pri[i]==pri2[k])
            {
                process2[i]=process[k];
                burs2[i]=burs[k];
                break;
            }
        }
    }

    for(i=0; i<n; i++)
    {
        sum=sum+burs2[i];
        comp[i]=sum;
    }
    sum=0;
    wait[0]=0;
    for(i=1; i<n; i++)
    {
        wait[i]=comp[i-1];
    }

    for(i=0; i<n; i++)
    {
        sum=sum+wait[i];
    }
    cout<<endl<<"Waiting Time is: "<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"P"<<process2[i]<<" : "<<wait[i]<<endl;
    }

    cout<<endl<<endl<<"Average Waiting Time is: "<<sum/n<<endl<<endl;

    cout<<"Gantt Chart is:"<<endl<<endl;
    for(i=0; i<n; i++)
    {

        while(1)
        {
            if(cnt==(burs2[i]/2))
            {
                cout<<"P"<<process2[i];
                cnt++;
            }
            else
            {
                cout<<" ";
                cnt++;
            }
            if(cnt==burs2[i]+1)
            {
                cnt=0;
                break;
            }
        }
    }

    cout<<endl<<"0";
    for(i=0; i<n; i++)
    {

        for(j=1; j<=burs2[i]; j++)
        {
            cout<<"=";
        }
        cout<<comp[i];
    }
    cout<<endl;


    return 0;
}

/**
4
8 3
4 2
9 1
5 0
*/

/**
5
10 3
1 1
2 4
1 5
5 2
*/

