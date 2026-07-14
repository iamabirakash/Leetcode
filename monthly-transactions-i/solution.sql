SELECT 
    SUBSTR(trans_date, 1, 7) AS month,  -- '2018-12-18' → '2018-12'
    country,
    COUNT(id) AS trans_count,
    SUM(state = 'approved') AS approved_count,
    SUM(amount) AS trans_total_amount,
    SUM(IF(state = 'approved', amount, 0)) AS approved_total_amount
FROM Transactions
GROUP BY month, country;
-- SELECT 
--     DATE_FORMAT(trans_date, '%Y-%m') AS month,
--     country,
--     COUNT(id) AS trans_count,
--     SUM(state = 'approved') AS approved_count,  -- MySQL treats boolean as 0/1
--     SUM(amount) AS trans_total_amount,
--     SUM(IF(state = 'approved', amount, 0)) AS approved_total_amount
-- FROM Transactions
-- GROUP BY month, country;