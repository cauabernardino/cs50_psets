SELECT m.title as 'title', r.rating as 'rating'
FROM movies m JOIN ratings r ON m.id = r.movie_id 
WHERE m.year = 2010
ORDER BY rating DESC, title;