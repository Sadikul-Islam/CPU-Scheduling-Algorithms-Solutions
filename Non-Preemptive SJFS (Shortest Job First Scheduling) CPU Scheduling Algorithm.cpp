/**
Title:- Non-Preemptive SJFS (Shortest Job First Scheduling) CPU Scheduling Algorithm
Purpose: CPU Scheduling Algorithm's Solutions
@author Md. Sadikul Islam Shuvo
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int process[100],burs[100],process2[100],burs2[100],wait[100],n,i,j,k,sum=0,temp,comp[100],cnt=0;
    cout<<"Enter The Process Number: ";
    cin>>n;
    cout<<"Enter The Burst/CPU Time: ";
    for(i=0; i<n; i++)
    {
        cin>>burs[i];
        process[i]=i+1;
    }

    for(i=0; i<n; i++)
    {
        process2[i]=process[i];
        burs2[i]=burs[i];
    }

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {

            if(burs[j] < burs[i])
            {
                temp = burs[i];
                burs[i] = burs[j];
                burs[j] = temp;
            }
        }
        for(k=0; k<n; k++)
        {
            if(burs[i]==burs2[k])
            {
                process2[i]=process[k];
                break;
            }
        }

    }

    for(i=0; i<n; i++)
    {
        sum=sum+burs[i];
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
            if(cnt==(burs[i]/2))
            {
                cout<<"P"<<process2[i];
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
4
6 8 7 3
*/
