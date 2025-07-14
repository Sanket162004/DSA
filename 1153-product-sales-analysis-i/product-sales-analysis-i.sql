# Write your MySQL query statement below
select Product.product_name,sales.year,sales.price from sales
left join product
     on Sales.product_id=product.product_id ;