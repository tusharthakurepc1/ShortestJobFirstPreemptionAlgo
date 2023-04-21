#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<limits.h>



int main(){
    int n=5;

    char p_name[][20]={"p1","p2","p3","p4","p5"};
    int arr_time[]={2,1,4,0,2};
    int burst_time[]={1,5,1,6,3};
    int burst_time_cp[n];
    int complete_time[n];

    
    
// Sort all the Array Accourding to the Arrival Time.
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < n; ++j){ 
            if (arr_time[i] > arr_time[j]) {
                int a =0;
                a=arr_time[i];    arr_time[i] = arr_time[j];      arr_time[j] = a;
                a=burst_time[i];  burst_time[i]=burst_time[j];    burst_time[j]=a;
                char ch[20]="";
                strncpy(ch,p_name[i],20);   strncpy(p_name[i],p_name[j],20);    strncpy(p_name[j],ch,20);
            }
        }
    }

    for(int i=0;i<n;i++){
        complete_time[i]=-1;
        burst_time_cp[i]=burst_time[i];
    }

// Calculate the Total Time for all the Process.
    int max_time=0;
    for(int i=0;i<n;i++){
        max_time+=burst_time[i];
    }
    printf("%d\n",max_time);

    int ready_q[n];
    
    for(int i=0;i<n;i++){
        ready_q[i]=0;
    }


        
// Run for Max len.
    for(int sp=0;sp<max_time;sp++){

        int temp_arrival_time[n];
        int temp_burst_time[n];
//      Initilize the array.
        for(int i=0;i<n;i++){
            temp_arrival_time[i]=-1;
            temp_burst_time[i]=-1;
        }

//      Assign process to the queue when the time interval come according to the AT
        int t_incr=0;
        for(int i=0;i<n;i++){
            if(arr_time[i] <= sp){
                temp_arrival_time[i] = arr_time[i];
                temp_burst_time[i] = burst_time[i];
                t_incr++;
            }
        }

//      Calculate the Minimum Burst Time .
        int min_burst_time=INT_MAX;
        int process_pos=-1;

        for(int i=0;i<n;i++){
            if(temp_burst_time[i] < min_burst_time && temp_burst_time[i] !=-1  && temp_burst_time[i] != 0){
                min_burst_time=temp_burst_time[i];
                process_pos=i;
            }
        }
        

        // Decrement the burst time with one
        temp_burst_time[process_pos]=temp_burst_time[process_pos]-1;
        // Store the Temperory bursttime into the main burst time
        burst_time[process_pos]=temp_burst_time[process_pos];


        // Calculate the Complete Time
        if(burst_time[process_pos] == 0){
            complete_time[process_pos]=sp+1;
        }

        
        // printf("%d --->\t",sp);
        // for(int iterator=0 ;iterator<n;iterator++){
        //     printf("%d   ",burst_time[iterator]);
        // }

        // printf("\n");
    }


    // printf("\n");
    int turn_around_time[n];
    int wating_time[n];

    for(int i=0;i<n;i++){
        turn_around_time[i]=-1;
        wating_time[i]=-1;
    }


    for(int i=0;i<n;i++){
        turn_around_time[i]= complete_time[i] -arr_time[i];
        wating_time[i]=turn_around_time[i]-burst_time_cp[i];
    }

    printf("PID \tAT\tBT\tCT \tTAT\tWT\t\n");
    for(int iterator=0 ;iterator<n;iterator++){
        printf("%s \t%d\t%d\t%d \t%d\t%d \n",p_name[iterator],arr_time[iterator],burst_time_cp[iterator],complete_time[iterator],turn_around_time[iterator],wating_time[iterator]);
    }

    float sum_tat=0,sum_wt=0;

    for(int i=0;i<n;i++){
        sum_tat=sum_tat+turn_around_time[i];
        sum_wt=sum_wt+wating_time[i];
    }
    sum_tat=sum_tat/n;
    sum_wt=sum_wt/n;

    printf("Average Turn Around Time: %f\n",sum_tat);
    printf("Average Wating Time: %f",sum_wt);

    return 0;
}