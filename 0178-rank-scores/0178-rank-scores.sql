# Write your MySQL query statement below
SELECT Score AS Score,
DENSE_RANK() OVER (ORDER BY Score DESC) AS "Rank"
FROM Scores; 