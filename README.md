BaconExperiment
===============

Experimenting with MySQL database and trying to implement own version of Kevin Bacon Problem using C and Python.

3/6/14
Currently the working files are imdb.c and imdbrev.c

They can be run by compiling with the following flags:
gcc imdb.c -o imdb  `mysql_config --cflags --libs` -std=c99
gcc imdbrev.c -o imdbrev  `mysql_config --cflags --libs` -std=c99

The first program prompts the user for an actor's name then returns the movies associated with the actor in the imdb database (which can be located here: http://www.imdb.com/interfaces)

The second program prompts the user for a movie's title then returns the actors associated with the movie title in the imdb database. 