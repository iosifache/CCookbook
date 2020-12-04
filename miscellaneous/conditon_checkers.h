#ifndef _CONDITION_CHECKERS_H

#define _CONDITION_CHECKERS_H

/*
 * If an error condition is met, return an error code
 */
#define RET_CONDITION_CHECKER(condition, error_code) \
    if (condition) return error_code;

/*
 * If an error condition is met, set an error flag and go to a label
 */
#define GOTO_CONDITION_CHECKER(condition, set_flag, exit_label) \
    if (condition){\
        set_flag = 1;\
        goto exit_label; \
    };

#endif