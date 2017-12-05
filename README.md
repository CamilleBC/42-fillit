# 42-fillit

This is a project from 42 school.
The main goal is to fill the smallest square possible with tetris parts.

## Rules

* Tetris parts are fed on the standard input, as a grid of 4x4 with '.' and '#' chars
  Example:
  ..#.
  .##.
  .#..
* All tetris parts are made up of 4 '#' chars.
* Each char should have one of the four sides in contact with another char.
* The square should be filled with the parts in order.
  1. Smallest square possible
  2. The first parts in the top of the square.
  3. Then on the leftmost side.
  4. Each part will use a letter depending on its order when fed to the program.
      Example:
      AA.B
      ABBB
      CCCC
      
## Optimization

I have tried to solve this using backtracking. In order to optimize the backtracking, I have realized that the bottlenecks were the two operations of checking if the part can be placed on the map (mostly) and placing it.
I have resolved that in this way:
  1. I converted the strings I receive in a table of ints.
  2. My map is also a table of int.
  3. I offset my part with the right number of bits to have the bits were I need to check
  4. I make a binary AND with the map. It will return 1 if anywhere I want to place my part (1) is aligned with a filled map (1).
  5. When I want to place the part, I do the same with a bitwise XOR. This allows me to place a part (1) when the map is empty, and to remove the part (1^1=0) when I want to.
  6. Then I convert back the number into strings when I want to display the map on the screen.
