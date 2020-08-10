WITH bacon_movies AS (
SELECT movies.id, movies.title, people.name
FROM ((people JOIN stars ON people.id = stars.person_id)
JOIN movies ON stars.movie_id = movies.id)
WHERE people.name = 'Kevin Bacon' AND people.birth = 1958
ORDER BY movies.title
)
SELECT DISTINCT people.name
FROM ((people JOIN stars ON people.id = stars.person_id)
JOIN bacon_movies ON stars.movie_id = bacon_movies.id)
WHERE NOT people.name = 'Kevin Bacon';