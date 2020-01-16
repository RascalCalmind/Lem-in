# lem-in (#42network)

Lem-in is an elemantary algorithmic project that is meant to make you code an ant farm manager.

---

- [lem-in (#42network)](#lem-in-42network)
  - [The Project](#The-Project)
    - [Mandetory Part](#Mandetory-Part)
    - [Bonus Part](#Bonus-Part)
  - [Algorithms](#Algorithms)
    - [Breath First Search](#Breath-First-Search)
    - [Edmonds Karp](#Edmonds-Karp)
    - [A* Search](#A-Search)
    - [Terms](#Terms)
  - [Concepts](#Concepts)
    - [Hash Tables](#Hash-Tables)
  - [Project Description](#Project-Description)

## The Project

The goal of this project is to find the quickest way to get *n* ants across the farm.

Quickest way means the solution with the least number of lines (*edges*), respecting the output format requested.

To be the first to arrive, ants will need to take the shortest path (and that isn’t necessarily the simplest). They will also need to avoid traffic jams as well as walking all over their fellow ants.

### Mandetory Part

- At the beginning of the game, all the ants are in the room ##start. The goal is to bring them to the room ##end with as few turns as possible. Each room can only contain one ant at a time.
  - (except at ##start and ##end which can contain as many ants as necessary.)
- We consider that all the ants are in the room ##start at the beginning of the game.
- At each turn you will only display the ants that moved.
- At each turn you can move each ant only once and through a tube (the room at the receiving end must be empty).
- You must to display your results on the standard output in the following format:

```
number_of_ants
the_rooms
the_links
Lx-y Lz-w Lr-o ...
```
*x, z, r represents the ants’ numbers (going from 1 to number_of_ants) and y,
w, o represents the rooms’ names.*

### Bonus Part

We're free to do our own bonusses, which will then be evaluated by the correctors according to their own taste. An example given is a ant farm vizualizer.

## Algorithms

These are the algorithms that we use within this project.

### Breath First Search

Traversing a graph using a queue.

1. Put first vertex to queue.
2. Explorer vertex (what are the connected nodes / vertexes)
3. Add those to the queue.
4. Mark vertex as explorered.
5. Select next item in queue.

### Edmonds Karp

Computes the maxiumum flow in a flow network.

// TODO: Figure out why useful, explain here.


### A* Search


### Terms
 - **Vertex**
   - "A vertex is a point where two or more curves, lines, or edges meet." - [Vertex](https://www.mathopenref.com/vertex.html)
   - Also can be called node
 - **Edge**
   - "The connections between the nodes"
 - **Flow Network**
   - "A directed graph in which each edge has a non-negative capacity." - [Flow Network](https://brilliant.org/wiki/flow-network/)
 - **(Undirected) Network**
   - Node / vertexies that are connected using edges, either with direction or without direction (undirected).
 - **Critical**
   - An *edge* can be ciritical if flow through an edge is equal to the maximum capacity.

## Concepts

The following coding concepts are being used. 

### Hash Tables


## Project Description

**Ants**\
The amount of ants is located at the top of the file.\
The ants cannot walk on top of one another (except in the start and end room).\
Ants will take the shortest path (this may not be the simpelest) and they avoid traffic jams.\
\
**Rooms**\
name coord_x coord_y\
name can contains any letter or number, but cannot start with an L or #\
Do coordinates only use positive integers? (check unsigned int max)\
\
**Commands**\
Lines that start with ##\
the only ones with an actual command will be:\
'##'start\
'##'end\
\
**Links**\
name1-name2\
\
**Comments**\
comments start with # and will be ignored\
\
**Output**\
number of ants.\
all the rooms\
all links\
\
path of each ant from start to end at every move written as so:\
L{ant number}-{room name}\
\
\
**Allowed functions**\
malloc\
free\
read\
write\
strerror\
perror\
exit\
\
\
**Goals**\
<2/3 == great, 9 == mediocre, 15+ == :(\


