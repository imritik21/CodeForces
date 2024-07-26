#include <stdio.h>

// Define the dob structure
struct dob {
    int day;
    int month;
    int year;
};

// Define the student_info structure
struct student_info {
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};

// Function to populate the student_info structure (call-by-value)
void printStudentInfoByValue(struct student_info student) {
    printf("\nPrinting student info (Call-by-Value):\n");
    printf("Roll No: %d\n", student.roll_no);
    printf("Name: %s\n", student.name);
    printf("CGPA: %.2f\n", student.CGPA);
    printf("Date of Birth: %02d-%02d-%04d\n", student.age.day, student.age.month, student.age.year);
}

// Function to populate the student_info structure (call-by-address)
void printStudentInfoByAddress(struct student_info *student) {
    printf("\nPrinting student info (Call-by-Address):\n");
    printf("Roll No: %d\n", student->roll_no);
    printf("Name: %s\n", student->name);
    printf("CGPA: %.2f\n", student->CGPA);
    printf("Date of Birth: %02d-%02d-%04d\n", student->age.day, student->age.month, student->age.year);
}

int main() {
    struct student_info student;

    // Assign values to the student_info structure
    printf("Enter roll number: ");
    scanf("%d", &student.roll_no);
    printf("Enter name: ");
    scanf("%s", student.name);
    printf("Enter CGPA: ");
    scanf("%f", &student.CGPA);
    printf("Enter date of birth (day month year): ");
    scanf("%d %d %d", &student.age.day, &student.age.month, &student.age.year);

    // Call the function using call-by-value
    printStudentInfoByValue(student);

    // Call the function using call-by-address
    printStudentInfoByAddress(&student);

    return 0;
}