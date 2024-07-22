# Write your MySQL query statement below



with reports as 
(
select reports_to as employee_id, count(*) as reports_count, round(avg(age)) as average_age from Employees
where reports_to is not null
group by reports_to
)
select 
Employees.employee_id as employee_id, 
Employees.name as name, 
reports.reports_count as reports_count, 
reports.average_age as average_age
from Employees, reports
where reports.employee_id = Employees.employee_id
order by reports.employee_id
;