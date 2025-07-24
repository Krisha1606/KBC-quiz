#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void countdown(int seconds) {
    while (seconds > 0) {
        printf("\rTime left: %d seconds", seconds);
        fflush(stdout);
        sleep(1); // Wait for 1 second
        seconds--;
    }
    printf("\rTime left: 0 seconds\n");
}

void time_extend(int *seconds) {
    printf("Do you want to extend your time by 30 seconds? (1 for Yes, 0 for No): ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        *seconds += 30;
        printf("Your time has been extended by 30 seconds.\n");
    }
}

void double_dip(int correct_answer, int *prize) {
    int first_try, second_try;
    printf("You have two chances to answer!\n");

    // First attempt
    printf("First attempt: Your answer: ");
    scanf("%d", &first_try);
    if (first_try == correct_answer) {
        *prize += 100000;
        printf("Correct! You earn 1,00,000 rupees.\n");
        return;
    } else {
        printf("Incorrect!\n");
    }

    // Second attempt
    printf("Second attempt: Your answer: ");
    scanf("%d", &second_try);
    if (second_try == correct_answer) {
        printf("Correct! You earn 1,00,000 rupees.\n");
        *prize += 100000;
    } else {
        printf("Incorrect! The correct answer was: %d.\n", correct_answer);
    }
}

void risk_free_attempt(int correct_answer, int *prize) {
    int answer;
    printf("You have a risk-free attempt! Answer correctly and earn 10 points.\n");
    printf("Your answer: ");
    scanf("%d", &answer);
    if (answer == correct_answer) {
        printf("Correct! You earn 100000 rupees.\n");
        *prize += 100000;
    } else {
        printf("Incorrect! But you lose no points.\n");
    }
}

int main() {
    int answer, prize = 0;
    int lifeline_choice;

    printf("Welcome to Kaun Banega Crorepati (KBC)!\n");
    char quit_choice;
    
    srand(time(NULL));

    // Question 1
    printf("\nQuestion 1: Who won the first-ever Cricket World Cup in 1975?\n");
    printf("1. India\n");
    printf("2. West Indies\n");
    printf("3. Australia\n");
    printf("4. England\n");
    int correct_answer_1 = 2;
    int time_left = 10;

    printf("Choose a lifeline: 1. Double Dip 2. Time Extend 3. Risk-Free Attempt 0. No Lifeline\n");
    printf("Your choice: ");
    scanf("%d", &lifeline_choice);

    // Apply selected lifeline
    if (lifeline_choice == 1) {
        double_dip(correct_answer_1, &prize); 
    } else if (lifeline_choice == 2) {
        time_extend(&time_left);
        countdown(time_left); 
        printf("Your answer: ");
        scanf("%d", &answer);
        if (answer == correct_answer_1) {
            printf("Correct! You earn 1,00,000 rupees.\n\n");
            prize += 100000;
        } else {
            printf("Incorrect! The correct answer is West Indies.\n\n");
        }
    } else if (lifeline_choice == 3) {
        risk_free_attempt(correct_answer_1, &prize); 
    } else {
        countdown(time_left); 
        printf("Your answer: ");
        scanf("%d", &answer);
        if (answer == correct_answer_1) {
            printf("Correct! You earn 1,00,000 rupees.\n\n");
            prize += 100000;
        } else {
            printf("Incorrect! The correct answer is West Indies.\n\n");
        }
    }

    // Question 2
    printf("\nQuestion 2: Who wrote the national anthem of India?\n");
    printf("1. Rabindranath Tagore\n");
    printf("2. Bankim Chandra Chattopadhyay\n");
    printf("3. Sarojini Naidu\n");
    printf("4. Lata Mangeshkar\n");
    int correct_answer_2 = 1; 
    printf("Do you want to quit? (Y/N): ");
    scanf(" %c", &quit_choice); 
    if (quit_choice == 'Y' || quit_choice == 'y') {
        printf("You chose to quit. Your total prize is: %d\n", prize);
        return 0; 
    }

    printf("Choose a lifeline: 1. Double Dip 2. Time Extend 3. Risk-Free Attempt 0. No Lifeline\n");
    printf("Your choice: ");
    scanf("%d", &lifeline_choice);

    // Apply selected lifeline
    if (lifeline_choice == 1) {
        double_dip(correct_answer_2, &prize); 
    } else if (lifeline_choice == 2) {
        time_extend(&time_left);
        countdown(time_left); 
        printf("Your answer: ");
        scanf("%d", &answer);
        if (answer == correct_answer_2) {
            printf("Correct! You earn 2,00,000 rupees.\n\n");
            prize += 100000;
        } else {
            printf("Incorrect! The correct answer is Rabindranath Tagore.\n\n");
        }
    } else if (lifeline_choice == 3) {
        risk_free_attempt(correct_answer_2, &prize);
    } else {
        countdown(time_left); 
        printf("Your answer: ");
        scanf("%d", &answer);
        if (answer == correct_answer_2) {
            printf("Correct! You earn 2,00,000 rupees.\n\n");
            prize += 100000;
        } else {
            printf("Incorrect! The correct answer is Rabindranath Tagore.\n\n");
        }
    }

    // Question 3
    printf("\nQuestion 3: Who wrote the famous play romeo and juliet?\n");
    printf("1. William Shakespeare\n");
    printf("2. Charles Dickens\n");
    printf("3. Mark Twain\n");
    printf("4. Jane Austen\n");
    int correct_answer_3 = 1;
    printf("Do you want to quit? (Y/N): ");
    scanf(" %c", &quit_choice); 
    if (quit_choice == 'Y' || quit_choice == 'y') {
        printf("You chose to quit. Your total score is: %d\n", prize);
        return 0; 
    }

    printf("Choose a lifeline: 1. Double Dip 2. Time Extend 3. Risk-Free Attempt 0. No Lifeline\n");
    printf("Your choice: ");
    scanf("%d", &lifeline_choice);

    // Apply selected lifeline
    if (lifeline_choice == 1) {
        double_dip(correct_answer_3, &prize);
    } else if (lifeline_choice == 2) {
        time_extend(&time_left); 
        countdown(time_left); 
        printf("Your answer: ");
        scanf("%d", &answer);
        if (answer == correct_answer_3) {
            printf("Correct! You earn 3,00,000 rupees.\n\n");
            prize+= 100000;
        } else {
            printf("Incorrect! The correct answer is William Shakespeare.\n\n");
        }
    } else if (lifeline_choice == 3) {
        risk_free_attempt(correct_answer_3, &prize);
    } else {
        countdown(time_left); 
        printf("Your answer: ");
        scanf("%d", &answer);
        if (answer == correct_answer_3) {
            printf("Correct! You earn 3,00,000 rupees.\n\n");
            prize += 100000;
        } else {
            printf("Incorrect! The correct answer is William Shakespeare.\n\n");
        }
    }

    // Question 4
    printf("\nQuestion 4: Which planet is known as the Red Planet?\n");
    printf("1. Venus\n");
    printf("2. Mercury\n");
    printf("3. Mars\n");
    printf("4. Saturn\n");
    int correct_answer_4 = 3;
    printf("Do you want to quit? (Y/N): ");
    scanf(" %c", &quit_choice);
    if (quit_choice == 'Y' || quit_choice == 'y') {
        printf("You chose to quit. Your total score is: %d\n", prize);
        return 0;
    }

    printf("Choose a lifeline: 1. Double Dip 2. Time Extend 3. Risk-Free Attempt 0. No Lifeline\n");
    printf("Your choice: ");
    scanf("%d", &lifeline_choice);

    // Apply selected lifeline
    if (lifeline_choice == 1) {
        double_dip(correct_answer_4, &prize); 
    } else if (lifeline_choice == 2) {
        time_extend(&time_left); 
        countdown(time_left);
        printf("Your answer: ");
        scanf("%d", &answer);
        if (answer == correct_answer_4) {
            printf("Correct! You earn 4,00,000 rupees.\n\n");
            prize += 100000;
        } else {
            printf("Incorrect! The correct answer is Mars.\n\n");
        }
    } else if (lifeline_choice == 3) {
        risk_free_attempt(correct_answer_4, &prize); 
    } else {
        countdown(time_left); 
        printf("Your answer: ");
        scanf("%d", &answer);
        if (answer == correct_answer_4) {
            printf("Correct! You earn 4,00,000 rupees.\n\n");
            prize += 100000;
        } else {
            printf("Incorrect! The correct answer is Mars.\n\n");
        }
    }

    // Question 5
    printf("\nQuestion 5: What does HTTP stand for?\n");
    printf("1.HyperText Transfer Protocol \n");
    printf("2. HyperText Translation Protocol \n");
    printf("3. HyperText Transmission Program\n");
    printf("4. HyperText Transfer Program\n");
    int correct_answer_5 = 1;
    printf("Do you want to quit? (Y/N): ");
    scanf(" %c", &quit_choice); 
    if (quit_choice == 'Y' || quit_choice == 'y') {
        printf("You chose to quit. Your total score is: %d\n", prize);
        return 0; 
    }

    printf("Choose a lifeline: 1. Double Dip 2. Time Extend 3. Risk-Free Attempt 0. No Lifeline\n");
    printf("Your choice: ");
    scanf("%d", &lifeline_choice);

    // Apply selected lifeline
    if (lifeline_choice == 1) {
        double_dip(correct_answer_5, &prize); 
    } else if (lifeline_choice == 2) {
        time_extend(&time_left); 
        countdown(time_left);
        printf("Your answer: ");
        scanf("%d", &answer);
        if (answer == correct_answer_5) {
            printf("Correct! You earn 5,00,000 rupees.\n\n");
            prize += 100000;
        } else {
            printf("Incorrect! The correct answer is HyperText Transfer Protocol.\n\n");
        }
    } else if (lifeline_choice == 3) {
        risk_free_attempt(correct_answer_5, &prize); 
    } else {
        countdown(time_left); 
        printf("Your answer: ");
        scanf("%d", &answer);
        if (answer == correct_answer_5) {
            printf("Correct! You earn 5,00,000 rupees.\n\n");
            prize += 100000;
        } else {
            printf("Incorrect! The correct answer is HyperText Transfer Protocol.\n\n");
        }
    }

    // Final score
    printf("\nYour total score is: %d\n", prize);
    if (prize == 500000) {
        printf("Congratulations! You are a KBC winner!\n");
    } else {
        printf("Thank you for playing! Better luck next time.\n");
    }

    return 0;
}
