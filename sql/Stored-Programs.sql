/**
-- TODO 1.Procedures
-- TODO 2.Functions
-- TODO 3.Triggers
-- * "Stored program which is called when event occurs."
-- * "the events are DM languages like: insert, update, delete, and truncate."
   create trigger <trigger_name>
    (before/after/instead of)
    [insert/update/delete/truncate]
    on <table_name>
    for each row
    [trigger body]
    begin ... end

-- TODO 4.Views
-- TODO 5.Tables
-- TODO 6.Sequences
-- TODO 7.Indexes
-- TODO 8.Constraints
-- TODO 9.Exiting
*/
-- !learning triggers
create table students(
  studentId int PRIMARY KEY AUTO_INCREMENT,
  StudentName varchar(20) NOT NULL,
  StudentLocation varchar(100) NOT NULL,
  studentMarks int default 0
);
DELIMITER # create TRIGGER addMarks Before
INSERT
  on students FOR EACH ROW BEGIN
SET
  new.studentMarks = new.studentMarks + 100;
END # DELIMITER;
-- !Exercies on triggers:
-- TODO account(accountNbr,branchId,customerId,balance,openDate)
-- TODO transaction(transactionId,transactionAmount,transactionDate,accountNumber,transactionType)
-- Define a trigger which updates the balance in account each time a transaction is done.
-- account table
create table account(
  accountNumber int PRIMARY KEY AUTO_INCREMENT,
  branchId int,
  customerId int,
  balance int,
  openDate date
);
-- transaction table
create table transaction(
  transactionId int PRIMARY KEY AUTO_INCREMENT,
  transactionAmount int,
  transactionDate date,
  accountNumber int,
  transactionType varchar(20),
  FOREIGN KEY (accountNumber) REFERENCES account(accountNumber)
);
-- creating the trigger
DELIMITER # create TRIGGER updateBalance
after
INSERT
  on transaction FOR EACH ROW BEGIN IF new.transactionType = 'DEBIT' THEN
UPDATE
  account
SET
  balance = balance - new.transactionAmount
WHERE
  accountNumber = new.accountNumber;
  ELSE
UPDATE
  account
SET
  balance = balance + new.transactionAmount
WHERE
  accountNumber = new.accountNumber;
END IF;
END # DELIMITER;
-- inserting values into account table
insert into
  account(branchId, customerId, balance, openDate)
values(1, 1, 1000, CURDATE()),(2, 2, 2000, CURDATE()),(3, 3, 3000, CURDATE());
-- inserting values into transaction table
insert into
  transaction(
    transactionAmount,
    transactionDate,
    accountNumber,
    transactionType
  )
values(100, CURDATE(), 1, 'DEBIT'),(100, CURDATE(), 2, 'CREDIT');