/*
 *    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 *
 *
 *
 * */

//Queue using a linear list
#include <stdio.h>
#include <malloc.h>

struct item{
	int val;
	struct item *p;
};

//Manage Queue
void queue_managing(void);
//Add an element to queue
struct item *add(struct item *,int);
//Delete an element from queue
struct item *del(struct item *,int *);
//Check is queue is empty
int is_empty(struct item *);
//Iterate queue and show each element
int show_queue(struct item *);

int main(){
	queue_managing();
}

void queue_managing(){
	struct item *qu_p = NULL;
	int cho = -1,val;
	while(cho != 0){
		printf("\n\n\n");
		printf("\t||QUEUE||\n");
		printf("\t 1) ADD AN ELEMENT \n");
		printf("\t 2) DELETE AN ELEMENT \n");
		printf("\t 3) SHOW QUEUE \n");
		printf("\t 0) QUIT \n");
		printf("\t Choose an option : ");
		scanf("%d",&cho);
		printf("\n\n\n");
		switch(cho){
			//Add an element
			case 1:
				printf("Type a new value : \n");
				scanf("%d",&val);
				qu_p = add(qu_p,val);
				break;
			//Delete an element
			case 2:
				if(is_empty(qu_p))
					printf("Queue is empty \n");
				else{
					qu_p = del(qu_p,&val);
					printf("%d deleted ",val);
				}
				break;
			//Show queue
			case 3:
				if(!is_empty(qu_p))
					show_queue(qu_p);
				else 
					printf("Queue is empty \n");
				break;
		}
	}
}




struct item *add(struct item *it,int val){
	//Allocate space for new item
	struct item *newit;
	newit = (struct item *)(malloc(sizeof(struct item)));
	//If it's first item
	if(it == NULL){
		it = newit;
		it->val = val;
		it->p = it;
	}
	else{
	//Assign new value to struct
	newit->val = val;
	//New element point to  previous pointer
	newit->p=it->p;
	//it point to new element
	it->p=newit;
	//Old object become new object
	it = it->p ;
	}
	//Return a pointer to new object
	return(it);
}

struct item *del(struct item *it,int *val){
	//Save old element in a aux pointer to free() it
	struct item *auxit=it->p;
	//Saving old value in a pointer to show it
	*val = auxit->val;
	//if there are more than one item
	if(it->p != it->p->p){
	//it point to next element
	it->p=it->p->p;
	}
	else{
	//Has been deleted last item
	it = NULL;
	}
	//free() old item
	free(auxit);
	return(it);
}


int is_empty(struct item *it){
	//Return if the queue is empty or no
	if(it == NULL)
		return(1);
	else
		return(0);
}


int show_queue(struct item *it){
	//Index to seek elements
	struct item *ind = it->p;
	//Pointer to complete output
	struct item *end = it;
	printf("\n||QUEUE'S ELEMENTS||\n");
	printf("Queue Head -> ");
	//If there's just one element 
	printf("%d ",ind->val);
	ind = ind->p;
	//
	while(ind != end->p){
		printf("%d ",ind->val);
		ind = ind->p;
	}
	printf(" <- Queue End \n");
}








