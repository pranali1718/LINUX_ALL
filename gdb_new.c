#include<stdio.h>
#include<string.h>
struct student
{
	int roll;
	char name[40],gender;
	float height;
}
first;

int main()
{
	struct student second;
	struct student third={103,"Hariprasad .D",'M',5.11};
	printf("\n Roll\tName\t\t\t\t\tGender\t Height\n");
	first.roll=101;
	strcpy(first.name,"Pheenedra Kumar.P");
	first.gender='M';
	first.height=5.6;

	printf("\n%3d\t%-40s\t%c\t%1.2f",first.name,first.roll,first.gender,first.height);
	printf("\n%3d\t%-40s\t%c\t%1.2f",third.name,third.roll,third.gender,third.height);
}
