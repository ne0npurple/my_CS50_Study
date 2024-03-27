-- SELECT title
SELECT title FROM shows ORDER BY title ASC;

-- Update title
UPDATE shows SET title = 'Game of Thrones' WHERE title LIKE '%game of thrones' or title LIKE 'GoT';