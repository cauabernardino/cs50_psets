WITH star_movies AS (
SELECT movies.id, movies.title, people.name
FROM ((people JOIN stars ON people.id = stars.person_id)
JOIN movies ON stars.movie_id = movies.id)
WHERE people.name = 'Chadwick Boseman'
ORDER BY movies.year DESC
)
SELECT star_movies.title
FROM star_movies JOIN ratings ON star_movies.id = ratings.movie_id
ORDER BY rating DESC
LIMIT 5;