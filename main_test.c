//
//  main_test.c
//  Week2
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#include "min_unit.h"
#include "core.h"

int tests_run = 0;
int tests_failed = 0;

static char * test_letter_grade() {
    mu_assert("100 should give letter grade 'A'", calculate_grade(100) == 'A');
    mu_assert("90 should give letter grade 'A'", calculate_grade(90) == 'A');
    mu_assert("89 should give letter grade 'B'", calculate_grade(89) == 'B');
    mu_assert("85 should give letter grade 'B'", calculate_grade(85) == 'B');
    mu_assert("80 should give letter grade 'B'", calculate_grade(80) == 'B');
    mu_assert("79 should give letter grade 'C'", calculate_grade(79) == 'C');
    mu_assert("70 should give letter grade 'C'", calculate_grade(70) == 'C');
    mu_assert("69 should give letter grade 'D'", calculate_grade(69) == 'D');
    mu_assert("60 should give letter grade 'D'", calculate_grade(60) == 'D');
    mu_assert("59 should give letter grade 'F'", calculate_grade(59) == 'F');
    mu_assert("40 should give letter grade 'F'", calculate_grade(40) == 'F');
    mu_assert("32 should give letter grade 'F'", calculate_grade(32) == 'F');
    mu_assert("0 should give letter grade 'F'", calculate_grade(0) == 'F');
    mu_assert("-1 should give letter grade 0", calculate_grade(-1) == 0);
    mu_assert("-99 should give letter grade 0", calculate_grade(-99) == 0);
    return 0;
}

static char * test_department_name() {
    mu_assert("01 should give name 'Computer Science'", strcmp("Computer Science", department_name(1)) == 0);
    mu_assert("02 should give name 'Computer Science'", strcmp("Computer Science", department_name(2)) == 0);
    mu_assert("05 should give name 'Computer Engineering'", strcmp("Computer Engineering", department_name(5)) == 0);
    mu_assert("10 should give name 'Physics'", strcmp("Physics", department_name(10)) == 0);
    mu_assert("20 should give name 'Chemistry'", strcmp("Chemistry", department_name(20)) == 0);
    mu_assert("100 should give name 'Math'", strcmp("Math", department_name(100)) == 0);
    mu_assert("17 should give name 'Unknown'", strcmp("Unknown", department_name(17)) == 0);
    mu_assert("0 should give name 'Unknown'", strcmp("Unknown", department_name(0)) == 0);
    mu_assert("-9 should give name 'Unknown'", strcmp("Unknown", department_name(-9)) == 0);
    return 0;
}

static char * test_factorial() {
    mu_assert("-5 factorial should be -1", factorial(-5) == -1);
    mu_assert("-99 factorial should be -1", factorial(-99) == -1);
    mu_assert("0 factorial should be 1", factorial(0) == 1);
    mu_assert("1 factorial should be 1", factorial(1) == 1);
    mu_assert("2 factorial should be 2", factorial(2) == 2);
    mu_assert("4 factorial should be 24", factorial(4) == 24);
    mu_assert("5 factorial should be 120", factorial(5) == 120);
    mu_assert("10 factorial should be 3,628,800", factorial(10) == 3628800);

    return 0;
}

static char * all_tests() {
    mu_run_test(test_letter_grade);
    mu_run_test(test_department_name);
    mu_run_test(test_factorial);
    return 0;
}

#ifdef TEST
int main(int argc, char **argv) {
    char *result = all_tests();
    
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    
    printf("%d tests of %d passed\n", tests_run - tests_failed, tests_run);
    
    return 0;
}
#endif

