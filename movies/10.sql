WITH dir_movies AS (
SELECT movies.id, people.name
FROM ((people JOIN directors ON people.id = directors.person_id)
JOIN movies ON directors.movie_id = movies.id)
)
SELECT DISTINCT dir_movies.name
FROM dir_movies JOIN ratings ON dir_movies.id = ratings.movie_id
WHERE ratings.rating >= 9.0;