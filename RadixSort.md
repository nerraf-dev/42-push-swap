# Radix Sort:

```c
void	sort_radix(t_stack_node **stack_a, t_stack_node **stack_b, int len)
{
	int		max_num;
	int		max_bits;
	int		i;
	int		j;

	max_num = len - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < len)
		{
			if ((((*stack_a)->value >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
```

Count the maximum number of bits needed to represent the maximum number in the stack:
```c
while ((max_num >> max_bits) != 0)
		max_bits++;
```

Then, iterate through the bits, shifting the number to the right by the bit number and checking if the bit is 1 or 0.

We enter the outer loop for each bit, and the inner loop for each number in the stack. The iterator `i` is the bit number, and the iterator `j` is the number in the stack.
```c
// Start checking with bit 0 (lsb) I is used in inner loop for the number of bits in the binary shift.
i = 0;
	while (i < max_bits)
	{

		j = 0;
		while (j < len)
		{
			// Perform the shift and binary & operation to check if the bit is 1 or 0.
			if ((((*stack_a)->value >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
```


```c

```
