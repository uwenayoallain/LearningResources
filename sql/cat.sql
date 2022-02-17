
create table product(
    id bigint primary key auto_increment,
    title varchar(75) not null,
    summary tinytext,
    type smallint not null DEFAULT 0,
    createdAt datetime not null DEFAULT CURRENT_TIMESTAMP,
    updatedAt datetime not null DEFAULT CURRENT_TIMESTAMP
);

create table transaction(
    id bigint primary key auto_increment,
    productId bigint not null,
    transactionType varchar(10) not null,
    quantity int not null DEFAULT 0,
    transactionDateTime datetime not null DEFAULT CURRENT_TIMESTAMP,
    comment text,
    foreign key (productId) references product(id)
);

create table ProductsAvailability(
    id bigint primary key auto_increment,
    productId bigint not null,
    storeStatus varchar(100) not null DEFAULT 'Product out of stock',
    quantityInStore int not null DEFAULT 0,
    lastTransactionDateTime datetime not null DEFAULT CURRENT_TIMESTAMP,
    foreign key (productId) references product(id)
);

DELIMITER # 
CREATE TRIGGER UWENAYO_Alain_Pacifique_startRecordingProductAvailability
AFTER INSERT ON product FOR EACH ROW
BEGIN
    INSERT INTO ProductsAvailability(productId)
    VALUES(NEW.id);
END #
DELIMITER ;

DELIMITER #
CREATE TRIGGER UWENAYO_Alain_Pacifique_RecordingProductAvailability
AFTER INSERT ON transaction FOR EACH ROW
BEGIN
    UPDATE ProductsAvailability
    SET quantityInStore = IF(NEW.transactionType = 'in', NEW.quantity + quantityInStore, quantityInStore - NEW.quantity),
    lastTransactionDateTime = NEW.transactionDateTime,
    storeStatus = IF(quantityInStore > 0, 'Product In Stock', 'Product Out of Stock')
    WHERE productId = NEW.productId;
END #
DELIMITER ;

INSERT INTO product(title, summary, type) VALUES('shoe', 'nike shoes', 0);
INSERT INTO transaction(productId, transactionType, quantity,comment) VALUES(1, 'in', 10," some updates ");