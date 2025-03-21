Push Swap Current:

For lists > 5 % < 500:
- First 2 integers are pushed to stack B
- Stack b is sorted in descending order
- While stack a > 3:
  - Find the best integer to push to stack B
    - `initialise_nodes_a`
	  - `current_index` - iterate through stacks  setting the index of each node and `above_median` flag to true/false depending on if the node is above the median
	  - `set_target` - set the target value for each node
	    - for each node in `a` iterate through `b` checking if current `b` value is less than the current `a` value and the index of `b` is greater than the target index. If true set `target_index` to value of `current_b` and `target_node` to `current_b`
		- if `target_index` is not set, set `target_index` to the biggest value in `b`
	  - `calculate_cost` - calculate the cost of pushing the node to stack B. Cost is set depending on position of the node in the stack.
	    - Iterate through stack `a`, `cost` is set to `index`.
		- if `above_median` is false, `cost` is set to `len_a - index`
		- if `a->target->above_median` is true, `cost` is set to `cost` + `a->target->index`
		- else `cost` is set to `cost` + `len_b - a->target->index`
	  - `set_lowest_cost` iterate through stack `a` and set the `lowest_cost` flag to `true` on node with the lowest cost
  - Push the integer to stack B
    - `get_lc_node` returns the node with the lowest cost
	  - if `lc_node->above_median` and `lc_node->target>above_median` is true, `rotate_stacks` is called
	    - the stacks are "re-indexed" with calls to `current_index`
	  - else if `!(lc_node->above_median)` & `!(lc_node->target->above_median)`
	    - rev_rotate_stacks
	- `push_prep` - prepare the stacks for pushing to stack `b`. Passes stack to work on and the top node, which is the lowest cost node
	- `pb`!! PUSH TO STACK B
- Stack `a` now has 3 integersm so `sort_small` is called
- Iterate through stack `b`
  - `initialise_nodes_b`
	- `current_index` - iterate through stacks  setting the index of each node and `above_median` flag to true/false depending on if the node is above the median
	- `set_target` - set the target value for each node
	  - for each node in `b` iterate through `a` checking if current `a` value is greater than the current `b` value and less than the target index. If true set `target_index` to value of `current_a` and `target_node` to `current_a`
		- if `target_index` is not set, set `target_index` to the smallest value in `a`
	- `push_b_to_a`
	  - `push_prep` prepare stack `a` by rotating until the target node is at the top
	  - `pa`!! PUSH TO STACK A
- `min_to_top` - rotate stack `a` until the smallest value is at the top
	while stack a value is not the result of `find_min`
	  - if `find_min` above_median
	    - `ra`!! ROTATE STACK A
	  - else
	    - `rra`!! REVERSE ROTATE STACK A

---

Chunking:

For up to 100 integers:
- MIN = 0, MAX = 99
- MEDIAN = 49
- Working in 'chunks', divide the list into 5 'chunks' of 20 integers:
  - 0 - 19, 20 - 39, 40 - 59, 60 - 79, 80 - 99
- For each chunk:
  - Move through the stack from the top to find the first iteration of a value from the chunk
  - Move from the bottom of the stack to find a value from the chunk
  - Calculate the number of moves to push the value to the top of the stack
    - if the value is above the median, the cost is the index
	- if the value is below the median, the cost is the length of the stack minus the index
  - Check if value is greater than value in stack `b`
	- if true, `pb`


1 2 3 4 5
 3: i - 2
 len- 5

 5 - 2 = 3

- For each chunk:
  - Find the median value
  - Push the median value to stack B
  - Push the remaining values to stack A
