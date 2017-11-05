//program to implement producer consumer problem in c

#include<stdio.h>
#include<stdlib.h>
int i=0,n;
int full=0,empty,mutex=0,item=0;


 int wait(int i)
 {
    ++i;
    return i;
 }

 int signal(int i)
 {
   --i;
   return i;

 }

void producer()
 {

	mutex=signal(mutex);
	if(item>=n)
          {
	    printf("\n buffer is full");
           return;
          }
	else
	 {

	full=signal(full);
        empty=wait(empty);
        item++;
        printf("\nproducer produces item %d\n",item);
	mutex=wait(mutex);
	 }
 }

void consumer()
 {
	mutex=signal(mutex);
	if(item<=0)
	 {
		printf("\n buffer is empty");
                return;
	 }
	else
	{
		
		full=wait(full);
		empty=signal(empty);
		printf("\n consumer consumes item %d\n",item);
		item--;
		mutex=wait(mutex);
	}
 }

void main()
{
	int ch,c;
		
	printf("\n enter the size of buffer\n");
        scanf("%d",&n);
	empty=n;

        do
	{
		printf("\n\t\t*PRODUCER CONSUMER PROBLEM*\n\t\t*************************\n1.producer\n2.consumer\n3.exit\nenter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:producer();
			break;
			case 2:consumer();
			break;
			case 3:exit(0);
			break;
			default: printf("\ninvalid character");
		}
//	printf("\n do you want to continue(1/0)? ");
  //      scanf("%d",&c);
	}while(ch!=3);
}	
	
