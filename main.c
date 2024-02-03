// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <process.h>

const int max_size = 3;
const int max_size_16 = 15;
const int magic_empty = -1;
const int magic_invalid = -2;
const int valid = -4;
const int invalid = -5;
const int magic_not_empty = -6;
const int magic_equal = -7;
const int magic_not_equal = -8;
const int magic_game_won = -9;
const int magic_game_loss = -10;
const int magic_game_current = -11;
const int magic_input_sup = -12;
const int magic_input_sdown = -13;
const int magic_input_sleft = -14;
const int magic_input_sright = -15;
const int magic_input_restart = -16;
const int magic_input_quit = -17;


struct stack_int4 {
  int data[4];
  int top;
  int is_valid;
};

typedef struct stack_int16 {
  int data[16];
  int top;
  int is_valid;
} Stack16;

typedef struct game_object {
    Stack16 matrix;
    int state;
    int score;
} Game;

struct stack_int4 create0() {
    struct stack_int4 stack;
    stack.is_valid = valid;
    stack.top = -1;
    return stack;
}

struct stack_int16 create16() {
    struct stack_int16 stack;
    stack.is_valid = valid;
    stack.top = -1;
    return stack;
}

int choose_random(int max_zero) {
    return floor(rand() % max_zero);
}

int is_equal(struct stack_int4 stack, int val0, int val1, int val2, int val3) {
    if(
        stack.data[0] == val0 &&
        stack.data[1] == val1 &&
        stack.data[2] == val2 &&
        stack.data[3] == val3)
        {
            return magic_equal;
    }

    return magic_not_equal;
}

struct stack_int4 create(int val0, int val1, int val2, int val3) {
    struct stack_int4 stack;
    stack.is_valid = valid;
    stack.top = 3;
    stack.data[0] = val0;
    stack.data[1] = val1;
    stack.data[2] = val2;
    stack.data[3] = val3;
    return stack;
}

int cmp(struct stack_int4 stack, struct stack_int4 stack2, struct stack_int4 stack3, struct stack_int4 stack4, struct stack_int4 stack5, struct stack_int4 stack6, struct stack_int4 stack7, struct stack_int4 stack8) {
    if((stack.data[0] == stack2.data[0]) && (stack.data[1] == stack2.data[1]) && (stack.data[2] == stack2.data[2]) && (stack.data[3] == stack2.data[3])
    && (stack3.data[0] == stack4.data[0]) && (stack3.data[1] == stack4.data[1]) && (stack3.data[2] == stack4.data[2]) && (stack3.data[3] == stack4.data[3])
    && (stack5.data[0] == stack6.data[0]) && (stack5.data[1] == stack6.data[1]) && (stack5.data[2] == stack6.data[2]) && (stack5.data[3] == stack6.data[3])
    && (stack7.data[0] == stack8.data[0]) && (stack7.data[1] == stack8.data[1]) && (stack7.data[2] == stack8.data[2]) && (stack7.data[3] == stack8.data[3])
      )
        return true;
    else
        return false;
}

struct stack_int4 push(struct stack_int4 stack, int new_element) {
    if(stack.top == max_size || stack.is_valid == invalid) {
        stack.is_valid = invalid;
        return stack;
    }
    stack.top++;
    stack.data[stack.top] = new_element;
    return stack;
}

struct stack_int4 pop(struct stack_int4 stack) {
    if(stack.top == -1 || stack.is_valid == invalid) {
        stack.is_valid = invalid;
        return stack;
    }
    stack.top--;
    return stack;
}

int peek(struct stack_int4 stack) {
    if(stack.top == -1) {
        return magic_empty;
    }
    if(stack.is_valid == invalid) {
        return magic_invalid;
    }
    return stack.data[stack.top];
}


struct stack_int16 push16(struct stack_int16 stack, int new_element) {
    if(stack.top == max_size_16 || stack.is_valid == invalid) {
        stack.is_valid = invalid;
        return stack;
    }
    stack.top++;
    stack.data[stack.top] = new_element;
    return stack;
}

struct stack_int16 pop16(struct stack_int16 stack) {
    if(stack.top == -1 || stack.is_valid == invalid) {
        stack.is_valid = invalid;
        return stack;
    }
    stack.top--;
    return stack;
}

int peek16(struct stack_int16 stack) {
    if(stack.top == -1) {
        return magic_empty;
    }
    if(stack.is_valid == invalid) {
        return magic_invalid;
    }
    return stack.data[stack.top];
}

int is_empty(struct stack_int4 stack) {
    if(stack.is_valid == invalid) {
        return magic_invalid;
    }
    if(stack.top == -1) {
        return magic_empty;
    }
    return magic_not_empty;
}

int is_empty16(Stack16 stack) {
    if(stack.is_valid == invalid) {
        return magic_invalid;
    }
    if(stack.top == -1) {
        return magic_empty;
    }
    return magic_not_empty;
}

Stack16 fill_zeroes() {
    Stack16 stack = create16();
    int x = 16;
    while(x --> 0) {
        stack = push16(stack, 0);
    }
    return stack;
}

void print_element(int i)
{
    if(i / 1000 > 0)
        {
            printf("| %d  ", i);
        }
    else if(i / 100 > 0)
        {
            printf("|  %d  ", i);
        }
    else if(i / 10 > 0)
        {
            printf("|  %d   ", i);
        }
    else if(i / 1 > 0)
        {
            printf("|   %d   ", i);
        }
    else
        {
            printf("|       ");
        }
}

void print_stack(struct stack_int4 stack) {
    if(stack.is_valid == invalid) {
        printf("%s", "Invalid stack!\n");
        return;
    }
    if(stack.top == -1) {
        printf("%s", "Empty stack!\n");
        return;
    }
    for(int i = 0; i <= stack.top; i++){
        print_element(stack.data[i]);
    }
    //printf("%s", "\n");
}

void print_stack16(struct stack_int16 stack) {
    if(stack.is_valid == invalid) {
        printf("%s", "Invalid stack!\n");
        return;
    }
    if(stack.top == -1) {
        printf("%s", "Empty stack!\n");
        return;
    }
    for(int i = 0; i <= stack.top; i++){
        printf("%d ", stack.data[i]);
    }
    printf("%s", "\n");
}

int length(struct stack_int4 stack) {
    if(stack.is_valid == invalid) {
        return magic_invalid;
    }
    return stack.top + 1;
}

struct stack_int4 coalesce_top2(struct stack_int4 stack, int* add_score) {
    int peeked = peek(stack);

    stack = pop(stack);
    while(peek(stack) == 0){
        stack = pop(stack);
    }

    if(peek(stack) == peeked) {
        stack = pop(stack);
        *add_score = *add_score + 2 * peeked;
        stack = push(stack, 2 * peeked);

    } else {
        stack = push(stack, peeked);
    }
    return stack;
}

struct stack_int4 swipe(struct stack_int4 stack, int *add_score) {

    struct stack_int4 scratchpad;
    scratchpad = create0();

    while(is_empty(stack) == magic_not_empty) {
        stack = coalesce_top2(stack, add_score);
        int peeked = peek(stack);
        if(peeked != 0) {
            scratchpad = push(scratchpad, peeked);
        }
        stack = pop(stack);
    }

    stack = create0();
    int number_of_zeroes = 4 - length(scratchpad);
    while(number_of_zeroes > 0) {
        stack = push(stack, 0);
        number_of_zeroes--;
    }

    while(is_empty(scratchpad) == magic_not_empty) {
        int peeked = peek(scratchpad);
        stack = push(stack, peek(scratchpad));
        scratchpad = pop(scratchpad);
    }

    return stack;
}

/*
void test_case_swipe(int val1, int val2, int val3, int val4, int val5, int val6, int val7, int val8) {

    struct stack_int4 test1 = create(val1, val2, val3, val4);
    if(is_equal(swipe(test1), val5, val6, val7, val8) == magic_not_equal) {
        printf("case failed!");
    }
    print_stack(test1);
    print_stack(swipe(test1));
    printf("--------------\n");

}

void test_swipe() {

    test_case_swipe(4, 0, 0, 4, 0, 0, 0, 8);
    test_case_swipe(0, 4, 0, 4, 0, 0, 0, 8);
    test_case_swipe(4, 4, 4, 4, 0, 0, 8, 8);
    test_case_swipe(0, 0, 8, 8, 0, 0, 0, 16);
    test_case_swipe(4, 0, 4, 0, 0, 0, 0, 8);
    test_case_swipe(4, 4, 0, 0, 0, 0, 0, 8);
    test_case_swipe(2, 4, 8, 16, 2, 4, 8, 16);
    test_case_swipe(2, 2, 4, 4, 0, 0, 4, 8);
    test_case_swipe(2, 0, 4, 8, 0, 2, 4, 8);
    return;
}

*/

struct stack_int4 reverse(struct stack_int4 stack) {
    struct stack_int4 scratchpad;
    scratchpad = create0();
    while(is_empty(stack) == magic_not_empty) {
        int peeked = peek(stack);
        stack = pop(stack);
        scratchpad = push(scratchpad, peeked);
    }
    return scratchpad;
}

Stack16 join_from_left(struct stack_int4 first, struct stack_int4 second, struct stack_int4 third, struct stack_int4 fourth) {

    Stack16 join_result;
    join_result = create16();

    int value = magic_invalid;

    while(is_empty(first) == magic_not_empty) {
        value = peek(first);
        first = pop(first);
        join_result = push16(join_result, value);
    }

    while(is_empty(second) == magic_not_empty) {
        value = peek(second);
        second = pop(second);
        join_result = push16(join_result, value);
    }

    while(is_empty(third) == magic_not_empty) {
        value = peek(third);
        third = pop(third);
        join_result = push16(join_result, value);
    }

    while(is_empty(fourth) == magic_not_empty) {
        value = peek(fourth);
        fourth = pop(fourth);
        join_result = push16(join_result, value);
    }

    return join_result;
}

Stack16 join_from_right(struct stack_int4 first, struct stack_int4 second, struct stack_int4 third, struct stack_int4 fourth) {
    return join_from_left(reverse(first), reverse(second), reverse(third), reverse(fourth));
}

Stack16 join_from_up(struct stack_int4 first, struct stack_int4 second, struct stack_int4 third, struct stack_int4 fourth) {

    Stack16 join_result;
    join_result = create16();

    int value = magic_invalid;

    while(is_empty(fourth) == magic_not_empty) {
        value = peek(first);
        first = pop(first);
        join_result = push16(join_result, value);

        value = peek(second);
        second = pop(second);
        join_result = push16(join_result, value);

        value = peek(third);
        third = pop(third);
        join_result = push16(join_result, value);

        value = peek(fourth);
        fourth = pop(fourth);
        join_result = push16(join_result, value);
    }

    return join_result;
}

Stack16 join_from_down(struct stack_int4 first, struct stack_int4 second, struct stack_int4 third, struct stack_int4 fourth) {
    return join_from_up(reverse(first), reverse(second), reverse(third), reverse(fourth));
}

typedef struct {
    struct stack_int4 first;
    struct stack_int4 second;
    struct stack_int4 third;
    struct stack_int4 fourth;
} x4stack_int4;

x4stack_int4 split_to_left(Stack16 stack) {
    x4stack_int4 split_result;
    split_result.first = create0();
    split_result.second = create0();
    split_result.third = create0();
    split_result.fourth = create0();

    int value = magic_invalid;

    for(int i = 0; i <= 3; i++) {
        value = peek16(stack);
        stack = pop16(stack);
        split_result.fourth = push(split_result.fourth, value);
    }

    for(int i = 0; i <= 3; i++) {
        value = peek16(stack);
        stack = pop16(stack);
        split_result.third = push(split_result.third, value);
    }

    for(int i = 0; i <= 3; i++) {
        value = peek16(stack);
        stack = pop16(stack);
        split_result.second = push(split_result.second, value);
    }

    for(int i = 0; i <= 3; i++) {
        value = peek16(stack);
        stack = pop16(stack);
        split_result.first = push(split_result.first, value);
    }

    return split_result;

}

x4stack_int4 split_to_right(Stack16 stack) {
    x4stack_int4 split_result = split_to_left(stack);
    split_result.first = reverse(split_result.first);
    split_result.second = reverse(split_result.second);
    split_result.third = reverse(split_result.third);
    split_result.fourth = reverse(split_result.fourth);

    return split_result;
}

x4stack_int4 split_to_up(Stack16 stack) {
    x4stack_int4 split_result;
    split_result.first = create0();
    split_result.second = create0();
    split_result.third = create0();
    split_result.fourth = create0();

    int value = magic_invalid;

    while(is_empty16(stack) == magic_not_empty) {
        value = peek16(stack);
        stack = pop16(stack);
        split_result.fourth = push(split_result.fourth, value);

        value = peek16(stack);
        stack = pop16(stack);
        split_result.third = push(split_result.third, value);

        value = peek16(stack);
        stack = pop16(stack);
        split_result.second = push(split_result.second, value);

        value = peek16(stack);
        stack = pop16(stack);
        split_result.first = push(split_result.first, value);

    }

    return split_result;
}

x4stack_int4 split_to_down(Stack16 stack) {
    x4stack_int4 split_result = split_to_up(stack);
    split_result.first = reverse(split_result.first);
    split_result.second = reverse(split_result.second);
    split_result.third = reverse(split_result.third);
    split_result.fourth = reverse(split_result.fourth);

    return split_result;
}

Stack16 rng(Stack16 stack) {
    Stack16 mirror_stack = create16();
    if(check_full(stack) == magic_game_loss)
        return stack;
    int zero_count = 0;
    int tof = rand() % 100;
    while(is_empty16(stack) == magic_not_empty) {
        int peeked = peek16(stack);
        if(peeked == 0)
        {
            zero_count++;
        }
        stack = pop16(stack);
        mirror_stack = push16(mirror_stack, peeked);
    }
    int rn_position = 0;
    rn_position = choose_random(zero_count);
    //printf("\nrn ---> %d\n", rn_position);
    while(is_empty16(mirror_stack) == magic_not_empty) {
        int peeked = peek16(mirror_stack);
        if(peeked == 0)
        {
            if(rn_position == 0)
            {
                if(tof < 95)
                    peeked = 2;
                else
                    peeked = 4;
            }
            rn_position--;
        }
        mirror_stack = pop16(mirror_stack);
        stack = push16(stack, peeked);
    }
    return stack;
}

void display_grid(Stack16 stack) {
    x4stack_int4 grid = split_to_right(stack);

    printf("\n\t\t\t\t\t\t\t\t\t\t\t");
    print_stack(grid.first);
    printf("|\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t|_______|_______|_______|_______|");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t|       |       |       |       |");

    printf("\n\t\t\t\t\t\t\t\t\t\t\t");
    print_stack(grid.second);
    printf("|\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t|_______|_______|_______|_______|");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t|       |       |       |       |");

    printf("\n\t\t\t\t\t\t\t\t\t\t\t");
    print_stack(grid.third);
    printf("|\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t|_______|_______|_______|_______|");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t|       |       |       |       |");

    printf("\n\t\t\t\t\t\t\t\t\t\t\t");
    print_stack(grid.fourth);
    printf("|\n");
}



Stack16 swipe_down(Stack16 stack, int* add_score) {
    bool res;
    x4stack_int4 splits = split_to_down(stack);
    stack = join_from_down(swipe(splits.first, add_score), swipe(splits.second, add_score), swipe(splits.third, add_score), swipe(splits.fourth, add_score));
    x4stack_int4 splits2 = split_to_down(stack);
    res = cmp(splits.first, splits2.first, splits.second, splits2.second, splits.third, splits2.third, splits.fourth, splits2.fourth);
    if(res == false)
    {
        stack = rng(stack);
        return stack;
    }
    else
        return stack;
}

Stack16 swipe_up(Stack16 stack, int* add_score) {
    bool res;
    x4stack_int4 splits = split_to_up(stack);
    stack = join_from_up(swipe(splits.first, add_score), swipe(splits.second, add_score), swipe(splits.third, add_score), swipe(splits.fourth, add_score));
    x4stack_int4 splits2 = split_to_up(stack);
    res = cmp(splits.first, splits2.first, splits.second, splits2.second, splits.third, splits2.third, splits.fourth, splits2.fourth);
    if(res == false)
    {
        stack = rng(stack);
        return stack;
    }
    else
        return stack;
}

Stack16 swipe_left(Stack16 stack, int* add_score) {
    bool res;
    x4stack_int4 splits = split_to_left(stack);
    stack = join_from_left(swipe(splits.first, add_score), swipe(splits.second, add_score), swipe(splits.third, add_score), swipe(splits.fourth, add_score));
    x4stack_int4 splits2 = split_to_left(stack);
    res = cmp(splits.first, splits2.first, splits.second, splits2.second, splits.third, splits2.third, splits.fourth, splits2.fourth);
    if(res == false)
    {
        stack = rng(stack);
        return stack;
    }
    else
        return stack;
}

Stack16 swipe_right(Stack16 stack, int* add_score) {
    bool res;
    x4stack_int4 splits = split_to_right(stack);
    stack = join_from_right(swipe(splits.first, add_score), swipe(splits.second, add_score), swipe(splits.third, add_score), swipe(splits.fourth, add_score));
    x4stack_int4 splits2 = split_to_right(stack);
    res = cmp(splits.first, splits2.first, splits.second, splits2.second, splits.third, splits2.third, splits.fourth, splits2.fourth);
    if(res == false)
    {
        stack = rng(stack);
        return stack;
    }
    else
        return stack;
}

Game initialize() {
    Game game;
    game.matrix = rng(rng(fill_zeroes()));
    game.state = magic_game_current;
    game.score = 0;
    return game;
}

void display(Game game) {
    /*system("cls");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t        222222                    00000                    4444444444           888888888       \n");
    printf("\t\t\t\t\t\t\t      2222222222                000000000                 44444444444         8888888888888     \n");
    printf("\t\t\t\t\t\t\t    22222222222222            0000  000000               44444 444444       88888     8888888   \n");
    printf("\t\t\t\t\t\t\t 222222      222222         0000      000000            44444  444444      88888       8888888  \n");
    printf("\t\t\t\t\t\t\t 22222         222222      0000        000000          44444   444444      88888       8888888  \n");
    printf("\t\t\t\t\t\t\t                222222    0000          000000        44444    444444       88888     8888888   \n");
    printf("\t\t\t\t\t\t\t                 222222  0000            000000      44444     444444         888888888888      \n");
    printf("\t\t\t\t\t\t\t                222222   0000            000000     44444      444444          8888888888       \n");
    printf("\t\t\t\t\t\t\t               222222    0000            000000    44444       444444         888888888888      \n");
    printf("\t\t\t\t\t\t\t             222222       0000          000000    44444        444444       88888     8888888   \n");
    printf("\t\t\t\t\t\t\t          2222222          0000        000000    444444444444444444444444  88888       8888888  \n");
    printf("\t\t\t\t\t\t\t       222222               0000      000000     444444444444444444444444  88888       8888888  \n");
    printf("\t\t\t\t\t\t\t    222222                    0000  000000       444444444444444444444444   88888     8888888   \n");
    printf("\t\t\t\t\t\t\t 2222222222222222222222         000000000                      444444         8888888888888     \n");
    printf("\t\t\t\t\t\t\t 2222222222222222222222           00000                        444444           888888888       \n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
    */printf("\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t                       Your score is: %d\n", game.score);
    printf("\t\t\t\t\t\t\t\t\t\t\t ________________________________\n\t\t\t\t\t\t\t\t\t\t\t|       |       |       |       |");
    display_grid(game.matrix);
    printf("\t\t\t\t\t\t\t\t\t\t\t|_______|_______|_______|_______|");
    printf("\n\n\n");

}

int check_win(Stack16 stack)
{
    while(is_empty16(stack) == magic_not_empty)
    {
        int peeked = peek16(stack);
        if(peeked == 2048)
            return magic_game_won;
        stack = pop16(stack);
    }
    return magic_game_current;
}

int check_full(Stack16 stack)
{
    while(is_empty16(stack) == magic_not_empty)
    {
        int peeked = peek16(stack);
        if(peeked == 0)
            return magic_game_current;
        stack = pop16(stack);
    }
    return magic_game_loss;
}

int check(Game game) {
    if(check_win(game.matrix) == magic_game_won)
        return magic_game_won;
    else if((check_full(game.matrix) == magic_game_loss) && (check_game_next(game) == magic_game_loss))
        return magic_game_loss;
    return magic_game_current;
    //Check for win/lose
}

int get_input() {
    //List options
    //Scanf choice
    //Return magic_choice
    char input;
    input = getch();

    switch (input)
    {
    case 'w'://72
    return magic_input_sup;

    case 'a'://75
    return magic_input_sleft;

    case 's'://80
    return magic_input_sdown;

    case 'd'://77
    return magic_input_sright;

    case 'r':
    return magic_input_restart;

    case 'q':
    return magic_input_quit;

    case 72:
    return magic_input_sup;

    case 75:
    return magic_input_sleft;

    case 80:
    return magic_input_sdown;

    case 77:
    return magic_input_sright;

    default:
    return get_input();
    }
}

Game do_input(Game game, int input) {
    //if swipe, swipe direction
    //return game;
    int add_score = 0;

    if(input == magic_input_sup)
        game.matrix = swipe_up(game.matrix, &add_score);

    else if(input == magic_input_sdown)
        game.matrix = swipe_down(game.matrix, &add_score);

    else if(input == magic_input_sleft)
        game.matrix = swipe_left(game.matrix, &add_score);

    else if(input == magic_input_sright)
        game.matrix = swipe_right(game.matrix, &add_score);

    else if(input == magic_input_quit)
        game.state = magic_input_quit;

    else if(input == magic_input_restart)
        game.state = magic_input_restart;

    game.score += add_score;

    return game;
}

int game_loop(int *score) {
    Game game = initialize();
    while(check(game) == magic_game_current) {
        display(game);
        game = do_input(game, get_input());
        if(game.state == magic_input_quit)
        {
            *score = game.score;
            return magic_input_quit;
        }
        else if(game.state == magic_input_restart)
        {
            *score = game.score;
            return magic_input_restart;
        }
        game.state = check(game);
        if(game.state == magic_game_won)
        {
            *score = game.score;
            display(game);
            return magic_game_won;
        }
        else if(game.state == magic_game_loss)
        {
            *score = game.score;
            display(game);
            return magic_game_loss;
        }
    }
    display(game);
}

bool game_compare(Game game1, Game game2)
{
    while(is_empty16(game1.matrix) == magic_not_empty)
    {
     int peeked = peek16(game1.matrix);
     int peeked2 = peek16(game2.matrix);
    if(peeked != peeked2)
        return false;
    else
    {
        game1.matrix = pop16(game1.matrix);
        game2.matrix = pop16(game2.matrix);
    }
    }
    return true;
}

int check_game_next(Game game){
    Game game1, game2, game3, game4;
    if(check_full(game.matrix) == magic_game_loss)
    {
        game1 = do_input(game, magic_input_sup);
        game2 = do_input(game, magic_input_sdown);
        game3 = do_input(game, magic_input_sleft);
        game4 = do_input(game, magic_input_sright);
    if((game_compare(game, game1)) && (game_compare(game, game2)) && (game_compare(game, game3)) && (game_compare(game, game4)))
        {
            return magic_game_loss;
        }
    }
    else
        return magic_game_current;
    }


int main() {
    // Write C code here
    //test_swipe();
    time_t t;
    srand((unsigned) time(&t));
    int high_score = 0;
    int score = 0;
    while(true){
    int a = game_loop(&score);
    if(score > high_score)
        high_score = score;
    if(a == magic_input_restart)
        continue;
    else if(a == magic_input_quit) {
        printf("\t\t\t\t\t\t\t\t\t\t\t\tYour high score is: %d\n", high_score);
        break;
    }
    else if(a == magic_game_loss)
        {
            char input;
            printf("%s", "\t\t\t\t\t\t\t\t\t\t\t\t     You Lost!\n\t\t\t\t\t\t\t\t\t\t\tWould you like to try again? (y/n) ");
            input = getch();
            if(input == 'y')
                continue;
            else if(input == 'n')
                break;
            else
                break;
        }
    else if(a == magic_game_won)
        {
            char input;
            printf("\t\t\t\t\t\t\t\t\t\t\t\t     You Win!\n\t\t\t\t\t\t\t\t\t\tYour score is: %d. Would you like to try again? (y/n) ", score);
            input = getch();
            if(input == 'y')
                continue;
            else if(input == 'n')
                break;
            else
                break;
        }
    }
    /*Game game = initialize();
    display(game);
    printf("<------>\n");
    game.matrix = swipe_left(game.matrix);
    display_grid(game.matrix);
    printf("<------>\n");
    game.matrix = swipe_up(game.matrix);
    display_grid(game.matrix);
    printf("<------>\n");
    game.matrix = swipe_down(game.matrix);
    display_grid(game.matrix);
    //display_grid(fill_zeroes());
    /*display_grid(join_from_right(
                create(0,  3,   0,  10),
                create(0,  0,   0,  13),
                create(0,  0,  10,  14),
                create(0,  0,   0,  15)));

    print_stack16(stak);

    print_stack16(rng(stak));
    */


    /*
    x4stack_int4 test2 = split_to_down(join_from_down(
                create(0,  4,   8,  12),
                create(1,  5,   9,  13),
                create(2,  6,  10,  14),
                create(3,  7,  11,  15)));

    print_stack(test2.first);
    print_stack(test2.second);
    print_stack(test2.third);
    print_stack(test2.fourth);
    */

    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t   %s\n", "End program!");
    return 0;
}
