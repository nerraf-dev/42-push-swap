
Whats happeing so far:

in `main.c` we have the following code:

```c
int	main(int argc, char **argv)
{
	int	*arr;
	int	*arr_start;

	if (argc <= 1)
		print_error_and_exit("No arguments provided", NULL);
	arr = parse_arguments(argc, argv);
	arr_start = arr;

	if (check_duplicates(arr, argc - 1))
		print_error_and_exit("Error: Duplicate number", arr);

	// Find the sorted solution
	sort_numbers(arr, argc - 1);
	free(arr_start);
	return (0);
}
```

This code is the entry point for the program. It checks if there are any arguments provided and if not, prints an error message and exits. It then parses the arguments in to an array of integers. It then checks for duplicates in the array and if found, prints an error message and exits. It then sorts the numbers and frees the memory allocated for the array. A set of static helper functions are used to achieve this.

`parse_arguments` is a function that takes the number of arguments and the arguments themselves and returns an array of integers. It uses `malloc` to allocate memory for the array and then uses `atoi` to convert the arguments to integers. It then returns the array.

`check_duplicates` is a function that takes an array of integers and the number of integers in the array and returns a boolean. It uses a nested loop to compare each element in the array with every other element. If it finds a duplicate, it returns true. If it doesn't find a duplicate, it returns false.

`print_error_and_exit` is a function that takes an error message and an array of integers and prints the error message and the array. It then frees the memory allocated for the array and exits the program.

`sort_numbers` is a function that takes an array of integers and the number of integers in the array and sorts the array. It gets a number of values required for completing the count sort by calling `get_props`.

```c
int	sort_numbers(int *arr, int length)
{
	int				*sorted_arr;
	t_node			*count;
	t_count_props	props;

	props = get_props(arr, length);
	ft_printf("Min: %d, Max: %d, Range: %d, Offset: %d\n", props.min, props.max, props.range, props.offset);
	count = create_linked_list(props.range);
	populate_count_list(arr, length, count, props.offset);

	print_linked_list(count);

	sorted_arr = (int *)malloc(length * sizeof(int));
	if (!sorted_arr)
	{
		ft_printf("Memory Allocation Failed");
		return (-1);
	}
	run_count_sort(sorted_arr, count, props.offset);
	compare_arrays(arr, sorted_arr, length);
	free_list(count);
	free(sorted_arr);

	return (0);
}
```

`get_props` takes an array of integers and the number of integers in the array and returns a struct containing the minimum, maximum, range and offset values. It uses a loop to find the minimum and maximum values in the array. It then calculates the range and offset values and returns a struct containing these values.

`count` is the result of the `create_linked_list` call. This should create a series of nodes with a pointer to the next. This should be sequential, enough nodes to fille the range, starting at 0.

`create_linked_list` takes an integer and returns a pointer to a linked list. It uses a loop to create a linked list of nodes with the number of nodes equal to the integer passed to it. It then returns a pointer to the head of the linked list. The integer passed is the `range` value so that enough nodes are created and is also used as the node value.

```c
t_node	*create_linked_list(int range)
{
	t_node	*head;
	t_node	*current;
	int		i;

	head = create_node(0);
	current = head;
	i = 1;
	while (i < range)
	{
		current->next = create_node(i);
		current = current->next;
		i++;
	}
	return (head);
}
```

`*create_node`
This function takes an integer and returns a pointer to a node. It uses `malloc` to allocate memory for the node and then assigns the value passed to it to the node. It then assigns 0 to the count of the node and `NULL` to the next pointer. It then returns a pointer to the node.
```c
t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->value = value;
	new_node->count = 0;
	new_node->next = NULL;
	return (new_node);
}
```

The `populate_count` funciton call should then populate the nodes with the relevant counts for the numbers.

```c
void	populate_count_list(int *arr, int length, t_node *head, int offset)
{
	int		i;
	int		index;
	t_node	*current;

	i = 0;
	while (i < length)
	{
		current = head;
		index = arr[i] + offset;
		while (index > 0)
		{
			current = current->next;
			index--;
		}
		current->count++;
		i++;
	}
}
```

`populate_count_list` is a function that takes an array of integers, the number of integers in the array, a pointer to the head of a linked list and an offset value. It uses a loop to iterate over the array and increment the count of the node at the index of the value in the array plus the offset value.

In the case of the initial array being [3 -1 2 1],
min: -1
max: 3
range:max - min + 1 = 3 - (-1) + 1 = 5
offset: 1

The range allows us to creatre a list with nodes to hold the numbers in the array. The ide is that the array value would be mapped to a node with a corresponding value, i.e. value of 1 its count would be stored in node value 1. But as we have negative numbers and we dont have negative indicies, we need to offset the value to ensure we can store the count in the correct node.

So for our array [3 -1 2 1], the count list should look like this:
index: count
```
0: 1 // -1
1: 0 // 0
2: 1 // 1
3: 1 // 2
4: 1 // 3
```


`run_count_sort` is a function that takes an array of integers, a pointer to the head of a linked list and an offset value. It uses a loop to iterate over the linked list and then over the count of each node. It then assigns the value of the node minus the offset value to the array and decrements the count of the node. This is done until the count of the node is 0.

```c
void	run_count_sort(int *sorted_arr, t_node *count, int offset)
{
	int		i;
	t_node	*current;

	i = 0;
	current = count;
	while (current != NULL)
	{
		while (current->count > 0)
		{
			sorted_arr[i++] = current->value - offset;
			current->count--;
		}
		current = current->next;
	}
}
```
The loop iterates over `sorted_arr` and assigns the value of the node minus the offset value to the array and decrements the count of the node. This is done until the count of the node is 0.
