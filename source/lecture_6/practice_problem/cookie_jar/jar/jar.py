class Jar:
    
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError("Capacity cannot be negative")
        self.__size = []
        self.__capacity = capacity


    def __str__(self):
        cookies = ""
        for i in range(len(self.__size)):
            cookies += "O"
        return cookies


    def deposit(self, n):
        if n < 0:
            raise ValueError("Cannot deposit negative amount")
        if self.__capacity < len(self.__size) + n:
            raise ValueError("Capacity exceeded")
        for i in range(n):
            self.__size.append(i)


    def withdraw(self, n):
        if n < 0:
            raise ValueError("Cannot withdraw negative amount")
        if n > len(self.__size):
            raise ValueError("Not enough cookies")
        self.__size = self.__size[:-n]


    @property
    def capacity(self):
        return self.__capacity

    
    @property
    def size(self):
        return len(self.__size)
    

def main():
    print("Initializing jar...")
    jar = Jar(10)
    jar.deposit(5)
    jar.withdraw(2)
    print(f"String of cookies: {str(jar)}")
    print(f"Current number of cookies: {jar.size}")
    print(f"Jar capacity: {jar.capacity}")
    
main()
    