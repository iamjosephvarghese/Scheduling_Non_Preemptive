#include<stdio.h>
void schd();
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
  int b[10],wt[10],ta[10],c[10],n,total_burst=0,i,j,val=0,loc;

  printf("Enter the number of processes:");
  scanf("%d",&n);
  printf("Enter the burst time of the processes\n");

  for(i=0;i<n;i++){
    ta[i] = 0;
    wt[i] = 0;
    printf("Process %d:",i);
    scanf("%d",&b[i]);
    total_burst+=b[i];
    c[i] = b[i];
    }

    printf("burst = %d\n",total_burst);




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
      printf("%d\t%d\t\t%d\t\t%d\n",i,c[i],wt[i],ta[i]);
    }

}

void schd(){

}

void roundrobin(){

}

void pri(){

}

void sjf(){

}
