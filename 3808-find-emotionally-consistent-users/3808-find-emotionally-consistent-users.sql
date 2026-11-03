WITH cnt AS (
    SELECT user_id, reaction, COUNT(*) AS c
    FROM reactions
    GROUP BY user_id, reaction
),
stats AS (
    SELECT user_id, MAX(c) AS mx, SUM(c) AS total
    FROM cnt
    GROUP BY user_id
    HAVING SUM(c) >= 5
       AND MAX(c) * 1.0 / SUM(c) >= 0.6
)
SELECT c.user_id, c.reaction AS dominant_reaction,
       ROUND(s.mx * 1.0 / s.total, 2) AS reaction_ratio
FROM cnt c
JOIN stats s ON c.user_id = s.user_id AND c.c = s.mx
ORDER BY reaction_ratio DESC, c.user_id;