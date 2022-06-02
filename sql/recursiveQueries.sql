CREATE TABLE employees (
    id INT PRIMARY KEY,
    name VARCHAR(100),
    manager_id INT,
    INDEX(manager_id),
    FOREIGN KEY (manager_id) REFERENCES employees(id)
);

INSERT INTO employees (id, name, manager_id)
VALUES (1, "Yasmina",NULL),
(2,"John",1),
(3,"Tarek",1),
(4,"Pedro",2),
(5,"Sarah",4),
(6,"Pierre",4),
(8,"Adil",3),
(9,"Sara",3);

WITH RECURSIVE EMPLOYEES_EXTENDED(id,name,path)
    AS
    (SELECT id,name,CAST(id as char(200))
    FROM employees
    WHERE manager_id IS NULL
    UNION ALL
    SELECT s.id, s.name, CONCAT(M.path , ",", s.id)
    FROM EMPLOYEES_EXTENDED M JOIN employees s ON M.id=s.manager_id)
    SELECT * FROM EMPLOYEES_EXTENDED ORDER BY path;