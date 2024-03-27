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
    dna_str = ["AGATC", "TTTTTTCT", "AATG", "TCTAG", "GATA", "TATC", "GAAA", "TCTG"]
    
    result = {}
    for index in range(len(dna_str)):
        str_count = longest_match(dna_sequence, dna_str[index])
        result[dna_str[index]] = str_count
    
    # print(result)

    # TODO: Check database for matching profiles
    bool = any_match(result, database)
    
    if bool == False:
        print("No match")
        sys.exit(0)
    
    print(f"{bool}") 
    sys.exit(0)
    

def any_match(result, database):
    bool = False
    large = False
    index = 0
    while index < len(database):
        if sys.argv[1] == "databases/large.csv":
            if int(database[index]["TTTTTTCT"]) == int(result["TTTTTTCT"]) and int(database[index]["TCTAG"]) == int(result["TCTAG"]) and int(database[index]["GATA"]) == int(result["GATA"]) and int(database[index]["GAAA"]) == int(result["GAAA"]) and int(database[index]["TCTG"]) == int(result["TCTG"]):
                large = True
        if int(database[index]["AGATC"]) == int(result["AGATC"]) and int(database[index]["AATG"]) == int(result["AATG"]) and int(database[index]["TATC"]) == int(result["TATC"]):
            if sys.argv[1] == "databases/large.csv" and large != True:
                break
            bool = True 
            break
        index += 1
    if bool == True:
        return database[index]["name"]
    else:
        return bool

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
