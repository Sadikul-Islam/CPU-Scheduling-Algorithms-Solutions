/**
Title:- FCFS (First-Come First-Served) CPU Scheduling Algorithm
Purpose: CPU Scheduling Algorithm's Solutions
@author Md. Sadikul Islam Shuvo
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arri[100],burs[100],i,j,n,wait[100],comp[100],turn[100],sum=0,sum1=0,sum2=0,cnt=0;
    cout<<"Enter The Process Number: ";
    cin>>n;

    cout<<"Enter The Arrival Time and Burst/CPU Time:\n";
    for(i=0; i<n; i++)
    {
        cin>>arri[i]>>burs[i];
    }

    for(i=0; i<n; i++)
    {
        sum=sum+burs[i];
        comp[i]=sum;
    }

    wait[0]=0-arri[0];
    for(i=1; i<n; i++)
    {
        wait[i]=comp[i-1]-arri[i];
    }

    for(i=0; i<n; i++)
    {
        turn[i]=wait[i]+burs[i];
    }

    cout<<endl<<"Process    "<<"Arrival Time    "<<"Burst Time    "<<"Waiting Time    "<<"Completion Time    "<<"Turnaround Time"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"  "<<"P"<<i+1<<"            "<<arri[i]<<"              "<<burs[i]<<"             "<<wait[i]<<"                "<<comp[i]<<"                 "<<turn[i]<<endl;
    }

    sum=0;
    cout<<endl<<endl<<"A.W.T"<<"   "<<"A.C.T"<<"   "<<"A.T.T"<<endl;

    for(i=0; i<n; i++)
    {
        sum=sum+wait[i];
        sum1=sum1+comp[i];
        sum2=sum2+turn[i];
    }
    cout<<"  "<<sum/n<<"     "<<sum1/n<<"      "<<sum2/n<<endl<<endl;

    cout<<"Gantt Chart is:"<<endl<<endl;
    for(i=0; i<n; i++)
    {
        while(1)
        {
            if(cnt==(burs[i]/2))
            {
                cout<<"P"<<i+1;
                cnt++;
            }
            else
            {
                cout<<" ";
                cnt++;
            }
            if(cnt==burs[i]+1)
            {
                cnt=0;
                break;
            }
        }
    }

    cout<<endl<<"0";
    for(i=0; i<n; i++)
    {

        for(j=1; j<=burs[i]; j++)
        {
            cout<<"=";
        }
        cout<<comp[i];
    }
    cout<<endl;


    return 0;
}

/**
Sample Inputs are:
3
0 18
1 3
2 3
*/

