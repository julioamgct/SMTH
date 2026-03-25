# Anexos 1, 2, 3, 6, 7
# Instalación de Servidor LAMP y phpMyAdmin

## Apache y Firewall
sudo apt update

sudo apt install apache2

sudo ufw app list

sudo ufw allow in "Apache"

sudo ufw status

## MySQL
sudo apt install mysql-server

sudo mysql

ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'password';

exit

sudo mysql_secure_installation

sudo mysql

## PHP
sudo apt install php libapache2-mod-php php-mysql

php -v

sudo systemctl restart apache2

sudo systemctl status apache2

## phpMyAdmin
sudo apt update

sudo apt install phpmyadmin php-mbstring php-zip php-gd php-json php-curl

sudo mysql

mysql -u root -p

UNINSTALL COMPONENT "file://component_validate_password";

exit

sudo apt install phpmyadmin

mysql -u root -p

INSTALL COMPONENT "file://component_validate_password";

sudo phpenmod mbstring

sudo systemctl restart apache2

## Privilegios de Usuario
sudo mysql

SELECT user,authentication_string,plugin,host FROM mysql.user;

ALTER USER 'root'@'localhost' IDENTIFIED WITH caching_sha2_password BY 'password';

ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'password';

SELECT user,authentication_string,plugin,host FROM mysql.user;

sudo mysql

mysql -u root -p

CREATE USER 'sammy'@'localhost' IDENTIFIED WITH caching_sha2_password BY 'password';

GRANT ALL PRIVILEGES ON *.* TO 'sammy'@'localhost' WITH GRANT OPTION;

exit
