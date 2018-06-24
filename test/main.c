#define CTEST_MAIN
#include "../include/data_global.h"
#include "../include/ListPlayers.h"
#include "../include/settings.h"
#include <ctest.h>

CTEST(Set_time, Correct) {
    int result = correct_set(15, 5);
    int expected = 1;
    ASSERT_EQUAL(expected,result);
}

CTEST(Set_time, Incorrect) {
    int result = correct_set(100, 5);
    int expected = 0;
    ASSERT_EQUAL(expected,result);
}

CTEST(Set_str, Correct) {
    int result = correct_set(50, 2);
    int expected = 1;
    ASSERT_EQUAL(expected,result);
}

CTEST(Set_str, Incorrect) {
    int result = correct_set(20, 0);
    int expected = 0;
    ASSERT_EQUAL(expected,result);
}


int main(int argc, const char** argv) {
    int test_res = ctest_main(argc, argv);
    return test_res;
}
