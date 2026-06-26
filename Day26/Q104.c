#include <stdio.h>
#include <ctype.h>
struct Question {
    char text[150];       
    char options[4][50];  
    char correct_ans;     
};

int main() {
    int score = 0;
    char user_choice;
    int total_questions = 4;
    struct Question quiz[] = {
        {
            "Which of the following is the correct extension of a C language source file?",
            {"A. .c", "B. .cpp", "C. .obj", "D. .exe"},
            'A'
        },
        {
            "Who is known as the father of C language?",
            {"A. Bjarne Stroustrup", "B. Dennis Ritchie", "C. James Gosling", "D. Linus Torvalds"},
            'B'
        },
        {
            "Which data type is used to store decimal values in C?",
            {"A. int", "B. char", "C. float", "D. void"},
            'C'
        },
        {
            "What is the starting index of an array in C?",
            {"A. -1", "B. 1", "C. 2", "D. 0"},
            'D'
        }
    };

    printf("==================================================\n");
    printf("         Welcome to the Computer Science Quiz      \n");
    printf("==================================================\n");
    printf("Instructions: Enter A, B, C, or D for each question.\n\n");

    for (int i = 0; i < total_questions; i++) {
        printf("Question %d: %s\n", i + 1, quiz[i].text);
        
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }

        while (1) {
            printf("Your Answer: ");
            scanf(" %c", &user_choice); 
            
            user_choice = toupper(user_choice);

            if (user_choice == 'A' || user_choice == 'B' || user_choice == 'C' || user_choice == 'D') {
                break; 
            }
            printf(" Invalid selection! Please choose from A, B, C, or D only.\n");
        }

        if (user_choice == quiz[i].correct_ans) {
            printf(" Correct!\n\n");
            score++;
        } else {
            printf(" Incorrect. The correct answer was option %c.\n\n", quiz[i].correct_ans);
        }
    }

    printf("==================================================\n");
    printf("                   QUIZ REPORT                    \n");
    printf("==================================================\n");
    printf("Total Questions: %d\n", total_questions);
    printf("Correct Answers: %d\n", score);
    printf("Final Score    : %.2f%%\n", ((float)score / total_questions) * 100);
    
    if (score == total_questions) {
        printf("Result         : Outstanding! Perfect score! \n");
    } else if (score >= total_questions / 2) {
        printf("Result         : Well played! Good job. \n");
    } else {
        printf("Result         : Keep practicing! Better luck next time.\n");
    }
    printf("==================================================\n");

    return 0;
}
