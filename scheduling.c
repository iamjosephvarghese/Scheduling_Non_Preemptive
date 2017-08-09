#include<stdio.h>
// void schd();
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
    for(i=0;i<n;i++){
      ta[i] = c[i] + wt[i];
      printf("%d\t%d\t\t%d\t\t%d\n",id[i],c[i],wt[i],ta[i]);
    }

}

// void schd(int id[],int b[],int c[],int wt[],int ta[],int tBurst,int n){
//
//   int i,j,val;
//
//
//   for(i=0;i<tBurst;i++){
//     val = 0;
//     while(b[val] == 0){
//       val++;
//     }
//     if(b[val] != 0 && val < n){
//       b[val]--;
//
//       for(j=val+1;j<n;j++){
//         wt[j]++;
//       }
//     }
//   }
//
//
//   printf("Process\tBurst Time\tWaiting Time\tTurn Around Time\n");
//   for(i=0;i<n;i++){
//     ta[i] = c[i] + wt[i];
//     printf("%d\t%d\t\t%d\t\t%d\n",id[i],c[i],wt[i],ta[i]);
//   }
//
// }

void roundrobin(){

  int id[10],b[10],wt[10],ta[10],c[10],n,total_burst=0,i,j,val=0,loc,tq;

  printf("Enter the number of processes:");
  scanf("%d",&n);
  printf("Enter the time quantum:");
  scanf("%d",&tq);
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
        }
      }
    }


    for(i=0;i<total_burst;i++){
      for(j=0;j<tq;j++){

      }
    }







    printf("Process\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(i=0;i<n;i++){
      ta[i] = c[i] + wt[i];
      printf("%d\t%d\t\t%d\t\t%d\n",id[i],c[i],wt[i],ta[i]);
    }

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

          // temp3 = b[j];
          // b[j] = b[j+1];
          // b[j+1] = temp3;

          temp2 = id[j];
          id[j] = id[j+1];
          id[j+1] = temp2;
        }
      }
    }

    //schd(id,b,c,wt,ta,total_burst,n);


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


    printf("Process\tPriority\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(i=0;i<n;i++){
      ta[i] = c[i] + wt[i];
      printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",id[i],p[i],c[i],wt[i],ta[i]);
    }


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

    //schd(id,b,c,wt,ta,total_burst,n);


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
    for(i=0;i<n;i++){
      ta[i] = c[i] + wt[i];
      printf("%d\t%d\t\t%d\t\t%d\n",id[i],c[i],wt[i],ta[i]);
    }

}
