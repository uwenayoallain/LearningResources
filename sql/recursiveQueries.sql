DELIMITER #
CREATE PROCEDURE UWENAYOAlainPacifiqueSubordinates(
    IN input_manager_id INT
    )
BEGIN
	WITH RECURSIVE subordinates_query(employee_id,manager_id,full_name)
    AS
    (
        SELECT employee_id,manager_id,full_name
        FROM employees
        WHERE employee_id = input_manager_id
        UNION ALL
        SELECT emp.employee_id, emp.manager_id, emp.full_name
        FROM employees emp JOIN subordinates_query sub ON emp.manager_id=sub.employee_id
    )
    SELECT * FROM subordinates_query;
END#
DELIMITER;

CALL UWENAYOALainPacifiqueSubordinates(2);