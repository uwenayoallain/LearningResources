CREATE TABLE IF NOT EXISTS `sample` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `created_at` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
);

INSERT INTO `sample` (`name`, `email`, `password`) VALUES
('John Doe', 'joe@gmail.com', 'password'),
('Jane Doe', 'jane@gmail.com', 'password')
('Tester King', 'tester@gmail.com', 'password');