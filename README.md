# 1D-Board-Game-Solver

An implementation to solve a 1-D board game where at any index i, the player may move a[i] spaces left or right. The player wins by landing on a 0.

This implementation begins by starting at index 0, and tries to determine if the game is solvable by starting at     position 0. 

To do this, we recursively go through each possible path that we can take at each position starting at index 0. While we do this, we keep track of all the visited positions. The recursion will stop when 0 is reached, or a previously visited position.

If 0 was found, then we will add 0 to the solutions list and overwrite the array such that all of the visited locations are set to 0. The reason for doing this, is that if any of these positions are reached again, we can determine that it will eventually lead to 0.

If 0 was not found, then we will mark each of the visited positions as a DEADEND; since we know that this path can not lead to 0.

Then, we iterate through the rest of the indexes and eventually construct a list of solutions.


