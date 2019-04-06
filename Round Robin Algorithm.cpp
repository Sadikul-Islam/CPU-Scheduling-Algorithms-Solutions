/**
Title:- Round Robin Algorithm
Purpose: CPU Scheduling Algorithm's Solutions
@author Md. Sadikul Islam Shuvo
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,time,remain,temps=0,time_quantum;
    int wt=0,tat=0;
    cout<<"Enter the Process Number: ";
    cin>>n;
    remain=n;
    vector<int>at(n);
    vector<int>bt(n);
    vector<int>rt(n);
    cout<<"Enter the Arrival time and Burst time:"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>at[i];
        cin>>bt[i];
        rt[i]=bt[i];
    }
    cout<<"Enter the time Quantum: ";
    cin>>time_quantum;

    cout<<"\n\nProcess No : Turnaround Time : Waiting Time\n\n";
    for(time=0,i=0; remain!=0;)
    {
        if(rt[i]<=time_quantum && rt[i]>0)
        {
            time += rt[i];
            rt[i]=0;
            temps=1;
        }

        else if(rt[i]>0)
        {
            rt[i] -= time_quantum;
            time += time_quantum;
        }

        if(rt[i]==0 && temps==1)
        {
            remain--;
            printf("Process %d:\t%d\t:\t%d\n",i+1,time-at[i],time-at[i]-bt[i]);
            cout<<endl;
            wt += time-at[i]-bt[i];
            tat += time-at[i];
            temps=0;
        }

        if(i == n-1)
            i=0;
        else if(at[i+1] <= time)
            i++;
        else
            i=0;
    }
    cout<<"Average waiting time "<<wt*1.0/n<<endl;
    cout<<"Average turn around time "<<tat*1.0/n<<endl;;

    return 0;
}
/**
3
0 24
0 3
0 3
*/
