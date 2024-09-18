#include <stdio.h>
#include <string.h>
#define MAX 50
//students data struct
typedef struct {
    char name[30];
    float grades[5];
    float average;
}student;
//global variabls
int count = 0;
student students[MAX];
//input data function to get student data
void input() {
    printf("==>Entrer your name: ");
    fgets(students[count].name,MAX,stdin);
    students[count].name[strcspn(students[count].name, "\n")] = '\0';
    printf("==>Entrer your grades: \n");
    for (int i = 0; i < 5;i++){
        printf("++Enter grade %d: ",i+1);
        scanf("%f",&students[count].grades[i]);
    }
    count++;
}
//Averag func to calculate average grade for the added student
void average(){
    for (int i = 0;i< count;i++){
        float totalgrades = 0;
        for (int j = 0; j < 5;j++){
            totalgrades =totalgrades+ students[i].grades[j] ;
        }
        students[i].average = (totalgrades /5);
        printf("==>The average grades for %s is %.2f.\n",students[i].name,students[i].average);
    }

}
// Find the highest average
void highAverg() {

    char name[30];
    float highAvg = -1;
    // loop to get the student who has the heighest average
    for (int i = 0; i < count; i++) {
        if (students[i].average > highAvg) {
            strcpy(name, students[i].name); 
            highAvg = students[i].average;
        }   
    }
    // check if there is a student
    if (count > 0) {
        printf("==> The student %s has the highest average %.2f.\n", name, highAvg); 
    } else {
        printf("==> There are no students.\n");
    }
}
// display all students infos
void display() {
    for (int i = 0; i < count ; i++) {
        printf("+++++The student %s has grades+++++ \n",students[i].name);
        for (int j = 0; j < 5; j++) {
            printf("==> grade %d = %.2f\n",i+1, students[i].grades[j]);;
        }
        printf("+++ with an average of %.2f\n",students[i].average);   
    }
}
int main() {
   int choice;
   do {
    printf("1.Enter your informations.\n");
    printf("2.Calculate the average grade for a student.\n");
    printf("3.Find highest average grade for a student.\n");
    printf("4.Display all students infos.\n");
    printf("5.Quit.\n");
    scanf("%d",&choice);
    getchar();
    switch (choice) {
        case 1:
        system("@cls||clear");
        input();
        break;
        case 2:
        system("@cls||clear");
        average();
        break;
        case 3:
        system("@cls||clear");
        highAverg();
        break;
        case 4:
        system("@cls||clear");
        display();
        break;
    }
   } while(choice != 5);
}