SELECT firstName, lastName, city, state
FROM person LEFT JOIN address 
ON person.personid = address.personid