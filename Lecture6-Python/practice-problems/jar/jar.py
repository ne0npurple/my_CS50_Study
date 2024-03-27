class Jar:
    def __init__(self, cpcty=0):
        if cpcty < 0:
            raise ValueError("Capacity is not an integer!")
        self.cpcty = cpcty
        self.length = 0
        
    def __str__(self):
        return "🍪" * self.size

    def deposit(self, n):
        if self.capacity > self.size and n <= (self.capacity-self.size):
            self.length += n
        else:
            raise ValueError("Jar is unable to store more cookies.")

    def withdraw(self, n):
        if n <= self.size:
            self.length -= n
        else:
            raise ValueError("No more cookies to withdraw.")

    @property
    def capacity(self):
        return self.cpcty

    @property
    def size(self):
        return self.length

jar = Jar(5)
jar.deposit(3)
print(jar.capacity, jar.size)
jar.withdraw(3)
print(jar.capacity, jar.size)
jar.withdraw(3)