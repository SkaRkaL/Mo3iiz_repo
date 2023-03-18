#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Student type
typedef struct
{
	char name[50];
	int ni;
	char group;
} Student;

// Function to input a student
void input_a_Student(Student *s)
{
	printf("Enter student name: ");
	scanf("%s", s->name);
	printf("Enter student NI: ");
	scanf("%d", &s->ni);
	printf("Enter student group (A, B, or C): ");
	scanf(" %c", &s->group);
	// Input control for group field
	while (s->group != 'A' && s->group != 'B' && s->group != 'C')
	{
		printf("\e[033;0;31m\tInvalid group %c!\e[0m\nEnter student group (A, B, or C): ", s->group);
		scanf(" %c", &s->group);
	}
}

// Function to display students in group B
void display_Group_A(Student *students, int numStudents)
{
	puts("\e[1;32m   Enter the name of group A:\e[0m");
	for (int i = 0; i < numStudents; i++)
	{
		if (students[i].group == 'A')
			printf("\t| %s |\n", students[i].name);
	}
}

void display_Group_B(Student *students, int numStudents)
{
	puts("\e[1;32m   Enter the name of group B:\e[0m");
	for (int i = 0; i < numStudents; i++)
	{
		if (students[i].group == 'B')
			printf("\t| %s |\n", students[i].name);
	}
}

void display_Group_C(Student *students, int numStudents)
{
	puts("\e[1;32m   Enter the name of group C:\e[0m");
	for (int i = 0; i < numStudents; i++)
	{
		if (students[i].group == 'C')
			printf("\t| %s |\n", students[i].name);
	}
}

// Function to search for a student by registration number
int search_By_NI(Student *students, int numStudents, int ni)
{
	for (int i = 0; i < numStudents; i++)
	{
		if (students[i].ni == ni)
			return 1;
	}
	return 0;
}

// Function to get the number of students per group
void get_NumStdnts_Per_Group(Student *students, int numStudents, int *A, int *B, int *C)
{
	*A = 0;
	*B = 0;
	*C = 0;
	for (int i = 0; i < numStudents; i++)
	{
		if (students[i].group == 'A')
			(*A)++;
		else if (students[i].group == 'B')
			(*B)++;
		else if (students[i].group == 'C')
			(*C)++;
	}
}

int main()
{
	int numStudents;
	// Welcome
	printf("\n\t\t\e[4;33m Hello Mr X \e[0m\n\n");
	
	printf("Enter the number of students: ");
	scanf("%d", &numStudents);

	// Allocate memory for students array
	Student *students = (Student *)malloc(numStudents * sizeof(Student));

	// Input students
	for (int i = 0; i < numStudents; i++)
	{
		printf("\n\e[0;36mStudent %d:\e[0m\n", i + 1);
		input_a_Student(&students[i]);
	}

	// Students in which group
	char group;
	printf("Enter the name of group: ");
	scanf(" %c", &group);

		// jump it's just if the user enters a wrong Group
	jump:
		printf("\e[1;31m❌ No |%c| Group ❌\e[0m\n", group);
		printf("Enter the name of group: ");
		scanf(" %c", &group);
	if (group == 'A')
		display_Group_A(students, numStudents);
	else if (group == 'B')
		display_Group_B(students, numStudents);
	else if (group == 'C')
		display_Group_C(students, numStudents);
	else
		goto jump;

	// Search for a student by registration number
	int niToSearch;
	printf("\n\e[1;34mEnter student NI for search: \e[0m");
	scanf("%d", &niToSearch);
	if (search_By_NI(students, numStudents, niToSearch))
		printf("	 ✅ Student with NI %d\e[0;32m EXISTS\e[0m in the list.\n", niToSearch);
	else
		printf("❌ Student with NI %d \e[033;0;31mDOES NOT EXIST\e[0m in the list.\n", niToSearch);

	// Get the number of students per group
	int A, B, C;
	get_NumStdnts_Per_Group(students, numStudents, &A, &B, &C);
	printf("\n\e[033;0;35m→ Number of students per group:\e[0m\n");
	printf("> Group A : %d\n", A);
	printf("> Group B : %d\n", B);
	printf("> Group C : %d\n", C);

	// Free memory allocated for students array
	free(students);

	return 0;
}