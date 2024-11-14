#include <stdio.h>
#include <string.h>

int areCompanions(char str1[], char str2[]) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 != len2) {
        return 0;  // false
    }

    int count1[256] = {0};
    int count2[256] = {0};

    for (int i = 0; i < len1; i++) {
        count1[(int)str1[i]]++;
        count2[(int)str2[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (count1[i] != count2[i]) {
            return 0;  // false
        }
    }

    return 1;  // true
}

void copyString(char source[], char destination[]) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';  
}

int stringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void concatenateStrings(char str1[], char str2[], char result[]) {
    int i = 0, j = 0;

    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }

    while (str2[j] != '\0') {
        result[i] = str2[j];
        i++;
        j++;
    }

    result[i] = '\0';  
}

int main() {
    char subjects[5][100], times[5][100], rooms[5][100];
    char result[300], copiedSubject[100];

    printf("Enter timetable details for 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Enter subject %d: ", i + 1);
        fgets(subjects[i], sizeof(subjects[i]), stdin);
        subjects[i][strcspn(subjects[i], "\n")] = '\0';  

        printf("Enter time for subject %d: ", i + 1);
        fgets(times[i], sizeof(times[i]), stdin);
        times[i][strcspn(times[i], "\n")] = '\0';  

        printf("Enter room number for subject %d: ", i + 1);
        fgets(rooms[i], sizeof(rooms[i]), stdin);
        rooms[i][strcspn(rooms[i], "\n")] = '\0';  
    }

    printf("\nCollege Timetable:\n");
    printf("-----------------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("%s | Time: %s | Room: %s\n", subjects[i], times[i], rooms[i]);
    }

    char subject1[100], subject2[100];
    printf("\nEnter two subjects to check if they are companions (anagrams):\n");
    printf("Enter subject 1: ");
    fgets(subject1, sizeof(subject1), stdin);
    subject1[strcspn(subject1, "\n")] = '\0';  

    printf("Enter subject 2: ");
    fgets(subject2, sizeof(subject2), stdin);
    subject2[strcspn(subject2, "\n")] = '\0';  

    if (areCompanions(subject1, subject2)) {
        printf("The subjects are companions (anagrams).\n");
    } else {
        printf("The subjects are not companions (anagrams).\n");
    }

    copyString(subjects[0], copiedSubject);
    printf("\nFirst subject copied: %s\n", copiedSubject);

    printf("\nLength of the first subject: %d\n", stringLength(subjects[0]));

    concatenateStrings(subjects[0], rooms[0], result);
    printf("\nConcatenated string of subject and room: %s\n", result);

    return 0;
}
