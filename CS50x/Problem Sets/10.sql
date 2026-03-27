-- 10. Names of all directors who have directed a movie that got a rating of at least 9.0
SELECT DISTINCT people.name
FROM directors
JOIN people ON directors.person_id = people.id
JOIN ratings ON directors.movie_id = ratings.movie_id
WHERE ratings.rating >= 9.0;
