#include<stdio.h>
void fcfs();
void sjf();
void pri();
void roundrobin();

void main()
{
  int menu,choice=0;
  printf("\tSCHEDULING\n");
  do{
    printf("Menu\n");
    printf("1.First Come First Server\n");
    printf("2.Shortest Job First\n");
    printf("3.Priority\n");
    printf("4.Round Robin\n");
    printf("Enter your choice:");
    scanf("%d",&menu);

    switch(menu){
      case 1: fcfs();
              break;

      case 2: sjf();
              break;

      case 3: pri();
              break;

      case 4: roundrobin();
              break;

      default: printf("Enter a valid choice!");

    }

    printf("Do you want to continue? Press 1 to continue!");
    scanf("%d",&choice);


  }while(choice == 1);
}


void fcfs(){
  int id[10],b[10],wt[10],ta[10],c[10],n,total_burst=0,i,j,val=0,loc;

  printf("Enter the number of processes:");
  scanf("%d",&n);
  printf("Enter the burst time of the processes\n");

  for(i=0;i<n;i++){
    id[i]=i+1;
    ta[i] = 0;
    wt[i] = 0;
    printf("Process %d:",i+1);
    scanf("%d",&b[i]);
    total_burst+=b[i];
    c[i] = b[i];
    }

    printf("Total Bust Time = %d\n",total_burst);




    for(i=0;i<total_burst;i++){
      val = 0;
      while(b[val] == 0){
        val++;
      }
      if(b[val] != 0 && val < n){
        b[val]--;

        for(j=val+1;j<n;j++){
          wt[j]++;
        }
      }
    }


    printf("Process\tBurst Time\tWaiting Time\tTurn Around Time\n");
    float total_turn_around = 0;
    float total_waiting_time = 0;
    for(i=0;i<n;i++){
      total_waiting_time+=wt[i];
      ta[i] = c[i] + wt[i];
      total_turn_around+=ta[i];
      printf("%d\t%d\t\t%d\t\t%d\n",id[i],c[i],wt[i],ta[i]);
    }

    printf("Average turnaround time = %f",total_turn_around/n);
    printf("Average waiting time = %f",total_waiting_time/n);

}



void roundrobin(){
  int i, j, n, b[10] , AT[10], PR[10], WT[10], TA[10];
float wt, ta;

  int tq , RT[10] , remain , t=0 , flag=0;
  	printf("\nEnter the number of processes: ");
          scanf("%d" , &n);
  	remain=n;
          printf("\nEnter the Burst times: \n");
          for(i=1 ; i<=n ; i++)
          {
                  printf("b[%d] = " , i);
                  scanf("%d" , &b[i]);
  		RT[i] = b[i];
          }
  	printf("\nEnter the Arrival times: \n");
          for(i=1 ; i<=n ; i++)
          {
                  printf("b[%d] = " , i);
                  scanf("%d" , &AT[i]);
          }
  	printf("\nEnter the time quantum: ");
  	scanf("%d" , &tq);

  	wt = 0;
  	ta = 0;

  	i=1;
  	while(remain != 0)
  	{
  		if(RT[i] <= tq && RT[i]>0)
  		{
  			t += RT[i];
  			RT[i] = 0;
  			flag = 1;
  		}
  		else if(RT[i] > 0)
  		{
  			RT[i] -= tq;
  			t += tq;
  		}
  		if(RT[i] == 0 && flag==1)
  		{
  			--remain;
  			WT[i] = t - AT[i] - b[i];
  			wt += WT[i];
  			TA[i] = t - AT[i];
  			ta += TA[i];
  			flag = 0;
  		}
  		if(i == n)
  			i=1;
  		else if(AT[i+1] <= t)
  			i++;
  		else
  			i=1;
  	}

  	wt /= n;
          ta /= n;

          printf ("\nThe waiting and turnaround times of all processes are: \n");
          printf("PNO:\tAT\tb\tWT\tTA\n");
          for(i=1 ; i<=n ; i++)
          {
  		printf("P%d\t%d\t%d\t%d\t%d\n" , i , AT[i] , b[i] , WT[i] , TA[i]);
          }
          printf("\nThe avg. waiting time is: %f\n" , wt);
          printf("\nThe avg. turnaround time is: %f\n" , ta);




}

void pri(){

  int n,p[10],b[10],c[10],ta[10],wt[10],id[10],total_burst=0,i,j,temp1,temp2,val;

  printf("Enter the number of processes:");
  scanf("%d",&n);
  printf("Enter the burst time and priority of the processes\n");

  for(i=0;i<n;i++){
    id[i]=i+1;
    ta[i] = 0;
    wt[i] = 0;
    printf("Burst Time Of Process %d:",i+1);
    scanf("%d",&b[i]);
    total_burst+=b[i];
    printf("Priority of Process %d:",i+1);
    scanf("%d",&p[i]);
    c[i] = b[i];
    }

    printf("Total Burst Time = %d\n",total_burst);

    for(i=0;i<n-1;i++){
      for(j=0;j<n-1-i;j++){
        if(p[j] > p[j+1]){
          temp1 = p[j];
          p[j] = p[j+1];
          p[j+1] = temp1;



          temp2 = id[j];
          id[j] = id[j+1];
          id[j+1] = temp2;
        }
      }
    }



    for(i=0;i<total_burst;i++){
      val = 0;
      while(b[val] == 0){
        val++;
      }
      if(b[val] != 0 && val < n){
        b[val]--;

        for(j=val+1;j<n;j++){
          wt[j]++;
        }
      }
    }


    float total_turn_around = 0;
    float total_waiting_time = 0;
    printf("Process\tPriority\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(i=0;i<n;i++){
      total_waiting_time+=wt[i];
      ta[i] = c[i] + wt[i];
      total_turn_around+=ta[i];
      printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",id[i],p[i],c[i],wt[i],ta[i]);
    }
    printf("Average turnaround time = %f",total_turn_around/n);
    printf("Average waiting time = %f",total_waiting_time/n);


}

void sjf(){
  int n,b[10],c[10],ta[10],wt[10],id[10],total_burst=0,i,j,temp1,temp2,val,temp3;

  printf("Enter the number of processes:");
  scanf("%d",&n);
  printf("Enter the burst time of the processes\n");

  for(i=0;i<n;i++){
    id[i]=i+1;
    ta[i] = 0;
    wt[i] = 0;
    printf("Process %d:",i+1);
    scanf("%d",&b[i]);
    total_burst+=b[i];
    c[i] = b[i];
    }

    printf("Total Burst Time = %d\n",total_burst);

    for(i=0;i<n-1;i++){
      for(j=0;j<n-1-i;j++){
        if(c[j] > c[j+1]){
          temp1 = c[j];
          c[j] = c[j+1];
          c[j+1] = temp1;

          temp3 = b[j];
          b[j] = b[j+1];
          b[j+1] = temp3;

          temp2 = id[j];
          id[j] = id[j+1];
          id[j+1] = temp2;
        }
      }
    }



    for(i=0;i<total_burst;i++){
      val = 0;
      while(b[val] == 0){
        val++;
      }
      if(b[val] != 0 && val < n){
        b[val]--;

        for(j=val+1;j<n;j++){
          wt[j]++;
        }
      }
    }


    float total_turn_around = 0;
    float total_waiting_time = 0;
    printf("Process\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(i=0;i<n;i++){
      total_waiting_time+=wt[i];
      ta[i] = c[i] + wt[i];
      total_turn_around+=ta[i];
      printf("%d\t%d\t\t%d\t\t%d\n",id[i],c[i],wt[i],ta[i]);
    }
    printf("Average turnaround time = %f",total_turn_around/n);
    printf("Average waiting time = %f",total_waiting_time/n);


}
