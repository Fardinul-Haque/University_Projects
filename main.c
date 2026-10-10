
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 50

typedef struct {
    char name[40];
    char ID[20];
    char session[10];
    char semester[20];
    char department[20];
} Person;

void StudentStructure();
void SecondMain();
void Attendance();
void NextSemester();
void Course();
void Eng();
void Math();
void Cse();
void CountCgpa();
void Mark(float sum);
void Exit();
void FirstMain();
void StudentSubMenu(Person arr[], int n);
void AddStudentRecord(Person arr[], int *n);
void DeleteStudentRecord(Person arr[], int *n);
void UpdateStudentRecord(Person arr[], int n);
void DisplayAllRecords(Person arr[], int n);
void DisplaySpecificRecord(Person arr[], int n);

int main() {
    char A;
    printf("Press Y to Run The Program / Press anything else to Close The Program: \n");
    scanf(" %c", &A);
    if (A == 'Y' || A == 'y') {
        printf("Please Provide User Name and Password To Log In:\n");
        FirstMain();
    } else {
        printf("Program is finished. Thank you.\n");
    }
    return 0;
}

void FirstMain() {
    char s1[20], s2[20];
    printf("User Name: ");
    scanf(" %[^\n]", s1);
    printf("Password: ");
    scanf(" %[^\n]", s2);

    int d1=strcmp(s1,"777");
    int d2=strcmp(s2,"777");

    if(d1==0&&d2==0){
    printf("\n****************** Welcome to Our Project ******************\n");
    SecondMain();}
    else{
        printf("Wrong\n");
        FirstMain();
    }
}

void SecondMain() {
    int N;

    printf("\n1. Student Structure\n");
    printf("2. Add Marks to Courses\n");
    printf("3. Student Attendance\n");
    printf("4. Next Semester\n");
    printf("5. Count CGPA\n");
    printf("6. Exit\n");
    printf("Enter the number to continue: ");
    scanf("%d", &N);

    switch (N) {
        case 1:
            StudentStructure();
            break;
        case 2:
            Course();
            break;
        case 3:
            Attendance();
            break;
        case 4:
            NextSemester();
            break;
        case 5:
            CountCgpa();
            break;
        case 6:
            Exit();
            break;
        default:
            printf("Error: Invalid choice\n");
            SecondMain();
            break;
    }
}



void StudentStructure() {
    int n;
    printf("\nEnter the Number of Students: ");
    scanf("%d", &n);
    Person arr[n];
    memset(arr, 0, sizeof(arr));
    // Display a submenu for student records
    StudentSubMenu(arr, n);
}

void StudentSubMenu(Person arr[], int n) {
    int choice;
    printf("\nStudent Record Menu:\n");
    printf("1. Add A Student Record\n");
    printf("2. Delete Student Record\n");
    printf("3. Update Student Record\n");
    printf("4. Display All Records\n");
    printf("5. Display Specific Record\n");
    printf("6. Return to Second Main Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            AddStudentRecord(arr, &n);
            break;
        case 2:
            DeleteStudentRecord(arr, &n);
            break;
        case 3:
            UpdateStudentRecord(arr, n);
            break;
        case 4:
            DisplayAllRecords(arr, n);
            break;
        case 5:
            DisplaySpecificRecord(arr, n);
            break;
        case 6:
            SecondMain();
            break;
        default:
            printf("Error: Invalid choice\n");
            StudentSubMenu(arr, n); // Display the submenu again
            break;
    }
}

void AddStudentRecord(Person arr[], int *n) {
    if (*n < MAX_STUDENTS) {
        printf("\nEnter Details for the New Student:\n");
        printf("Enter Name: ");
        scanf(" %[^\n]s", arr[*n].name);
        printf("Enter ID: ");
        scanf(" %[^\n]s", arr[*n].ID);
        printf("Enter Department: ");
        scanf(" %[^\n]s", arr[*n].department);
        printf("Enter Session: ");
        scanf(" %[^\n]s", arr[*n].session);
        printf("Enter Semester: ");
        scanf(" %[^\n]s", arr[*n].semester);

        (*n)++; // Increment the number of students in the array
        printf("Student Record Added Successfully!\n");
    } else {
        printf("Maximum number of students reached. Cannot add more records.\n");
    }
    StudentSubMenu(arr, *n); // Display the submenu again
}


void DeleteStudentRecord(Person arr[], int *n) {
    char rollNumberToDelete[20];
    printf("\nEnter the ID of the Student to Delete: ");
    scanf(" %[^\n]s", rollNumberToDelete);

    int found = 0;
    for (int i = 0; i < *n; i++) {
        if (strcmp(arr[i].ID, rollNumberToDelete) == 0) {
            found = 1;
            // Shift elements to the left to overwrite the deleted record
            for (int j = i; j < *n - 1; j++) {
                strcpy(arr[j].name, arr[j + 1].name);
                strcpy(arr[j].ID, arr[j + 1].ID);
                strcpy(arr[j].session, arr[j + 1].session);
                strcpy(arr[j].semester, arr[j + 1].semester);
                strcpy(arr[j].department, arr[j + 1].department);
            }
            (*n)--; // Decrement the count of students
            break;
        }
    }

    if (found) {
        printf("Student Record with ID %s Deleted Successfully!\n", rollNumberToDelete);
    } else {
        printf("Student Record with ID %s Not Found!\n", rollNumberToDelete);
    }

    StudentSubMenu(arr, *n); // Display the submenu again
}


void UpdateStudentRecord(Person arr[], int n) {
    char rollNumberToUpdate[20];
    printf("\nEnter the ID of the Student to Update: ");
    scanf(" %[^\n]s", rollNumberToUpdate);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].ID, rollNumberToUpdate) == 0) {
            found = 1;
            printf("\nEnter Updated Details for the Student with ID %s:\n", rollNumberToUpdate);
            printf("Updated Name: ");
            scanf(" %[^\n]s", arr[i].name);
            printf("Updated Department: ");
            scanf(" %[^\n]s", arr[i].department);
            printf("Updated Session: ");
            scanf(" %[^\n]s", arr[i].session);
            printf("Updated Semester: ");
            scanf(" %[^\n]s", arr[i].semester);
            break;
        }
    }

    if (found) {
        printf("Student Record with ID %s Updated Successfully!\n", rollNumberToUpdate);
    } else {
        printf("Student Record with ID %s Not Found!\n", rollNumberToUpdate);
    }

    StudentSubMenu(arr, n); // Display the submenu again
}


void DisplayAllRecords(Person arr[], int n) {
    printf("\nAll Student Records:\n");
    printf("------------------------------------------------------------------------------------\n");
    printf(" %-20s %-20s %-10s %-20s %-20s\n", "Name", "ID", "Department", "Session", "Semester");
    printf("------------------------------------------------------------------------------------\n");

    

    for (int i = 0; i < n; i++) {
        if (arr[i].ID[0] != '\0') {
            printf(" %-20s %-20s %-10s %-20s %-20s\n", arr[i].name, arr[i].ID, arr[i].department, arr[i].session, arr[i].semester);
        }
    }

    printf("------------------------------------------------------------------------------------\n");
    StudentSubMenu(arr, n); // Display the submenu again
}


void DisplaySpecificRecord(Person arr[], int n) {
    char rollNumberToDisplay[20];
    printf("\nEnter the ID of the Student to Display: ");
    scanf(" %[^\n]s", rollNumberToDisplay);

    int found = 0;
    printf("\nStudent Record:\n");
    printf("------------------------------------------------------------------------------------\n");
    printf(" %-20s %-20s %-10s %-20s %-20s\n", "Name", "ID", "Department", "Session", "Semester");
    printf("------------------------------------------------------------------------------------\n");
    

    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].ID, rollNumberToDisplay) == 0) {
            found = 1;
            printf(" %-20s %-20s %-10s %-20s %-20s\n", arr[i].name, arr[i].ID, arr[i].department, arr[i].session, arr[i].semester);
            break;
        }
    }

    if (!found) {
        printf("Student Record with ID %s Not Found!\n", rollNumberToDisplay);
    }

    printf("------------------------------------------------------------------------------------\n");
    StudentSubMenu(arr, n);
}


void Attendance() {
    int joinedclass;
    char ID[20];
    FILE *ptr2;
    ptr2=fopen("Attendence.txt","a");
    printf("\nID: ");
    scanf(" %[^\n]s", &ID);
    printf("\nPresent: ");
    scanf("%d", &joinedclass);
    int Absent = 25 - joinedclass;
    printf("Present: %d days\n", joinedclass);
    printf("Absent: %d days\n", Absent);
    fprintf(ptr2,"ID= %s   Present: %d   Absent: %d \n",ID,joinedclass,Absent);
    fclose(ptr2);
    printf("Enter any DIGIT to Go To Second Main menu: ");
    int a;
    scanf("%d", &a);
    printf("Reverting to Second Main Menu...\n");
    SecondMain();
}


void NextSemester() {
    char course1[20], course2[20], course3[20];
    char ID[20];
    FILE *ptr4;
    ptr4=fopen("Course.txt","a");
    printf("Enter the Id:");
    scanf(" %[^\n]s",ID);
    printf("\nEnter 3 Courses: \n");
    printf("1st course: ");
    scanf(" %[^\n]", course1);
    printf("2nd course: ");
    scanf(" %[^\n]", course2);
    printf("3rd course: ");
    scanf(" %[^\n]", course3);
    fprintf(ptr4,"ID: %s   Course 1: %s   Course 2: %s   Course 3: %s\n",ID,course1,course2,course3);
    fclose(ptr4);
    printf("Reverting to Second Main menu...\n");
    SecondMain();
}

void Course() {
    int a;
    printf("\n(Add Marks To Calculate Grade Point)\n");
    printf("\n1. Enter Marks for English\n");
    printf("2. Enter Marks for Math\n");
    printf("3. Enter Marks for CSE\n");
    printf("4. Return to Second Main Menu\n");
    printf("Enter the number to continue: ");
    scanf("%d", &a);

    switch (a) {
        case 1:
            Eng();
            break;
        case 2:
            Math();
            break;
        case 3:
            Cse();
            break;
        case 4:
            SecondMain();
            break;
        default:
            printf("Error: Invalid choice\n");
            SecondMain();
            break;
    }
}

void Eng() {
    float q1, q2, q3, mid, final, presentation, attendance;
    printf("\nEnter exam marks for English\n");
    printf("Enter English Quiz 1 Out of 10: ");
    scanf("%f", &q1);
    printf("Enter English Quiz 2 Out of 10: ");
    scanf("%f", &q2);
    printf("Enter English Quiz 3 Out of 10: ");
    scanf("%f", &q3);

    float quiz = ((q1 + q2 + q3) * 10) / 30;

    printf("Enter Marks of Presentation & Project Out of 10: ");
    scanf("%f", &presentation);
    printf("Enter Marks on Attendance Out of 10: ");
    scanf("%f", &attendance);

    printf("Enter English Mid Out of 30: ");
    scanf("%f", &mid);
    printf("Enter English Final Out of 40: ");
    scanf("%f", &final);

    float engTotal = quiz + presentation + attendance + mid + final;


    printf("Total Number: %.2f\n", engTotal);
    Mark(engTotal);
    printf("\n");
    Course();
}

void Math() {
    float q1, q2, q3, mid, final, presentation, attendance;
    printf("\nEnter exam marks for Math\n");
    printf("Enter Math Quiz 1 Out of 10: ");
    scanf("%f", &q1);
    printf("Enter Math Quiz 2 Out of 10: ");
    scanf("%f", &q2);
    printf("Enter Math Quiz 3 Out of 10: ");
    scanf("%f", &q3);

    float quiz = ((q1 + q2 + q3) * 10) / 30;

    printf("Enter Marks of Presentation & Project Out of 10: ");
    scanf("%f", &presentation);
    printf("Enter Marks on Attendance Out of 10: ");
    scanf("%f", &attendance);

    printf("Enter Math Mid Out of 30: ");
    scanf("%f", &mid);
    printf("Enter Math Final Out of 40: ");
    scanf("%f", &final);

    float mathTotal = quiz + presentation + attendance + mid + final;


    printf("Total Number: %.2f\n", mathTotal);
    Mark(mathTotal);
    printf("\n");
    Course();
}

void Cse() {
    float q1, q2, q3, mid, final, presentation, attendance;
    printf("\nEnter exam marks for CSE\n");
    printf("Enter CSE Quiz 1 Out of 10: ");
    scanf("%f", &q1);
    printf("Enter CSE Quiz 2 Out of 10: ");
    scanf("%f", &q2);
    printf("Enter CSE Quiz 3 Out of 10: ");
    scanf("%f", &q3);

    float quiz = ((q1 + q2 + q3) * 10) / 30;

    printf("Enter Marks of Presentation & Project Out of 10: ");
    scanf("%f", &presentation);
    printf("Enter Marks on Attendance Out of 10: ");
    scanf("%f", &attendance);

    printf("Enter CSE Mid Out of 30: ");
    scanf("%f", &mid);
    printf("Enter CSE Final Out of 40: ");
    scanf("%f", &final);

    float cseTotal = quiz + presentation + attendance + mid + final;
    float cseCGPA = (cseTotal * 4) / 100;

    printf("Total Number: %.2f\n", cseTotal);
    Mark(cseTotal);
    printf("\n");
    Course();
}


void CountCgpa() {
    float c1, m1, e1, c2, m2, e2, total;
    char ID[20];
    FILE *ptr3;
    ptr3=fopen("CountCGPA.txt","a");
    printf("Enter the Id:");
    scanf(" %[^\n]s",ID);
    printf("\nEnter the Total Credit for MATH: ");
    scanf("%f", &m1);
    printf("Enter the Total Credit for ENGLISH: ");
    scanf("%f", &e1);
    printf("Enter the Total Credit for CSE: ");
    scanf("%f", &c1);
    printf("Enter the GPA of MATH: ");
    scanf("%f", &m2);
    printf("Enter the GPA OF ENGLISH: ");
    scanf("%f", &e2);
    printf("Enter the GPA of CSE: ");
    scanf("%f", &c2);
    total = (c1 * c2 + e1 * e2 + m1 * m2) / (c1 + m1 + e1);

    printf("\nHere the Combined CGPA is: %.2f\n", total);
    fprintf(ptr3,"ID= %s    CGPA= %.2f \n",ID,total);
    fclose(ptr3);
    printf("Press any DIGIT to Go To Second Main menu: ");
    int s;
    scanf("%d", &s);
    printf("Reverting to Second Main Menu...\n");
    SecondMain();
}


void Mark(float sum){

    if(sum>=80&&sum<=100){
            printf("\nLetter Grade: A+ , Grade Point: 4.00");}
    else if(sum>=75&&sum<=79.99){
            printf("\nLetter Grade: A , Grade Point: 3.75");}
    else if(sum>=70&&sum<=74.99){
            printf("\nLetter Grade: A- , Grade Point: 3.50");}
    else if(sum>=65&&sum<=69.99){
            printf("\nLetter Grade: B+ , Grade Point: 3.25");}
    else if(sum>=60&&sum<=64.99){
            printf("\nLetter Grade: B , Grade Point: 3.00");}
    else if(sum>=55&&sum<=59.99){
            printf("\nLetter Grade: B- , Grade Point: 2.75");}
    else if(sum>=50&&sum<=54.99){
            printf("\nLetter Grade: C+ , Grade Point: 2.50");}
    else if(sum>=45&&sum<=49.99){
            printf("\nLetter Grade: C , Grade Point: 2.25");}
    else if(sum>=39&&sum<=44.99){
            printf("\nLetter Grade: D , Grade Point: 2.00");}
    else if(sum>=0&&sum<=39.99){
            printf("\nLetter Grade: F , Grade Point: 0.00");}
}

void Exit() {
    printf("\nReverting to main menu...\n");
    main();
}
