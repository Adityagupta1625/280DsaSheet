// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Brute Force:
// Take two loops check if they sum to given target.

// Map Solution:
// Take map of intialise with i. Now traverse and check if index is equal or not and equal to target-nums[i].

// optimised Solution:
// Sort the array and use two pointer apporach.