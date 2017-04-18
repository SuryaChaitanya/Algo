/* ----------JURASSIC PARK PROBLEM USING THREADS AND SEMAPHORE----------
						    BY 
					  SURYA CHAITANYA
   					     106115049
------------------------------------------------------------------------*/   					

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t carWait, ready, dropped,gotin;

void *riders_of_the_lost_world(void *p);
void *Car(void *p);

main ()
{
	  int NO_OF_PEOPLE, NO_OF_CARS;    
	  printf("Enter the number of customers :: ");
	  scanf("%d",&NO_OF_PEOPLE);

      printf("Enter the number of Cars      :: ");
	  scanf("%d",&NO_OF_CARS);

	  pthread_t cus[NO_OF_PEOPLE], car[NO_OF_CARS];
	  int i, cusid[NO_OF_PEOPLE];
		  
	  //initiallize semaphore
	  
	  sem_init (&carWait, 0, 0);
	  sem_init (&gotin, 0, 0);
	  sem_init (&dropped, 0, 0);
	  
	  //creating threads of customers
	  
	  for (i=0; i<NO_OF_PEOPLE; i++)
	  {
		cusid[i] = i;
		if (pthread_create (&cus[i], NULL,riders_of_the_lost_world, &cusid[i]))
		  		exit (1);
	  }

	  //creating threads of cars
		int p[20];
	  for (i = 0; i < NO_OF_CARS; i++)
	  {
	  		p[i]=i;
		  if (pthread_create (&car[i], NULL, Car, (void *)p[i]))
	   			exit (1);
	  }
	  
	  //release threads
	  
	  for (i=0; i<NO_OF_PEOPLE; i++)
		pthread_join (cus[i], NULL);
 	  
	  printf("\n\t--------------------------------------------\n");
}

`void *riders_of_the_lost_world (void *p)
{
  int i, *cusid;   		
  cusid=(int *)p;
	  
	  
	  sem_wait (&carWait);	//wait till car is in waiting queue
	  
 	  sem_wait (&gotin);	//wait till customer is ready to get into the car
	  	printf("Customer [ %.2d ] \t Started \n",*cusid+1);
	  	
	  sem_wait (&dropped);	//wait till customer finishes the safari ride
	    
	    //customer finishes the safari - print it is done
	    printf("Customer [ %.2d ] \t ----Dropped---- \n",*cusid+1);
	    
}


void *Car (void *p)
{
	int *index=*p;
  while(1)
	{
	
	  sem_post (&carWait);	//signal car wait list - whether car is waiting or not

	  sleep (rand()%3); 
	  
	  sem_post (&gotin);	//signal if customer gets into the car
		printf("Car [ %.2d ] is taking the customer", *index+1);	  
	  sleep (rand()%3);		//the safari takes some time to finish

	  sem_post(&dropped);	//signal that the safari is over
	}
}

