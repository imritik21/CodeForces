#include <stdio.h>
#include <string.h>

typedef struct {
    int Sl_no;
    int roll_no;
    char name[50];
    char gender[10];
    char dob[15]; // Date of Birth
    char ph_no[15];
    int phy_marks;
    int chem_marks;
    int math_marks;
    float percentage;
} Student;

void getStudentsDetails(Student *student, int index) {
    printf("Enter the details of student %d :\n", index + 1);
    student->Sl_no = index + 1;

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

    student->percentage = (student->phy_marks + student->chem_marks + student->math_marks) / 3.0;
}

void displayStudentDetails(Student *students, int n) {
    printf("\nStudent List:\n");
    printf("SL.no\tRoll number\tName\t\tGender\t\tDate of Birth\tMobile number\tPhy mark\tChem mark\tMath mark\tPercentage\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%s\t\t%s\t\t%s\t%s\t\t%d\t\t%d\t\t%d\t\t%.2f\n", 
            students[i].Sl_no, students[i].roll_no, students[i].name, students[i].gender, 
            students[i].dob, students[i].ph_no, students[i].phy_marks, students[i].chem_marks, 
            students[i].math_marks, students[i].percentage);
    }
}

void displayByGender(Student *students, int n, char *gender) {
    printf("\n%s Students List:\n", gender);
    printf("SL.no\tRoll number\tName\t\tDate of Birth\tMobile number\tPhy mark\tChem mark\tMath mark\tPercentage\n");

    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].gender, gender) == 0) {
            printf("%d\t%d\t\t%s\t\t%s\t%s\t\t%d\t\t%d\t\t%d\t\t%.2f\n", 
                students[i].Sl_no, students[i].roll_no, students[i].name, 
                students[i].dob, students[i].ph_no, students[i].phy_marks, 
                students[i].chem_marks, students[i].math_marks, students[i].percentage);
        }
    }
}

void sortStudentsByPercentage(Student *students, int n) {
    Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].percentage < students[j + 1].percentage) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    displayStudentDetails(students, n);
}

void displayByPhoneNumberSuffix(Student *students, int n, char *suffix) {
    printf("\nStudents with phone number ending in %s:\n", suffix);
    printf("SL.no\tRoll number\tName\t\tGender\t\tDate of Birth\tMobile number\tPhy mark\tChem mark\tMath mark\tPercentage\n");

    for (int i = 0; i < n; i++) {
        if (strstr(students[i].ph_no, suffix) == students[i].ph_no + strlen(students[i].ph_no) - strlen(suffix)) {
            printf("%d\t%d\t\t%s\t\t%s\t\t%s\t%s\t\t%d\t\t%d\t\t%d\t\t%.2f\n", 
                students[i].Sl_no, students[i].roll_no, students[i].name, students[i].gender, 
                students[i].dob, students[i].ph_no, students[i].phy_marks, students[i].chem_marks, 
                students[i].math_marks, students[i].percentage);
        }
    }
}

void displayHighestLowestMarks(Student *students, int n, char *subject) {
    int highest = -1, lowest = 101;
    char highest_name[50], lowest_name[50];

    for (int i = 0; i < n; i++) {
        int marks;
        if (strcmp(subject, "Physics") == 0) {
            marks = students[i].phy_marks;
        } else if (strcmp(subject, "Chemistry") == 0) {
            marks = students[i].chem_marks;
        } else if (strcmp(subject, "Mathematics") == 0) {
            marks = students[i].math_marks;
        } else {
            printf("Invalid subject name.\n");
            return;
        }

        if (marks > highest) {
            highest = marks;
            strcpy(highest_name, students[i].name);
        }
        if (marks < lowest) {
            lowest = marks;
            strcpy(lowest_name, students[i].name);
        }
    }

    printf("\nHighest mark in %s: %d (Student: %s)\n", subject, highest, highest_name);
    printf("Lowest mark in %s: %d (Student: %s)\n", subject, lowest, lowest_name);
}

int main() {
    int n = 0;
    Student students[100]; // Assuming a maximum of 100 students for simplicity
    int choice;

    do {
        printf("\nStudent Menu:\n");
        printf("0. Quit\n");
        printf("1. Store student data\n");
        printf("2. Display student data\n");
        printf("3. Display male and female categories separately\n");
        printf("4. Display student data along with %% mark sorted in %% mark\n");
        printf("5. Display the student data having a mobile number ending with 042\n");
        printf("6. Display the highest and lowest mark in any subject as per the user's wish\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Exiting...\n");
                break;
            case 1:
                printf("Enter the number of students: \n");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    getStudentsDetails(&students[i], i);
                }
                break;
            case 2:
                displayStudentDetails(students, n);
                break;
            case 3:
                displayByGender(students, n, "Male");
                displayByGender(students, n, "Female");
                break;
            case 4:
                sortStudentsByPercentage(students, n);
                break;
            case 5:
                displayByPhoneNumberSuffix(students, n, "042");
                break;
            case 6: {
                char subject[20];
                printf("Enter the subject name (Physics/Chemistry/Mathematics): ");
                scanf("%s", subject);
                displayHighestLowestMarks(students, n, subject);
                break;
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}