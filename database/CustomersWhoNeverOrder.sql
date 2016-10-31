select name from Customers where id not in (select CustomerId from Orders);
