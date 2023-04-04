#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

union person_data
{
	char name[256];
	int age;
};


int main(int argc, char **argv){
	int num_people = argc / 2;
	union person_data people[num_people];
	
	for (int i = 0; i < num_people; i++) {
			int name_index = i * 2 + 1;
			int age_index = name_index + 1;
			
			strncpy(people[i].name, argv[name_index], sizeof(people[i].name));
			people[i].age = atoi(argv[age_index]);
	}
	
	for (int i = 0; i < num_people; i++) {
			printf("person %d: %s %d\n", i+1, people[i].name, people[i].age);
	}
	return 0;	
}
