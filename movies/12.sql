WITH depp_movies AS (
SELECT movies.id, movies.title, people.name
FROM ((people JOIN stars ON people.id = stars.person_id)
JOIN movies ON stars.movie_id = movies.id)
WHERE people.name = 'Johnny Depp'
ORDER BY movies.title
),
carter_movies AS (
SELECT movies.id, movies.title, people.name
FROM ((people JOIN stars ON people.id = stars.person_id)
JOIN movies ON stars.movie_id = movies.id)
WHERE people.name = 'Helena Bonham Carter'
ORDER BY movies.title
)
SELECT depp_movies.title
FROM depp_movies JOIN carter_movies ON depp_movies.id = carter_movies.id;

