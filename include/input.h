#ifndef INPUT_H
#define INPUT_H

typedef struct {
    int move_up;
    int move_down;
    int move_left;
    int move_right;
} InputCommand;

void input_init(void);
InputCommand input_read(void);

#endif