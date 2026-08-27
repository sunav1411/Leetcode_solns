# Write your MySQL query statement below
SELECT ROUND(sum(tiv_2016),2) AS tiv_2016
FROM(
SELECT pid,tiv_2015,tiv_2016,lat,lon,
       COUNT(tiv_2015) OVER (PARTITION BY tiv_2015) AS count,
       COUNT(*) OVER (PARTITION BY lat,lon) AS count_latlon
FROM Insurance) AS temp_table
WHERE count > 1 AND count_latlon = 1