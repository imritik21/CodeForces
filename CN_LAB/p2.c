#include <stdio.h>

typedef struct {
    int sl_no;
    int roll_no;
    char name[50];
    char gender[10];
    char dob[15];
    char ph_no[15];
    int phy_marks;
    int chem_marks;
    int math_marks;
} Student;

void getStudentsDetails(Student *student, int index) {
    printf("Enter the details of student %d :\n", index + 1);
    student->sl_no = index + 1;

    printf("Roll number: ");
    scanf("%d", &student->roll_no);

    printf("Name: ");
    scanf("%s", student->name);

    printf("Gender: ");
    scanf("%s", student->gender);

    printf("Date of Birth (dd-mm-yyyy): ");
    scanf("%s", student->dob);

    printf("Mobile number: ");
    scanf("%s", student->ph_no);

    printf("Physics mark: ");
    scanf("%d", &student->phy_marks);

    printf("Chemistry mark: ");
    scanf("%d", &student->chem_marks);

    printf("Mathematics mark: ");
    scanf("%d", &student->math_marks);
}

void displayStudentDetails(Student *students, int n) {
    printf("\nStudent List:\n");
    printf("SL.no\tRoll number\tName\t\tGender\tDOB\tMobile number\tPhy mark\tChem mark\tMath mark\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%s\t\t%s\t%s\t\t%s\t\t%d\t\t%d\t\t%d\n", 
            students[i].sl_no, students[i].roll_no, students[i].name, students[i].gender, students[i].dob,
            students[i].ph_no, students[i].phy_marks, students[i].chem_marks, students[i].math_marks);
    }
}

int main() {
    int n;
    printf("Enter the number of students: \n");
    scanf("%d", &n);
    Student students[n];

    for (int i = 0; i < n; i++) {
        getStudentsDetails(&students[i], i);
    }

    displayStudentDetails(students, n);

    return 0;
}