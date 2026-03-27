-- 9. Names of all people who starred in a movie released in 2004, ordered by birth year
SELECT DISTINCT people.id, people.name
FROM stars
JOIN people ON stars.person_id = people.id
JOIN movies ON stars.movie_id = movies.id
WHERE movies.year = 2004
ORDER BY people.birth;
