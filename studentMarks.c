//Accpet student marks from user and calculate Total,Average,Percentage 
 #include <stdio.h>

float calcSum(float marks[], int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += marks[i];
    }
    return sum;
}

float calcAverage(float sum, int n) {
    return sum / n;
}

float calcPercentage(float sum, int n, float total_marks_per_subject) {
    return (sum / (n * total_marks_per_subject)) * 100;
}

int main() {
    int n;
    float marks[100], total_marks_per_subject, sum, average, percentage;

    printf("Enter number of subjects: ");
    scanf("%d", &n);

    printf("Enter total marks for each subject: ");
    scanf("%f", &total_marks_per_subject);

    for (int i = 0; i < n; i++) {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%f", &marks[i]);
	if(marks[i]>total_marks_per_subject || marks[i]<0)
	{
		printf("ERROR:INVALID INPUT VALUE\n");
		//printf("Enter marks for subject %d:",i+1);
		//scanf("%f",&marks[i]);
		i--;
	}
    }

    sum = calcSum(marks, n);
    average = calcAverage(sum, n);
    percentage = calcPercentage(sum, n, total_marks_per_subject);

    printf("\nTotal Marks Obtained: %.2f", sum);
    printf("\nAverage Marks: %.2f", average);
    printf("\nPercentage: %.2f%%\n", percentage);

    return 0;
}
