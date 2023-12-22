import sys

QUARTER_VALUE = 25
DIME_VALUE = 10
NICKEL_VALUE = 5
PENNY_VALUE = 1


def get_cents():
    while True:
        try:
            # Get input from user.
            # Convert input to float, round to 2 decimal places and multiply by 100.
            # Convert to int for easier calculation.
            input_cents = int(round(float(input("Change owed: ")), 2) * 100)
            if input_cents >= 0:
                return input_cents
            else:
                print("Invalid input")
                continue    
        except ValueError:
            # Handle non-integer input
            print("Invalid input")
            continue
        except KeyboardInterrupt:
            # Handle Ctrl+C
            print()
            print("Exiting...")
            sys.exit(1)
        except EOFError:
            # Handle Ctrl+D
            print()
            print("Exiting...")
            sys.exit(1)


def calculate_quarters(cents: int):
    return int(cents / QUARTER_VALUE)

def calculate_dimes(cents: int):
    return int(cents / DIME_VALUE)

def calculate_nickels(cents: int):
    return int(cents / NICKEL_VALUE)

def calculate_pennies(cents: int):
    return int(cents / PENNY_VALUE)

def main():
    # Ask how many cents the customer is owed
    cents = get_cents()

    if cents == 0:
        print("0")
        return

    # Calculate the number of quarters to give the customer
    quarters = calculate_quarters(cents)
    cents = cents - quarters * QUARTER_VALUE

    # Calculate the number of dimes to give the customer
    dimes = calculate_dimes(cents)
    cents = cents - dimes * DIME_VALUE

    # Calculate the number of nickels to give the customer
    nickels = calculate_nickels(cents)
    cents = cents - nickels * NICKEL_VALUE

    # Calculate the number of pennies to give the customer
    pennies = calculate_pennies(cents)
    cents = cents - pennies * PENNY_VALUE

    # Sum coins
    coins = quarters + dimes + nickels + pennies

    # Print total number of coins to give the customer
    print(coins)

if __name__ == "__main__":
    main()
