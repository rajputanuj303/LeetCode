
SELECT r.contest_id, ROUND(100 * COUNT(u.user_id) / (SELECT COUNT(*) FROM Users), 2) percentage
FROM Register r
LEFT JOIN Users u
ON r.user_id = u.user_id
GROUP BY r.contest_id
ORDER BY percentage DESC, contest_id ASC;