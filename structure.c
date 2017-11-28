// Define a structure named 'student' with the following info :
// roll, name. marks in sub1, marks in sub2
// Now WAP in C to perform the following operation using above st.
// 1. Find the details of a particular student
// 2. Calculate the average marks in each sub among all the students.
// 3. Find the roll no, name, highest marks of each subject among all students.

#include <stdio.h>

struct Student{
	int roll;
	char name[20];
	int m1, m2;
};
struct Student stu[20];
int n, i;
void entry(int);
void average();
void highest();
void display(int);

int main(){
	int ch, r;
	printf("\nEnter number of students : ");
	scanf("%d", &n);
	for(i = 0;i < n;i++)
		entry(i); // Calling method entry
	do{
		printf("\n1. Details of student\n2. Average marks\n3. Highest marks\n4. Exit");
		printf("\nEnter your choice : ");
		scanf("%d", &ch);
		switch(ch){
			case 1: // Find the details of a particular student
				printf("\nEnter the roll no : ");
				scanf("%d", &r);
				display(r);
				break;
			case 2: // Displaying average marks 
				average();
				break;
			case 3: // Displaying highest marks in each subject
				highest();
				break;
			case 4:
				break;
			default:
				printf("\nWrong choice!");
				break;
		}
	} while(ch != 4);
	
	return 0;
}

// Definition of 'entry'
void entry(int i){
	printf("\nEnter the details of student %d : ", i+1);
	printf("\nEnter roll : ");
	scanf("%d", &stu[i].roll);
	printf("\nEnter name : ");
	scanf("%s", &stu[i].name);
	printf("\nEnter marks in subject 1 : ");
	scanf("%d", &stu[i].m1);
	printf("\nEnter marks in subject 2 : ");
	scanf("%d", &stu[i].m2);
}

// Definition of 'display'
void display(int r){
	for(i = 0;i <  n;i++){
		if(stu[i].roll == r){
			printf("\nDetails of student");
			printf("\n\tRoll : %d\n\tName : %s", stu[i].roll, stu[i].name);
			printf("\nMarks in ");
			printf("\n\tSubject 1 : %d", stu[i].m1);
			printf("\n\tSubject 2 : %d", stu[i].m2);
			break;
		}
	}
	if(i == n){
		printf("\nRecord does not exist for roll %d!", r);
	}
}

// Definition of method average
void average(){
	int t1 = 0, t2 = 0;
	float avg1, avg2;
	for(i = 0;i<n;){
		t1 += stu[i].m1; // Finding sum of all marks in sub1
		t2 += stu[i++].m2; // Finding sum of all marks in sub2
	}
	avg1 = t1/n; avg2 = t2/n;
	printf("\nAverage marks in sub 1 : %0.2f", avg1);
	printf("\nAverage marks in sub 2 : %0.2f", avg2);
}

//Definition of method highest
void highest(){
	int max1 = 0, max2 = 0, c1, c2;
	for(i = 0;i < n;i++){
		if(stu[i].m1 > max1){
			max1 = stu[i].m1;
			c1 = i;
		}
		if(stu[i].m2 > max2){
			max2 = stu[i].m1;
			c2 = i;
		}
	}
	if(c1 == c2){
		printf("\nDetails of student");
		printf("\n\tRoll : %d\n\tName : %s", stu[c1].roll, stu[c1].name);
		printf("\nScored highest marks in both the subjects!");
	}
	else{	
		printf("\nDetails of students who scored the highest marks");
		printf("\n\tRoll : %d\n\tName : %s", stu[c1].roll, stu[c1].name);
		printf("\nScored the highest marks in subject 1!");
		printf("\n\tRoll : %d\n\tName : %s", stu[c2].roll, stu[c2].name);
		printf("\nScored the highest marks in subject 2!");
	}
}
