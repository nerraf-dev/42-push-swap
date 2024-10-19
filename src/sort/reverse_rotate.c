#include "../../includes/push_swap.h"

static void reverse_rotate(t_stack_node **stack) {
    t_stack_node *last;
    t_stack_node *second_last;

    if (!stack || !*stack || !(*stack)->next) {
        return;
    }

    last = get_last_node(*stack);
    second_last = last->prev;

    // Debug prints to trace the state before rotation
    ft_printf("Before Reverse Rotate:\n");
    print_stack(*stack);

    if (second_last) {
        second_last->next = NULL;
    }
    last->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;

    // Debug prints to trace the state after rotation
    ft_printf("After Reverse Rotate:\n");
    print_stack(*stack);
}

void rra(t_stack_node **stack) {
    reverse_rotate(stack);
    ft_printf("rra\n");
    // Debug print to trace the state of stack A after rra
    ft_printf("Stack A after rra:\n");
    print_stack(*stack);
}

void rrb(t_stack_node **stack) {
    reverse_rotate(stack);
    ft_printf("rrb\n");
    // Debug print to trace the state of stack B after rrb
    ft_printf("Stack B after rrb:\n");
    print_stack(*stack);
}

void rrr(t_stack_node **stack_a, t_stack_node **stack_b) {
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    ft_printf("rrr\n");
    // Debug prints to trace the state of both stacks after rrr
    ft_printf("Stack A after rrr:\n");
    print_stack(*stack_a);
    ft_printf("Stack B after rrr:\n");
    print_stack(*stack_b);
}
