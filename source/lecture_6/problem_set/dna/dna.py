import csv
import sys


def main():

    try:
        # Check for command-line usage
        if len(sys.argv) != 3:
            raise AttributeError('Error! Wrong number of arguments!')

        # Read database file into a variable
        dna_db_name = sys.argv[1]
        dna_db = []
        file = open(dna_db_name, "r")
        reader = csv.DictReader(file)
        for row in reader:
            dna_db.append(row)

        # print(f"Database: {dna_db}")
        subsequences = list(dna_db[0].keys())[1:]
        # print(f"Subsequences: {subsequences}")

        # Read DNA sequence file into a variable
        dna_sequence_file = sys.argv[2]
        sequence = open(dna_sequence_file, "r").read()
        # print(f"sequence: {sequence}")
        
        # Find longest match of each STR in DNA sequence
        longest_matches = []
        for subsequence in subsequences:
            result = {subsequence : longest_match(sequence, subsequence)}
            longest_matches.append(result)
        
        # debugging prints
        # print(f"Result: {longest_matches}")
        # print()
        
        # Check database for matching profiles
        db_entry = []
        for entry in dna_db:
            # Bring entry into a list of dictionaries
            person_dna = []
            person_name = entry["name"]
            for key, value in entry.items():
                if key == "name":
                    continue
                person_dna.append({key : int(value)})
            
            # debugging prints
            # print(f"Person DNA: {person_name} -> {person_dna}")
            # print(f"Longest matches: {longest_matches}")
            
            match_counter = 0
            for i in range(len(person_dna)):
                # debugging prints
                # print(f"Comparing {person_dna[i]} to {longest_matches[i]}")
                # print(f"Values: {list(person_dna[i].values())} to {list(longest_matches[i].values())}")
                if list(person_dna[i].values()) == list(longest_matches[i].values()):
                    # debugging prints
                    # print(f"Match found for {person_name}!")
                    match_counter += 1
            
            if match_counter == len(person_dna):
                db_entry.append(person_name)
        
        if len(db_entry) == 0:
            print("No match")
        elif len(db_entry) == 1:
            print(f"{db_entry[0]}")
        else:
            print(f"Multiple matches: {db_entry}")

    except EOFError:
        print("Exiting...")
        sys.exit(0)
    except KeyboardInterrupt:
        print("Exiting...")
        sys.exit(0)
    except AttributeError as error:
        print(error.args)
        sys.exit(1)

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            
            # If there is no match in the substring
            else:
                break
        
        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
