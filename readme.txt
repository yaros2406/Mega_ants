~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                                Lem-in
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Authors: lkuhic and bshaquan.

This algo project is about designing and implementing an algorithm to solve a special case of the maximum flow problem in the graph theory.
The goal is to find the optimal flow of ants through an anthill that minimizes the number of rounds needed to traverse the anthill.
An anthill is described as a network composed of 'rooms' (graph nodes) and 'tunnels' (edges) linking the rooms together, with all ants starting and finishing at two precise rooms.
The real trouble begins when each room can welcome only one ant at a time (except for the start and end rooms).
A round ends when no more ants are able to start or move any further in the anthill.

## Algorithm ##

Modified Edmonds-Karp with BFS searching for paths minimizing the lines of output. :)

## Usage ##

A map with a precise format is sent to the `lem-in` program as `stdin` input:

./lem-in [-h --help] [-a --anthill] [-p --paths] [-v --visual] < maps/demo_map

## Map format ##

5		 << ants number
##start		 << start room is following
r0 1 2
r1 2 3
r2 3 4
r3 4 5
r4 3 5
r5 6 7
r6 8 9
r7 7 9
##end		<< end room is following
r8 90 1
r0-r1		<< tunnels
r1-r2
r2-r8
r0-r6
#comment	<< optional comments at any line
r6-r7
r1-r6
r1-r4
r4-r8
r0-r3
r3-r2
r2-r5
r5-r8
```
Many more examples are provided in the `/maps` repository.

## Options ##

* -h --help : Display usage.
* -a --anthill : Display the anthill rooms and tunnels.
* -p --paths : Display the paths found by the algorithm.
* -v --visual : Display the visual in a new Google Chrome tab.

## Output ##

The output of the program is divided in two parts:
* the file read from `stdin`.
* one line per round (output to minimize). It represents the movements of ants with the format `LX-Y` (`X`is the ant's number and `Y` is the room's name).

### Example ###
```
5
##start
r0 1 2
r1 2 3
r2 3 4
r3 4 5
r4 3 5
r5 6 7
r6 8 9
r7 7 9
##end
r8 90 1
r0-r1
r1-r2
r2-r8
r0-r6
r6-r7
r1-r6
r1-r4
r4-r8
r0-r3
r3-r2
r2-r5
r5-r8

L1-r3 L2-r1				<< round 0
L1-r2 L2-r4 L3-r3 L4-r1			<< round 1
L1-r8 L2-r8 L3-r2 L4-r4 L5-r3		<< round 2
L3-r8 L4-r8 L5-r2			<< round 3
L5-r8					<< round 4
```

Cool tester and map generator are included.