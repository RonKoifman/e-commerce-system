/* Few notes about our project:

1. We chose to implement users login to enter the system. There is an option to register as a new
   seller or a new customer, or to sign in as an existing seller or an existing customer.
   Sellers and customers have different authorizations so it makes sense for us.
   Also, by creating a login, the possibility of authentication is added.

2. According to project instructions, there is no need to manage seller's stock. As a result
   of that, we don't allow a seller to add products with the same name. However, different sellers
   can add products with identical names but each of them will have unique serial number.
   Additionally, for the same reason we don't allow customers to add the same product (same serial
   number) to their cart.

3. We decided to add both seller and customer the option of search a product by name
   and view all products in the shop. The reason is that customers need to know which products
   offered for sale so they can choose items to purchase, and logically sellers need to know
   their competitors products to do market survey and prices comparison.
   
4. The option to place an order is available inside the checkout.

5. The options of view all existing sellers and customers available at the main login menu. */