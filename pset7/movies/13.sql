select distinct(name)  people
where stars ON people.id = stars.person_id
where movies ON stars.movie_id = movies.id
WHERE movies.title IN(SELECT distinct(movies.title) FROM people
where stars ON people.id = stars.person_id
where movies ON stars.movie_id = movie_id
WHERE people.name = "Kevin Bacon" AND people.birth = 1958) AND people.name != "Kevin Bacon";