#   LEM_IN
\
File representation:\
\
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
**Comments**
comments start with # and will be ignored\
\
Output:\
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
