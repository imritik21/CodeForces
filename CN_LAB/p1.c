#include<stdio.h>
#include<string.h>
struct student
{
    /* data */
    int sl_no;
    int roll;
    char name[35];
    char gender;
    int mob_No;
    float phy_marks;
    float chem_marks;
    float math_marks;
};

int main() {
    // Your code here
    int n;
    printf("Enter the number of student : ");
    scanf("%d",&n);

    struct student students[n];
    for(int i=0;i<n;i++){
        printf("Enter sl_no: ");
        scanf("%d",&students[i].sl_no);

        printf("Roll Number: ");
        scanf("%d", &students[i].roll);

        printf("Name: ");
        scanf("%[^\n]%*c", students[i].name); 
        // gets(students[i].name);

        printf("Gender (M/F): ");
        scanf("%c", &students[i].gender);

        printf("Mobile Number: ");
        scanf("%d", &students[i].mob_No);

        printf("Physics Marks: ");
        scanf("%d", &students[i].phy_marks);

        printf("Chemistry Marks: ");
        scanf("%d", &students[i].chem_marks);

        printf("Math Marks: ");
        scanf("%d", &students[i].math_marks);
    }

    printf("\nEntered details of students are:\n");
    for (int i = 0; i < n; i++) {
        printf("Details of student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].roll);
        printf("Name: %s\n", students[i].name);
        printf("Gender: %c\n", students[i].gender);
        printf("Mobile Number: %d\n", students[i].mob_No);
        printf("Physics Marks: %d\n", students[i].phy_marks);
        printf("Chemistry Marks: %d\n", students[i].chem_marks);
        printf("Math Marks: %d\n", students[i].math_marks);
        printf("\n");
    }
    return 0;
}