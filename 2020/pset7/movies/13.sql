SELECT DISTINCT name FROM movies
JOIN stars on movies.id = stars.movie_id
JOIN people on stars.person_id = people.id
WHERE name != "Kevin Bacon" AND movies.id IN
(SELECT movies.id FROM movies
JOIN stars on movies.id = stars.movie_id
JOIN people on stars.person_id = people.id
WHERE name = "Kevin Bacon" AND birth = 1958);