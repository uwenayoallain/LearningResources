-- SQLPLUS Oracle commands --
select * from global_name;
-- returns the global name of the current user

CREATE Table server_status
(
    eventNo INT auto_increment ,
    eventName VARCHAR(40),
    eventType VARCHAR(40),
    eventDate DATE,
    evenTime VARCHAR(40),
    PRIMARY KEY (eventNo)
);


CREATE OR REPLACE TRIGGER statup_trigger
AFTER STARTUP ON DATABASE
BEGIN
INSERT INTO server_status (eventName, eventType, eventDate, eventTime)
VALUES ('Server Startup', ora_sysevent, SYSDATE, TO_CHAR(SYSTIMESTAMP, 'HH24:MI:SS'));
END;

CREATE OR REPLACE TRIGGER shutdown_trigger
BEFORE SHUTDOWN ON DATABASE
BEGIN
INSERT INTO server_status (eventName, eventType, eventDate, eventTime)
VALUES ('Server Shutdown', ora_sysevent, SYSDATE, TO_CHAR(SYSTIMESTAMP, 'HH24:MI:SS'));
END;

CREATE OR REPLACE TRIGGER logon_trigger
AFTER LOGON ON DATABASE
BEGIN
INSERT INTO server_status (eventName, eventType, eventDate, eventTime)
VALUES (TO_CHAR(USER+"logged in"), ora_sysevent, SYSDATE, TO_CHAR(SYSTIMESTAMP, 'HH24:MI:SS'));
END;

CREATE OR REPLACE TRIGGER logoff_trigger
BEFORE LOGOFF ON DATABASE
BEGIN
INSERT INTO server_status (eventName, eventType, eventDate, eventTime)
VALUES (TO_CHAR(USER+"logged off"), ora_sysevent, SYSDATE, TO_CHAR(SYSTIMESTAMP, 'HH24:MI:SS'));
END;