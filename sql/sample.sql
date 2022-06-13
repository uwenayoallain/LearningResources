CREATE DATABASE sample;

use sample;

CREATE TABLE Users(
    id INT NOT NULL AUTO_INCREMENT,
    first_name VARCHAR(80) NOT NULL,
    last_name VARCHAR(80) NOT NULL,
    email VARCHAR(80) NOT NULL,
    password VARCHAR(80) NOT NULL,
    PRIMARY KEY (id)
);

INSERT INTO Users (first_name, last_name, email, password) VALUES
    ('John', 'Doe', 'joe@gmail.com', 'password'),
    ('Jane', 'Doe', 'jane@gmail.com', 'password'),
    ('uwenayo', 'alain', 'alain@gmail.com', 'password'),
    ('capitain', 'america','capitain@gmail.com', 'password'),
    ('jean', 'michel', 'jeanmichel@gmail.com', 'password');

-- TIP 6:

-- SELECT DISTINCT first_name FROM Users;

-- TIP 7:

SELECT * FROM USERS WHERE id = 1;

SELECT first_name, last_name FROM users WHERE id = 1;

-- TIP 8:

-- SELECT TOP (4) * FROM USERS WHERE password = 'password'; # not supported by mysql
SELECT * from Users  WHERE password = 'password' LIMIT 1;