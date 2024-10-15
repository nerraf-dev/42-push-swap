#Randomly generating 4 digit codes from 0000 - 9999

import random   #Import the random modules

i = 0
nums = list(range(1, 501))
random.shuffle(nums)


cmd = "leaks -atExit -- ./push_swap "
while (i < len(nums)):
  cmd = cmd + str(nums[i]) + " "
  i+=1

print(cmd)
