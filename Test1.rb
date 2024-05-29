# Препроцесорні директиви
require 'json'

# Коментар однорядковий
=begin
Це багаторядковий коментар
=end

# Клас та методи
class Example
	def initialize(value)
		@value = value
	end

	def display
		puts "Value is: #{@value}"
	end
end

# Об'єкти, числа, рядки та ідентифікатори
example1 = Example.new(42)
example2 = Example.new(3.14)
example3 = Example.new(0xFF)

# Рядкові та символьні константи
str = "Hello, world!"
char = 'c'

# Оператори та розділові знаки
if example1 != example2
	example1.display()
	example2.display()
else
	example3.display()
end

# Використання зарезервованих слів
while true
	break if example1 == example2
end
