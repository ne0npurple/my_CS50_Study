import csv
import sys

def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} database/file.csv sequences/file.txt")
        sys.exit(1)

    # TODO: Read database file into a variable
    database = []
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            database.append(row)
    
    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as dnafile:
        dna_sequence = dnafile.read()
    
    # TODO: Find longest match of each STR in DNA sequence
    STR_list = list(database[0].keys())[1:]
    # store the longest str count
    result = {}
    for index in range(len(STR_list)):
        str_count = longest_match(dna_sequence, STR_list[index])
        result[STR_list[index]] = str_count
    
    # TODO: Check database for matching profiles
    bool = find_match(result, database, STR_list)

    if bool == False:
        print("No match")
        sys.exit(0)
    
    print(f"{bool}") 
    sys.exit(0)
    
    
def find_match(result, database, str_list):
    for i in range(len(database)):
        counter = 0
        for j in str_list:
            if int(result[j]) == int(database[i][j]):
                counter += 1
        if counter == len(str_list):
                return database[i]["name"]
    return False

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
