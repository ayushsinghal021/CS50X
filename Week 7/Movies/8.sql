SELECT name FROM people JOIN stars ON people.id = stars.person_id WHERE movie_id IN (SELECT id FROM movies WHERE title = 'Toy Story');
